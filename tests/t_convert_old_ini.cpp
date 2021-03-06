#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <cstdlib>
#include <cstdio>
#include <string>

#include <iterator>
#include <algorithm>
#include <iostream>

#include <glib.h>
#include <glib/gstdio.h>

#include "inifile.hpp"

static const char *tmpfname = "/tmp/stardict.cfg";

class TmpFile {
public:
	TmpFile(const std::string& fn) : fname_(fn) {}
	~TmpFile() { remove(fname_.c_str()); }
private:
	std::string fname_;
};

int main()
{	
	remove(tmpfname);
	
	{
		TmpFile tf(tmpfname);
		inifile ini(tmpfname);
		std::string s;
		g_assert(ini.read_string("stardict-private", "version", s));
		g_assert(s == "1.0");
	}
	FILE * f = g_fopen(tmpfname, "wb");
	if (!f) {
		fprintf(stderr, "Can not open: %s\n", tmpfname);
		return EXIT_FAILURE;
	}
	guchar list[] = {'a', 0xFF, 'b', 0xFF, 'c', '\0' };
	g_fprintf(f, "[somegroup]\nsomevalue=%s\n", list);
	fclose(f);
	{
		//TmpFile tf(tmpfname);
		inifile ini(tmpfname);
		std::string s;
		g_assert(ini.read_string("stardict-private", "version", s));
		g_assert(s == "1.0");
		std::list<std::string> slist;
		g_assert(ini.read_strlist("somegroup", "somevalue", slist));
		std::list<std::string>::iterator it = slist.begin();
		for (int i = 0; i < 3; ++i, ++it) {
			g_assert(it != slist.end());
			g_assert(*it == std::string(1, char('a' + i)));
		}
	}
	return EXIT_SUCCESS;
}
