// OneOS - simple UI string localization
// To switch language: write "en", "ja", "zh_cn", "zh_tw", or "ko" to
// SHARED_USERDATA_PATH/lang.txt
//
// Per-language Noto Sans CJK font is selected automatically so the script
// renders with its native glyph forms (jp/sc/tc/kr).

#ifndef __LANG_H__
#define __LANG_H__

typedef struct {
	// font path for this language (full path under RES_PATH)
	const char* font_path;
	// libretro language id (enum retro_language), used to query localized core options
	int retro_lang;
	// button labels (api.c, minui.c) — upper case in upstream
	const char* resume;
	const char* brightness;
	const char* volume;
	const char* power;
	const char* sleep;
	const char* info;
	const char* back;
	const char* open;
	// status / messages (minui.c)
	const char* empty_folder;
	// root entries (minui.c)
	const char* recently_played;
	const char* collections;
	const char* tools;
	const char* settings;
	const char* language;
	// in-game menu (minarch.c top-level)
	const char* continue_;
	const char* save;
	const char* load;
	const char* options;
	const char* quit;
	const char* reset;
	// in-game options menu (minarch.c)
	const char* frontend;
	const char* emulator;
	const char* controls;
	const char* shortcuts;
	const char* save_changes;
	// shortcut names (minarch.c)
	const char* save_state;
	const char* load_state;
} Lang;

extern Lang lang;

void Lang_init(void);

#endif
