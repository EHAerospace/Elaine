#include "radio.hpp"

void setup() {
    Serial.begin(115200);
    Serial.println(F("Starting"));

    initPMU();
    radio_setup();

}

void loop() {
    os_runloop_once();

    //displayInfo();
}
