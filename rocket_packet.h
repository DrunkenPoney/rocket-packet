/*
 * rocket_packet.h
 *
 *  Created on: Nov 1, 2018
 *	  Author: laplace
 */

#include <stdint.h>
#include <string.h>

#include "motor_command.h"


#ifndef _ROCKET_PACKET_H_
#define _ROCKET_PACKET_H_

#define ACK_PACKET_SIZE 7
#define CMD_PACKET_SIZE 8
#define AVIONICS_DATA_SIZE 76

#define MOTOR_DATA_SIZE ( \
	ACTUATORS_NUM \
	+ (4 * MANOMETERS_NUM) \
	+ 2 \
)

#define ROCKET_PACKET_SIZE ( \
	AVIONICS_DATA_SIZE \
	+ MOTOR_DATA_SIZE \
	+ 3 \
)

#define ROCKET_PACKET_START 's'
#define COMMAND_START 0xface
#define ACK_START COMMAND_START

#define ACK 0x01
#define NACK 0xff


struct __attribute__ ((packed)) {
	/* time since boot in milliseconds */
	double timestamp;
	/* GPS values */
	double latitude;
	double longitude;
	char NSIndicator;
	char EWIndicator;
	char nsatellites;
	/* 10DOF values */
	/* BMP180 */
	float altitude;
	uint32_t pressure;
	float temperature;
	/* lsm303 */
	int16_t acc_x_uncomp;
	int16_t acc_y_uncomp;
	int16_t acc_z_uncomp;
	int16_t mag_x;
	int16_t mag_y;
	int16_t mag_z;
	/* l3dg20 */
	int16_t x_gyro;
	int16_t y_gyro;
	int16_t z_gyro;
} AvionicsData;

struct __attribute__ ((packed)) {
	unsigned char actuator_states[ACTUATORS_NUM];
	int manometers[MANOMETERS_NUM];
	uint16_t piezoelectric;
} MotorData;

struct __attribute__ ((packed)) {
	char start_char;
	AvionicsData avionics_data;
	MotorData motor_data;
	uint16_t crc;
} RocketPacket;

struct __attribute__ ((packed)) {
	uint16_t start_short;
	uint16_t id;
	uint8_t function;
	uint8_t arg;
	uint16_t crc;
} CommandPacket;

struct __attribute__ ((packed)) {
	uint16_t start_short;
	uint16_t id;
	uint8_t ack;
	uint16_t crc;
} AckPacket;


#endif /* _ROCKET_PACKET_H_ */
