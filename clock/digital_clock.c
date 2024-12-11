#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#define True	1

void time_count_clock(void);
void menu(void);
void digital_clock_display(void);

int main(void) {  /* CPU --> Program count execute main */
	int n, ex;

	system("clear");

	menu();

	printf("\n\nEnter Choose [0 - 2] : ");
	scanf("%d", &n);

	if (n == 1 || n == 0 || n == 2) {
		printf("found\n");
	}
	else {
		printf("Incorrect input\n");
		exit(EXIT_FAILURE);
	}
	

	switch (n) {
		case 0 : exit(EXIT_SUCCESS);

		case 1 : time_count_clock();
			 if (ex == EOF)
				 exit(EXIT_SUCCESS);

		case 2 : digital_clock_display();
			 break;
		
		default :exit(EXIT_FAILURE);
	}


	return 0;
}

void time_count_clock(void) {
	int sec, min, hr;

	sec = min = hr = 0;

	while(True) {    /*  00 : 00 : 00 */
		system("clear");

		printf("\t\t%02d : %02d : %02d\n", hr, min, sec);
		fflush(stdout);
		
		sec++;
		if (sec == 60) {
			min += 1; /* min = min + 1 */
			sec = 0;
		}

		if (min == 60) {
			hr += 1; /* hr = hr = 1 */
			min = 0;
		}
		
		if (hr == 24) {
			hr = 0;
			min = 0; 
			sec = 0;
		}

		sleep(1);
	}
}

void menu(void) {
	printf("*******************************\n");
	printf("*******************************\n");
	printf("******        MENU       ******\n");
	printf("******                   ******\n");
	printf("****** 1   CLOCK COUNT   ******\n");
	printf("******                   ******\n");
	printf("****** 2  DIGITAL CLOCK  ******\n");
	printf("******                   ******\n");
	printf("****** 0       EXIT      ******\n");
	printf("*******************************\n");
	printf("*******************************\n");
}

void digital_clock_display(void) {
	int sec, min, hr;
	time_t s;
	struct tm* current_time;

	s = time(NULL);

	current_time = localtime(&s);

	sec = current_time -> tm_sec;
	min = current_time -> tm_min;
	hr = current_time -> tm_hour;

	printf("\t\t%02d : %02d : %02d\n", hr, min, sec);

}
