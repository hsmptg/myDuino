#include "main.h"

SerialServer server;

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
		}
	}
}
