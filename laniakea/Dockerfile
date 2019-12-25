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
# The builder image
FROM	debian:buster-20191224-slim AS builder
RUN	apt-get update &&\
	apt-get install -y gcc &&\
	apt-get clean &&\
	rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
WORKDIR /root
ADD	selfadd.c .
RUN	gcc selfadd.c -Wall -Wextra -O3 -o selfadd

#==============================================================================
# The laniakea image
FROM	debian:buster-20191224-slim
COPY	--from=builder /root/selfadd /usr/local/sbin/
RUN	chmod u+s /usr/local/sbin/selfadd
COPY	entrypoint /usr/local/bin/
ENTRYPOINT	["/usr/local/bin/entrypoint"]
CMD	["bash"]
