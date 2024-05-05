#pragma once

#ifdef COMBO_ENABLE

#ifdef COMB
#undef COMB
#endif

#define COMB(name, action, ...)  C_##name,
enum myCombos {
#include "combos.def"
};
#undef COMB

#define COMB(name, action, ...)  const uint16_t PROGMEM name##_combo[] = {__VA_ARGS__, COMBO_END};
#include "combos.def"
#undef COMB

#define COMB(name, action, ...)  [C_##name] = COMBO(name##_combo, action),
combo_t key_combos[] = {
#include "combos.def"
};
#undef COMB

#endif
