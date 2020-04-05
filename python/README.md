# `lanicore`

Laniakea's `python` Docker image is the base for other python packages
used by Project Laniakea.
Similar to the `lanicore` Docker image, it contains a special
`selfadd` program and an `entrypoint` script to enable running the
container as a named non-root user.
This makes Laniakea's `python`-based containers behave like
Singularity containers and useful for (interactive) data analysis.

`selfadd` checks the current `uid` and add the necessary information
to `/etc/passwd` and `/etc/group`.
Therefore, to run Laniakea `python`-based images as a named non-root
user, use

    docker run --rm -it -u $(id -u):$(id -g) -e USER=$(whoami) laniakeasrc/python:20200327

Images that build on `python`, if override the entrypoint, should use
an entrypoint script similar to `python`'s.
