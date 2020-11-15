#pragma once


#define COMBO_VARIABLE_LEN
#define COMBO_COUNT COMBO_VARIABLE_LEN
// Time (in ms) for combo processing
#define COMBO_TERM 39

#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY

// Time (in ms) before one shot keys are released
#define ONESHOT_TIMEOUT 5000

// Prevent accidental repeats of the tap-hold keys when typing quickly.
#define TAPPING_FORCE_HOLD

// Prevent normal rollover on alphas from accidentally triggering home row mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Prevent short hold periods being interpreted as individual taps when typing quickly.
#define PERMISSIVE_HOLD

// Don't allow dyn macro calls in dyn macros
#define DYNAMIC_MACRO_NO_NESTING

// RGB Underglow
#ifdef RGBLIGHT_ENABLE
  // Turn off LEDS when host sleeps
  #define RGBLIGHT_SLEEP
  // Don't mirror LEDS
  #undef RGBLIGHT_SPLIT
  // Define LEDs in a loop so rainbow swirl is continous across sides
  #define RGBLIGHT_LED_MAP {0,1,2,9,8,7,4,3,5,6,19,18,17,10,11,12,15,16,14,13}
  // Only include animations you're using
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  // Allow underglow to change with active layer
  #define RGBLIGHT_LAYERS
#endif

// Allows media codes to properly register in macros and rotary encoder code
#define TAP_CODE_DELAY 10

// Determine left / right by which file is flashed.
/* #define EE_HANDS */

// Using an Elite C rev3 on the slave side
#define SPLIT_USB_DETECT
#define NO_USB_STARTUP_CHECK


// Key Mouse settings

// Set the mouse settings to a comfortable speed/accuracy trade-off
// Assume the screen refresh rate is 60 Htz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
// #undef to override default settings
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16

// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 40

// The default is 300. Make this as low as possible while keeping the cursor responsive
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 100
