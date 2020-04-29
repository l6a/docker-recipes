# [`lanipython`][1]

[`lanipython`][1] is Project Laniakea's base Docker image for python.
Similar to the `lanibase` Docker image, it contains a special
`selfadd` program and an `entrypoint` script to enable running the
container as a named non-root user.
This makes `lanipython`-based containers behave like Singularity
containers and useful for (interactive) data analysis.

`selfadd` checks the current `uid` and add the necessary information
to `/etc/passwd` and `/etc/group`.
Therefore, to run `lanipython`-based images as a named non-root user,
use

    l6a lanipython [args]

Images that build on `lanipython`, if override the entrypoint, should
use an entrypoint script similar to `lanipython`'s.

## Releases

[`l6acon/lanipython`][1] tags | `l6acon/lanibase` tag | `python` digest
--- | --- | ---
`3.8.1`, `20200130`, `3.8`, `3`, `latest` | `20200130` | `sha256:73f3903470a6e55202a6bb989c23b047487eb1728feba655410076da24106838`

Note that `lanipython`'s "release tags", e.g., `3.8.1`, is not always
most up to date.
There is a long reason behind it.
`lanipython` uses the official `python:<version>-slim-buster` images
as base, and then copy `lanibase`'s `selfadd` etc to it.
However, it turns out that these official python images are based on
`debian:buster-slim`, which is also an image with rolling tag---that
the same tag `buster-slim` can point to different images.
The python image tags only stabilize when another version of python
comes out.
For example, as python 3.8.2 came out, the `python:3.8.2-slim-buster`
becomes the rolling tag, while `python:3.8.1-slim-buster` no longer
gets updated and is stabilized.
While in Project Laniakea, we also use digest to select external
docker images, we decided to stick with the stable python tag.

[1]: https://hub.docker.com/repository/docker/l6acon/lanipython
