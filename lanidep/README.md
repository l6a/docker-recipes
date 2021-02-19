# [`lanidep`][1]

[`lanidep`][1] provides popular build dependencies for Project Laniakea.

Compare to the popular Docker
[`buildpack-deps`](https://hub.docker.com/_/buildpack-deps), it
contains a special `selfadd` program and an `entrypoint` script to
enable running the container as a named non-root user.
This makes `lanidep`-based containers behave like Singularity
containers and useful for software development.

`selfadd` checks the current `uid` and add the necessary information
to `/etc/passwd` and `/etc/group`.
Therefore, to run `lanidep`-based images as a named non-root user, use

    l6a lanidep [args]

Images that build on `lanidep`, if override the entrypoint, should
use an entrypoint script similar to `lanidep`'s.

## Releases

[`l6acon/lanidep`][1] tags | `l6acon/laniscm` tag
--- | ---
`10.6`, `20201117`, `10`, `buster`, `latest` | `20201117`
`10.5`, `20200908`                           | `20200908`
`10.4`, `20200720`                           | `20200720`
`10.3`, `20200422`                           | `20200422`
`10.2`, `20200130`                           | `20200130`

Note that `lanidep`'s "release tags", e.g., `10.2`, have different
meaning than `debian`'s point release versions.
For `debian`, the
[point release versions](https://wiki.debian.org/DebianReleases/PointReleases)
are defined at the release time.
However, `lanidep` images are based on
[official `debian` Docker images](https://hub.docker.com/_/debian),
which are freezes of the rolling releases.
Because the `debian:10.2` Docker image only got frozen at
`debian:buster-20191014-slim`, which is closer to the `debian` 10.2
point release, there is a time lag between the same versions of
`debian` Docker images and point releases.
This time lag is carried over to `lanidep`.

[1]: https://hub.docker.com/repository/docker/l6acon/lanidep
