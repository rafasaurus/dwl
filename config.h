/* dwl config.h - Converted from dwm config */

/* Taken from https://github.com/djpohly/dwl/issues/466 */
#define COLOR(hex)    { ((hex >> 24) & 0xFF) / 255.0f, \
                        ((hex >> 16) & 0xFF) / 255.0f, \
                        ((hex >> 8) & 0xFF) / 255.0f, \
                        (hex & 0xFF) / 255.0f }
/* appearance */
static const int sloppyfocus               = 1;  /* focus follows mouse */
static const int bypass_surface_visibility = 0;  /* 1 means idle inhibitors will disable idle tracking even if it's surface isn't visible  */
static const int smartgaps                 = 0;  /* 1 means no outer gap when there is only one window */
static const int monoclegaps               = 0;  /* 1 means outer gaps in monocle layout */
static const unsigned int gappih           = 10; /* horiz inner gap between windows */
static const unsigned int gappiv           = 10; /* vert inner gap between windows */
static const unsigned int gappoh           = 10; /* horiz outer gap between windows and screen edge */
static const unsigned int gappov           = 10; /* vert outer gap between windows and screen edge */
static const int smartborders              = 1;
static const unsigned int borderpx         = 3;  /* border pixel of windows (from dwm borderpx) */
static const float rootcolor[]             = COLOR(0x1C1021ff); /* from dwm normbgcolor */
static const float bordercolor[]           = COLOR(0x333333ff); /* from dwm normbordercolor */
static const float focuscolor[]            = COLOR(0x4F335Fff); /* from dwm selbordercolor */
static const float urgentcolor[]           = COLOR(0xff0000ff); /* Default red */
/* This conforms to the xdg-protocol. Set the alpha to zero to restore the old behavior */
static const float fullscreen_bg[]         = {0.1f, 0.1f, 0.1f, 1.0f}; /* Default */

/* tagging - TAGCOUNT must be no greater than 31 */
#define TAGCOUNT (5) /* from dwm tags */

/* logging */
static int log_level = WLR_ERROR;

/* NOTE: ALWAYS keep a rule declared even if you don't use rules (e.g leave at least one example) */
/* Rules converted from dwm, removed fields: iscentered, isterminal, noswallow */
/* dwm class maps roughly to dwl app_id */
static const Rule rules[] = {
	/* app_id                title                    tags mask     isfloating   monitor */
	{ "Nm-connection-editor", NULL,                   0,            1,           -1 },
	{ "firefox",              NULL,                   1 << 1,       0,           -1 },
	{ "LibreWolf",            NULL,                   1 << 1,       0,           -1 },
	{ "Google-chrome",        NULL,                   1 << 1,       0,           -1 },
	{ "Firefox",              "Firefox Preferences",  0,            1,           -1 }, // Assuming app_id is "Firefox"
	{ "Nightly",              NULL,                   1 << 1,       0,           -1 },
	{ "TelegramDesktop",      NULL,                   1 << 2,       0,           -1 },
	{ "dino",                 NULL,                   1 << 2,       0,           -1 },
	{ "KotatogramDesktop",    NULL,                   1 << 2,       0,           -1 },
	{ "Signal",               NULL,                   1 << 2,       0,           -1 },
	{ "Zeal",                 NULL,                   1 << 3,       0,           -1 },
	{ "Anki",                 NULL,                   1 << 3,       0,           -1 },
	{ "Darktable",            NULL,                   1 << 3,       0,           -1 },
	{ "Surf",                 NULL,                   1 << 3,       0,           -1 }, // Note: dwl might see Surf differently
	{ "obsidian",             NULL,                   1 << 3,       0,           -1 },
	{ "MATLAB R2024a",        NULL,                   1 << 3,       0,           -1 }, // Check if app_id is correct
	{ "Notion",               NULL,                   1 << 4,       0,           -1 },
	{ "notion-app",           NULL,                   1 << 4,       0,           -1 },
	{ "Spotify",              NULL,                   1 << 4,       1,           -1 }, // Was centered=1, now just floating=1
	{ "transmission",         NULL,                   1 << 4,       0,           -1 }, // Assuming app_id is "transmission"
	{ "VirtualBox Machine",   NULL,                   1 << 4,       0,           -1 }, // Check app_id
	{ "VirtualBox Manager",   NULL,                   1 << 4,       0,           -1 }, // Check app_id
	{ "jetbrains-studio",     NULL,                   1 << 4,       0,           -1 },
	{ NULL,                   "VP",                   1 << 3,       1,           -1 }, // Was centered=1
	{ "Synergy",              NULL,                   1 << 4,       0,           -1 }, // Check app_id
	{ "APM Planner",          NULL,                   1 << 4,       0,           -1 }, // Check app_id
	{ "Google Earth Pro",     NULL,                   1 << 4,       0,           -1 }, // Check app_id
	{ "Barrier",              NULL,                   1 << 4,       0,           -1 }, // Check app_id
	{ "rhythmbox",            NULL,                   0,            1,           -1 }, // Was centered=1
	{ "QtPass",               NULL,                   0,            1,           -1 }, // Was centered=1
	{ "Rhythmbox",            NULL,                   0,            1,           -1 }, // Was centered=1
	{ "Pcmanfm",              NULL,                   0,            1,           -1 }, // Was centered=1
	{ "Mavproxy",             NULL,                   1 << 3,       1,           -1 }, // Check app_id
	{ "vlc",                  NULL,                   1 << 4,       0,           -1 },
	{ "sxiv",                 NULL,                   0,            0,           -1 },
	{ "mpv",                  NULL,                   0,            0,           -1 },
	{ "St",                   NULL,                   0,            0,           -1 }, // Note: isterminal/noswallow removed
	{ "Chromium",             NULL,                   1 << 1,       0,           -1 }, // Note: noswallow removed
	{ "Brave-browser",        NULL,                   1 << 1,       0,           -1 }, // Note: noswallow removed
	{ "QGroundControl",       NULL,                   1 << 3,       0,           -1 },
	{ "XTerm",                NULL,                   1 << 4,       0,           -1 },
	{ "Cpupower-gui",         NULL,                   0,            1,           -1 }, // Was centered=1
	{ NULL,                   "popup",                0,            1,           -1 }, // Was centered=1, noswallow removed
	{ "wmbubble",             NULL,                   0,            1,           -1 }, // Was centered=1
	{ "Pavucontrol",          NULL,                   0,            1,           -1 }, // Was centered=1
	{ "shermans_applet",      NULL,                   0,            1,           -1 }, // Was centered=1, noswallow removed
	{ "wmforecast",           NULL,                   0,            1,           -1 }, // Was centered=1, noswallow removed
	{ "wmfishtime",           NULL,                   0,            1,           -1 }, // Was centered=1, noswallow removed
    /* Example dwl rules */
	{ "Gimp_EXAMPLE",         NULL,                   0,            1,           -1 },
	{ "firefox_EXAMPLE",      NULL,                   1 << 8,       0,           -1 },
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
/* Moved mfact and nmaster from dwm config here */
static const MonitorRule monrules[] = {
	/* name       mfact nmaster scale layout       rotate/reflect                x    y */
	/* example of a HiDPI laptop monitor:
	{ "eDP-1",    0.5f,  1,      2,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
	*/
	/* defaults */
	{ NULL,       0.55f, 1,      1,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 }, /* mfact=0.55, nmaster=1 from dwm */
};

/* keyboard */
static const struct xkb_rule_names xkb_rules = {
	/* can specify fields: rules, model, layout, variant, options */
	/* example:
	*/
    .layout = "us,am,ru",
    .variant = ",phonetic,phonetic",
	.options = "grp:win_space_toggle",
};

static const int repeat_rate = 25;
static const int repeat_delay = 600;

/* Trackpad - Using dwl template defaults */
static const int tap_to_click = 1;
static const int tap_and_drag = 1;
static const int drag_lock = 1;
static const int natural_scrolling = 0;
static const int disable_while_typing = 1;
static const int left_handed = 0;
static const int middle_button_emulation = 0;
static const enum libinput_config_scroll_method scroll_method = LIBINPUT_CONFIG_SCROLL_2FG;
static const enum libinput_config_click_method click_method = LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS;
static const uint32_t send_events_mode = LIBINPUT_CONFIG_SEND_EVENTS_ENABLED;
static const enum libinput_config_accel_profile accel_profile = LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE;
static const double accel_speed = 0.0;
static const enum libinput_config_tap_button_map button_map = LIBINPUT_CONFIG_TAP_MAP_LRM;

/* If you want to use the windows key for MODKEY, use WLR_MODIFIER_LOGO */
#define MODKEY WLR_MODIFIER_ALT /* Changed from dwm Mod1Mask */

#define TAGKEYS(KEY,SKEY,TAG) \
	{ MODKEY,                    KEY,            view,            {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_CTRL,  KEY,            toggleview,      {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_SHIFT, SKEY,           tag,             {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_CTRL|WLR_MODIFIER_SHIFT,SKEY,toggletag, {.ui = 1 << TAG} }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[] = { "alacritty", NULL }; /* Set your preferred Wayland terminal */
static const char *menucmd[] = { "wmenu-run", NULL }; /* Replaced dmenu_run */
static const char *launchcmd[] = { "fuzzel", NULL };
static const char *brightup[] = { "brightnessctl", "set", "10%+", NULL };
static const char *brightdown[] = { "brightnessctl", "set", "10%-", NULL };
static const char *scrcmd[] = { "sh", "-c", "$HOME/.local/bin/screenshot.sh", NULL };
static const char *thunarcmd[] = { "sh", "-c", "thunar", "$HOME/Pictures/screenshots", NULL };
static const char *volumeup[] = { "pamixer", "-i","10", NULL };
static const char *volumedown[] = { "pamixer", "-d","10", NULL };
static const char *volumetoggle[] = { "amixer", "-D", "pulse", "set", "Master", "toggle", NULL };

/* Keybindings converted from dwm, removed bindings for bar, gaps, extra layouts, scratchpad etc. */
static const Key keys[] = {
	/* Note that Shift changes certain key codes: c -> C, 2 -> at, etc. */
	/* modifier                  key                 function        argument */
    { 0,                         XKB_KEY_XF86AudioRaiseVolume,          spawn, {.v = volumeup} },
    { 0,                         XKB_KEY_XF86AudioLowerVolume,          spawn, {.v = volumedown} },
    { 0,                         XKB_KEY_XF86AudioMute,                 spawn, {.v = volumetoggle} },
	{ MODKEY,                    XKB_KEY_p,          spawn,          {.v = menucmd} },
	{ MODKEY,                    XKB_KEY_v,          spawn,          {.v = brightup} },
	{ MODKEY,                    XKB_KEY_c,          spawn,          {.v = brightdown} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_P,          spawn,          {.v = scrcmd} },
	{ MODKEY,                    XKB_KEY_o,          spawn,          {.v = launchcmd} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_O,          spawn,          {.v = thunarcmd} },
	{ MODKEY,                    XKB_KEY_Return,     spawn,          {.v = termcmd} },
	{ MODKEY,                    XKB_KEY_b,          togglebar,      {0} },
	/* { MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } }, // Removed: No rotatestack */
	/* { MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } }, // Removed: No rotatestack */
	{ MODKEY,                    XKB_KEY_j,          focusstack,     {.i = +1} },
	{ MODKEY,                    XKB_KEY_k,          focusstack,     {.i = -1} },
	{ MODKEY,                    XKB_KEY_w,          incnmaster,     {.i = +1} }, // dwm: XK_w
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_W,          incnmaster,     {.i = -1} }, // dwm: XK_w | ShiftMask
	{ MODKEY,                    XKB_KEY_h,          setmfact,       {.f = -0.05f} },
	{ MODKEY,                    XKB_KEY_l,          setmfact,       {.f = +0.05f} },
	/* Gap bindings removed */
	{ MODKEY,                       XKB_KEY_s,      incgaps,       {.i = +10 } },
	/* { MODKEY|WLR_MODIFIER_SHIFT,             XKB_KEY_s,      incgaps,       {.i = -15 } }, */
	{ MODKEY|WLR_MODIFIER_SHIFT,    XKB_KEY_S,      incgaps,       {.i = -10 } },
	// { MODKEY|WLR_MODIFIER_SHIFT,             XKB_KEY_z,      incgaps,       {.i = -10 } },
	{ MODKEY,                       XKB_KEY_g,      togglegaps,     {0} },
	/* { MODKEY|WLR_MODIFIER_SHIFT,             XKB_KEY_g,      defaultgaps,    {0} }, */
	/* XRDB binding removed */
	{ MODKEY,                    XKB_KEY_space,      zoom,           {0} }, // dwm: XK_space
	{ MODKEY,                    XKB_KEY_Tab,        view,           {0} }, // dwm: XK_Tab
	/* { MODKEY|ShiftMask,             XK_Tab,    view,           {1} }, // Removed: dwm specific alt-tab? */
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_C,          killclient,     {0} }, // dwm: XK_c | ShiftMask
	{ MODKEY,                    XKB_KEY_t,          setlayout,      {.v = &layouts[0]} }, /* tile */
	{ MODKEY,                    XKB_KEY_n,          setlayout,      {.v = &layouts[1]} }, /* floating (NULL) - dwm: XK_n */
	{ MODKEY,                    XKB_KEY_m,          setlayout,      {.v = &layouts[2]} }, /* monocle */
    { MODKEY,                    XKB_KEY_d,          setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                    XKB_KEY_e,          togglescratchpad,    {0} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_E,          addscratchpad, {0} },
	{ MODKEY,                    XKB_KEY_equal,          removescratchpad, {0} },
	/* Removed layout bindings for: bstack, deck, centeredmaster, centeredfloatingmaster, spiral, dwindle, grid */
	/* { MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[8]} }, // bstack */
	/* { MODKEY,                       XK_d,      setlayout,      {.v = &layouts[9]} }, // deck */
	/* { MODKEY,                       XK_i,      setlayout,      {.v = &layouts[5]} }, // centeredmaster */
	/* { MODKEY|ShiftMask,             XK_i,      setlayout,      {.v = &layouts[4]} }, // centeredfloatingmaster */
	/* { MODKEY,                       XK_y,      setlayout,      {.v = &layouts[6]} }, // spiral */
	/* { MODKEY|ShiftMask,             XK_y,      setlayout,      {.v = &layouts[7]} }, // dwindle */
	/* { MODKEY,                       XK_g,      setlayout,      {.v = &layouts[3]} }, // grid - was togglegaps in dwm */
	{ MODKEY,                    XKB_KEY_f,          togglefullscreen, {0} }, // dwm: XK_f | ShiftMask
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_space,      togglefloating, {0} }, // dwm: XK_space | ShiftMask
	/* { MODKEY,                       XK_0,      view,           {.ui = ~0 } }, // Using template default for view all */
	{ MODKEY,                    XKB_KEY_0,          view,           {.ui = ~0} }, // dwl template default
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_parenright, tag,            {.ui = ~0} }, // dwm: XK_0 | ShiftMask -> Key is ')' which is Shift+0
	{ MODKEY,                    XKB_KEY_comma,      focusmon,       {.i = WLR_DIRECTION_LEFT} },
	{ MODKEY,                    XKB_KEY_period,     focusmon,       {.i = WLR_DIRECTION_RIGHT} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_less,       tagmon,         {.i = WLR_DIRECTION_LEFT} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_greater,    tagmon,         {.i = WLR_DIRECTION_RIGHT} },
	/* { MODKEY|ShiftMask,             XK_n,      togglealttag,   {0} }, // Removed: Alt tags patch */
	/* Use dwl TAGKEYS macro format (Key, ShiftedKey, TagIndex) */
	/* dwm TAGKEYS( XK_1, 0 ) etc. */
	TAGKEYS(          XKB_KEY_1, XKB_KEY_exclam,                     0),
	TAGKEYS(          XKB_KEY_2, XKB_KEY_at,                         1),
	TAGKEYS(          XKB_KEY_3, XKB_KEY_numbersign,                 2),
	TAGKEYS(          XKB_KEY_4, XKB_KEY_dollar,                     3),
	TAGKEYS(          XKB_KEY_5, XKB_KEY_percent,                    4),
	/* TAGKEYS(                        XK_6,                      5), // Removed: Only 5 tags defined */
	/* TAGKEYS(                        XK_7,                      6), */
	/* TAGKEYS(                        XK_8,                      7), */
	/* TAGKEYS(                        XK_9,                      8), */
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_Q,          quit,           {0} }, // dwm: XK_q | ShiftMask
	/* Scratchpad bindings removed */
	/* { MODKEY,                       XK_quoteleft, scratchpad_show,  {0} }, */
	/* { MODKEY|ShiftMask,             XK_quoteleft, scratchpad_hide,  {0} }, */
	/* { MODKEY,                       XK_equal, scratchpad_remove,{0} }, */

	/* Ctrl-Alt-Backspace and Ctrl-Alt-Fx (dwl template defaults) */
	{ WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_Terminate_Server, quit, {0} },
#define CHVT(n) { WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_XF86Switch_VT_##n, chvt, {.ui = (n)} }
	CHVT(1), CHVT(2), CHVT(3), CHVT(4), CHVT(5), CHVT(6),
	CHVT(7), CHVT(8), CHVT(9), CHVT(10), CHVT(11), CHVT(12),
};

/* Button bindings converted from dwm, bar clicks removed */
static const Button buttons[] = {
	/* click           event mask  button    function        argument */
	{ MODKEY,          BTN_LEFT,   moveresize,     {.ui = CurMove} },    // dwm: ClkClientWin, MODKEY, Button1, movemouse
	{ MODKEY,          BTN_MIDDLE, togglefloating, {0} },                // dwm: ClkClientWin, MODKEY, Button2, togglefloating
	{ MODKEY|WLR_MODIFIER_SHIFT,          BTN_LEFT,  moveresize,     {.ui = CurResize} },  // dwm: ClkClientWin, MODKEY, Button3, resizemouse (Note: dwm also had Shift+B1)
};
