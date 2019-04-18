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
 int main(int argc, char *argv[]) {
	char input;
	// always initialize cape library first
	rc_initialize();
	printf("nHello BeagleBonen");
	// done initializing so set state to RUNNING
	rc_set_state(RUNNING);
	// bring H-bridges of of standby
	rc_enable_motors();
	rc_set_led(GREEN,ON);
	rc_set_led(RED,ON);
	rc_set_motor_free_spin(1);
	rc_set_motor_free_spin(2);
	printf("Motors are now ready.n");

	// Set the L & R motor #s from input
	int left = ctoi(argv[1]);
	int right = ctoi(argv[2]);

	// Turn on a raw terminal to get a single charactersystem("stty=raw");
	do {
		printf("> ");
		input = getchar();
		switch(input) {
			case 'f':
				rc_set_motor(right, -0.5);
			 	rc_set_motor(left, 0.5);
			 	break;
			 
			case 'r':
			 	rc_set_motor(right, 0.5);
			 	rc_set_motor(left, 0.5);
			 	break;

			case 'l':
			 	rc_set_motor(right, -0.5);
			 	rc_set_motor(left, -0.5);
			 	break;
			
			case 'b':
			 	rc_set_motor(right, 0.5);
			 	rc_set_motor(left, -0.5);
			 	break;
			
			case 's':
			 	rc_set_motor_brake_all();
			 	break;
			 
			case 'q':
			 	rc_disable_motors();
			 	break;
			
			default:
				printf("Invalid Character.n");
		}

	} while(input != 'q');
	
	printf("Donen");
	rc_cleanup();
	system("stty cooked");
	return 0;
}