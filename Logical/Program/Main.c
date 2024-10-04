
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	enable=1;
	counter=0;
	speed=0;
	fb_motor.dt=0.01;
	fb_motor.ke=43.98;
	fb_motor.Tm=0.173;
	fb_motor2.dt=0.01;
	fb_motor2.ke=43.98;
	fb_motor2.Tm=0.173;
	
	fb_controller.dt=0.02;
	fb_controller.k_p=3.804;
	fb_controller.k_i =21.99;
	fb_controller.max_abs_value=24;
}

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

void _EXIT ProgramExit(void)
{

}

