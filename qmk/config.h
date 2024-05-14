#pragma once

// Time (in ms) for combo processing
#define COMBO_TERM 37

#define TAPPING_TERM 170

// Allow tapping repeat of a dual purpose key (held / tapped)
#define QUICK_TAP_TERM 100

// Prevent short hold periods being interpreted as individual taps when typing quickly.
#define PERMISSIVE_HOLD

// Don't allow macro calls in macros
#define DYNAMIC_MACRO_NO_NESTING

// Allows media codes to properly register in macros and rotary encoder code
#define TAP_CODE_DELAY 10

// RGB Underglow
#ifdef RGBLIGHT_ENABLE
  #undef RGBLIGHT_SPLIT  // Don't mirror LEDS
  // Define LEDs in a loop so rainbow swirl is continous across sides
  #define RGBLIGHT_LED_MAP {0,1,2,9,8,7,4,3,5,6,19,18,17,10,11,12,15,16,14,13}
  // Only include animations you're using
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  // Set deefault mode when flashing the eprom
  #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
  // Allow underglow to change with active layer
  #define RGBLIGHT_LAYERS
#endif


// Determine left / right by which file is flashed.
/* #define EE_HANDS */

// Key Mouse settings

// Set the mouse settings to a comfortable speed/accuracy trade-off
// Assume the screen refresh rate is 60 Htz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
// #undef to override default settings
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 21

// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 37

// The default is 300. Make this as low as possible while keeping the cursor responsive
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 120

// If needed, save firmware space by disabling unused features
/* #undef LOCKING_SUPPORT_ENABLE */
/* #undef LOCKING_RESYNC_ENABLE */
/* #define NO_ACTION_ONESHOT */
/* #define NO_MUSIC_MODE */
/* #define LAYER_STATE_8BIT */
/* #define EXTRA_SHORT_COMBOS */
