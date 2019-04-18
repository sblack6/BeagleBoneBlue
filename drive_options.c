 /*********************************************************************
*********
 * rc_motor_control.c
 *
 * This is a simple dc motor control program. It takes in a
 character
 * and then controls the motors to move forward, reverse, left or
 right
***************************************************************************
***/
 #include <rc_usefulincludes.h>
 #include <roboticscape.h>
 /*********************************************************************
 *********
 * int main()
 *
 * This main function contains these critical components
 * - call to initialize_cape
 * - main while loop that checks for EXITING condition
 * - switch statement to send proper controls to the motors
 * - cleanup_roboticscape() at the end
 **********************************************************************
 ********/
 int main() {
	char input;
	 
	 // Set the L & R motor #s
	int left = 4;
	int right = 1;
	 
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
	printf("Motors are now ready.n");

	// Turn on a raw terminal to get a single character
	system("stty=raw");
	do {
		printf("> ");
		input = getchar();
		switch(input) {
			case 'f':
				rc_motor_set(right, -0.5);
			 	rc_motor_set(left, 0.5);
			 	break;
			 
			case 'r':
			 	rc_motor_set(right, 0.5);
			 	//rc_motor_set(left, 0.5);
			 	sleep(0.5);
				rc_motor_set(right, 0);
				break;

			case 'l':
			 	rc_motor_set(right, -0.5);
			 	rc_motor_set(left, -0.5);
			 	break;
			
			case 'b':
			 	rc_motor_set(right, 0.5);
			 	rc_motor_set(left, -0.5);
			 	break;
			
			case 's':
				rc_motor_brake(right);
			 	rc_motor_brake(left);
			 	break;
			 
			case 'q':
			 	rc_motor_set(right, 0);
			 	rc_motor_set(left, 0);
			 	break;
			
			default:
				printf("Invalid Character.n");
		}

	} while(input != 'q');
	
	printf("Donen");
	rc_motor_cleanup();
	system("stty cooked");
	return 0;
}
