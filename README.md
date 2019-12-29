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

In Laniakea, *a container is always a frozen environment for running
reproducible jobs*.
For example, a [CASA](https://casa.nrao.edu/) container can run
astrophysical data process jobs with identical results.
A python container can run python scripts with identical outputs.
A gcc container can compile codes with bit-to-bit identical binaries.
The types of jobs that can be reproduced by a Laniakea container
define the *scope* of the container.
