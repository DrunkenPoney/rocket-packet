#include "mcu_command.h"


int
mc_valid_function(int function)
{
	return (0 <= function) && (function <= MC_SET_STATES);
}


int
mc_valid_arg(int function, int arg)
{
	int valid;

	switch (function) {
	case MC_SET_ACTUATOR: /* fallthrough */
	case MC_CLR_ACTUATOR:
		/* argument is actuator id number */
		valid = (0 <= arg) && (arg <= PISTON);
		break;
	case MC_SET_ACTUATOR_MASK: /* fallthrough */
	case MC_CLR_ACTUATOR_MASK:
	case MC_SET_STATES:
		/* check that argument is 6-bit mask */
		valid = (0xc0 & arg) == 0;
		break;
	}

	return valid;
}


