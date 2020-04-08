# Laniakea Docker Recipes

This git repository contains Dockerfiles and related source codes and
scripts used by Project Laniakea.
It is intended to be a stable source for building base Docker images
for Project Laniakea.

## Architecture

Project Laniakea has a strong emphasis in reproducible because of its
focus on scientific computing and data analysis.
Its special needs require a different architecture for layering Docker
images.
Standard tools such Jupyter's
[`repo2docker`](https://repo2docker.readthedocs.io/en/latest/),
therefore, cannot be used directly.

In Project Laniakea, *a container is always a frozen environment for
running reproducible jobs*.
For example, a python container can run python scripts with identical
outputs.
A gcc container can compile codes with bit-to-bit identical binaries.
A [CASA](https://casa.nrao.edu/) container can run
astrophysical data process jobs with identical results.
The types of jobs that can be reproduced by a Laniakea container
define the *scope* of the container.

In order to achieve bit-to-bit reproducibility, containers in Project
Laniakea avoid pulling information that changes with time.
For example, we freeze the package repository to a snapshot in
`lanibase` to ensure that it always installs the same set of packages.
We also require that pip packages mark their specific versions.

## Image Releases

Because reproducibility is the main goal, Project Laniakea is
conservative in releasing its image.
We avoid releasing the version `x.0` software as there are often bug
fixes; we also avoid the latest software as their official Docker
images would change.
Detailed release methods are described in each project's `README.md`
file.
