# Laniakea Docker Recipes

This git repository contains Dockerfiles, related source codes, and
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

In Project Laniakea, *a container is a frozen environment for running
reproducible jobs*.
For example, a python container can run python scripts with identical
outputs.
A gcc container can compile codes with bit-to-bit identical binaries.
A [CASA](https://casa.nrao.edu/) container can run astrophysical data
process jobs with identical results.
The types of jobs that can be reproduced by a Laniakea container
define the *scope* of the container.

In order to achieve bit-to-bit reproducibility, containers in Project
Laniakea avoid pulling information that changes with time.
For example, we freeze the package repository to a snapshot in
`lanibase` to ensure that it always installs the same set of packages.
We also require that pip packages mark their specific versions.

In addition, given that Project Laniakea is developer-oriented, there
are situations that unstable images are needed.
These images will be post fixed by `dev` in their tags.
See the following section for details.

## Image Releases

Because reproducibility is the main goal, Project Laniakea is
conservative in releasing its image.
We avoid releasing the version `x.0` software as there are often bug
fixes; we also avoid the latest software as their official Docker
images would change.

Detailed release methods are described in each project's `README.md`
file.
Nevertheless, a typical `README.md` contains a table like the
following in its "Releases" section.

`l6acon/lanidep` tags | `l6acon/laniscm` tag
--- | ---
`buster-dev`, `dev` | `20200130`
`10.2`, `20200130`, `buster`, `latest` | `20200130`

Laniakea uses two tagging tracks to enable rapid software development
and stable software releases (for reproducible science).
All tags end with `dev` are in the "development" track and all other
tracks are in the stable track.
The development tags are rolling, i.e., the images that they point to
are expected to change, usually upon changes in upstream images.
These tags will be promoted to the stable track when they are frozen.
For example, when `debian` 10.2 is released, `10.1-dev` will be
promoted to `10.1` and become a stable tag.
Stable tags should always point the same images with fixed digests.
They are ideal for production grade data analysis pipeline to ensure
reproducibility.
