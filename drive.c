#include <rc_usefulincludes.h>
#include <roboticscape.h>
 /*********************************************************************
 *********
 * Drive the robot in a short predetermined circle
 **********************************************************************
 ********/
int main() {
  // Set the L & R motor #s
	int left = 2;
	int right = 3;
	 
	// always initialize cape library first
	rc_motor_init();
	printf("\nHello BeagleBone\n");
	// done initializing so set state to RUNNING
	rc_set_state(RUNNING); //**
	// bring H-bridges of of standby
	rc_motor_init();  //**
	rc_led_set(RC_LED_GREEN,1);
	rc_led_set(RC_LED_RED,1);
	rc_motor_free_spin(left);
	rc_motor_free_spin(right);
	printf("Motors are now ready.\n");

   	// Move forward for a few seconds **************
   	rc_motor_set(right, -0.4);
	rc_motor_set(left, 0.4);
   	sleep(5);
   	rc_motor_brake(right);
	rc_motor_brake(left);
   	// Slow turn around ****************************
   	rc_motor_set(right, -0.4);
	rc_motor_set(left, 0.2);
   	sleep(3.5);
   	rc_motor_brake(right);
	rc_motor_brake(left);
   	// Move forward to get back ******************
	rc_motor_set(right, -0.4);
	rc_motor_set(left, 0.4);
	sleep(5);
   	rc_motor_brake(right);
	rc_motor_brake(left);
	
	printf("Done\n");
	rc_motor_cleanup();
	return 0;
}
