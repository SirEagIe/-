#include <stdio.h>
int main()
{
	short hour1, min1, sec1, hour2, min2, sec2, hour, min, sec;
	printf("Enter the start time of the interval (hour min sec)\n");
	scanf("%hi%hi%hi", &hour1, &min1, &sec1);
	printf("Enter the end time of the interval (hour min sec)\n");
	scanf("%hi%hi%hi", &hour2, &min2, &sec2);
	long sum_sec = (hour2-hour1)*3600+(min2-min1)*60+sec2-sec1;
	hour = sum_sec/3600;
	min = (sum_sec-hour*3600)/60;
	sec = sum_sec-hour*3600-min*60;
	printf("Interval duration from %hi:%hi:%hi to %hi:%hi:%hi is %hi:%hi:%hi", hour1, min1, sec1, hour2, min2, sec2, hour, min, sec);
	return 0;
}