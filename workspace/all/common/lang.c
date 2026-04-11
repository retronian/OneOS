// OneOS - simple UI string localization
//
// Switch language by writing one of:
//   en, ja, zh_cn, zh_tw, ko
// to <SHARED_USERDATA_PATH>/lang.txt

#include <stdio.h>
#include <string.h>

#include "defines.h"
#include "lang.h"

Lang lang;

#define FONT_JP RES_PATH "/NotoSansCJKjp-Bold.otf"
#define FONT_SC RES_PATH "/NotoSansCJKsc-Bold.otf"
#define FONT_TC RES_PATH "/NotoSansCJKtc-Bold.otf"
#define FONT_KR RES_PATH "/NotoSansCJKkr-Bold.otf"

static const Lang lang_en = {
	.font_path       = FONT_JP, // jp variant has full Latin coverage
	.retro_lang      = 0,  // RETRO_LANGUAGE_ENGLISH
	.resume          = "RESUME",
	.brightness      = "BRIGHTNESS",
	.volume          = "VOLUME",
	.power           = "POWER",
	.sleep           = "SLEEP",
	.info            = "INFO",
	.back            = "BACK",
	.open            = "OPEN",
	.empty_folder    = "Empty folder",
	.recently_played = "Recently Played",
	.collections     = "Collections",
	.tools           = "Tools",
	.settings        = "Settings",
	.language        = "Language",
	.continue_       = "Continue",
	.save            = "Save",
	.load            = "Load",
	.options         = "Options",
	.quit            = "Quit",
	.reset           = "Reset",
	.frontend        = "Frontend",
	.emulator        = "Emulator",
	.controls        = "Controls",
	.shortcuts       = "Shortcuts",
	.save_changes    = "Save Changes",
	.save_state      = "Save State",
	.load_state      = "Load State",
};

static const Lang lang_ja = {
	.font_path       = FONT_JP,
	.retro_lang      = 1,  // RETRO_LANGUAGE_JAPANESE
	.resume          = "再開",
	.brightness      = "明るさ",
	.volume          = "音量",
	.power           = "電源",
	.sleep           = "スリープ",
	.info            = "情報",
	.back            = "戻る",
	.open            = "開く",
	.empty_folder    = "空のフォルダ",
	.recently_played = "最近遊んだ",
	.collections     = "コレクション",
	.tools           = "ツール",
	.settings        = "設定",
	.language        = "言語",
	.continue_       = "続ける",
	.save            = "セーブ",
	.load            = "ロード",
	.options         = "設定",
	.quit            = "終了",
	.reset           = "リセット",
	.frontend        = "本体",
	.emulator        = "エミュレーター",
	.controls        = "操作",
	.shortcuts       = "ショートカット",
	.save_changes    = "保存",
	.save_state      = "状態保存",
	.load_state      = "状態読込",
};

// Simplified Chinese (中国大陆 / Mainland China, Singapore)
static const Lang lang_zh_cn = {
	.font_path       = FONT_SC,
	.retro_lang      = 12,  // RETRO_LANGUAGE_CHINESE_SIMPLIFIED
	.resume          = "继续",
	.brightness      = "亮度",
	.volume          = "音量",
	.power           = "电源",
	.sleep           = "睡眠",
	.info            = "信息",
	.back            = "返回",
	.open            = "打开",
	.empty_folder    = "空文件夹",
	.recently_played = "最近游玩",
	.collections     = "收藏",
	.tools           = "工具",
	.settings        = "设置",
	.language        = "语言",
	.continue_       = "继续",
	.save            = "保存",
	.load            = "读取",
	.options         = "选项",
	.quit            = "退出",
	.reset           = "重置",
	.frontend        = "系统",
	.emulator        = "模拟器",
	.controls        = "控制",
	.shortcuts       = "快捷键",
	.save_changes    = "保存",
	.save_state      = "存档",
	.load_state      = "读档",
};

// Traditional Chinese (台灣 / Taiwan, Hong Kong)
static const Lang lang_zh_tw = {
	.font_path       = FONT_TC,
	.retro_lang      = 11,  // RETRO_LANGUAGE_CHINESE_TRADITIONAL
	.resume          = "繼續",
	.brightness      = "亮度",
	.volume          = "音量",
	.power           = "電源",
	.sleep           = "睡眠",
	.info            = "資訊",
	.back            = "返回",
	.open            = "開啟",
	.empty_folder    = "空資料夾",
	.recently_played = "最近遊玩",
	.collections     = "收藏",
	.tools           = "工具",
	.settings        = "設定",
	.language        = "語言",
	.continue_       = "繼續",
	.save            = "儲存",
	.load            = "載入",
	.options         = "選項",
	.quit            = "結束",
	.reset           = "重設",
	.frontend        = "系統",
	.emulator        = "模擬器",
	.controls        = "控制",
	.shortcuts       = "快捷鍵",
	.save_changes    = "儲存",
	.save_state      = "存檔",
	.load_state      = "讀檔",
};

// Spanish (Español)
static const Lang lang_es = {
	.font_path       = FONT_JP, // jp variant has full Latin coverage
	.retro_lang      = 3,  // RETRO_LANGUAGE_SPANISH
	.resume          = "REANUDAR",
	.brightness      = "BRILLO",
	.volume          = "VOLUMEN",
	.power           = "ENCENDER",
	.sleep           = "SUSPENDER",
	.info            = "INFO",
	.back            = "ATRÁS",
	.open            = "ABRIR",
	.empty_folder    = "Carpeta vacía",
	.recently_played = "Recientes",
	.collections     = "Colecciones",
	.tools           = "Herramientas",
	.settings        = "Ajustes",
	.language        = "Idioma",
	.continue_       = "Continuar",
	.save            = "Guardar",
	.load            = "Cargar",
	.options         = "Opciones",
	.quit            = "Salir",
	.reset           = "Reiniciar",
	.frontend        = "Sistema",
	.emulator        = "Emulador",
	.controls        = "Controles",
	.shortcuts       = "Atajos",
	.save_changes    = "Guardar",
	.save_state      = "Guardar est.",
	.load_state      = "Cargar est.",
};

// French (Français)
static const Lang lang_fr = {
	.font_path       = FONT_JP, // jp variant has full Latin coverage
	.retro_lang      = 2,  // RETRO_LANGUAGE_FRENCH
	.resume          = "REPRENDRE",
	.brightness      = "LUMINOSITÉ",
	.volume          = "VOLUME",
	.power           = "ALIM",
	.sleep           = "VEILLE",
	.info            = "INFO",
	.back            = "RETOUR",
	.open            = "OUVRIR",
	.empty_folder    = "Dossier vide",
	.recently_played = "Récents",
	.collections     = "Collections",
	.tools           = "Outils",
	.settings        = "Réglages",
	.language        = "Langue",
	.continue_       = "Continuer",
	.save            = "Sauver",
	.load            = "Charger",
	.options         = "Options",
	.quit            = "Quitter",
	.reset           = "Reset",
	.frontend        = "Système",
	.emulator        = "Émulateur",
	.controls        = "Commandes",
	.shortcuts       = "Raccourcis",
	.save_changes    = "Sauver",
	.save_state      = "Sauv. état",
	.load_state      = "Charg. état",
};

// Korean (한국어)
static const Lang lang_ko = {
	.font_path       = FONT_KR,
	.retro_lang      = 10,  // RETRO_LANGUAGE_KOREAN
	.resume          = "재개",
	.brightness      = "밝기",
	.volume          = "음량",
	.power           = "전원",
	.sleep           = "절전",
	.info            = "정보",
	.back            = "뒤로",
	.open            = "열기",
	.empty_folder    = "빈 폴더",
	.recently_played = "최근 플레이",
	.collections     = "컬렉션",
	.tools           = "도구",
	.settings        = "설정",
	.language        = "언어",
	.continue_       = "계속",
	.save            = "저장",
	.load            = "로드",
	.options         = "설정",
	.quit            = "종료",
	.reset           = "재시작",
	.frontend        = "본체",
	.emulator        = "에뮬",
	.controls        = "조작",
	.shortcuts       = "단축키",
	.save_changes    = "저장",
	.save_state      = "상태저장",
	.load_state      = "상태로드",
};

void Lang_init(void) {
	lang = lang_en; // default

	FILE* f = fopen(SHARED_USERDATA_PATH "/lang.txt", "r");
	if (!f) return;

	char code[16] = {0};
	if (fgets(code, sizeof(code), f)) {
		// strip trailing whitespace/newlines
		for (int i = (int)strlen(code) - 1; i >= 0; i--) {
			if (code[i] == '\n' || code[i] == '\r' || code[i] == ' ' || code[i] == '\t') code[i] = '\0';
			else break;
		}
		if (strcmp(code, "ja") == 0)         lang = lang_ja;
		else if (strcmp(code, "zh_cn") == 0) lang = lang_zh_cn;
		else if (strcmp(code, "zh_tw") == 0) lang = lang_zh_tw;
		else if (strcmp(code, "ko") == 0)    lang = lang_ko;
		else if (strcmp(code, "es") == 0)    lang = lang_es;
		else if (strcmp(code, "fr") == 0)    lang = lang_fr;
	}
	fclose(f);
}
