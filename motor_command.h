/*
 * Library to describe commands that can be sent to the motor
 */


#ifndef _MOTOR_COMMAND_H_
#define _MOTOR_COMMAND_H_


/* valid functions */

/* set an actuator to HIGH state */
#define MC_SET_ACTUATOR 1

/* set an actuator to LOW state */
#define MC_CLR_ACTUATOR 2

/* using bitmask, set actuators to HIGH state */
#define MC_SET_ACTUATOR_MASK 3

/* using bitmask, set actuators to LOW state */
#define MC_CLR_ACTUATOR_MASK 4

/* set all actuators to bitmask states */
#define MC_SET_STATES 5

/* actuators id numbers */
#define ACTUATORS_NUM 6
#define VALVE_A 0
#define VALVE_B 1
#define VALVE_C 2
#define VALVE_D 3
#define VALVE_E 4
#define PISTON 5

/* validation functions */

/* check if a motor command function is valid */
int mc_valid_function(int function);

/* check if a motor command argument to a function is valid */
int mc_valid_arg(int function, int arg);


#endif /* _MOTOR_COMMAND_H_ */
