#ifndef MYDUINO3_TICK_H_
#define MYDUINO3_TICK_H_

#include "Arduino.h"

class Tick {
public:
	Tick(int pin);
	void start();
	void stop();
	void loop();
private:
	int pin_;
	bool on_;
	unsigned long last_;
};

#endif /* MYDUINO3_TICK_H_ */
