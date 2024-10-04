
{REDUND_ERROR} FUNCTION_BLOCK FB_Integrator (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		in : {REDUND_UNREPLICABLE} REAL; (*input integrator*)
	END_VAR
	VAR_OUTPUT
		out : {REDUND_UNREPLICABLE} REAL; (*output integrator*)
	END_VAR
	VAR
		dt : {REDUND_UNREPLICABLE} REAL; (*step in sec*)
		state : REAL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK FB_Motor (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		u : REAL; (*input voltage [v]*)
	END_VAR
	VAR_OUTPUT
		w : {REDUND_UNREPLICABLE} REAL; (*frequency of revolving [rev/min]*)
		phi : {REDUND_UNREPLICABLE} REAL; (*position [rad]*)
	END_VAR
	VAR
		integrator : FB_Integrator; (*integrator*)
		Tm : REAL; (*el_mech const of time [sec]*)
		ke : REAL; (*EDS of motor [V*min/rev]*)
		dt : REAL; (*step of calculation [sec]*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK FB_Regulator (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		e : REAL; (*dissonance between input and real speed of motor revolving [rev/min]*)
	END_VAR
	VAR_OUTPUT
		u : {REDUND_UNREPLICABLE} REAL; (*voltage goes in motor [v]*)
	END_VAR
	VAR
		k_i : REAL; (*integral coef*)
		k_p : REAL; (*proprtional coef*)
		integrator : FB_Integrator; (*integrator*)
		iyOld : REAL; (*previous state*)
		max_abs_value : REAL; (*border of restriction block [v]*)
		dt : REAL; (*step of calculation*)
	END_VAR
END_FUNCTION_BLOCK
