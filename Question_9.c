#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main()

{
	FILE *text = fopen("./cpu_burst.txt", "r");
  	int burst_time[20],pro[20],wait_time[20],turn_around_time[20],i=0,j,n=5,total=0,pos,temp;
    float avg_waiting_time,avg_turn_around_time;
  	printf("\nReading------------------\n");
    while((getc(text))!=EOF){
		fscanf(text, "%d", &burst_time[i]);
        if(burst_time[i]>0){
        	pro[i]=i+1;
			i++;
		}         
	}
	n=i;
	for(i=0;i<n;i++)

	{
    	pos=i;
    	for(j=i+1;j<n;j++)
    	{
        	if(burst_time[j]<burst_time[pos])
            	pos=j;
    	}
    
    	temp=burst_time[i];
    	burst_time[i]=burst_time[pos];
    	burst_time[pos]=temp;
    	temp=pro[i];
    	pro[i]=pro[pos];
    	pro[pos]=temp;
	}
	wait_time[0]=0;            
	for(i=1;i<n;i++)
	{
    	wait_time[i]=0;
    	for(j=0;j<i;j++)
        wait_time[i]+=burst_time[j];
    	total+=wait_time[i];
	}
	avg_waiting_time=(float)total/n; 
	total=0;
	printf("\nResults:---------------------\n");
	printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
   	for(i=0;i<n;i++)
   	{
       turn_around_time[i]=burst_time[i]+wait_time[i];     
       total+=turn_around_time[i];
       printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",pro[i],burst_time[i],wait_time[i],turn_around_time[i]);
   	}
   	avg_turn_around_time=(float)total/n;    
   	printf("\n\nAverage Waiting Time=%f",avg_waiting_time);
   	printf("\nAverage Turnaround Time=%f\n",avg_turn_around_time);
   	fclose(text);
   	return 0;

}
