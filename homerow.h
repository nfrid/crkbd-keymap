#include QMK_KEYBOARD_H

#define M_LS(kc) MT(MOD_LSFT, kc)
#define M_LG(kc) MT(MOD_LGUI, kc)
#define M_LA(kc) MT(MOD_LALT, kc)
#define M_LC(kc) MT(MOD_LCTL, kc)

#define M_RS(kc) MT(MOD_RSFT, kc)
#define M_RG(kc) MT(MOD_RGUI, kc)
#define M_RA(kc) MT(MOD_RALT, kc)
#define M_RC(kc) MT(MOD_RCTL, kc)

/* clang-format off */
#define HRM_LAYOUT_split_3x6_3( \
    k0a, k00, k01, k02, k03, k04,       k05, k06, k07, k08, k09, k0b, \
    k1a, k10, k11, k12, k13, k14,       k15, k16, k17, k18, k19, k1b, \
    k2a, k20, k21, k22, k23, k24,       k25, k26, k27, k28, k29, k2b, \
                     k32, k33, k34,   k35, k36, k37 \
) LAYOUT_split_3x6_3( \
    k0a,       k00,       k01,       k02,       k03, k04,       k05,       k06,       k07,       k08,       k09, k0b, \
    k1a, M_LS(k10), M_LG(k11), M_LA(k12), M_LC(k13), k14,       k15, M_LC(k16), M_LA(k17), M_LG(k18), M_LS(k19), k1b, \
    k2a,       k20,       k21,       k22,       k23, k24,       k25,       k26,       k27,       k28,       k29, k2b, \
                                             k32, k33, k34,   k35, k36, k37 \
)
