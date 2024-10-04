
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
void FB_Motor(struct FB_Motor* inst)
{
	/*motor*/
	REAL buf1 = inst->u*(1/inst->ke) - inst->w;
	REAL buf2 = buf1/inst->Tm;
	
	inst->integrator.in = buf2;
	FB_Integrator(&inst->integrator);
	
	inst->w = inst->integrator.out;
	
	/*speed sensor*/
	inst->integrator.in = inst->w;
	FB_Integrator(&inst->integrator);
	
	inst->phi = inst->integrator.out;
	
}
