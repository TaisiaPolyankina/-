
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	enable=1;
	counter=0;
	speed=0;
	fb_motor.dt=0.02;
	fb_motor.ke=5;
	fb_motor.Tm=0.05;
	fb_motor2.dt=0.02;
	fb_motor2.ke=5;
	fb_motor2.Tm=0.05;
	
	fb_controller.dt=0.02;
	fb_controller.k_p=0.0064;
	fb_controller.k_i=0.16;
	fb_controller.max_abs_value=24;
}
