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

ARG	snapdate=20200327

#==============================================================================
# The base image: an official debian slim image

FROM	debian:buster-${snapdate}-slim AS base

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

COPY	--from=builder /usr/local/sbin/* /usr/local/sbin/
RUN	chmod u+s /usr/local/sbin/selfadd

ENTRYPOINT	["/usr/local/sbin/entrypoint"]
CMD	["/bin/bash"]
