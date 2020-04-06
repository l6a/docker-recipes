# `lanipython`

`lanipython` is Project Laniakea's base Docker image for python.
Similar to the `lanibase` Docker image, it contains a special
`selfadd` program and an `entrypoint` script to enable running the
container as a named non-root user.
This makes `lanipython`-based containers behave like Singularity
containers and useful for (interactive) data analysis.

`selfadd` checks the current `uid` and add the necessary information
to `/etc/passwd` and `/etc/group`.
Therefore, to run `lanipython`-based images as a named non-root user,
use

    docker run --rm -it -u $(id -u):$(id -g) -e USER=$(whoami) laniakeasrc/lanipython:20200327

Images that build on `lanipython`, if override the entrypoint, should
use an entrypoint script similar to `lanipython`'s.
