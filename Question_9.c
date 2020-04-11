#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main()

{
	FILE *text = fopen("./cpu_burst.txt", "r");
  	int burst_time[20],pro[20],wait_time[20],turn_ard_time[20],i=0,j,n=5,total=0,pos,temp;
    float avg_wait_time,avg_turn_ard_time;
  	printf("\nReading the File\n");
    while((getc(text))!=EOF){
		fscanf(text, "%d", &burst_time[i]);
        if(burst_time[i]>0){
        	pro[i]=i+1;
			i++;
		}         
	}
