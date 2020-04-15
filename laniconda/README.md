# `laniconda`

`laniconda` is Project Laniakea's base Docker image for Conda.
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
