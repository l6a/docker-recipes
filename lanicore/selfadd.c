/*
 * Copyright 2019 Chi-kwan Chan
 * Copyright 2019 Steward Observatory
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License.  You
 * may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.  See the License for the specific language governing
 * permissions and limitations under the License.
 */
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

static const char *
getuser(const char *def)
{
	const char *u = getenv("USER");
	return u ? u : def;
}

static int
match(FILE *f, const char *u, char d)
{
	for(; *u; ++u)
		if(getc(f) != (int)*u)
			return 0;
	return getc(f) == (int)d;
}

static int
nextline(FILE *f)
{
	for(;;) switch(getc(f)) {
		case EOF : return 0; break;
		case '\n': return 1; break;
	}
}

static void
append(const char *path, const char *u, const char *fmt, ...)
{
	va_list args;

	FILE *f = fopen(path, "a+");
	do {
		if(match(f, u, ':'))
			return; /* do not append */
	} while(nextline(f));

	va_start(args, fmt);
	vfprintf(f, fmt, args);
	va_end(args);
	fclose(f);
}

int
main(int argc, char *argv[])
{
	uid_t i = getuid();
	if(i) {
		const char *u = getuser("self");
		const char *b = "/home";
		const char *s = "/bin/bash";
		append("/etc/passwd", u,
		       "%s:x:%u:%u::%s/%s:%s\n", u, i, i, b, u, s);
		append("/etc/group", u,
		       "%s:x:%u:\n", u, i);

		if(argc > 1)
			if(!strcmp(argv[1], "-u"))
				printf("%s\n", u);
	}
	return 0;
}
