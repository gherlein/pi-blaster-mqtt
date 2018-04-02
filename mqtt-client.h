#include <sys/types.h>
#include <unistd.h>

#include <signal.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <mosquitto.h>


#define MQTT_TOPIC_TEXT "pi-blaster-mqtt/text"
#define MQTT_TOPIC_BIN  "pi-blaster-mqtt/bin"


void mqtt_go_go(void);
void mqtt_cleanup(void);


