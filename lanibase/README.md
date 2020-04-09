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

    docker run --rm -it -u $(id -u):$(id -g) -e USER laniakeasrc/lanibase

Images that build on `lanibase`, if override the entrypoint, should
use an entrypoint script similar to `lanibase`'s.

## Releases

[`lanibase`][1] tags | `debian` tag | `debian` digest
--- | --- | ---
`10.1`, `20191014`, `buster`, `latest` | `buster-20191014-slim` | `sha256:11253793361a12861562d1d7b15b8b7e25ac30dd631e3d206ed1ca969bf97b7d`

Note that `lanibase`'s "release tags", e.g., `10.1`, have different
meaning than `debian`'s point release versions.
For `debian`, the
[point release versions](https://wiki.debian.org/DebianReleases/PointReleases)
are defined at the release time.
However, `lanibase` images are based on
[official `debian` Docker images](https://hub.docker.com/_/debian),
which are freezes of the rolling releases.
Because the `debian:10.1` Docker image only got frozen at
`debian:buster-20191014-slim`, which is closer to the `debian` 10.2
point release, there is a time lag between the same versions of
`debian` Docker images and point releases.
This time tag is carried over to `lanibase`.

[1]: https://hub.docker.com/repository/docker/laniakeasrc/lanibase
