# Rocket Packet

## <u>Details</u>

### Sizes
__Total packet size:__ _avionic_size + motor_size + 3 =_ <u>103 bytes</u><br>
__Motor data size:__ _actuators + (4 * manometers) + 2 =_ <u>24 bytes</u><br>
__Avionic data size:__ <u>76 bytes</u><br>

### Other
__Number of actuators:__ 6<br>
__Number of manometers:__ 4<br>

## <u>Structure & Content Infos</u>

|  #  | name | Sensor | Unit | Data Type | Bytes | Description |
|:---:|:----:|:------:|:----:|:---------:|:-----:| ----------- |
| 0 | `start_short` | <hr> | <hr> | `char` | 1 | Packet type identifier |
| 1 | `timestamp` | <hr> | _ms_ | `unsigned`<br>`long` | 8 | Time since boot in milliseconds |
| 2 | `latitude` | GPS | _°_ | `double` | 8 | todo |
| 3 | `longitude` | GPS | _°_ | `double` | 8 | todo |
| 4 | `NSIndicator` | GPS | _`N`/`S`_ | `char` | 1 | todo |
| 5 | `EWIndicator` | GPS | _`E`/`W`_ | `char` | 1 | todo |
| 6 | `nsatellites` | GPS | <hr> | `uint8` | 1 | Number of GPS stellites |
| 7 | `altitude` | [BMP180][BMP180] | _m_ | `float` | 4 | Altitude in meters |
| 8 | `pressure` | [BMP180][BMP180] | _?_ | `uint32` | 4 | todo |
| 9 | `temperature` | [BMP180][BMP180] | _°C_ | `float` | 4 | Temperature in celsius |
| 10 | `acc_x_uncomp` | [LSM303][LSM303] | _g_ | `int16` | 2 | Acceleration en g |
| 11 | `acc_y_uncomp` | [LSM303][LSM303] | _g_ | `int16` | 2 | Acceleration en g |
| 12 | `acc_z_uncomp` | [LSM303][LSM303] | _g_ | `int16` | 2 | Acceleration en g |
| 13 | `mag_x` | [LSM303][LSM303] | _?_ | `int16` | 2 | todo |
| 14 | `mag_y` | [LSM303][LSM303] | _?_ | `int16` | 2 | todo |
| 15 | `mag_z` | [LSM303][LSM303] | _?_ | `int16` | 2 | todo |
| 16 | `x_gyro` | [L3DG20][L3GD20] | _°/sec_ | `int16` | 2 | Angular speed in degrees per second |
| 17 | `y_gyro` | [L3DG20][L3GD20] | _°/sec_ | `int16` | 2 | Angular speed in degrees per second |
| 18 | `z_gyro` | [L3DG20][L3GD20] | _°/sec_ | `int16` | 2 | Angular speed in degrees per second |
| <hr> | <u>__Motor__</u> | <hr> | <hr> | <hr> | <hr> | <hr> |
| 19 | `actuator_state_1` | <hr> | _0/1_ | `uint8` | 1 | todo |
| 20 | `actuator_state_2` | <hr> | _0/1_ | `uint8` | 1 | todo |
| 21 | `actuator_state_3` | <hr> | _0/1_ | `uint8` | 1 | todo |
| 22 | `actuator_state_4` | <hr> | _0/1_ | `uint8` | 1 | todo |
| 23 | `actuator_state_5` | <hr> | _0/1_ | `uint8` | 1 | todo |
| 24 | `actuator_state_6` | <hr> | _0/1_ | `uint8` | 1 | todo |
| 20 | `manometer_1` | ??? | _?_ | `int` | 4 | todo |
| 20 | `manometer_2` | ??? | _?_ | `int` | 4 | todo |
| 20 | `manometer_3` | ??? | _?_ | `int` | 4 | todo |
| 20 | `manometer_4` | ??? | _?_ | `int` | 4 | todo |
| 21 | `piezoelectric` | ??? | _?_ | `uint16` | 2 | todo |
| <hr> | <u>__Checksum__</u> | <hr> | <hr> | <hr> | <hr> | <hr> |
| 21 | `crc` | <hr> | <hr> | `uint16` | 2 | CRC Checksum |

[BMP180]:(https://cdn-shop.adafruit.com/datasheets/BST-BMP180-DS000-09.pdf)
[LSM303]:(https://cdn-shop.adafruit.com/datasheets/LSM303DLHC.PDF)
[L3GD20]:(https://www.st.com/resource/ja/application_note/dm00119036-l3gd20-3-axis-digital-output-gyroscope-stmicroelectronics.pdf)