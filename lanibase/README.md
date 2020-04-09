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

[1]: https://hub.docker.com/repository/docker/laniakeasrc/lanibase
