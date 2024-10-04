
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	if(enable == 1)
	{
		counter+=1;
		if (counter >= 500 && counter <= 1000) speed1 = 40;
		else speed1 = 5;
	}
	
	else speed1 = 0;
	fb_controller.e = speed1 - fb_motor.w;
	fb_motor2.u = speed1*fb_motor2.ke;
	fb_motor.u = fb_controller.u * fb_motor.ke;
	FB_Regulator(&fb_controller);
	FB_Motor(&fb_motor);
	FB_Motor(&fb_motor2);
}
