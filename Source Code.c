/* CO222 : Project01
 *
 * This program gives digital clock as output
 *
 * Author: Jeewantha Udeshika Ariyawansha (E/18/028)
 *
 */

#include <stdio.h>
#include <time.h> // To get time based functions
#include <unistd.h> // To get sleep() function
#include <string.h>
#include <stdlib.h>

// Declaring Functions
int digitcolor(char*);
void digitprint(int array[5][6], int);
void digitmake(char, int);
int digitplace(int);
void colonprint(int);

// Definning designed number arrays
// 0
int pixel0[5][6] = {
                        {1, 1, 1, 1, 1, 1},
                        {1, 1, 0, 0, 1, 1},
                        {1, 1, 0, 0, 1, 1},
                        {1, 1, 0, 0, 1, 1},
                        {1, 1, 1, 1, 1, 1}
                };

// 1
int pixel1[5][6] = {
                        {0, 0, 0, 0, 1, 1},
                        {0, 0, 0, 0, 1, 1},
                        {0, 0, 0, 0, 1, 1},
                        {0, 0, 0, 0, 1, 1},
                        {0, 0, 0, 0, 1, 1}
                };

// 2
int pixel2[5][6] = {
                        {1, 1, 1, 1, 1, 1},
                        {0, 0, 0, 0, 1, 1},
                        {1, 1, 1, 1, 1, 1},
                        {1, 1, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1}
                };

//3
int pixel3[5][6] = {
                        {1, 1, 1, 1, 1, 1},
                        {0, 0, 0, 0, 1, 1},
                        {1, 1, 1, 1, 1, 1},
                        {0, 0, 0, 0, 1, 1},
                        {1, 1, 1, 1, 1, 1}
                };

//4
int pixel4[5][6] = {
                        {1, 1, 0, 0, 1, 1},
                        {1, 1, 0, 0, 1, 1},
                        {1, 1, 1, 1, 1, 1},
                        {0, 0, 0, 0, 1, 1},
                        {0, 0, 0, 0, 1, 1}
                };

//5
int pixel5[5][6] = {
                        {1, 1, 1, 1, 1, 1},
                        {1, 1, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1},
                        {0, 0, 0, 0, 1, 1},
                        {1, 1, 1, 1, 1, 1}
                };

//6
int pixel6[5][6] = {
                        {1, 1, 1, 1, 1, 1},
                        {1, 1, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1},
                        {1, 1, 0, 0, 1, 1},
                        {1, 1, 1, 1, 1, 1}
                };

// 7
int pixel7[5][6] = {
                        {1, 1, 1, 1, 1, 1},
                        {0, 0, 0, 0, 1, 1},
                        {0, 0, 0, 0, 1, 1},
                        {0, 0, 0, 0, 1, 1},
                        {0, 0, 0, 0, 1, 1}
                };

// 8
int pixel8[5][6] = {
                        {1, 1, 1, 1, 1, 1},
                        {1, 1, 0, 0, 1, 1},
                        {1, 1, 1, 1, 1, 1},
                        {1, 1, 0, 0, 1, 1},
                        {1, 1, 1, 1, 1, 1}
                };

// 9
int pixel9[5][6] = {
                        {1, 1, 1, 1, 1, 1},
                        {1, 1, 0, 0, 1, 1},
                        {1, 1, 1, 1, 1, 1},
                        {0, 0, 0, 0, 1, 1},
                        {1, 1, 1, 1, 1, 1}
                };

// colan
int pixelcol[5][6] = {
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0}
                };

int color = 7; //set default color to white

int main(int argc, char** argv){

	time_t timeNow; // To get row time in seconds
	struct tm*readTime; // To convert row time
	char timeArray[100], // Array to store formatted time
	     dayArray[100]; // Array to store formatted date
	int flag;

	if (argc > 1){// Checking are there any arguments
		while ((flag = getopt(argc, argv, ":ch")) != -1){// checking options
			
			switch (flag){
				case 'c': // if option is c
					for (int i = 1; i < argc; i++){  
   						 if (i + 1 != argc){
        						if (strcmp(argv[i], "-c") == 0){                 
           						 	color  = digitcolor(argv[i + 1]);
								if (color == 100){
									printf("%s :This is a not valid color, Please enter one of these colours: black, red, green, yellow, blue, magenta, cyan, white\n", argv[i+1]);
									return 0;
								}
								break;
            						
								return 0;
        						}
    						}

						else if (i+1 == argc){
							printf("Invalid use of arguments\nusage : clock -h\t\tquick help on cmd\nusage : clock -c <color>\tprint clock with a color\n");
							return 0;
						}		 
					}	


				break;

				case 'h': // If option is h
					printf("usage : clock -h\t\tquick help on cmd\nusage : clock -c <color>\tprint clock with a color\n<color-black|red|green|yellow|blue|magenta|cyan|white>  supported colors\n");
					return 0;
				
				break;

				case '?': // if option is anything otherthan c and h
					printf("Invalid use of arguments\nusage : clock -h\t\tquick help on cmd\nusage : clock -c <color>\tprint clock with a color\n");
					return 0;

				break;
			}

		}	
	
	}

	printf("\033[?25l");
	printf("\033[1;1H");
	printf("\033[2J");

	while(1){
		// Getting current time of the system
		time(&timeNow);

		// Convert current time into local time
		readTime = localtime(&timeNow);

		// Formatting time
		strftime(timeArray, 100, "%H%M%S", readTime);

		// Formatting date
		strftime(dayArray, 100, "%Y-%m-%d", readTime);
	
		// Printing Date
                // Move cursor to nextline
                printf("\033[8;23H");
                // Printing date
                printf("\033[3%dm%s",color, dayArray);
		
		// Printing Time
		
		// Printing Hours
		for (int k=0; k<2; k++){
			digitmake(timeArray[k], digitplace(k));
		}

		// Printing Colon
		colonprint(15);

		// Printing Minutes
		for (int l=3; l<5; l++){
			digitmake(timeArray[l-1], digitplace(l));
		}

		// Print colon
		colonprint(34);

		// Print seconds
		for (int m=6; m<8; m++){
			digitmake(timeArray[m-2], digitplace(m));
		}

		
		printf("\033[9;0H\n"); //Move cursor to another line

		sleep(1);
		fflush(stdout);
		printf("\033[0m");// Reset colors

	}
	return 0;
}

// This function changes the color of output
int digitcolor(char* input){
	int colorIndex;

	if (strcmp(input, "black") == 0){
		colorIndex = 0;
	}

	else if (strcmp(input, "red") == 0){
		colorIndex = 1;
	}

	else if (strcmp(input, "green") == 0){
		colorIndex = 2;
	}		
	
	else if (strcmp(input, "yellow") == 0){
		colorIndex = 3;
	}

	else if (strcmp(input, "blue") == 0){
		colorIndex = 4;
	}

	else if (strcmp(input, "magenta") == 0){
		colorIndex = 5;
	}

	else if (strcmp(input, "cyan") == 0){
		colorIndex = 6;
	}

	else if (strcmp(input, "white") == 0){
		colorIndex = 7;
	}
	else{
		colorIndex = 100;
	}


	return colorIndex;


}

// This functoin prints the digits
void digitprint(int (*array1)[6], int place){
	for (int row=0; row<5; row++){
		for (int column = 0; column<6; column++){

			printf("\033[%d;%dH",row + 2, column+place);// Move cursor to position

			if (array1[row][column] == 1){
				printf("\033[4%dm ", color); // Highlighting
				printf("\033[0m"); // Resetting

			}
			else if (array1[row][column] == 0){
				printf(" ");
			}
		}
	}
}

// This function finds the pixel array and prints it
void digitmake(char digit, int place){
	int pixel[5][6];

	if (digit == '0'){
		memcpy(pixel, pixel0, sizeof(pixel0));
	}
	else if (digit == '1'){
		memcpy(pixel, pixel1, sizeof(pixel1));
	}
	else if (digit == '2'){
		memcpy(pixel, pixel2, sizeof(pixel2));
	}
	else if (digit == '3'){
		memcpy(pixel, pixel3, sizeof(pixel3));
	}
	else if (digit == '4'){
		memcpy(pixel, pixel4, sizeof(pixel4));
	}
	else if (digit == '5'){
		memcpy(pixel, pixel5, sizeof(pixel5));
	}
	else if (digit == '6'){
		memcpy(pixel, pixel6, sizeof(pixel6));
	}
	else if (digit == '7'){
		memcpy(pixel, pixel7, sizeof(pixel7));
	}
	else if (digit == '8'){
		memcpy(pixel, pixel8, sizeof(pixel8));
	}
	else if (digit == '9'){
		memcpy(pixel, pixel9, sizeof(pixel9));
	}


	digitprint(pixel, place);
}

// This function gives the place to print digit
int digitplace(int clockPlace){
	int acPlace;

	if (clockPlace == 0){
		acPlace = 2;
	}
	else if (clockPlace == 1){
		acPlace = 9;
	}
	else if (clockPlace == 3){
		acPlace = 21;
	}
	else if (clockPlace == 4){
		acPlace = 28;
	}
	else if (clockPlace == 6){
		acPlace = 40;
	}
	else if (clockPlace == 7){
		acPlace = 47;
	}

	return acPlace;
}

// This function prints the colon
void colonprint(int place){
	for (int row=0; row<5; row++){
		for (int column = 0; column<6; column++){

			printf("\033[%d;%dH",row + 2, column+place);// Move cursor to position

			if (pixelcol[row][column] == 1){
				printf("\033[4%dm ", color); // Highlighting
				printf("\033[0m"); // Resetting

			}
			else if (pixelcol[row][column] == 0){
				printf(" ");
			}
		}
	}	
} 
