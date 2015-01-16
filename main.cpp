#include "main.h"

SerialServer server;

#define LED 13
Tick tick(LED);

void setup() {
	server.begin(115200);
	server.sendMsg(VERSION_STR);
}

void loop() {
	char *cmd;
	if ((cmd = server.getCmd()) != 0) {
		switch(cmd[0]) {
		case 'v':
			server.sendMsg(VERSION_STR);
			break;
		case 't':
			if (cmd[1] == '1')
				tick.start();
			else
				tick.stop();
			break;
		}
	}
	tick.loop();
}
