# [`laniscm`][1]

[`laniscm`][1] provides different source-control management (SCM) such
as `git` and `mercurial`.
It is a base image to build `lanidev`.

## Releases

[`l6acon/laniscm`][1] tags | `l6acon/lanicurl` tag
--- | ---
`10.6`, `20201117`, `10`, `buster`, `latest` | `20201117`
`10.5`, `20200908`                           | `20200908`
`10.4`, `20200720`                           | `20200720`
`10.3`, `20200422`                           | `20200422`
`10.2`, `20200130`                           | `20200130`

Note that `laniscm`'s "release tags", e.g., `10.2`, have different
meaning than `debian`'s point release versions.
For `debian`, the
[point release versions](https://wiki.debian.org/DebianReleases/PointReleases)
are defined at the release time.
However, `laniscm` images are based on
[official `debian` Docker images](https://hub.docker.com/_/debian),
which are freezes of the rolling releases.
Because the `debian:10.2` Docker image only got frozen at
`debian:buster-20191014-slim`, which is closer to the `debian` 10.2
point release, there is a time lag between the same versions of
`debian` Docker images and point releases.
This time lag is carried over to `laniscm`.

[1]: https://hub.docker.com/repository/docker/l6acon/laniscm
