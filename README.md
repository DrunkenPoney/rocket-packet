# rocket-packet

Repo for the rocket packet format, to be used as submodule in all projects
that send/receive data.
See the source files for the field names, types and placement of all structures.
See important notes at the bottom for what is to be done and potential changes.

## Avionics data

The avionics data structure contains the data from the avionics board.
The data contained in the struct is:

- a timestamp when the packet was created, represents the uptime of the
	avionics board
- GPS values: latitude, longitude, north-south and east-west indicator and the
	UTC time from the satellite)
- value from the IMU10DOF's sensors:
	- BMP180: altitude, pressure, temperature
	- LSM303: acceleration (uncompensated and compensated) on 3 axis and
		magnetic field on 3 axis)
	- L3DG20: angular speed on 3 axis

## Motor data

The motor data structure contains the data from the motor control unit:

- States of the various actuators (6)
- analog readings from the pressure sensors (4)
- analog reading from the piezoelectric sensor

## Rocket packet

The packet is the structure which is transmitted to the ground station.
It is composed of the motor data and avionics data.
It also has a start character and a 16-bit CRC for data integrity check.

# Command packet

The command packet is critical to the operation of the rocket's launch system.
It communicates with the motor control unit by sending commands.

### Start short

First, the command packet contains a start short (16-bit) which identifies 
the packet as a command packet to the receiver.

### Identifier

It also contains an ID which is used to match command packets to acknowledge
packets, as well as checking the order of reception of those packets
(the identifier is incremented for each command).

### Function and argument

The command's syntax has a function and a single argument. The following
table shows each function and associated arguments:

| Function                  | Argument                       |
| ------------------------- | ------------------------------ |
| `0` start a sequence      | to be determined, see notes    |
| `1` set actuator          | Actuator number                |
| `2` reset actuator        | Actuator number                |
| `3` set actuators         | Actuator numbers (as bit mask) |
| `4` reset actuators       | Actuator numbers (as bit mask) |
| `5` set actuators states  | Actuators states (as bit mask) |


### CRC

The same usual 16-bit CRC described at the bottom is used to check data
integrity.

## Acknowledge packet

The Acknowledge packets are transmitted from the motor control unit to the
ground station. It is used by the ground station to confirm whether or not
the corresponding command was executed or not.

The motor control unit should send an Ack packet with the ID matching
the command packet. If a packet was missed, the following should occur:

- ground station sends command packet id=20
- packet is lost
- ground station sends command packet id=21
- motor control unit receives the packet
- motor control unit sees that it missed packet id=20
- motor control unit sends *two* Ack packets with the `ack` field set to NACK,
	with id 20 and 21
- ground station receives the packets and resends packets 20 and 21

## CRC implementation

The CRC used in data transmission from the rocket to the ground station and
back is the CRC-16/CCITT-FALSE. This is a 16-bit with the following
characteristics:

- width: 16 bit
- polynomial: 0x1021
- xor in: 0xffff
- xor out: 0x0000
- reflect in: false
- reflect out: false

# Notes

- In terms of software implementation, I'm questionning my choice to have the
	data packets defined by a single library (and you may have the same
	question). I did this so all repos (one repo/project per MCU) can have
	the rocket-packet repo as a submodule and obey its implementation of the
	structures. I still think this makes sense to a degree, but feel free to
	make it better if you have a better idea (email
	me at maxime_glmt@hotmail.ca), I'd be glad to hear about it).
- The `start a sequence` function could be replaced by just using the other
	functions. This might be safer as it gives the opportunity to see the
	effects of the changes before changing another actuator.


