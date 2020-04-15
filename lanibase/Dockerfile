# Copyright 2019 Chi-kwan Chan
# Copyright 2019 Steward Observatory
#
# Licensed under the Apache License, Version 2.0 (the "License"); you
# may not use this file except in compliance with the License.  You
# may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied.  See the License for the specific language governing
# permissions and limitations under the License.

ARG	dsttag=10.1,20191014,buster,latest
ARG	srctag=buster-20191014-slim
ARG	digest=sha256:11253793361a12861562d1d7b15b8b7e25ac30dd631e3d206ed1ca969bf97b7d

#==============================================================================
# The base image: an official debian slim image

FROM	debian:${srctag}@${digest} AS base
LABEL	maintainer="Chi-kwan Chan <chanc@arizona.edu>"

RUN     sed -i- 's/^#//g;s/^d/# d/g;s/^ //g;' /etc/apt/sources.list &&\
	echo 'Acquire::Check-Valid-Until false;' > /etc/apt/apt.conf.d/10nochk

#==============================================================================
# The builder image: compile `selfadd`

FROM	base AS builder

COPY	entrypoint lani* selfadd.c /usr/local/sbin/
WORKDIR /usr/local/sbin/
RUN	laniapt libc6-dev tcc &&\
	tcc selfadd.c -Wall -o selfadd &&\
	rm selfadd.c

#==============================================================================
# The Laniakea base runtime image

FROM	base
ENV	LANG=C.UTF-8 \
	LC_ALL=C.UTF-8

COPY	--from=builder /usr/local/sbin/* /usr/local/sbin/
RUN	chmod u+s /usr/local/sbin/selfadd

ENTRYPOINT	["/usr/local/sbin/entrypoint"]
CMD	["bash"]
