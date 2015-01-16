#include "tick.h"

Tick::Tick(int pin) {
	pin_ = pin;

	pinMode(pin_, OUTPUT);
	digitalWrite(pin_, LOW);
	on_ = false;

	last_ = millis();
}

void Tick::start() {
	on_ = true;
	digitalWrite(pin_, HIGH);
}

void Tick::stop() {
	on_ = false;
	digitalWrite(pin_, LOW);
}

void Tick::loop() {
	if (on_) {
		unsigned long now = millis();
		if (now-last_ > 100) {
			digitalWrite(pin_, LOW);
			if (now-last_ > 1000) {
				digitalWrite(pin_, HIGH);
				last_ += 1000;
			}
		}
	}
}
