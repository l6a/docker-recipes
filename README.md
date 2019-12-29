# Laniakea Docker Recipes

This git repository contains Dockerfiles and related source codes and
scripts used by Project Laniakea.
It is intended to be a stable source for building base Docker images
for Project Laniakea.

## Architecture

Project Laniakea has a strong emphasis in reproducible because of its
focus on scientific computing and data analysis.
Its special needs require a different architecture for layering its
Docker images.
Standard tools such Jupyter's
[`repo2docker`](https://repo2docker.readthedocs.io/en/latest/),
therefore, cannot be used directly.
