
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotorCont.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Regulator(struct FB_Regulator* inst)
{
	/*TODO: Add your code here*/
	REAL buf_up = inst->e*inst->k_p;
	REAL buf_down = inst->e*inst->k_i;
	if (buf_up > inst->max_abs_value || buf_up < -inst->max_abs_value)
	{
		if (buf_up > 0) buf_up = inst->max_abs_value;
		else buf_up = -inst->max_abs_value;
	}
	
	buf_down = buf_down+inst->iyOld;
	
	inst->integrator.in = buf_down;
	FB_Integrator(&inst->integrator);
	
	buf_down = inst->integrator.out;
	
	REAL buf = buf_up+buf_down;
	
	if (buf > inst->max_abs_value || buf < -inst->max_abs_value)
	{
		if (buf > 0) buf = inst->max_abs_value;
		else buf = -inst->max_abs_value;
		inst->u = buf;
	}
	else
	{
		inst->u = buf;
	}
	inst->iyOld = inst->u-buf;
	
}

