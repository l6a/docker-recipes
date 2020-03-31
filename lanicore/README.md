# `lanicore`

`lanicore` is the base Docker image used by Project Laniakea.
It contains a special `selfadd` program and an `entrypoint` script to
enable running the container as a named non-root user.
This makes `lanicore`-based containers behave like Singularity
containers and useful for (interactive) data analysis.

`selfadd` checks the current `uid` and add the necessary information
to `/etc/passwd` and `/etc/group`.
Therefore, to run `lanicore`-based images as a named non-root user,
use

    docker run --rm -it -u $(id -u):$(id -g) -e USER=$(whoami) laniakeasrc/lanicore:20200327

Images that build on `lanicore`, if override the entrypoint, should
use an entrypoint script similar to `lanicore`'s.
