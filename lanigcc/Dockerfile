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

ARG	dsttag=10.6,20201117,10,buster,latest
ARG	srctag=20201117

FROM	l6acon/lanidep:${srctag}
RUN	laniapt gcc g++ gfortran libopenmpi-dev \
		libtool \
		libscalapack-mpi-dev \
		libfftw3-mpi-dev \
		libhdf5-mpi-dev libnetcdf-mpi-dev
