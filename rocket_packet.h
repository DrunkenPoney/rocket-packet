/*
 * rocket_packet.h
 *
 *  Created on: Nov 1, 2018
 *      Author: laplace
 */

#include <string.h>


#ifndef _ROCKET_PACKET_H_
#define _ROCKET_PACKET_H_

/* size of the packet including the crc */
#define ROCKET_PACKET_SIZE 92
#define ROCKET_PACKET_START 's'


typedef struct {
	/* time since boot in milliseconds */
	double timestamp;
	/* GPS values */
	double latitude;
	double longitude;
	char NSIndicator;
	char EWIndicator;
	double UTCTime;
	/*
	 * 10DOF values
	 * BMP180
	 */
	float altitude;
	uint32_t pressure;
	float temperature;
	/*
	 * lsm303
	 * acceleration values are in milli-G
	 * magnetic field values are in milli-gauss
	 */
	int16_t acc_x_uncomp;
	int16_t acc_y_uncomp;
	int16_t acc_z_uncomp;
	float acc_x;
	float acc_y;
	float acc_z;
	int16_t mag_x;
	int16_t mag_y;
	int16_t mag_z;
	/*
	 * l3dg20
	 * angular speed values are in degrees/s
	 */
	int16_t x_gyro;
	int16_t y_gyro;
	int16_t z_gyro;
} AvionicsData;


typedef struct {
	/* TODO: fix types and array sizes */
	uint8_t valve_states[5];
	uint8_t piston_state;
	uint16_t manometers[5];
	uint16_t piezoelectric;
} MotorData;


typedef struct {
	AvionicsData avionics_data;
	MotorData motor_data;
	char start_char;
	uint16_t crc;
} RocketPacket;


/*
 * Serialize the rocket packet for transmission.
 */
unsigned int serialize_rocket_packet(RocketPacket* pkt, uint8_t* s);

#endif /* _ROCKET_PACKET_H_ */
