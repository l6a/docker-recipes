# [`lanidev`][1]

[`lanidev`][1] provides popular build dependencies.

Compare to the popular Docker
[`buildpack-deps`](https://hub.docker.com/_/buildpack-deps),
it contains a special `selfadd` program and an `entrypoint` script to
enable running the container as a named non-root user.
This makes `lanidev`-based containers behave like Singularity
containers and useful for software development.

`selfadd` checks the current `uid` and add the necessary information
to `/etc/passwd` and `/etc/group`.
Therefore, to run `lanidev`-based images as a named non-root user,
use

    docker run --rm -it -u $(id -u):$(id -g) -e USER l6acon/lanidev

Images that build on `lanidev`, if override the entrypoint, should
use an entrypoint script similar to `lanidev`'s.

## Releases

[`lanidev`][1] tags | `lanidev` tag
--- | ---
`10.1`, `20191014`, `buster`, `latest` | `20191014`

Note that `lanidev`'s "release tags", e.g., `10.1`, have different
meaning than `debian`'s point release versions.
For `debian`, the
[point release versions](https://wiki.debian.org/DebianReleases/PointReleases)
are defined at the release time.
However, `lanidev` images are based on
[official `debian` Docker images](https://hub.docker.com/_/debian),
which are freezes of the rolling releases.
Because the `debian:10.1` Docker image only got frozen at
`debian:buster-20191014-slim`, which is closer to the `debian` 10.2
point release, there is a time lag between the same versions of
`debian` Docker images and point releases.
This time tag is carried over to `lanidev`.

[1]: https://hub.docker.com/repository/docker/l6acon/lanidev
