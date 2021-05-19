#ifndef __RADIO_HPP
#define __RADIO_HPP

#include <Arduino.h>
#include <lmic.h>
#include <hal/hal.h>
#include <SPI.h>
#include <CayenneLPP.h>

#define OLED_SDA 4
#define OLED_SCL 15
#define OLED_RST 16

CayenneLPP lpp(51);

// These callbacks are only used in over-the-air activation, so they are
// left empty here (we cannot leave them out completely unless
// DISABLE_JOIN is set in config.h, otherwise the linker will complain).
void os_getArtEui (u1_t* buf) { }
void os_getDevEui (u1_t* buf) { }
void os_getDevKey (u1_t* buf) { }

static osjob_t sendjob;

// Schedule TX every this many seconds (might become longer due to duty
// cycle limitations).
const unsigned TX_INTERVAL = 15;

/* -------------------------------- */
/*           Radio pins             */
/* -------------------------------- */

#define RADIO_SCLK_PIN               5
#define RADIO_MISO_PIN              19
#define RADIO_MOSI_PIN              27
#define RADIO_CS_PIN                18
#define RADIO_DI0_PIN               26
#define RADIO_RST_PIN               14
#define RADIO_DIO1_PIN              33
#define RADIO_BUSY_PIN              32

// Pin mapping
const lmic_pinmap lmic_pins = {
    .nss = RADIO_CS_PIN,
    .rxtx = LMIC_UNUSED_PIN,
    .rst = RADIO_RST_PIN,
    .dio = {RADIO_DI0_PIN, RADIO_DIO1_PIN, RADIO_BUSY_PIN},
};

// void radio_setup();

#endif
