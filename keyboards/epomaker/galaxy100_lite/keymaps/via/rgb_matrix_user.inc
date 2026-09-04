RGB_MATRIX_EFFECT(BLUE_RAIN)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// How long (in effect ticks) a drop stays visibly lighter before fading back to base
#ifndef BLUE_RAIN_DROP_LIFETIME
#    define BLUE_RAIN_DROP_LIFETIME 60
#endif

static uint8_t blue_rain_life[RGB_MATRIX_LED_COUNT];

static void blue_rain_set_color(int i, effect_params_t* params) {
    if (!HAS_ANY_FLAGS(g_led_config.flags[i], params->flags)) return;

    // Base color comes from whatever hue/sat/brightness is set in VIA's color picker
    // (set this to a blue hue there — the effect itself doesn't hardcode the color)
    HSV hsv = rgb_matrix_config.hsv;

    if (blue_rain_life[i] > 0) {
        uint8_t fade = blue_rain_life[i]; // counts down from BLUE_RAIN_DROP_LIFETIME to 0
        // Desaturate and brighten proportionally to how "fresh" the drop is,
        // so it reads as a lighter shade of the same base blue rather than a new color
        hsv.s = qsub8(hsv.s, scale8(fade, 140));
        hsv.v = qadd8(hsv.v, scale8(fade, 90));
        blue_rain_life[i]--;
    }

    RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
}

bool BLUE_RAIN(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    if (params->init) {
        for (int i = led_min; i < led_max; i++) {
            blue_rain_life[i] = 0;
        }
    }

    // Spawn a new drop periodically; tied to the effect's speed slider in VIA
    if (scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 16)) % 12 == 0) {
        int drop              = random8_max(RGB_MATRIX_LED_COUNT);
        blue_rain_life[drop]  = BLUE_RAIN_DROP_LIFETIME;
    }

    for (int i = led_min; i < led_max; i++) {
        blue_rain_set_color(i, params);
    }

    return rgb_matrix_check_finished_leds(led_max);
}
#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
