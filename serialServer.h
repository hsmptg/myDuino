#ifndef DUINO__SERIALSERVER_H_
#define DUINO__SERIALSERVER_H_

#include "Arduino.h"

class SerialServer {
	public:
		void begin(unsigned long int baudrate);
		char *getCmd();
		void sendMsg(const char *msg);
};

#endif /* DUINO__SERIALSERVER_H_ */
