# [`lanibase`][1]

[`lanibase`][1] is the base Docker image used by Project Laniakea.
It contains a special `selfadd` program and an `entrypoint` script to
enable running the container as a named non-root user.
This makes `lanibase`-based containers behave like Singularity
containers and useful for (interactive) data analysis.

`selfadd` checks the current `uid` and add the necessary information
to `/etc/passwd` and `/etc/group`.
Therefore, to run `lanibase`-based images as a named non-root user,
use

    docker run --rm -it -u $(id -u):$(id -g) -e USER l6acon/lanibase

Images that build on `lanibase`, if override the entrypoint, should
use an entrypoint script similar to `lanibase`'s.

## Releases

[`l6acon/lanibase`][1] tags | `debian` tag | `debian` digest
--- | --- | ---
`10.3-dev`, `buster-dev`, `dev`        | `buster-20200414-slim` | `sha256:1b8a66f829a3563f98f941f4e0e2ecc619ad12f22331d297d2a9d1e2f18dc257`
`10.2`, `20200130`, `buster`, `latest` | `buster-20200130-slim` | `sha256:9ab269df3cfa21324fcbfcf5366722d99d77ab480a8cbb0727612f7ea4e6ae27`
`10.1`, `20191014`                     | `buster-20191014-slim` | `sha256:11253793361a12861562d1d7b15b8b7e25ac30dd631e3d206ed1ca969bf97b7d`

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

Because of this scheme, that `lanibase`'s stable release tags have
different meaning than `debian`'s point release versions.
For `debian`, the [point release
versions](https://wiki.debian.org/DebianReleases/PointReleases) are
defined at the release time.
However, `lanibase` images are based on [official `debian` Docker
images](https://hub.docker.com/_/debian), which are freezes of the
rolling releases.
Because the `debian:10.1` Docker image only got frozen at
`debian:buster-20191014-slim`, which is closer to the `debian` 10.2
point release, there is a time lag between the same versions of
`debian` Docker images and point releases.
This time tag is carried over to `lanibase`.

[1]: https://hub.docker.com/repository/docker/l6acon/lanibase
