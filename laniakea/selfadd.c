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

static const char *getuser(const char *def)
{
	const char *u = getenv("USER");
	return u ? u : def;
}

static void append(const char *path, const char *fmt, ...)
{
	FILE *f = fopen(path, "a");
	va_list args;
	va_start(args, fmt);
	vfprintf(f, fmt, args);
	va_end(args);
	fclose(f);
}

int main()
{
	uid_t i = getuid();
	if(i) {
		const char *u = getuser("self");
		const char *b = "/home";
		const char *s = "/bin/bash";
		append("/etc/passwd",
		       "%s:x:%u:%u::%s/%s:%s\n", u, i, i, b, u, s);
		append("/etc/group",
		       "%s:x:%u:\n", u, i);
	}
	return 0;
}
