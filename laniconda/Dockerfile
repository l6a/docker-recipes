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

ARG	dsttag=
ARG	srctag=20200327
ARG	condaversion=Miniconda3-py38_4.8.2-Linux-x86_64

#==============================================================================
# The base image: the Laniakea base image

FROM	l6acon/lanibase:${srctag} AS base

#==============================================================================
# The Laniakea Conda runtime image

FROM	base
ENV	PATH=/opt/conda/bin:$PATH
# HACK: redefine `ARG condaversion` so it survives after FROM
ARG	condaversion

RUN	laniapt wget bzip2 ca-certificates \
		libglib2.0-0 libxext6 libsm6 libxrender1 \
		git mercurial subversion
RUN	wget --quiet https://repo.anaconda.com/miniconda/${condaversion}.sh -O ~/miniconda.sh &&\
	/bin/bash ~/miniconda.sh -b -p /opt/conda &&\
	rm ~/miniconda.sh &&\
	/opt/conda/bin/conda clean -tipsy &&\
	find /opt/conda/ -follow -type f -name '*.a' -delete &&\
	find /opt/conda/ -follow -type f -name '*.js.map' -delete &&\
	/opt/conda/bin/conda clean -afy
RUN	printf "\n\
. /opt/conda/etc/profile.d/conda.sh\n\
conda activate base\n\
" | tee -a /etc/profile /etc/bash.bashrc
