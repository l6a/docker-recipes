# Copyright 2020 Chi-kwan Chan
# Copyright 2020 Steward Observatory
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
# The base image: the Laniakea base image

FROM	laniakeasrc/lanibase:${snapdate} AS base

#==============================================================================
# The Laniakea Conda runtime image

FROM	base

ENV	LANG=C.UTF-8 LC_ALL=C.UTF-8
ENV	PATH /opt/conda/bin:$PATH

RUN	apt-get update &&\
	apt-get install -y --no-install-recommends \
		wget bzip2 ca-certificates \
		libglib2.0-0 libxext6 libsm6 libxrender1 \
		git mercurial subversion &&\
	apt-get clean && rm -rf /var/lib/apt/lists/* /var/tmp/* /tmp/*

RUN	wget --quiet https://repo.anaconda.com/miniconda/Miniconda3-py38_4.8.2-Linux-x86_64.sh -O ~/miniconda.sh &&\
	/bin/bash ~/miniconda.sh -b -p /opt/conda &&\
	rm ~/miniconda.sh &&\
	/opt/conda/bin/conda clean -tipsy &&\
	ln -s /opt/conda/etc/profile.d/conda.sh /etc/profile.d/conda.sh &&\
	echo ". /opt/conda/etc/profile.d/conda.sh" >> ~/.bashrc &&\
	echo "conda activate base" >> ~/.bashrc &&\
	find /opt/conda/ -follow -type f -name '*.a' -delete &&\
	find /opt/conda/ -follow -type f -name '*.js.map' -delete &&\
	/opt/conda/bin/conda clean -afy

CMD	["/bin/bash"]
