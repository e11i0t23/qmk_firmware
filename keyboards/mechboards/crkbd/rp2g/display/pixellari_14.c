/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --no-compress --font Pixellari.ttf --range 0-255 --format lvgl -o pixellari_14.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "../../lvgl.h"
#endif

#ifndef PIXELLARI_14
#define PIXELLARI_14 1
#endif

#if PIXELLARI_14

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xfc, 0xf0,

    /* U+0022 "\"" */
    0xff, 0xf0,

    /* U+0023 "#" */
    0x6c, 0xdb, 0xff, 0xf6, 0xcd, 0xbf, 0xff, 0x6c,
    0xd8,

    /* U+0024 "$" */
    0x31, 0xf7, 0xfe, 0xf9, 0xff, 0xfe, 0x30, 0xc0,

    /* U+0025 "%" */
    0x20, 0xc4, 0x1b, 0x6e, 0x6d, 0x85, 0xec, 0xff,
    0x8b, 0xc9, 0xd9, 0x31, 0xc4, 0x18,

    /* U+0026 "&" */
    0x3c, 0xf9, 0x96, 0x6e, 0xcf, 0x1e, 0x66, 0xc5,
    0xfd, 0xf8,

    /* U+0027 "'" */
    0xfc,

    /* U+0028 "(" */
    0x6f, 0x6d, 0xb6, 0xcd, 0x80,

    /* U+0029 ")" */
    0xd9, 0xb6, 0xdb, 0x7b, 0x0,

    /* U+002A "*" */
    0x27, 0xfe, 0xef, 0xec,

    /* U+002B "+" */
    0x37, 0xfe, 0x63, 0x0,

    /* U+002C "," */
    0xf6,

    /* U+002D "-" */
    0xff, 0xc0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x8, 0xc4, 0x63, 0x39, 0x8c, 0xc6, 0x0,

    /* U+0030 "0" */
    0x7b, 0xfd, 0xf7, 0xdf, 0xff, 0xff, 0xfd, 0xe0,

    /* U+0031 "1" */
    0x33, 0xbd, 0xe3, 0x18, 0xc6, 0xff, 0xc0,

    /* U+0032 "2" */
    0x7b, 0xfc, 0xc3, 0xc, 0x77, 0x3c, 0xff, 0xf0,

    /* U+0033 "3" */
    0x7b, 0xfc, 0xc3, 0x18, 0x60, 0xf3, 0xfd, 0xe0,

    /* U+0034 "4" */
    0xc, 0x18, 0xf3, 0xec, 0xd9, 0xbf, 0xff, 0xc,
    0x18,

    /* U+0035 "5" */
    0xff, 0xf1, 0x8f, 0xfc, 0x7b, 0xfb, 0x80,

    /* U+0036 "6" */
    0x77, 0xf7, 0x8f, 0xff, 0x7b, 0xfb, 0x80,

    /* U+0037 "7" */
    0xff, 0xfc, 0x18, 0x71, 0xc6, 0xc, 0x18, 0x30,
    0x60,

    /* U+0038 "8" */
    0x73, 0xb7, 0xbf, 0xff, 0x7b, 0xfb, 0x80,

    /* U+0039 "9" */
    0x77, 0xf7, 0xb7, 0xbc, 0x7b, 0xfb, 0x80,

    /* U+003A ":" */
    0xf0, 0x3c,

    /* U+003B ";" */
    0xf0, 0x3d, 0x80,

    /* U+003C "<" */
    0x7, 0x8f, 0xcf, 0x9e, 0xf, 0x0, 0xf0, 0x7e,
    0xf,

    /* U+003D "=" */
    0xff, 0xc0, 0xf, 0xfc,

    /* U+003E ">" */
    0xf0, 0x7e, 0xf, 0x80, 0xf0, 0x79, 0xe3, 0xf1,
    0xe0,

    /* U+003F "?" */
    0x7b, 0xfc, 0xc3, 0x18, 0xe3, 0x0, 0x30, 0xc0,

    /* U+0040 "@" */
    0x3f, 0x87, 0xf3, 0x3, 0xef, 0x3f, 0xf7, 0xe6,
    0xfc, 0xdf, 0x9b, 0xff, 0xfb, 0xfb, 0x0, 0x3f,
    0xe3, 0xfc,

    /* U+0041 "A" */
    0x38, 0xfb, 0xbe, 0x3c, 0x7f, 0xff, 0xe3, 0xc7,
    0x8c,

    /* U+0042 "B" */
    0xfd, 0xff, 0x1e, 0x3f, 0xdf, 0xb1, 0xe3, 0xff,
    0xf8,

    /* U+0043 "C" */
    0x7b, 0xfc, 0xf0, 0xc3, 0xc, 0x33, 0xfd, 0xe0,

    /* U+0044 "D" */
    0xfd, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xff,
    0xf8,

    /* U+0045 "E" */
    0xff, 0xfc, 0x30, 0xff, 0xfc, 0x30, 0xff, 0xf0,

    /* U+0046 "F" */
    0xff, 0xfc, 0x30, 0xff, 0xfc, 0x30, 0xc3, 0x0,

    /* U+0047 "G" */
    0x7b, 0xfc, 0xf0, 0xc3, 0x7d, 0xf3, 0xfd, 0xe0,

    /* U+0048 "H" */
    0xc7, 0x8f, 0x1e, 0x3f, 0xff, 0xf1, 0xe3, 0xc7,
    0x8c,

    /* U+0049 "I" */
    0xff, 0x66, 0x66, 0x66, 0xff,

    /* U+004A "J" */
    0x1e, 0x3c, 0x30, 0x60, 0xc1, 0x83, 0x66, 0xfc,
    0xf0,

    /* U+004B "K" */
    0xc7, 0x8f, 0x36, 0xcf, 0x1e, 0x36, 0x6e, 0xcf,
    0x8c,

    /* U+004C "L" */
    0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xff, 0xf0,

    /* U+004D "M" */
    0xc1, 0xe0, 0xfd, 0xff, 0xfc, 0x9e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xc0,

    /* U+004E "N" */
    0xc3, 0xe3, 0xf3, 0xf3, 0xdb, 0xdb, 0xdf, 0xcf,
    0xcf, 0xc3,

    /* U+004F "O" */
    0x7d, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xfe,
    0xf8,

    /* U+0050 "P" */
    0xfb, 0xfc, 0xf3, 0xcf, 0xff, 0xb0, 0xc3, 0x0,

    /* U+0051 "Q" */
    0x7c, 0xfe, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xce,
    0xfe, 0x7f,

    /* U+0052 "R" */
    0xfd, 0xff, 0x1e, 0x3f, 0xd8, 0xf1, 0xe3, 0xc7,
    0x8c,

    /* U+0053 "S" */
    0x7d, 0xff, 0x1e, 0x7, 0xef, 0xc1, 0xe3, 0xfe,
    0xf8,

    /* U+0054 "T" */
    0xff, 0xfc, 0xc1, 0x83, 0x6, 0xc, 0x18, 0x30,
    0x60,

    /* U+0055 "U" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xfe,
    0xf8,

    /* U+0056 "V" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xb6, 0x38,
    0x20,

    /* U+0057 "W" */
    0xc3, 0xc3, 0xc3, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb,
    0x7e, 0x24,

    /* U+0058 "X" */
    0xc7, 0xdd, 0xb3, 0xe1, 0x2, 0xe, 0x3e, 0xef,
    0x8c,

    /* U+0059 "Y" */
    0xc7, 0xcd, 0x93, 0xe1, 0x83, 0x6, 0xc, 0x18,
    0x30,

    /* U+005A "Z" */
    0xff, 0xff, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc0,
    0xc0, 0xff, 0xff, 0xc0,

    /* U+005B "[" */
    0xff, 0x6d, 0xb6, 0xdf, 0x80,

    /* U+005C "\\" */
    0xc7, 0x18, 0xe3, 0x18, 0x42, 0x8, 0x40,

    /* U+005D "]" */
    0xfd, 0xb6, 0xdb, 0x7f, 0x80,

    /* U+005E "^" */
    0x21, 0xef, 0xf3,

    /* U+005F "_" */
    0xff, 0xfc,

    /* U+0060 "`" */
    0xdd, 0x80,

    /* U+0061 "a" */
    0x77, 0xf7, 0xbd, 0xfd, 0xe0,

    /* U+0062 "b" */
    0xc3, 0xc, 0x36, 0xff, 0xbc, 0xfb, 0xff, 0x60,

    /* U+0063 "c" */
    0x7b, 0xfc, 0xf0, 0xcf, 0xf7, 0x80,

    /* U+0064 "d" */
    0xc, 0x30, 0xdb, 0xff, 0x7c, 0xf7, 0xfd, 0xb0,

    /* U+0065 "e" */
    0x7b, 0xfc, 0xff, 0xcf, 0xf7, 0x80,

    /* U+0066 "f" */
    0x37, 0x6f, 0xf6, 0x66, 0x66,

    /* U+0067 "g" */
    0x6f, 0xfd, 0xf3, 0xcf, 0xff, 0xc3, 0xff, 0xe0,

    /* U+0068 "h" */
    0xc3, 0xc, 0x36, 0xff, 0xbc, 0xf3, 0xcf, 0x30,

    /* U+0069 "i" */
    0xf3, 0xff, 0xf0,

    /* U+006A "j" */
    0x33, 0x3, 0x33, 0x33, 0x33, 0x3f, 0xe0,

    /* U+006B "k" */
    0xc3, 0xc, 0x33, 0xcf, 0x6f, 0xb6, 0xcf, 0x30,

    /* U+006C "l" */
    0xff, 0xff, 0xf0,

    /* U+006D "m" */
    0xfe, 0xff, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb,

    /* U+006E "n" */
    0xf7, 0xf7, 0xbd, 0xef, 0x60,

    /* U+006F "o" */
    0x77, 0xf7, 0xbd, 0xfd, 0xc0,

    /* U+0070 "p" */
    0xdb, 0xfe, 0xf3, 0xcf, 0xff, 0xf0, 0xc3, 0x0,

    /* U+0071 "q" */
    0x6f, 0xfd, 0xf3, 0xcf, 0xff, 0xc3, 0xc, 0x30,

    /* U+0072 "r" */
    0xfb, 0xfc, 0xf0, 0xc3, 0xc, 0x0,

    /* U+0073 "s" */
    0x7f, 0xfc, 0x1e, 0x7f, 0xff, 0x80,

    /* U+0074 "t" */
    0x66, 0x6f, 0xf6, 0x66, 0x73,

    /* U+0075 "u" */
    0xde, 0xf7, 0xbd, 0xfd, 0xe0,

    /* U+0076 "v" */
    0xde, 0xf7, 0xbd, 0xb8, 0x80,

    /* U+0077 "w" */
    0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xff, 0x7f,

    /* U+0078 "x" */
    0xcf, 0xf7, 0x8c, 0x7b, 0xfc, 0xc0,

    /* U+0079 "y" */
    0xde, 0xf7, 0xbd, 0xed, 0xc6, 0xe7, 0x0,

    /* U+007A "z" */
    0xff, 0xc6, 0x66, 0x7f, 0xe0,

    /* U+007B "{" */
    0x33, 0x66, 0x6c, 0xe6, 0x63, 0x30,

    /* U+007C "|" */
    0xff, 0xff, 0xfc,

    /* U+007D "}" */
    0xcc, 0x33, 0x33, 0x33, 0x3c, 0xc0,

    /* U+007E "~" */
    0x77, 0xff, 0x70,

    /* U+00A0 " " */
    0x0,

    /* U+00A1 "¡" */
    0xf3, 0xff, 0xf0,

    /* U+00A2 "¢" */
    0x30, 0xc7, 0xbf, 0xff, 0xcf, 0xff, 0x78, 0xc0,

    /* U+00A3 "£" */
    0x3c, 0xff, 0x9f, 0x6, 0x1f, 0x3e, 0x30, 0x79,
    0xff, 0xb8,

    /* U+00A4 "¤" */
    0xc3, 0xff, 0x7e, 0x66, 0x66, 0x7e, 0xff, 0xc3,

    /* U+00A5 "¥" */
    0xc7, 0xdd, 0xb3, 0xe3, 0xdf, 0xff, 0xff, 0xfe,
    0x20,

    /* U+00A6 "¦" */
    0xff, 0xcf, 0xfc,

    /* U+00A7 "§" */
    0xff, 0xf6, 0x1c, 0x73, 0x3c, 0xd9, 0x3c, 0x70,
    0xc1, 0x7d, 0xf0,

    /* U+00A8 "¨" */
    0xff,

    /* U+00A9 "©" */
    0x3f, 0x98, 0x1f, 0x79, 0xff, 0xbf, 0x37, 0xe0,
    0xfc, 0x1f, 0x9b, 0xff, 0x78, 0x1d, 0xff, 0x1f,
    0xc0,

    /* U+00AA "ª" */
    0x73, 0xb7, 0xbd, 0xfd, 0xe0,

    /* U+00AB "«" */
    0x77, 0x9b, 0x33, 0xb7, 0x60,

    /* U+00AC "¬" */
    0xff, 0xfc, 0x18, 0x30,

    /* U+00AE "®" */
    0x3f, 0x98, 0x1f, 0xf9, 0xff, 0x3f, 0x37, 0xfe,
    0xff, 0x9f, 0x9b, 0xf3, 0x78, 0x1d, 0xff, 0x1f,
    0xc0,

    /* U+00AF "¯" */
    0xe0,

    /* U+00B0 "°" */
    0x26, 0xf6, 0xe2, 0x0,

    /* U+00B1 "±" */
    0x31, 0xbf, 0xf3, 0x7f, 0xe0,

    /* U+00B2 "²" */
    0x77, 0xd3, 0x7f, 0xf0,

    /* U+00B3 "³" */
    0x73, 0xb6, 0x7d, 0xfd, 0xc0,

    /* U+00B4 "´" */
    0x7f, 0x0,

    /* U+00B5 "µ" */
    0xde, 0xf7, 0xbd, 0xff, 0xf8, 0xc6, 0x0,

    /* U+00B6 "¶" */
    0x7f, 0xfc, 0xf3, 0xcf, 0xf7, 0xcf, 0x3c, 0xf3,
    0xcf,

    /* U+00B7 "·" */
    0xf0,

    /* U+00B8 "¸" */
    0xef, 0xe0,

    /* U+00B9 "¹" */
    0x6e, 0xef, 0xf0,

    /* U+00BA "º" */
    0x21, 0x37, 0xbd, 0xb8, 0x80,

    /* U+00BB "»" */
    0xdc, 0xcd, 0x9e, 0xed, 0xc0,

    /* U+00BC "¼" */
    0x60, 0x1c, 0x33, 0x86, 0x33, 0x8f, 0x61, 0xe8,
    0x2, 0x30, 0x46, 0x3b, 0xee, 0x7d, 0x83, 0x0,

    /* U+00BD "½" */
    0x60, 0x38, 0x4e, 0x11, 0x8c, 0xf6, 0x3d, 0x60,
    0xfc, 0x2f, 0x39, 0x9c, 0xf6, 0x3c,

    /* U+00BE "¾" */
    0x60, 0x1e, 0x13, 0x42, 0x19, 0xcd, 0x31, 0xec,
    0x1b, 0xb0, 0x46, 0x1b, 0xe6, 0x7c, 0x83, 0x0,

    /* U+00BF "¿" */
    0x30, 0xc0, 0xc, 0x71, 0x8c, 0x33, 0xfd, 0xe0,

    /* U+00C0 "À" */
    0x10, 0x20, 0x43, 0xee, 0xf8, 0xff, 0xff, 0xc7,
    0x8f, 0x18,

    /* U+00C1 "Á" */
    0x10, 0x20, 0x43, 0xee, 0xf8, 0xff, 0xff, 0xc7,
    0x8f, 0x18,

    /* U+00C2 "Â" */
    0x10, 0x50, 0xe3, 0xec, 0x78, 0xff, 0xff, 0xc7,
    0x8f, 0x18,

    /* U+00C3 "Ã" */
    0x18, 0x60, 0xe3, 0xec, 0x78, 0xff, 0xff, 0xc7,
    0x8f, 0x18,

    /* U+00C4 "Ä" */
    0x28, 0x0, 0xe3, 0xee, 0xf8, 0xff, 0xff, 0xc7,
    0x8f, 0x18,

    /* U+00C5 "Å" */
    0x38, 0x20, 0x43, 0xee, 0xf8, 0xff, 0xff, 0xc7,
    0x8f, 0x18,

    /* U+00C6 "Æ" */
    0xf, 0xf1, 0xff, 0x1b, 0x3, 0x30, 0x23, 0xf2,
    0x3f, 0x3f, 0x7, 0xf0, 0xc3, 0xfc, 0x3f,

    /* U+00C7 "Ç" */
    0x79, 0xec, 0xf3, 0xc3, 0xc, 0x30, 0xcf, 0xf3,
    0x86, 0x38, 0xc0,

    /* U+00C8 "È" */
    0x20, 0x4f, 0xff, 0xc3, 0xf, 0xff, 0xc3, 0xff,
    0xc0,

    /* U+00C9 "É" */
    0x10, 0x8f, 0xff, 0xc3, 0xf, 0xff, 0xc3, 0xff,
    0xc0,

    /* U+00CA "Ê" */
    0x31, 0x2f, 0xff, 0xc3, 0xf, 0xff, 0xc3, 0xff,
    0xc0,

    /* U+00CB "Ë" */
    0x48, 0xf, 0xff, 0xc3, 0xf, 0xff, 0xc3, 0xff,
    0xc0,

    /* U+00CC "Ì" */
    0x42, 0xff, 0x66, 0x66, 0x6f, 0xf0,

    /* U+00CD "Í" */
    0x24, 0xff, 0x66, 0x66, 0x6f, 0xf0,

    /* U+00CE "Î" */
    0x69, 0xf6, 0x66, 0x66, 0x6f, 0xf0,

    /* U+00CF "Ï" */
    0x90, 0xff, 0x66, 0x66, 0x6f, 0xf0,

    /* U+00D0 "Ð" */
    0x3f, 0x8f, 0xf3, 0xc, 0xc3, 0xf8, 0xfe, 0x33,
    0xc, 0xc3, 0x3f, 0xcf, 0xe0,

    /* U+00D1 "Ñ" */
    0x34, 0x48, 0xc3, 0xe3, 0xf3, 0xf3, 0xdb, 0xcf,
    0xcf, 0xc7, 0xc3,

    /* U+00D2 "Ò" */
    0x10, 0x21, 0xf7, 0xfc, 0x78, 0xf1, 0xe3, 0xc7,
    0xfd, 0xf0,

    /* U+00D3 "Ó" */
    0x10, 0x21, 0xf7, 0xfc, 0x78, 0xf1, 0xe3, 0xc7,
    0xfd, 0xf0,

    /* U+00D4 "Ô" */
    0x10, 0x51, 0xf7, 0xfc, 0x78, 0xf1, 0xe3, 0xc7,
    0xfd, 0xf0,

    /* U+00D5 "Õ" */
    0x18, 0x61, 0xf7, 0xfc, 0x78, 0xf1, 0xe3, 0xc7,
    0xfd, 0xf0,

    /* U+00D6 "Ö" */
    0x28, 0x1, 0xf7, 0xfc, 0x78, 0xf1, 0xe3, 0xc7,
    0xfd, 0xf0,

    /* U+00D7 "×" */
    0xcf, 0xf7, 0x9e, 0xcf, 0x30,

    /* U+00D8 "Ø" */
    0x1f, 0xd9, 0xff, 0xdc, 0x1c, 0xc1, 0xe6, 0x3b,
    0x31, 0x99, 0x98, 0xcf, 0x86, 0x78, 0x33, 0x83,
    0xbf, 0xfd, 0xbf, 0x80,

    /* U+00D9 "Ù" */
    0x10, 0x23, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0xfd, 0xf0,

    /* U+00DA "Ú" */
    0x10, 0x23, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0xfd, 0xf0,

    /* U+00DB "Û" */
    0x10, 0x53, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0xfd, 0xf0,

    /* U+00DC "Ü" */
    0x28, 0x3, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0xfd, 0xf0,

    /* U+00DD "Ý" */
    0x8, 0x23, 0x1f, 0x36, 0x4f, 0x86, 0xc, 0x18,
    0x30, 0x60,

    /* U+00DE "Þ" */
    0xc1, 0x83, 0xe7, 0xec, 0xf9, 0xff, 0x7e, 0xc1,
    0x80,

    /* U+00DF "ß" */
    0x79, 0xfb, 0x36, 0x6d, 0x9b, 0xb3, 0x73, 0xff,
    0xb8,

    /* U+00E0 "à" */
    0x21, 0x0, 0xef, 0xef, 0x7b, 0xfb, 0xc0,

    /* U+00E1 "á" */
    0x21, 0x0, 0xef, 0xef, 0x7b, 0xfb, 0xc0,

    /* U+00E2 "â" */
    0x22, 0x80, 0xef, 0xef, 0x7b, 0xfb, 0xc0,

    /* U+00E3 "ã" */
    0x33, 0x0, 0xef, 0xef, 0x7b, 0xfb, 0xc0,

    /* U+00E4 "ä" */
    0x50, 0x1d, 0xfd, 0xef, 0x7f, 0x78,

    /* U+00E5 "å" */
    0x22, 0x88, 0x7, 0x7f, 0x7b, 0xdf, 0xde,

    /* U+00E6 "æ" */
    0x7b, 0xbf, 0xfc, 0xcf, 0x3f, 0xcc, 0xff, 0xf7,
    0xf8,

    /* U+00E7 "ç" */
    0x7b, 0xfc, 0xf0, 0xc3, 0x3f, 0xce, 0x18, 0xe3,
    0x0,

    /* U+00E8 "è" */
    0x20, 0x40, 0x1e, 0xff, 0x3f, 0xf3, 0xfd, 0xe0,

    /* U+00E9 "é" */
    0x10, 0x80, 0x1e, 0xff, 0x3f, 0xf3, 0xfd, 0xe0,

    /* U+00EA "ê" */
    0x31, 0x20, 0x1e, 0xff, 0x3f, 0xf3, 0xfd, 0xe0,

    /* U+00EB "ë" */
    0x48, 0x7, 0xbf, 0xcf, 0xfc, 0xff, 0x78,

    /* U+00EC "ì" */
    0x93, 0xff, 0xf0,

    /* U+00ED "í" */
    0x63, 0xff, 0xf0,

    /* U+00EE "î" */
    0x69, 0x6, 0x66, 0x66, 0x66,

    /* U+00EF "ï" */
    0x90, 0x66, 0x66, 0x66, 0x60,

    /* U+00F0 "ð" */
    0x7f, 0xed, 0x9e, 0xfb, 0x6d, 0xb6, 0xf9, 0xc0,

    /* U+00F1 "ñ" */
    0x33, 0x1, 0xef, 0xef, 0x7b, 0xde, 0xc0,

    /* U+00F2 "ò" */
    0x21, 0x0, 0xef, 0xef, 0x7b, 0xfb, 0x80,

    /* U+00F3 "ó" */
    0x21, 0x0, 0xef, 0xef, 0x7b, 0xfb, 0x80,

    /* U+00F4 "ô" */
    0x22, 0x80, 0xef, 0xef, 0x7b, 0xfb, 0x80,

    /* U+00F5 "õ" */
    0x33, 0x0, 0xef, 0xef, 0x7b, 0xfb, 0x80,

    /* U+00F6 "ö" */
    0x50, 0x1d, 0xfd, 0xef, 0x7f, 0x70,

    /* U+00F7 "÷" */
    0x20, 0x3f, 0xf2, 0x0,

    /* U+00F8 "ø" */
    0x1, 0x8f, 0xcf, 0xcd, 0xe7, 0xf3, 0xd9, 0xf9,
    0xf8, 0xc0, 0x0,

    /* U+00F9 "ù" */
    0x21, 0x1, 0xbd, 0xef, 0x7b, 0xfb, 0xc0,

    /* U+00FA "ú" */
    0x21, 0x1, 0xbd, 0xef, 0x7b, 0xfb, 0xc0,

    /* U+00FB "û" */
    0x22, 0x81, 0xbd, 0xef, 0x7b, 0xfb, 0xc0,

    /* U+00FC "ü" */
    0x50, 0x37, 0xbd, 0xef, 0x7f, 0x78,

    /* U+00FD "ý" */
    0x20, 0x9, 0xbd, 0xef, 0x7b, 0xdb, 0x8d, 0xce,
    0x0,

    /* U+00FE "þ" */
    0xc1, 0x83, 0x6, 0xc, 0x1f, 0xbf, 0x67, 0xcf,
    0xfb, 0xe6, 0xc, 0x0,

    /* U+00FF "ÿ" */
    0x56, 0xf7, 0xbd, 0xef, 0x6e, 0x37, 0x38
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 70, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 56, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 98, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 6, .adv_w = 126, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 15, .adv_w = 126, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 23, .adv_w = 196, .box_w = 11, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 37, .adv_w = 140, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 56, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 48, .adv_w = 70, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 53, .adv_w = 84, .box_w = 3, .box_h = 11, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 58, .adv_w = 98, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 62, .adv_w = 112, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 66, .adv_w = 56, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 67, .adv_w = 112, .box_w = 5, .box_h = 2, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 69, .adv_w = 56, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 70, .adv_w = 98, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 77, .adv_w = 126, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 85, .adv_w = 126, .box_w = 5, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 92, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 100, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 108, .adv_w = 126, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 117, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 124, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 131, .adv_w = 126, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 140, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 147, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 154, .adv_w = 56, .box_w = 2, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 156, .adv_w = 56, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 159, .adv_w = 154, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 168, .adv_w = 112, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 172, .adv_w = 154, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 181, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 189, .adv_w = 196, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 207, .adv_w = 140, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 216, .adv_w = 140, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 225, .adv_w = 140, .box_w = 6, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 233, .adv_w = 154, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 242, .adv_w = 126, .box_w = 6, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 250, .adv_w = 126, .box_w = 6, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 258, .adv_w = 140, .box_w = 6, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 266, .adv_w = 140, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 275, .adv_w = 84, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 280, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 289, .adv_w = 140, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 298, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 306, .adv_w = 168, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 318, .adv_w = 154, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 154, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 337, .adv_w = 126, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 345, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 355, .adv_w = 140, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 364, .adv_w = 140, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 373, .adv_w = 140, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 382, .adv_w = 154, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 391, .adv_w = 154, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 400, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 410, .adv_w = 140, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 419, .adv_w = 140, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 428, .adv_w = 154, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 440, .adv_w = 70, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 445, .adv_w = 98, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 452, .adv_w = 84, .box_w = 3, .box_h = 11, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 457, .adv_w = 112, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 460, .adv_w = 126, .box_w = 7, .box_h = 2, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 462, .adv_w = 70, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 464, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 469, .adv_w = 126, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 477, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 483, .adv_w = 126, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 491, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 84, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 502, .adv_w = 126, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 510, .adv_w = 126, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 518, .adv_w = 56, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 521, .adv_w = 56, .box_w = 4, .box_h = 13, .ofs_x = -1, .ofs_y = -3},
    {.bitmap_index = 528, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 536, .adv_w = 56, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 539, .adv_w = 168, .box_w = 8, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 546, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 551, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 556, .adv_w = 126, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 564, .adv_w = 126, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 572, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 578, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 584, .adv_w = 70, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 589, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 594, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 599, .adv_w = 168, .box_w = 8, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 606, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 612, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 619, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 624, .adv_w = 84, .box_w = 4, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 630, .adv_w = 56, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 633, .adv_w = 84, .box_w = 4, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 639, .adv_w = 140, .box_w = 7, .box_h = 3, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 642, .adv_w = 70, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 643, .adv_w = 56, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 646, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 654, .adv_w = 126, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 664, .adv_w = 140, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 672, .adv_w = 140, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 681, .adv_w = 56, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 684, .adv_w = 126, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 695, .adv_w = 84, .box_w = 4, .box_h = 2, .ofs_x = 0, .ofs_y = 9},
    {.bitmap_index = 696, .adv_w = 168, .box_w = 11, .box_h = 12, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 713, .adv_w = 98, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 718, .adv_w = 126, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 723, .adv_w = 140, .box_w = 7, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 727, .adv_w = 168, .box_w = 11, .box_h = 12, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 744, .adv_w = 98, .box_w = 3, .box_h = 1, .ofs_x = 2, .ofs_y = 9},
    {.bitmap_index = 745, .adv_w = 98, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 749, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 754, .adv_w = 84, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 758, .adv_w = 84, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 763, .adv_w = 70, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 765, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 772, .adv_w = 126, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 781, .adv_w = 56, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 782, .adv_w = 70, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 784, .adv_w = 84, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 787, .adv_w = 98, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 792, .adv_w = 126, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 797, .adv_w = 210, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 813, .adv_w = 196, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 827, .adv_w = 196, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 843, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 851, .adv_w = 140, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 861, .adv_w = 140, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 871, .adv_w = 140, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 881, .adv_w = 140, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 891, .adv_w = 140, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 901, .adv_w = 140, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 911, .adv_w = 196, .box_w = 12, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 926, .adv_w = 140, .box_w = 6, .box_h = 14, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 937, .adv_w = 126, .box_w = 6, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 946, .adv_w = 126, .box_w = 6, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 955, .adv_w = 126, .box_w = 6, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 964, .adv_w = 126, .box_w = 6, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 973, .adv_w = 84, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 979, .adv_w = 84, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 985, .adv_w = 84, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 991, .adv_w = 84, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 997, .adv_w = 154, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1010, .adv_w = 154, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1021, .adv_w = 154, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1031, .adv_w = 154, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1041, .adv_w = 154, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1051, .adv_w = 154, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1061, .adv_w = 154, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1071, .adv_w = 112, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 1076, .adv_w = 182, .box_w = 13, .box_h = 12, .ofs_x = -2, .ofs_y = -1},
    {.bitmap_index = 1096, .adv_w = 154, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1106, .adv_w = 154, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1116, .adv_w = 154, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1126, .adv_w = 154, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1136, .adv_w = 140, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1146, .adv_w = 140, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1155, .adv_w = 140, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1164, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1171, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1178, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1185, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1192, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1198, .adv_w = 112, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1205, .adv_w = 182, .box_w = 10, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1214, .adv_w = 112, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1223, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1231, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1239, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1247, .adv_w = 112, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1254, .adv_w = 56, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1257, .adv_w = 56, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1260, .adv_w = 70, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1265, .adv_w = 70, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1270, .adv_w = 126, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1278, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1285, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1292, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1299, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1306, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1313, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1319, .adv_w = 112, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 1323, .adv_w = 154, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1334, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1341, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1348, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1355, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1361, .adv_w = 112, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1370, .adv_w = 140, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1382, .adv_w = 112, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 160, .range_length = 13, .glyph_id_start = 96,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 174, .range_length = 82, .glyph_id_start = 109,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 3,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};

extern const lv_font_t lv_font_montserrat_14;


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t pixellari_14 = {
#else
lv_font_t pixellari_14 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 15,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = &lv_font_montserrat_14,
#endif
    .user_data = NULL,
};



#endif /*#if PIXELLARI_14*/

