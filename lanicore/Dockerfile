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

#==============================================================================
# The base image

FROM	debian:buster-20191224-slim AS base

RUN     sed -i- 's/^#//g;s/^d/# d/g;s/^ //g;' /etc/apt/sources.list &&\
	echo 'Acquire::Check-Valid-Until false;' > /etc/apt/apt.conf.d/10nochk

#==============================================================================
# The builder image

FROM	base AS builder

RUN	apt-get update &&\
	apt-get install -y --no-install-recommends libc6-dev tcc &&\
	apt-get clean && rm -rf /var/lib/apt/lists/* /var/tmp/* /tmp/*

WORKDIR /root
ADD	selfadd.c .
RUN	tcc selfadd.c -Wall -o selfadd

#==============================================================================
# The lanicore image

FROM	base

COPY	--from=builder /root/selfadd /usr/local/sbin/
RUN	chmod u+s /usr/local/sbin/selfadd

COPY	entrypoint /usr/local/bin/
ENTRYPOINT	["/usr/local/bin/entrypoint"]

CMD	["bash"]
