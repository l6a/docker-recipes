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

    l6a laniconda [args]

Images that build on `laniconda`, if override the entrypoint, should
use an entrypoint script similar to `laniconda`'s.

## Releases

[`l6acon/laniconda`][1] tags | `l6acon/lanibase` tag | Conda version
--- | --- | ---
`4.8.2`, `20200311`, `4.8`, `4`, `latest` | `20200130` | `py38_4.8.2`

Note that `laniconda`'s "release tags", e.g., `4.8.2`, refers to
Conda's version and is unrelated to its python or debian version.
Nevertheless, we tend try to provide more updated releases for
`laniconda` so we would use the latest version of python and debian
available at docker build time.

[1]: https://hub.docker.com/repository/docker/l6acon/laniconda
