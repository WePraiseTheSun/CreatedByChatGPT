#include "Freenove_WS2812_Lib_for_ESP32.h"

#define LEDS_COUNT  1
#define LEDS_PIN    48
#define CHANNEL     0

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);

u8 m_color[5][3] = { {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {0, 0, 0} };
int delayval = 100;
// Function prototypes
void flash_random_led_color(int led_pin);//*****
void turn_on_led(int led_pin, int r, int g, int b);
void turn_off_led(int led_pin);
void set_led_brightness(int led_pin, int brightness);
void cycle_colors(int led_pin);
void rainbow_cycle(int led_pin);//*****
void theater_chase(int led_pin);
void color_wipe(int led_pin, int r, int g, int b);
void gradient_wipe(int led_pin);
void blink_led(int led_pin, int r, int g, int b, int delay_time);//*****

// Function prototypes
void chase_effect(int led_pin, int r, int g, int b, int delay_time);
void color_wave(int led_pin, int r1, int g1, int b1, int r2, int g2, int b2);
void sparkle(int led_pin, int delay_time);//*****
void breathe_led(int led_pin, int r, int g, int b, int duration);//*****
void alternating_colors(int led_pin, int r1, int g1, int b1, int r2, int g2, int b2, int delay_time);
void twinkle(int led_pin, int r, int g, int b, int delay_time);
void color_bounce(int led_pin, int r, int g, int b);
void meteor_rain(int led_pin, int r, int g, int b, int size, int decay);//***
void color_sweep(int led_pin, int r1, int g1, int b1, int r2, int g2, int b2, int delay_time);//*****
void color_strobe(int led_pin, int r, int g, int b, int delay_time);//*****

// Function prototypes
void set_led_color_by_hsv(int index, uint32_t h, uint32_t s, uint32_t v);//*
void set_led_color_by_wheel(int index, uint8_t pos);//*
void fade_in_and_out(int index, int r, int g, int b, int duration);
void led_wave_effect(int index, int r, int g, int b, int delay_time);
void set_random_color(int index);
void alternate_two_colors(int r1, int g1, int b1, int r2, int g2, int b2, int delay_time);
void fill_gradient(int start_index, int r1, int g1, int b1, int r2, int g2, int b2);
void led_chase_effect(int r, int g, int b, int delay_time);
void led_theater_chase_effect(int r, int g, int b, int delay_time);
void led_bounce_effect(int r, int g, int b, int delay_time);

// Function prototypes
uint8_t qadd8(uint8_t i, uint8_t j);
void police_lights_effect(int delay_time);//*****
void gradient_fill(int r1, int g1, int b1, int r2, int g2, int b2);
void festival_lights(int delay_time);
void fire_effect(int cooling, int sparking);
void led_twinkle_effect(int delay_time);
void color_sparkle(int r, int g, int b, int delay_time);
void color_pulse(int r, int g, int b, int duration);
void color_strobe_effect(int r, int g, int b, int delay_time);
void chasing_lights(int r, int g, int b, int delay_time);
void led_breathing_effect(int r, int g, int b, int duration);

// Function prototype
void play_bad_pulse_effect();

// Function prototype
void play_bad_melody_effect();

// Function prototype
void play_mission_impossible_melody_effect();


void setup() {
    strip.begin();
    strip.setBrightness(255);    
}

void loop() {
  // Example usage of reusable functions
  // flash_random_led_color(LEDS_PIN);
  // turn_on_led(LEDS_PIN, 255, 0, 0);
  // turn_off_led(LEDS_PIN);
  //  set_led_brightness(LEDS_PIN, 50);
  //  cycle_colors(LEDS_PIN);
   // rainbow_cycle(LEDS_PIN);
  //  theater_chase(LEDS_PIN);
  //  color_wipe(LEDS_PIN, 255, 0, 0);
  // gradient_wipe(LEDS_PIN);
  //  blink_led(LEDS_PIN, 255, 255, 255, 500);

    // Example usage of additional reusable functions
  //  chase_effect(LEDS_PIN, 255, 0, 0, 100); not working
   // color_wave(LEDS_PIN, 255, 0, 0, 0, 255, 0); not working
   //sparkle(LEDS_PIN, 50);
  //  breathe_led(LEDS_PIN, 255, 0, 0, 1000);
 //   alternating_colors(LEDS_PIN, 255, 0, 0, 0, 0, 255, 500); not working
  //  twinkle(LEDS_PIN, 255, 255, 255, 100); not working
 //  color_bounce(LEDS_PIN, 255, 0, 0); not working
 //   meteor_rain(LEDS_PIN, 255, 0, 0, 10, 64);
  //  color_sweep(LEDS_PIN, 255, 0, 0, 0, 255, 0, 100);
  //  color_strobe(LEDS_PIN, 255, 255, 255, 50);

    // Example usage of additional reusable functions
   // set_led_color_by_hsv(0, 120, 100, 100);
   // set_led_color_by_wheel(1, 111);
   // fade_in_and_out(0, 255, 0, 0, 2000); not working
   // led_wave_effect(0, 255, 0, 0, 100); not working
  //  set_random_color(0); not wokring
  //  alternate_two_colors(255, 0, 0, 0, 0, 255, 500); not wokring
   // fill_gradient(0, 255, 0, 0, 0, 0, 255);not wokring
  // led_chase_effect(255, 0, 0, 50); not working
   // led_theater_chase_effect(255, 0, 0, 50);not working
 //  led_bounce_effect(255, 0, 0, 100); not working

    // Example usage of additional reusable functions
    //police_lights_effect(100);
   // gradient_fill(255, 0, 0, 0, 0, 255);
   // festival_lights(100);
   // fire_effect(50, 120);
   // led_twinkle_effect(50);
   // color_sparkle(255, 0, 0, 100);
   // color_pulse(255, 0, 0, 1000);
   // color_strobe_effect(255, 255, 255, 50);
   // chasing_lights(255, 0, 0, 100);
   // led_breathing_effect(255, 0, 0, 2000);

 //   play_bad_pulse_effect();

    //play_bad_melody_effect();


    play_mission_impossible_melody_effect();

}


// Function implementations
void flash_random_led_color(int led_pin) {
    for (int i = 0; i < 10; i++) {
        strip.setLedColorData(0, random(0, 256), random(0, 256), random(0, 256));
        strip.show();
        delay(100);
        strip.setLedColorData(0, 0, 0, 0);
        strip.show();
        delay(100);
    }
}

void turn_on_led(int led_pin, int r, int g, int b) {
    strip.setLedColorData(0, r, g, b);
    strip.show();
}

void turn_off_led(int led_pin) {
    strip.setLedColorData(0, 0, 0, 0);
    strip.show();
}

void set_led_brightness(int led_pin, int brightness) {
    strip.setBrightness(brightness);
    strip.show();
}

void cycle_colors(int led_pin) {
    for (int j = 0; j < 5; j++) {
        strip.setLedColorData(0, m_color[j][0], m_color[j][1], m_color[j][2]);
        strip.show();
        delay(500);
    }
}

void rainbow_cycle(int led_pin) {
    for (int j = 0; j < 256 * 5; j++) {
        for (int i = 0; i < LEDS_COUNT; i++) {
            int WheelPos = (i * 256 / LEDS_COUNT + j) & 255;
            if (WheelPos < 85) {
                strip.setLedColorData(i, WheelPos * 3, 255 - WheelPos * 3, 0);
            } else if (WheelPos < 170) {
                WheelPos -= 85;
                strip.setLedColorData(i, 255 - WheelPos * 3, 0, WheelPos * 3);
            } else {
                WheelPos -= 170;
                strip.setLedColorData(i, 0, WheelPos * 3, 255 - WheelPos * 3);
            }
        }
        strip.show();
        delay(20);
    }
}

void theater_chase(int led_pin) {
    for (int j = 0; j < 10; j++) {
        for (int q = 0; q < 3; q++) {
            for (int i = 0; i < LEDS_COUNT; i = i + 3) {
                strip.setLedColorData(i + q, 127, 127, 127);
            }
            strip.show();
            delay(50);
            for (int i = 0; i < LEDS_COUNT; i = i + 3) {
                strip.setLedColorData(i + q, 0, 0, 0);
            }
        }
    }
}

void color_wipe(int led_pin, int r, int g, int b) {
    for (int i = 0; i < LEDS_COUNT; i++) {
        strip.setLedColorData(i, r, g, b);
        strip.show();
        delay(50);
    }
}

void gradient_wipe(int led_pin) {
    for (int i = 0; i < LEDS_COUNT; i++) {
        strip.setLedColorData(i, i * (255 / LEDS_COUNT), 0, 255 - (i * (255 / LEDS_COUNT)));
        strip.show();
        delay(50);
    }
}

void blink_led(int led_pin, int r, int g, int b, int delay_time) {
    strip.setLedColorData(0, r, g, b);
    strip.show();
    delay(delay_time);
    strip.setLedColorData(0, 0, 0, 0);
    strip.show();
    delay(delay_time);
}

// Function implementations
void chase_effect(int led_pin, int r, int g, int b, int delay_time) {
    for (int i = 0; i < LEDS_COUNT; i++) {
        strip.setLedColorData(i, r, g, b);
        strip.show();
        delay(delay_time);
        strip.setLedColorData(i, 0, 0, 0);
    }
}

void color_wave(int led_pin, int r1, int g1, int b1, int r2, int g2, int b2) {
    for (int i = 0; i < LEDS_COUNT; i++) {
        int r = (r1 * (LEDS_COUNT - i) + r2 * i) / LEDS_COUNT;
        int g = (g1 * (LEDS_COUNT - i) + g2 * i) / LEDS_COUNT;
        int b = (b1 * (LEDS_COUNT - i) + b2 * i) / LEDS_COUNT;
        strip.setLedColorData(i, r, g, b);
    }
    strip.show();
}

void sparkle(int led_pin, int delay_time) {
    for (int i = 0; i < LEDS_COUNT; i++) {
        if (random(0, 10) > 5) {
            strip.setLedColorData(i, 255, 255, 255);
        } else {
            strip.setLedColorData(i, 0, 0, 0);
        }
    }
    strip.show();
    delay(delay_time);
}

void breathe_led(int led_pin, int r, int g, int b, int duration) {
    for (int i = 0; i < 256; i++) {
        strip.setBrightness(i);
        strip.setLedColorData(0, r, g, b);
        strip.show();
        delay(duration / 512);
    }
    for (int i = 255; i >= 0; i--) {
        strip.setBrightness(i);
        strip.setLedColorData(0, r, g, b);
        strip.show();
        delay(duration / 512);
    }
}

void alternating_colors(int led_pin, int r1, int g1, int b1, int r2, int g2, int b2, int delay_time) {
    for (int i = 0; i < LEDS_COUNT; i++) {
        if (i % 2 == 0) {
            strip.setLedColorData(i, r1, g1, b1);
        } else {
            strip.setLedColorData(i, r2, g2, b2);
        }
    }
    strip.show();
    delay(delay_time);
    for (int i = 0; i < LEDS_COUNT; i++) {
        if (i % 2 == 0) {
            strip.setLedColorData(i, r2, g2, b2);
        } else {
            strip.setLedColorData(i, r1, g1, b1);
        }
    }
    strip.show();
}

void twinkle(int led_pin, int r, int g, int b, int delay_time) {
    int random_led = random(0, LEDS_COUNT);
    strip.setLedColorData(random_led, r, g, b);
    strip.show();
    delay(delay_time);
    strip.setLedColorData(random_led, 0, 0, 0);
    strip.show();
}

void color_bounce(int led_pin, int r, int g, int b) {
    for (int i = 0; i < LEDS_COUNT; i++) {
        strip.setLedColorData(i, r, g, b);
        strip.show();
        delay(50);
        strip.setLedColorData(i, 0, 0, 0);
    }
    for (int i = LEDS_COUNT - 1; i >= 0; i--) {
        strip.setLedColorData(i, r, g, b);
        strip.show();
        delay(50);
        strip.setLedColorData(i, 0, 0, 0);
    }
}

void meteor_rain(int led_pin, int r, int g, int b, int size, int decay) {
    for (int i = 0; i < LEDS_COUNT + size; i++) {
        for (int j = 0; j < LEDS_COUNT; j++) {
            if ((i - j) < size && (i - j) >= 0) {
                strip.setLedColorData(j, r, g, b);
            } else {
                int dim_value = decay * (i - j);
                strip.setLedColorData(j, max(r - dim_value, 0), max(g - dim_value, 0), max(b - dim_value, 0));
            }
        }
        strip.show();
        delay(50);
    }
}

void color_sweep(int led_pin, int r1, int g1, int b1, int r2, int g2, int b2, int delay_time) {
    for (int i = 0; i < LEDS_COUNT; i++) {
        strip.setLedColorData(i, r1, g1, b1);
        strip.show();
        delay(delay_time);
    }
    for (int i = 0; i < LEDS_COUNT; i++) {
        strip.setLedColorData(i, r2, g2, b2);
        strip.show();
        delay(delay_time);
    }
}

void color_strobe(int led_pin, int r, int g, int b, int delay_time) {
    for (int i = 0; i < 10; i++) {
        strip.setLedColorData(0, r, g, b);
        strip.show();
        delay(delay_time);
        strip.setLedColorData(0, 0, 0, 0);
        strip.show();
        delay(delay_time);
    }
}


// Utility function to ensure values stay within 0-255 range
uint8_t qsub8(uint8_t i, uint8_t j) {
    return i > j ? i - j : 0;
}

// Function implementations
void set_led_color_by_hsv(int index, uint32_t h, uint32_t s, uint32_t v) {
    uint32_t rgb = strip.hsv2rgb(h, s, v);
    strip.setLedColorData(index, rgb >> 16 & 0xFF, rgb >> 8 & 0xFF, rgb & 0xFF);
}

void set_led_color_by_wheel(int index, uint8_t pos) {
    uint32_t color = strip.Wheel(pos);
    strip.setLedColorData(index, color >> 16 & 0xFF, color >> 8 & 0xFF, color & 0xFF);
}

void fade_in_and_out(int index, int r, int g, int b, int duration) {
    for (int i = 0; i < 256; i++) {
        strip.setBrightness(i);
        strip.setLedColorData(index, r, g, b);
        strip.show();
        delay(duration / 512);
    }
    for (int i = 255; i >= 0; i--) {
        strip.setBrightness(i);
        strip.setLedColorData(index, r, g, b);
        strip.show();
        delay(duration / 512);
    }
}

void led_wave_effect(int index, int r, int g, int b, int delay_time) {
    for (int j = 0; j < 256; j++) {
        int wheelPos = (index * 256 / LEDS_COUNT + j) & 255;
        uint32_t color = strip.Wheel(wheelPos);
        strip.setLedColorData(index, color >> 16 & 0xFF, color >> 8 & 0xFF, color & 0xFF);
        strip.show();
        delay(delay_time);
    }
}

void set_random_color(int index) {
    uint32_t color = strip.Wheel(random(256));
    strip.setLedColorData(index, color >> 16 & 0xFF, color >> 8 & 0xFF, color & 0xFF);
}

void alternate_two_colors(int r1, int g1, int b1, int r2, int g2, int b2, int delay_time) {
    for (int i = 0; i < 2; i++) {
        if (i % 2 == 0) {
            strip.setLedColorData(i, r1, g1, b1);
        } else {
            strip.setLedColorData(i, r2, g2, b2);
        }
    }
    strip.show();
    delay(delay_time);
    for (int i = 0; i < 2; i++) {
        if (i % 2 == 0) {
            strip.setLedColorData(i, r2, g2, b2);
        } else {
            strip.setLedColorData(i, r1, g1, b1);
        }
    }
    strip.show();
}

void fill_gradient(int start_index, int r1, int g1, int b1, int r2, int g2, int b2) {
    for (int i = start_index; i < LEDS_COUNT; i++) {
        int r = (r1 * (LEDS_COUNT - i) + r2 * i) / LEDS_COUNT;
        int g = (g1 * (LEDS_COUNT - i) + g2 * i) / LEDS_COUNT;
        int b = (b1 * (LEDS_COUNT - i) + b2 * i) / LEDS_COUNT;
        strip.setLedColorData(i, r, g, b);
    }
    strip.show();
}

void led_chase_effect(int r, int g, int b, int delay_time) {
    for (int i = 0; i < 2; i++) {
        strip.setLedColorData(i, r, g, b);
        strip.show();
        delay(delay_time);
        strip.setLedColorData(i, 0, 0, 0);
    }
}

void led_theater_chase_effect(int r, int g, int b, int delay_time) {
    for (int j = 0; j < 10; j++) {
        for (int q = 0; q < 3; q++) {
            for (int i = 0; i < 2; i += 3) {
                strip.setLedColorData(i + q, r, g, b);
            }
            strip.show();
            delay(delay_time);
            for (int i = 0; i < 2; i += 3) {
                strip.setLedColorData(i + q, 0, 0, 0);
            }
        }
    }
}

void led_bounce_effect(int r, int g, int b, int delay_time) {
    for (int i = 0; i < 2; i++) {
        strip.setLedColorData(i, r, g, b);
        strip.show();
        delay(delay_time);
        strip.setLedColorData(i, 0, 0, 0);
    }
    for (int i = 1; i >= 0; i--) {
        strip.setLedColorData(i, r, g, b);
        strip.show();
        delay(delay_time);
        strip.setLedColorData(i, 0, 0, 0);
    }
}

// Additional functions
void police_lights_effect(int delay_time) {
    for (int i = 0; i < 10; i++) {
        strip.setLedColorData(0, 255, 0, 0);
        strip.show();
        delay(delay_time);
        strip.setLedColorData(0, 0, 0, 255);
        strip.show();
        delay(delay_time);
    }
}

void gradient_fill(int r1, int g1, int b1, int r2, int g2, int b2) {
    strip.setLedColorData(0, r1, g1, b1);
    strip.show();
    delay(500);
    strip.setLedColorData(0, r2, g2, b2);
    strip.show();
}

void festival_lights(int delay_time) {
    for (int i = 0; i < 5; i++) {
        strip.setLedColorData(0, m_color[i][0], m_color[i][1], m_color[i][2]);
        strip.show();
        delay(delay_time);
    }
}

void fire_effect(int cooling, int sparking) {
    static byte heat[LEDS_COUNT];
    heat[0] = qsub8(heat[0], random(0, ((cooling * 10) / LEDS_COUNT) + 2));
    if (random(255) < sparking) {
        heat[0] = qadd8(heat[0], random(160, 255));
    }
    uint32_t color = strip.Wheel((heat[0] * 240 / 255) % 255);
    strip.setLedColorData(0, color >> 16 & 0xFF, color >> 8 & 0xFF, color & 0xFF);
    strip.show();
    delay(30);
}

void led_twinkle_effect(int delay_time) {
    if (random(10) > 5) {
        strip.setLedColorData(0, 255, 255, 255);
    } else {
        strip.setLedColorData(0, 0, 0, 0);
    }
    strip.show();
    delay(delay_time);
}

void color_sparkle(int r, int g, int b, int delay_time) {
    strip.setLedColorData(0, r, g, b);
    strip.show();
    delay(delay_time);
    strip.setLedColorData(0, 0, 0, 0);
    strip.show();
}

void color_pulse(int r, int g, int b, int duration) {
    for (int i = 0; i < 256; i++) {
        strip.setBrightness(i);
        strip.setLedColorData(0, r, g, b);
        strip.show();
        delay(duration / 512);
    }
    for (int i = 255; i >= 0; i--) {
        strip.setBrightness(i);
        strip.setLedColorData(0, r, g, b);
        strip.show();
        delay(duration / 512);
    }
}

void color_strobe_effect(int r, int g, int b, int delay_time) {
    for (int i = 0; i < 10; i++) {
        strip.setLedColorData(0, r, g, b);
        strip.show();
        delay(delay_time);
        strip.setLedColorData(0, 0, 0, 0);
        strip.show();
        delay(delay_time);
    }
}

void chasing_lights(int r, int g, int b, int delay_time) {
    strip.setLedColorData(0, r, g, b);
    strip.show();
    delay(delay_time);
    strip.setLedColorData(0, 0, 0, 0);
    strip.show();
}

void led_breathing_effect(int r, int g, int b, int duration) {
    for (int i = 0; i < 256; i++) {
        strip.setBrightness(i);
        strip.setLedColorData(0, r, g, b);
        strip.show();
        delay(duration / 512);
    }
    for (int i = 255; i >= 0; i--) {
        strip.setBrightness(i);
        strip.setLedColorData(0, r, g, b);
        strip.show();
        delay(duration / 512);
    }
}


// Function implementation
void play_bad_pulse_effect() {
    // Timings based on the beat of "Bad" by Michael Jackson for the first 10 seconds
    const int beat_delay = 500; // Adjust this to match the beat

    // Light pulses corresponding to the beat
    for (int i = 0; i < 20; i++) { // 20 beats in 10 seconds at 120 BPM (half-second per beat)
        // Pulse effect
        for (int brightness = 0; brightness <= 255; brightness += 5) {
            strip.setBrightness(brightness);
            strip.setLedColorData(0, 255, 0, 0); // Red color
            strip.show();
            delay(beat_delay / 51);
        }
        for (int brightness = 255; brightness >= 0; brightness -= 5) {
            strip.setBrightness(brightness);
            strip.setLedColorData(0, 255, 0, 0); // Red color
            strip.show();
            delay(beat_delay / 51);
        }
        delay(beat_delay);
    }

    // Ensure the LED is turned off after the effect
    strip.setLedColorData(0, 0, 0, 0);
    strip.show();
}




// Function prototype
void play_bad_melody_effect();

// Function implementation
void play_bad_melody_effect() {
    // Timings based on the beats of "Bad" by Michael Jackson
    const int beat_delay = 500; // Adjust this to match the beat
    const int fast_beat_delay = 250; // Fast beat

    // Verse 1
    for (int i = 0; i < 8; i++) {
        pulse_led(255, 0, 0, beat_delay); // Red pulses
    }

    // Chorus
    for (int i = 0; i < 4; i++) {
        pulse_led(0, 255, 0, beat_delay); // Green pulses
    }

    // Verse 2
    for (int i = 0; i < 8; i++) {
        pulse_led(0, 0, 255, beat_delay); // Blue pulses
    }

    // Bridge
    for (int i = 0; i < 4; i++) {
        pulse_led(255, 255, 0, fast_beat_delay); // Yellow pulses
    }

    // Chorus
    for (int i = 0; i < 4; i++) {
        pulse_led(0, 255, 0, beat_delay); // Green pulses
    }

    // Outro
    for (int i = 0; i < 8; i++) {
        pulse_led(255, 0, 255, beat_delay); // Purple pulses
    }

    // Ensure the LED is turned off after the effect
//    strip.setLedColorData(0, 0, 0, 0);
  //  strip.show();
delay(1000);
}

void pulse_led(int r, int g, int b, int delay_time) {
    // Pulse effect
    for (int brightness = 0; brightness <= 255; brightness += 5) {
        strip.setBrightness(brightness);
        strip.setLedColorData(0, r, g, b);
        strip.show();
        delay(delay_time / 51);
    }
    for (int brightness = 255; brightness >= 0; brightness -= 5) {
        strip.setBrightness(brightness);
        strip.setLedColorData(0, r, g, b);
        strip.show();
        delay(delay_time / 51);
    }
}


// Function implementation
void play_mission_impossible_melody_effect() {
    // Timings based on the beats of "Mission: Impossible" theme
    const int short_beat = 150; // Short beat
    const int long_beat = 300; // Long beat

    // Cycle through the main part of the "Mission: Impossible" melody
    while (true) {
        pulse_led(255, 0, 0, short_beat);  // Red pulse
        pulse_led(255, 0, 0, short_beat);  // Red pulse
        pulse_led(255, 0, 0, short_beat);  // Red pulse
        delay(long_beat);

        pulse_led(255, 0, 0, short_beat);  // Red pulse
        pulse_led(255, 0, 0, short_beat);  // Red pulse
        pulse_led(255, 0, 0, short_beat);  // Red pulse
        delay(long_beat);

        pulse_led(0, 255, 0, short_beat);  // Green pulse
        pulse_led(0, 255, 0, short_beat);  // Green pulse
        delay(long_beat);

        pulse_led(0, 255, 0, short_beat);  // Green pulse
        pulse_led(0, 255, 0, short_beat);  // Green pulse
        delay(long_beat);

        pulse_led(0, 0, 255, short_beat);  // Blue pulse
        pulse_led(0, 0, 255, short_beat);  // Blue pulse
        pulse_led(0, 0, 255, short_beat);  // Blue pulse
        delay(long_beat);

        pulse_led(0, 0, 255, short_beat);  // Blue pulse
        pulse_led(0, 0, 255, short_beat);  // Blue pulse
        pulse_led(0, 0, 255, short_beat);  // Blue pulse
        delay(long_beat);
    }
}



