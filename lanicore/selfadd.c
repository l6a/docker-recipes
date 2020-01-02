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

/**
 ** Add $USER to "/etc/passwd" and "/etc/group"
 **
 ** Writing a BASH script to use `useradd` is probably the simplest
 ** way to do the same thing.  However, setuid is disallowed for
 ** scripts so we have to write a mini compiled program for this.
 **/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
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

static int
exist(FILE *f, const char *u, char d)
{
	do {
		if(match(f, u, d))
			return 1;
	} while(nextline(f));
	return 0;
}

static void
append(const char *path, const char *u, const char *fmt, ...)
{
	FILE *f = fopen(path, "a+");
	if(!f) {
		fprintf(stderr,
		        "Failed to open \"%s\" for reading and appending; "
		        "do nothing\n",
		        path);
		return;
	}

	if(exist(f, u, ':'))
		fprintf(stderr,
		        "\"%s\" found in \"%s\"; do nothing.\n",
		        u, path);
	else {
		va_list args;
		va_start(args, fmt);
		vfprintf(f, fmt, args);
		va_end(args);
	}
	fclose(f);
}

int
main(int argc, char *argv[])
{
	uid_t i = getuid();
	if(i) {
		const char *u = getuser("self");
		const char *m = "Laniakea User";
		const char *b = "/home";
		const char *s = "/bin/bash";
		append("/etc/passwd", u,
		       "%s:x:%u:%u:%s:%s/%s:%s\n", u, i, i, m, b, u, s);
		append("/etc/group", u,
		       "%s:x:%u:\n", u, i);

		if(argc > 1 && !strcmp(argv[1], "-u"))
			printf("%s\n", u);
	}
	return 0;
}
