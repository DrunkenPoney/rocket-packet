#include "motor_command.h"


int mc_valid_function(int function) {
	return (0 <= function) && (function <= MC_SET_STATES);
}


int mc_valid_arg(int function, int arg) {
	int valid;

	switch (function) {
	case MC_SET_ACTUATOR:
		/* fallthrough */
	case MC_CLR_ACTUATOR:
		/* argument is actuator id number */
		valid = (0 <= arg) && (arg <= PISTON);
		break;
	case MC_SET_ACTUATOR_MASK:
	case MC_CLR_ACTUATOR_MASK:
	case MC_SET_STATES:
		/* argument is 6-bit mask */
		valid = (0 <= arg) && (arg <= 0b00111111);
		break;
	}

	return valid;
}


