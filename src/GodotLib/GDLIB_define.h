﻿

#ifndef GDN_DEFINE_H
#define GDN_DEFINE_H
// #include<DJS_define.h>

#define EXGD   extern"C" void __declspec(dllexport) 
#define gd    godot::

#define REGISTER_FUNC(CLAss,FUUu)    register_method(#FUUu,&CLAss::FUUu)

typedef const int    cint; 
   
typedef const bool    cbool;

typedef const float    cfloat;

typedef const long    clong;

typedef const double    cdouble;

#define cvector    const vector 



#define f001    0.01f
#define f099    0.99f
#define f09999    0.9999f
#define f00001    0.0001f
#define f0000001    0.000001f
#define f99    99f
#define f9999    9999f

#define i64    64
#define i128    128
#define i256    256
#define i512    512

#ifndef PI
    #define PI   3.141592653589793
    #define ang180    3.141592653589793
    #define PI2  6.283185307179586
    #define ang360    6.283185307179586
    #define PIΞ2  1.5707963267948966
    #define ang90   1.5707963267948966
    #define PI3Ξ4  2.356194490192345
    #define ang270   2.356194490192345
    #define PI4Ξ6   2.094395
    #define ang240   2.094395
    #define PIΞ4   0.7853981633974483  
    #define ang45    0.7853981633974483  
    #define PIΞ8  0.392699 
    #define ang22   0.392699 
    #define PIΞ16   0.196349541875
    #define ang11  0.196349541875
    #define SIN45   0.70710678118655
    #define ANG100   1.74532925199
#endif

#define FOR(V,SIZE,I_)    const int& SIZE=V.size();     for(int I_=0;I_<SIZE;++I_)
#define For(SIZE,I_)    for(int I_=0;I_<SIZE;++I_)

#define ASSERT1
#define __trued
#define __0d
#define __falsed

enum PrimitiveType {
    PRIMITIVE_POINTS = 0,
    PRIMITIVE_LINES = 1,
    PRIMITIVE_LINE_STRIP = 2,
    PRIMITIVE_LINE_LOOP = 3,
    PRIMITIVE_TRIANGLES = 4,
    PRIMITIVE_TRIANGLE_STRIP = 5,
    PRIMITIVE_TRIANGLE_FAN = 6,
};
enum TextureType {
    TEXTURE_TYPE_2D = 0,
    TEXTURE_TYPE_CUBEMAP = 1,
    TEXTURE_TYPE_2D_ARRAY = 2,
    TEXTURE_TYPE_3D = 3,
};

#define MARGIN_LEFT    0
#define MARGIN_TOP    1
#define MARGIN_RIGHT    2
#define MARGIN_BOTTOM    3
#define CORNER_TOP_LEFT    0
#define CORNER_TOP_RIGHT    1
#define CORNER_BOTTOM_RIGHT    2
#define CORNER_BOTTOM_LEFT    3
#define VERTICAL    1
#define HORIZONTAL    0
#define HALIGN_LEFT    0
#define HALIGN_CENTER    1
#define HALIGN_RIGHT    2
#define VALIGN_TOP    0
#define VALIGN_CENTER    1
#define VALIGN_BOTTOM    2
#define SPKEY    16777216
#define KEY_ESCAPE    16777217
#define KEY_TAB    16777218
#define KEY_BACKTAB    16777219
#define KEY_BACKSPACE    16777220
#define KEY_ENTER    16777221
#define KEY_KP_ENTER    16777222
#define KEY_INSERT    16777223
#define KEY_DELETE    16777224
#define KEY_PAUSE    16777225
#define KEY_PRINT    16777226
#define KEY_SYSREQ    16777227
#define KEY_CLEAR    16777228
#define KEY_HOME    16777229
#define KEY_END    16777230
#define KEY_LEFT    16777231
#define KEY_UP    16777232
#define KEY_RIGHT    16777233
#define KEY_DOWN    16777234
#define KEY_PAGEUP    16777235
#define KEY_PAGEDOWN    16777236
#define KEY_SHIFT    16777237
#define KEY_CONTROL    16777238
#define KEY_META    16777239
#define KEY_ALT    16777240
#define KEY_CAPSLOCK    16777241
#define KEY_NUMLOCK    16777242
#define KEY_SCROLLLOCK    16777243
#define KEY_F1    16777244
#define KEY_F2    16777245
#define KEY_F3    16777246
#define KEY_F4    16777247
#define KEY_F5    16777248
#define KEY_F6    16777249
#define KEY_F7    16777250
#define KEY_F8    16777251
#define KEY_F9    16777252
#define KEY_F10    16777253
#define KEY_F11    16777254
#define KEY_F12    16777255
#define KEY_F13    16777256
#define KEY_F14    16777257
#define KEY_F15    16777258
#define KEY_F16    16777259
#define KEY_KP_MULTIPLY    16777345
#define KEY_KP_DIVIDE    16777346
#define KEY_KP_SUBTRACT    16777347
#define KEY_KP_PERIOD    16777348
#define KEY_KP_ADD    16777349
#define KEY_KP_0    16777350
#define KEY_KP_1    16777351
#define KEY_KP_2    16777352
#define KEY_KP_3    16777353
#define KEY_KP_4    16777354
#define KEY_KP_5    16777355
#define KEY_KP_6    16777356
#define KEY_KP_7    16777357
#define KEY_KP_8    16777358
#define KEY_KP_9    16777359
#define KEY_SUPER_L    16777260
#define KEY_SUPER_R    16777261
#define KEY_MENU    16777262
#define KEY_HYPER_L    16777263
#define KEY_HYPER_R    16777264
#define KEY_HELP    16777265
#define KEY_DIRECTION_L    16777266
#define KEY_DIRECTION_R    16777267
#define KEY_BACK    16777280
#define KEY_FORWARD    16777281
#define KEY_STOP    16777282
#define KEY_REFRESH    16777283
#define KEY_VOLUMEDOWN    16777284
#define KEY_VOLUMEMUTE    16777285
#define KEY_VOLUMEUP    16777286
#define KEY_BASSBOOST    16777287
#define KEY_BASSUP    16777288
#define KEY_BASSDOWN    16777289
#define KEY_TREBLEUP    16777290
#define KEY_TREBLEDOWN    16777291
#define KEY_MEDIAPLAY    16777292
#define KEY_MEDIASTOP    16777293
#define KEY_MEDIAPREVIOUS    16777294
#define KEY_MEDIANEXT    16777295
#define KEY_MEDIARECORD    16777296
#define KEY_HOMEPAGE    16777297
#define KEY_FAVORITES    16777298
#define KEY_SEARCH    16777299
#define KEY_STANDBY    16777300
#define KEY_OPENURL    16777301
#define KEY_LAUNCHMAIL    16777302
#define KEY_LAUNCHMEDIA    16777303
#define KEY_LAUNCH0    16777304
#define KEY_LAUNCH1    16777305
#define KEY_LAUNCH2    16777306
#define KEY_LAUNCH3    16777307
#define KEY_LAUNCH4    16777308
#define KEY_LAUNCH5    16777309
#define KEY_LAUNCH6    16777310
#define KEY_LAUNCH7    16777311
#define KEY_LAUNCH8    16777312
#define KEY_LAUNCH9    16777313
#define KEY_LAUNCHA    16777314
#define KEY_LAUNCHB    16777315
#define KEY_LAUNCHC    16777316
#define KEY_LAUNCHD    16777317
#define KEY_LAUNCHE    16777318
#define KEY_LAUNCHF    16777319
#define KEY_UNKNOWN    33554431
#define KEY_SPACE    32
#define KEY_EXCLAM    33
#define KEY_QUOTEDBL    34
#define KEY_NUMBERSIGN    35
#define KEY_DOLLAR    36
#define KEY_PERCENT    37
#define KEY_AMPERSAND    38
#define KEY_APOSTROPHE    39
#define KEY_PARENLEFT    40
#define KEY_PARENRIGHT    41
#define KEY_ASTERISK    42
#define KEY_PLUS    43
#define KEY_COMMA    44
#define KEY_MINUS    45
#define KEY_PERIOD    46
#define KEY_SLASH    47
#define KEY_0    48
#define KEY_1    49
#define KEY_2    50
#define KEY_3    51
#define KEY_4    52
#define KEY_5    53
#define KEY_6    54
#define KEY_7    55
#define KEY_8    56
#define KEY_9    57
#define KEY_COLON    58
#define KEY_SEMICOLON    59
#define KEY_LESS    60
#define KEY_EQUAL    61
#define KEY_GREATER    62
#define KEY_QUESTION    63
#define KEY_AT    64
#define KEY_A    65
#define KEY_B    66
#define KEY_C    67
#define KEY_D    68
#define KEY_E    69
#define KEY_F    70
#define KEY_G    71
#define KEY_H    72
#define KEY_I    73
#define KEY_J    74
#define KEY_K    75
#define KEY_L    76
#define KEY_M    77
#define KEY_N    78
#define KEY_O    79
#define KEY_P    80
#define KEY_Q    81
#define KEY_R    82
#define KEY_S    83
#define KEY_T    84
#define KEY_U    85
#define KEY_V    86
#define KEY_W    87
#define KEY_X    88
#define KEY_Y    89
#define KEY_Z    90
#define KEY_BRACKETLEFT    91
#define KEY_BACKSLASH    92
#define KEY_BRACKETRIGHT    93
#define KEY_ASCIICIRCUM    94
#define KEY_UNDERSCORE    95
#define KEY_QUOTELEFT    96
#define KEY_BRACELEFT    123
#define KEY_BAR    124
#define KEY_BRACERIGHT    125
#define KEY_ASCIITILDE    126
#define KEY_NOBREAKSPACE    160
#define KEY_EXCLAMDOWN    161
#define KEY_CENT    162
#define KEY_STERLING    163
#define KEY_CURRENCY    164
#define KEY_YEN    165
#define KEY_BROKENBAR    166
#define KEY_SECTION    167
#define KEY_DIAERESIS    168
#define KEY_COPYRIGHT    169
#define KEY_ORDFEMININE    170
#define KEY_GUILLEMOTLEFT    171
#define KEY_NOTSIGN    172
#define KEY_HYPHEN    173
#define KEY_REGISTERED    174
#define KEY_MACRON    175
#define KEY_DEGREE    176
#define KEY_PLUSMINUS    177
#define KEY_TWOSUPERIOR    178
#define KEY_THREESUPERIOR    179
#define KEY_ACUTE    180
#define KEY_MU    181
#define KEY_PARAGRAPH    182
#define KEY_PERIODCENTERED    183
#define KEY_CEDILLA    184
#define KEY_ONESUPERIOR    185
#define KEY_MASCULINE    186
#define KEY_GUILLEMOTRIGHT    187
#define KEY_ONEQUARTER    188
#define KEY_ONEHALF    189
#define KEY_THREEQUARTERS    190
#define KEY_QUESTIONDOWN    191
#define KEY_AGRAVE    192
#define KEY_AACUTE    193
#define KEY_ACIRCUMFLEX    194
#define KEY_ATILDE    195
#define KEY_ADIAERESIS    196
#define KEY_ARING    197
#define KEY_AE    198
#define KEY_CCEDILLA    199
#define KEY_EGRAVE    200
#define KEY_EACUTE    201
#define KEY_ECIRCUMFLEX    202
#define KEY_EDIAERESIS    203
#define KEY_IGRAVE    204
#define KEY_IACUTE    205
#define KEY_ICIRCUMFLEX    206
#define KEY_IDIAERESIS    207
#define KEY_ETH    208
#define KEY_NTILDE    209
#define KEY_OGRAVE    210
#define KEY_OACUTE    211
#define KEY_OCIRCUMFLEX    212
#define KEY_OTILDE    213
#define KEY_ODIAERESIS    214
#define KEY_MULTIPLY    215
#define KEY_OOBLIQUE    216
#define KEY_UGRAVE    217
#define KEY_UACUTE    218
#define KEY_UCIRCUMFLEX    219
#define KEY_UDIAERESIS    220
#define KEY_YACUTE    221
#define KEY_THORN    222
#define KEY_SSHARP    223
#define KEY_DIVISION    247
#define KEY_YDIAERESIS    255
#define KEY_CODE_MASK    33554431
#define KEY_MODIFIER_MASK    -16777216
#define KEY_MASK_SHIFT    33554432
#define KEY_MASK_ALT    67108864
#define KEY_MASK_META    134217728
#define KEY_MASK_CTRL    268435456
#define KEY_MASK_CMD    268435456
#define KEY_MASK_KPAD    536870912
#define KEY_MASK_GROUP_SWITCH    1073741824
#define BUTTON_LEFT    1
#define BUTTON_RIGHT    2
#define BUTTON_MIDDLE    3
#define BUTTON_XBUTTON1    8
#define BUTTON_XBUTTON2    9
#define BUTTON_WHEEL_UP    4
#define BUTTON_WHEEL_DOWN    5
#define BUTTON_WHEEL_LEFT    6
#define BUTTON_WHEEL_RIGHT    7
#define BUTTON_MASK_LEFT    1
#define BUTTON_MASK_RIGHT    2
#define BUTTON_MASK_MIDDLE    4
#define BUTTON_MASK_XBUTTON1    128
#define BUTTON_MASK_XBUTTON2    256
#define JOY_BUTTON_0    0
#define JOY_BUTTON_1    1
#define JOY_BUTTON_2    2
#define JOY_BUTTON_3    3
#define JOY_BUTTON_4    4
#define JOY_BUTTON_5    5
#define JOY_BUTTON_6    6
#define JOY_BUTTON_7    7
#define JOY_BUTTON_8    8
#define JOY_BUTTON_9    9
#define JOY_BUTTON_10    10
#define JOY_BUTTON_11    11
#define JOY_BUTTON_12    12
#define JOY_BUTTON_13    13
#define JOY_BUTTON_14    14
#define JOY_BUTTON_15    15
#define JOY_BUTTON_MAX    16
#define JOY_SONY_CIRCLE    1
#define JOY_SONY_X    0
#define JOY_SONY_SQUARE    2
#define JOY_SONY_TRIANGLE    3
#define JOY_XBOX_B    1
#define JOY_XBOX_A    0
#define JOY_XBOX_X    2
#define JOY_XBOX_Y    3
#define JOY_DS_A    1
#define JOY_DS_B    0
#define JOY_DS_X    3
#define JOY_DS_Y    2
#define JOY_SELECT    10
#define JOY_START    11
#define JOY_DPAD_UP    12
#define JOY_DPAD_DOWN    13
#define JOY_DPAD_LEFT    14
#define JOY_DPAD_RIGHT    15
#define JOY_L    4
#define JOY_L2    6
#define JOY_L3    8
#define JOY_R    5
#define JOY_R2    7
#define JOY_R3    9
#define JOY_AXIS_0    0
#define JOY_AXIS_1    1
#define JOY_AXIS_2    2
#define JOY_AXIS_3    3
#define JOY_AXIS_4    4
#define JOY_AXIS_5    5
#define JOY_AXIS_6    6
#define JOY_AXIS_7    7
#define JOY_AXIS_8    8
#define JOY_AXIS_9    9
#define JOY_AXIS_MAX    10
#define JOY_ANALOG_LX    0
#define JOY_ANALOG_LY    1
#define JOY_ANALOG_RX    2
#define JOY_ANALOG_RY    3
#define JOY_ANALOG_L2    6
#define JOY_ANALOG_R2    7
#define MIDI_MESSAGE_NOTE_OFF    8
#define MIDI_MESSAGE_NOTE_ON    9
#define MIDI_MESSAGE_AFTERTOUCH    10
#define MIDI_MESSAGE_CONTROL_CHANGE    11
#define MIDI_MESSAGE_PROGRAM_CHANGE    12
#define MIDI_MESSAGE_CHANNEL_PRESSURE    13
#define MIDI_MESSAGE_PITCH_BEND    14
#define OK    0
#define FAILED    1
#define ERR_UNAVAILABLE    2
#define ERR_UNCONFIGURED    3
#define ERR_UNAUTHORIZED    4
#define ERR_PARAMETER_RANGE_ERROR    5
#define ERR_OUT_OF_MEMORY    6
#define ERR_FILE_NOT_FOUND    7
#define ERR_FILE_BAD_DRIVE    8
#define ERR_FILE_BAD_PATH    9
#define ERR_FILE_NO_PERMISSION    10
#define ERR_FILE_ALREADY_IN_USE    11
#define ERR_FILE_CANT_OPEN    12
#define ERR_FILE_CANT_WRITE    13
#define ERR_FILE_CANT_READ    14
#define ERR_FILE_UNRECOGNIZED    15
#define ERR_FILE_CORRUPT    16
#define ERR_FILE_MISSING_DEPENDENCIES    17
#define ERR_FILE_EOF    18
#define ERR_CANT_OPEN    19
#define ERR_CANT_CREATE    20
#define ERR_PARSE_ERROR    43
#define ERR_QUERY_FAILED    21
#define ERR_ALREADY_IN_USE    22
#define ERR_LOCKED    23
#define ERR_TIMEOUT    24
#define ERR_CANT_ACQUIRE_RESOURCE    28
#define ERR_INVALID_DATA    30
#define ERR_INVALID_PARAMETER    31
#define ERR_ALREADY_EXISTS    32
#define ERR_DOES_NOT_EXIST    33
#define ERR_DATABASE_CANT_READ    34
#define ERR_DATABASE_CANT_WRITE    35
#define ERR_COMPILATION_FAILED    36
#define ERR_METHOD_NOT_FOUND    37
#define ERR_LINK_FAILED    38
#define ERR_SCRIPT_FAILED    39
#define ERR_CYCLIC_LINK    40
#define ERR_BUSY    44
#define ERR_HELP    46
#define ERR_BUG    47
#define PROPERTY_HINT_NONE    0
#define PROPERTY_HINT_RANGE    1
#define PROPERTY_HINT_EXP_RANGE    2
#define PROPERTY_HINT_ENUM    3
#define PROPERTY_HINT_EXP_EASING    4
#define PROPERTY_HINT_LENGTH    5
#define PROPERTY_HINT_KEY_ACCEL    7
#define PROPERTY_HINT_FLAGS    8
#define PROPERTY_HINT_LAYERS_2D_RENDER    9
#define PROPERTY_HINT_LAYERS_2D_PHYSICS    10
#define PROPERTY_HINT_LAYERS_3D_RENDER    11
#define PROPERTY_HINT_LAYERS_3D_PHYSICS    12
#define PROPERTY_HINT_FILE    13
#define PROPERTY_HINT_DIR    14
#define PROPERTY_HINT_GLOBAL_FILE    15
#define PROPERTY_HINT_GLOBAL_DIR    16
#define PROPERTY_HINT_RESOURCE_TYPE    17
#define PROPERTY_HINT_MULTILINE_TEXT    18
#define PROPERTY_HINT_PLACEHOLDER_TEXT    19
#define PROPERTY_HINT_COLOR_NO_ALPHA    20
#define PROPERTY_HINT_IMAGE_COMPRESS_LOSSY    21
#define PROPERTY_HINT_IMAGE_COMPRESS_LOSSLESS    22
#define PROPERTY_USAGE_STORAGE    1
#define PROPERTY_USAGE_EDITOR    2
#define PROPERTY_USAGE_NETWORK    4
#define PROPERTY_USAGE_EDITOR_HELPER    8
#define PROPERTY_USAGE_CHECKABLE    16
#define PROPERTY_USAGE_CHECKED    32
#define PROPERTY_USAGE_INTERNATIONALIZED    64
#define PROPERTY_USAGE_GROUP    128
#define PROPERTY_USAGE_CATEGORY    256
#define PROPERTY_USAGE_NO_INSTANCE_STATE    2048
#define PROPERTY_USAGE_RESTART_IF_CHANGED    4096
#define PROPERTY_USAGE_SCRIPT_VARIABLE    8192
#define PROPERTY_USAGE_DEFAULT    7
#define PROPERTY_USAGE_DEFAULT_INTL    71
#define PROPERTY_USAGE_NOEDITOR    5
#define METHOD_FLAG_NORMAL    1
#define METHOD_FLAG_EDITOR    2
#define METHOD_FLAG_NOSCRIPT    4
#define METHOD_FLAG_CONST    8
#define METHOD_FLAG_REVERSE    16
#define METHOD_FLAG_VIRTUAL    32
#define METHOD_FLAG_FROM_SCRIPT    64
#define METHOD_FLAGS_DEFAULT    1
#define TYPE_NIL    0
#define TYPE_BOOL    1
#define TYPE_INT    2
#define TYPE_REAL    3
#define TYPE_STRING    4
#define TYPE_VECTOR2    5
#define TYPE_RECT2    6
#define TYPE_VECTOR3    7
#define TYPE_TRANSFORM2D    8
#define TYPE_PLANE    9
#define TYPE_QUAT    10
#define TYPE_AABB    11
#define TYPE_BASIS    12
#define TYPE_TRANSFORM    13
#define TYPE_COLOR    14
#define TYPE_NODE_PATH    15
#define TYPE_RID    16
#define TYPE_OBJECT    17
#define TYPE_DICTIONARY    18
#define TYPE_ARRAY    19
#define TYPE_RAW_ARRAY    20
#define TYPE_INT_ARRAY    21
#define TYPE_REAL_ARRAY    22
#define TYPE_STRING_ARRAY    23
#define TYPE_VECTOR2_ARRAY    24
#define TYPE_VECTOR3_ARRAY    25
#define TYPE_COLOR_ARRAY    26
#define TYPE_MAX    27
#define OP_EQUAL    0
#define OP_NOT_EQUAL    1
#define OP_LESS    2
#define OP_LESS_EQUAL    3
#define OP_GREATER    4
#define OP_GREATER_EQUAL    5
#define OP_ADD    6
#define OP_SUBTRACT    7
#define OP_MULTIPLY    8
#define OP_DIVIDE    9
#define OP_NEGATE    10
#define OP_POSITIVE    11
#define OP_MODULE    12
#define OP_STRING_CONCAT    13
#define OP_SHIFT_LEFT    14
#define OP_SHIFT_RIGHT    15
#define OP_BIT_AND    16
#define OP_BIT_OR    17
#define OP_BIT_XOR    18
#define OP_BIT_NEGATE    19
#define OP_AND    20
#define OP_OR    21
#define OP_XOR    22
#define OP_NOT    23
#define OP_IN    24
#define OP_MAX    25










////END////END////END////END////END////END////END////
#endif


