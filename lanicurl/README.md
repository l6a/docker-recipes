# [`lanicurl`][1]

[`lanicurl`][1] provides basic file download packages.
It is a base image to build `lanidev`.

## Releases

[`lanicurl`][1] tags | `lanibase` tag
--- | ---
`10.2`, `20200130`, `buster`, `latest` | `20200130`

Note that `lanicurl`'s "release tags", e.g., `10.1`, have different
meaning than `debian`'s point release versions.
For `debian`, the
[point release versions](https://wiki.debian.org/DebianReleases/PointReleases)
are defined at the release time.
However, `lanicurl` images are based on
[official `debian` Docker images](https://hub.docker.com/_/debian),
which are freezes of the rolling releases.
Because the `debian:10.1` Docker image only got frozen at
`debian:buster-20191014-slim`, which is closer to the `debian` 10.2
point release, there is a time lag between the same versions of
`debian` Docker images and point releases.
This time tag is carried over to `lanicurl`.

[1]: https://hub.docker.com/repository/docker/l6acon/lanicurl
