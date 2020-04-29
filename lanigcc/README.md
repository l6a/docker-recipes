# [`lanigcc`][1]

[`lanigcc`][1] provides popular build dependencies.

Compare to the popular Docker
[`buildpack-deps`](https://hub.docker.com/_/buildpack-deps),
it contains a special `selfadd` program and an `entrypoint` script to
enable running the container as a named non-root user.
This makes `lanigcc`-based containers behave like Singularity
containers and useful for software development.

`selfadd` checks the current `uid` and add the necessary information
to `/etc/passwd` and `/etc/group`.
Therefore, to run `lanigcc`-based images as a named non-root user,
use

    docker run --rm -it -u $(id -u):$(id -g) -e USER l6acon/lanigcc

Images that build on `lanigcc`, if override the entrypoint, should
use an entrypoint script similar to `lanigcc`'s.

## Releases

[`l6acon/lanigcc`][1] tags | `l6acon/lanigcc` tag
--- | ---
`10.2`, `20200130`, `buster`, `latest` | `20200130`

Note that `lanigcc`'s "release tags", e.g., `10.2`, have different
meaning than `debian`'s point release versions.
For `debian`, the
[point release versions](https://wiki.debian.org/DebianReleases/PointReleases)
are defined at the release time.
However, `lanigcc` images are based on
[official `debian` Docker images](https://hub.docker.com/_/debian),
which are freezes of the rolling releases.
Because the `debian:10.2` Docker image only got frozen at
`debian:buster-20191014-slim`, which is closer to the `debian` 10.2
point release, there is a time lag between the same versions of
`debian` Docker images and point releases.
This time lag is carried over to `lanigcc`.

[1]: https://hub.docker.com/repository/docker/l6acon/lanigcc
