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
	 
	 // Set the L & R motor #s from input
	int left = ctoi(argv[1]);
	int right = ctoi(argv[2]);
	 
	// always initialize cape library first
	rc_motor_init();
	printf("nHello BeagleBonen");
	// done initializing so set state to RUNNING
	rc_set_state(RUNNING); //**
	// bring H-bridges of of standby
	rc_enable_motors();  //**
	rc_led_set(GREEN,ON);
	rc_led_set(RED,ON);
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
			 	rc_motor_set(left, 0.5);
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
			 	rc_disable_motors();  //**
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
