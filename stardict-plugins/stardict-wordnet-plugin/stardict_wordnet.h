#ifndef _STARDICT_WORDNET_PLUGIN_H_
#define _STARDICT_WORDNET_PLUGIN_H_

#ifdef _WIN32
#if BUILDING_DLL
# define DLLIMPORT __declspec (dllexport)
#else /* Not BUILDING_DLL */
# define DLLIMPORT __declspec (dllimport)
#endif /* Not BUILDING_DLL */
#else
# define DLLIMPORT
#endif

#include "../../src/lib/plugin.h"
#include "../../src/lib/specialdictplugin.h"

extern "C" {
	DLLIMPORT extern bool stardict_plugin_init(StarDictPlugInObject *obj);
	DLLIMPORT extern void stardict_plugin_exit(void);
	DLLIMPORT extern bool stardict_specialdict_plugin_init(StarDictSpecialDictPlugInObject *obj);
}

#endif
