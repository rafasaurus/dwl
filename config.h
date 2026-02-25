/* Taken from https://github.com/djpohly/dwl/issues/466 */
#define COLOR(hex)    { ((hex >> 24) & 0xFF) / 255.0f, \
                        ((hex >> 16) & 0xFF) / 255.0f, \
                        ((hex >> 8) & 0xFF) / 255.0f, \
                        (hex & 0xFF) / 255.0f }
/* appearance */
static const int sloppyfocus               = 1;  /* focus follows mouse */
static const int bypass_surface_visibility = 0;  /* 1 means idle inhibitors will disable idle tracking even if it's surface isn't visible  */
static const unsigned int borderpx         = 2;  /* border pixel of windows */
static const int smartgaps                 = 0;  /* 1 means no outer gap when there is only one window */
static const int monoclegaps               = 0;  /* 1 means outer gaps in monocle layout */
static const unsigned int gappih           = 10; /* horiz inner gap between windows */
static const unsigned int gappiv           = 10; /* vert inner gap between windows */
static const unsigned int gappoh           = 10; /* horiz outer gap between windows and screen edge */
static const unsigned int gappov           = 10; /* vert outer gap between windows and screen edge */
static const float rootcolor[]             = COLOR(0x222222ff);
static const float bordercolor[]           = COLOR(0x444444ff);
static const float focuscolor[]            = COLOR(0x00638bff);
static const float urgentcolor[]           = COLOR(0xff0000ff);
/* This conforms to the xdg-protocol. Set the alpha to zero to restore the old behavior */
static const float fullscreen_bg[]         = {0.0f, 0.0f, 0.0f, 1.0f}; /* You can also use glsl colors */

/* tagging - TAGCOUNT must be no greater than 31 */
#define TAGCOUNT (7)

/* logging */
static int log_level = WLR_ERROR;

/* NOTE: ALWAYS keep a rule declared even if you don't use rules (e.g leave at least one example) */
/* Rules converted from dwm, removed fields: iscentered, isterminal, noswallow */
/* dwm class maps roughly to dwl app_id */
static const Rule rules[] = {
	/* app_id                title                    tags mask     isfloating   monitor */
	{ "anki",                 NULL,                   1 << 3,       0,           -1 },
	{ "apm planner*",         NULL,                   1 << 4,       0,           -1 },
	{ "brave",                NULL,                   1 << 1,       0,           -1 },
	{ "brave-browser",        NULL,                   1 << 1,       0,           -1 },
	{ "chromium",             NULL,                   1 << 1,       0,           -1 },
	{ "cpupower-gui",         NULL,                   0,            1,           -1 },
	{ "darktable",            NULL,                   1 << 3,       0,           -1 },
	{ "dino",                 NULL,                   1 << 2,       0,           -1 },
	{ "firefox",              NULL,                   1 << 1,       0,           -1 },
	{ "google-chrome",        NULL,                   1 << 1,       0,           -1 },
	{ "librepods",            NULL,                   0,            1,           -1 },
	{ "librewolf",            NULL,                   1 << 1,       0,           -1 },
	{ "nm-connection-editor", NULL,                   0,            1,           -1 },
	{ "obsidian",             NULL,                   1 << 3,       0,           -1 },
	{ "oracle virtualbox machine",   NULL,            1 << 4,       0,           -1 },
	{ "oracle virtualbox manager",   NULL,            1 << 4,       0,           -1 },
	{ "pavucontrol",          NULL,                   0,            1,           -1 },
	{ "qbittorrent",          NULL,                   1 << 4,       0,           -1 },
	{ "qgroundcontrol",       "QGroundControl",       1 << 3,       0,           -1 },
	{ "qtpass",               NULL,                   0,            1,           -1 },
	{ "rhythmbox",            NULL,                   0,            1,           -1 },
	{ "signal",               NULL,                   1 << 2,       0,           -1 },
	{ "element",              NULL,                   1 << 2,       0,           -1 },
	{ "spotify",              NULL,                   1 << 4,       1,           -1 },
	{ "telegram",             NULL,                   1 << 2,       0,           -1 },
	{ "telegramdesktop",      NULL,                   1 << 2,       0,           -1 },
	{ "transmission",         NULL,                   1 << 4,       0,           -1 },
	{ "vlc",                  NULL,                   1 << 4,       0,           -1 },
	{ "wmbubble",             NULL,                   0,            1,           -1 },
	{ "xterm",                "xterm",                1 << 4,       0,           -1 },
	{ NULL,                   "VP",                   1 << 3,       1,           -1 },
	{ NULL,                   "popup",                0,            1,           -1 },
};

/* layout(s) */
/* Removed layouts from dwm patches: grid, centeredmaster, centeredfloatingmaster, spiral, dwindle, bstack, deck */
/* Apply dwl layout patches if you need these */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* Default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
    { "[D]",      deck },
};

/* monitors */
/* (x=-1, y=-1) is reserved as an "autoconfigure" monitor position indicator
 * WARNING: negative values other than (-1, -1) cause problems with Xwayland clients
 * https://gitlab.freedesktop.org/xorg/xserver/-/issues/899
*/
/* NOTE: ALWAYS add a fallback rule, even if you are completely sure it won't be used */
static const MonitorRule monrules[] = {
	/* name       mfact  nmaster scale layout       rotate/reflect                x    y */
	/* example of a HiDPI laptop monitor:
	{ "eDP-1",    0.5f,  1,      2,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
	*/
	/* defaults */
	{ NULL,       0.55f, 1,      1,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
};

/* keyboard */
static const struct xkb_rule_names xkb_rules[] = {
    { .layout = "us", },
    { .layout = "am", .variant = "phonetic", },
    { .layout = "ru", .variant = "phonetic", }
};

static const int repeat_rate = 25;
static const int repeat_delay = 600;

/* Trackpad */
static const int tap_to_click = 1;
static const int tap_and_drag = 1;
static const int drag_lock = 1;
static const int natural_scrolling = 0;
static const int disable_while_typing = 1;
static const int left_handed = 0;
static const int middle_button_emulation = 1;
/* You can choose between:
LIBINPUT_CONFIG_SCROLL_NO_SCROLL
LIBINPUT_CONFIG_SCROLL_2FG
LIBINPUT_CONFIG_SCROLL_EDGE
LIBINPUT_CONFIG_SCROLL_ON_BUTTON_DOWN
*/
static const enum libinput_config_scroll_method scroll_method = LIBINPUT_CONFIG_SCROLL_2FG;

/* You can choose between:
LIBINPUT_CONFIG_CLICK_METHOD_NONE
LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS
LIBINPUT_CONFIG_CLICK_METHOD_CLICKFINGER
*/
static const enum libinput_config_click_method click_method = LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS;

/* You can choose between:
LIBINPUT_CONFIG_SEND_EVENTS_ENABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED_ON_EXTERNAL_MOUSE
*/
static const uint32_t send_events_mode = LIBINPUT_CONFIG_SEND_EVENTS_ENABLED;

/* You can choose between:
LIBINPUT_CONFIG_ACCEL_PROFILE_FLAT
LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE
*/
static const enum libinput_config_accel_profile accel_profile = LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE;
static const double accel_speed = 0.1;

/* You can choose between:
LIBINPUT_CONFIG_TAP_MAP_LRM -- 1/2/3 finger tap maps to left/right/middle
LIBINPUT_CONFIG_TAP_MAP_LMR -- 1/2/3 finger tap maps to left/middle/right
*/
static const enum libinput_config_tap_button_map button_map = LIBINPUT_CONFIG_TAP_MAP_LRM;

/* If you want to use the windows key for MODKEY, use WLR_MODIFIER_LOGO */
#define MODKEY WLR_MODIFIER_ALT

#define TAGKEYS(KEY,SKEY,TAG) \
	{ MODKEY,                    KEY,            view,            {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_CTRL,  KEY,            toggleview,      {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_SHIFT, SKEY,           tag,             {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_CTRL|WLR_MODIFIER_SHIFT,SKEY,toggletag, {.ui = 1 << TAG} }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[] = { "alacritty", NULL };
static const char *menucmd[] = { "wmenu-run", NULL };
static const char *launchcmd[] = { "fuzzel", NULL };
static const char *brightup[] = { "brightnessctl", "set", "10%+", NULL };
static const char *brightdown[] = { "brightnessctl", "set", "10%-", NULL };
static const char *scrcmdselect[] = { "sh", "-c", "screenshot.sh -s", NULL };
static const char *scrcmd[] = { "sh", "-c", "screenshot.sh", NULL };
static const char *thunarcmd[] = { "sh", "-c", "thunar $HOME/Pictures/screenshots", NULL };
static const char *volumeup[]     = { "sh", "-c", "pamixer -i 3; dwlb-status --signal 0", NULL };
static const char *volumedown[]   = { "sh", "-c", "pamixer -d 3; dwlb-status --signal 0", NULL };
static const char *volumetoggle[] = { "sh", "-c", "pamixer -t; dwlb-status --signal 0", NULL };
static const char *suspendwithlock[] = { "sh", "-c", "lock.sh && systemctl suspend", NULL };
static const char *openpdfcmd[] = { "open_pdfs.sh", NULL };
// static const char *sendesc[] = { "wtype", "-k", "Escape", NULL };

#define SHIFT WLR_MODIFIER_SHIFT
#define CTRL WLR_MODIFIER_CTRL
static const Key keys[] = {
    /* Note that Shift changes certain key codes: c -> C, 2 -> at, etc. */
    /* modifier                  key                 function        argument */
    { 0,                    XKB_KEY_XF86AudioRaiseVolume,   spawn,              {.v = volumeup} },
    { 0,                    XKB_KEY_XF86AudioLowerVolume,   spawn,              {.v = volumedown} },
    { 0,                    XKB_KEY_XF86PowerOff,           spawn_reset_kb,     {.v = suspendwithlock} },
    { MODKEY|CTRL|SHIFT,    XKB_KEY_U,                      spawn,              {.v = volumeup} },
    { MODKEY|CTRL|SHIFT,    XKB_KEY_D,                      spawn,              {.v = volumedown} },
    { MODKEY|CTRL|SHIFT,    XKB_KEY_M,                      spawn,              {.v = volumetoggle} },
    { 0,                    XKB_KEY_XF86AudioMute,          spawn,              {.v = volumetoggle} },
    { MODKEY,               XKB_KEY_p,                      spawn,              {.v = menucmd} },
    { MODKEY,               XKB_KEY_v,                      spawn,              {.v = brightup} },
    { MODKEY,               XKB_KEY_c,                      spawn,              {.v = brightdown} },
    { MODKEY|SHIFT,         XKB_KEY_P,                      spawn,              {.v = scrcmdselect} },
    { MODKEY|SHIFT|CTRL,    XKB_KEY_P,                      spawn,              {.v = scrcmd} },
    { MODKEY,               XKB_KEY_o,                      spawn,              {.v = launchcmd} },
    { MODKEY|SHIFT,         XKB_KEY_O,                      spawn,              {.v = thunarcmd} },
    { MODKEY|CTRL|SHIFT,    XKB_KEY_O,                      spawn,              {.v = openpdfcmd} },
    { MODKEY,               XKB_KEY_Return,                 spawn,              {.v = termcmd} },
    { MODKEY|SHIFT,         XKB_KEY_b,                      togglebar,          {0} },
    { MODKEY,               XKB_KEY_j,                      focusstack,         {.i = +1} },
    { MODKEY,               XKB_KEY_k,                      focusstack,         {.i = -1} },
    { MODKEY,               XKB_KEY_w,                      incnmaster,         {.i = +1} },
    { MODKEY|SHIFT,         XKB_KEY_W,                      incnmaster,         {.i = -1} },
    { MODKEY,               XKB_KEY_h,                      setmfact,           {.f = -0.05f} },
    { MODKEY,               XKB_KEY_l,                      setmfact,           {.f = +0.05f} },
    { MODKEY,               XKB_KEY_s,                      incgaps,            {.i = +10 } },
    { MODKEY|SHIFT,         XKB_KEY_S,                      incgaps,            {.i = -10 } },
    { MODKEY,               XKB_KEY_g,                      togglegaps,         {0} },
    { MODKEY|SHIFT,         XKB_KEY_G,                      defaultgaps,        {0} },
    { MODKEY,               XKB_KEY_space,                  zoom,               {0} },
    { MODKEY,               XKB_KEY_Tab,                    view,               {0} },
    { MODKEY|SHIFT,         XKB_KEY_C,                      killclient,         {0} },
    { MODKEY,               XKB_KEY_t,                      setlayout,          {.v = &layouts[0]} },
    // { MODKEY,               XKB_KEY_n,                      setlayout,          {.v = &layouts[1]} },
    { MODKEY,               XKB_KEY_m,                      setlayout,          {.v = &layouts[2]} },
    { MODKEY|SHIFT,         XKB_KEY_T,                      setlayout,          {.v = &layouts[3]} },
    { MODKEY,               XKB_KEY_e,                      togglescratchpad,   {0} },
    { MODKEY|SHIFT,         XKB_KEY_E,                      addscratchpad,      {0} },
    { MODKEY,               XKB_KEY_equal,                  removescratchpad,   {0} },
    { MODKEY|SHIFT,         XKB_KEY_F,                      togglefullscreen,   {0} },
    { MODKEY|SHIFT,         XKB_KEY_space,                  togglefloating,     {0} },
    { MODKEY,               XKB_KEY_0,                      view,               {.ui = ~0} },
    { MODKEY|SHIFT,         XKB_KEY_parenright,             tag,                {.ui = ~0} }, // ShiftMask -> Key is
    { MODKEY,               XKB_KEY_comma,                  focusmon,           {.i = WLR_DIRECTION_LEFT} },
    { MODKEY,               XKB_KEY_period,                 focusmon,           {.i = WLR_DIRECTION_RIGHT} },
    { MODKEY|SHIFT,         XKB_KEY_less,                   tagmon,             {.i = WLR_DIRECTION_LEFT} },
    { MODKEY|SHIFT,         XKB_KEY_greater,                tagmon,             {.i = WLR_DIRECTION_RIGHT} },
    { MODKEY,               XKB_KEY_u,                      setxkbrules,        {.i = +0} },
    { MODKEY,               XKB_KEY_a,                      setxkbrules,        {.i = +1} },
    { MODKEY,               XKB_KEY_r,                      setxkbrules,        {.i = +2} },
    { WLR_MODIFIER_LOGO,    XKB_KEY_u,                      setxkbrules,        {.i = +0} },
    { WLR_MODIFIER_LOGO,    XKB_KEY_a,                      setxkbrules,        {.i = +1} },
    { WLR_MODIFIER_LOGO,    XKB_KEY_r,                      setxkbrules,        {.i = +2} },
    TAGKEYS(                XKB_KEY_1,                      XKB_KEY_exclam,     0),
    TAGKEYS(                XKB_KEY_2,                      XKB_KEY_at,         1),
    TAGKEYS(                XKB_KEY_3,                      XKB_KEY_numbersign, 2),
    TAGKEYS(                XKB_KEY_4,                      XKB_KEY_dollar,     3),
    TAGKEYS(                XKB_KEY_5,                      XKB_KEY_percent,    4),
    TAGKEYS(                XKB_KEY_6,                      XKB_KEY_asciicircum,5),
    TAGKEYS(                XKB_KEY_7,                      XKB_KEY_ampersand,  6),
    // TAGKEYS(                XKB_KEY_grave,                  XKB_KEY_asciitilde, 6),
    { MODKEY|SHIFT,         XKB_KEY_Q,          quit,           {0} },

	/* Ctrl-Alt-Backspace and Ctrl-Alt-Fx used to be handled by X server */
	{ WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_Terminate_Server, quit, {0} },
	/* Ctrl-Alt-Fx is used to switch to another VT, if you don't know what a VT is
	 * do not remove them.
	 */
#define CHVT(n) { WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_XF86Switch_VT_##n, chvt, {.ui = (n)} }
	CHVT(1), CHVT(2), CHVT(3), CHVT(4), CHVT(5), CHVT(6),
	CHVT(7), CHVT(8), CHVT(9), CHVT(10), CHVT(11), CHVT(12),
};

static const Button buttons[] = {
	{ MODKEY, BTN_LEFT,   moveresize,     {.ui = CurMove} },
	{ MODKEY, BTN_MIDDLE, togglefloating, {0} },
	{ MODKEY|SHIFT, BTN_LEFT,  moveresize,     {.ui = CurResize} },
};
