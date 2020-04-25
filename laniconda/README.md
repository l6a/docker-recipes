# [`laniconda`][1]

[`laniconda`][1] is Project Laniakea's base Docker image for Conda.
Similar to the `lanibase` Docker image, it contains a special
`selfadd` program and an `entrypoint` script to enable running the
container as a named non-root user.
This makes `laniconda`-based containers behave like Singularity
containers and useful for (interactive) data analysis.

`selfadd` checks the current `uid` and add the necessary information
to `/etc/passwd` and `/etc/group`.
Therefore, to run `laniconda`-based images as a named non-root user,
use

    docker run --rm -it -u $(id -u):$(id -g) -e USER l6acon/laniconda

Images that build on `laniconda`, if override the entrypoint, should
use an entrypoint script similar to `laniconda`'s.

## Releases

[`l6acon/laniconda`][1] tags | `l6acon/lanibase` tag | Conda version
--- | --- | ---
`4.8.2`, `20200130`, `4.8`, `4`, `latest` | `20200130` | `py38_4.8.2`

Note that `laniconda`'s "release tags", e.g., `10.1`, have different
meaning than `debian`'s point release versions.
For `debian`, the
[point release versions](https://wiki.debian.org/DebianReleases/PointReleases)
are defined at the release time.
However, `laniconda` images are based on
[official `debian` Docker images](https://hub.docker.com/_/debian),
which are freezes of the rolling releases.
Because the `debian:10.1` Docker image only got frozen at
`debian:buster-20191014-slim`, which is closer to the `debian` 10.2
point release, there is a time lag between the same versions of
`debian` Docker images and point releases.
This time tag is carried over to `laniconda`.

[1]: https://hub.docker.com/repository/docker/l6acon/laniconda
