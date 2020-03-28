# rocket-packet
repo for the rocket packet format, to be used as submodule in all projects that send/receive data


## CRC used

The CRC used in data transmission from the rocket to the ground station and
back is the CRC-16/CCITT-FALSE. This is a 16-bit with the following characteristics:

- width: 16 bit
- polynomial: 0x1021
- xor in: 0xffff
- xor out: 0x0000
- reflect in: false
- reflect out: false

