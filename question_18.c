#include<stdio.h>
int n;
struct process
{

	int p_no;
	
	int arrival_time,burst_time,ct,wait_t,turn_around,p;
	
	int flag;
	 }p_list[100];
	 void Sorting()
	 {
	struct process p;
	
	int i, j;
	
	for(i=0;i<n-1;i++)
	
	{

	for(j=i+1;j<n;j++)
	
	{
	
	if(p_list[i].arrival_time > p_list[j].arrival_time)
	
	{
	
	p = p_list[i];
	
	p_list[i] = p_list[j];
	
	p_list[j] = p;
	
	}
	
	}
	
	}
}
int main()
	 {
	
	int i,t=0,b_t=0,peak;
	
	int a[10];
	
	float wait_time = 0, turn_around = 0, avg_w_t=0, avg_turn_around=0;
	
	printf("How many processes? : ");
	
	scanf("%d",&n);
	
	for(i = 0; i < n; i++)
	
	{
	
	p_list[i].p_no = i+1;
	
	printf("\nEnter Details For P%d process:-\n", p_list[i].p_no);
	printf("Arrival Time: ");
	scanf("%d", &p_list[i].arrival_time );
	printf("Burst Time: ");
	scanf("%d", &p_list[i].burst_time);
	p_list[i].flag = 0;
	b_t = b_t + p_list[i].burst_time;
	}
	Sorting();
	for(int i=0;i<n;i++)
	{
	a[i]=p_list[i].burst_time;
	}
	p_list[9].burst_time = 9999;
	for(t = p_list[0].arrival_time; t <= b_t+1;)
	{
	peak = 9;
	for(i=0;i<n;i++)
	{
	if(p_list[i].arrival_time <= t && p_list[i].burst_time < p_list[peak].burst_time && p_list[i].flag != 1)
	{
	peak = i;
	}
	if(p_list[peak].burst_time==0 && p_list[i].flag != 1)
	{
	p_list[i].flag = 1;
	p_list[peak].ct=t;p_list[peak].burst_time=9999;
	printf("P%d completing in %d\n",p_list[i].p_no,p_list[peak].ct);
	}
	}
	t++;
	(p_list[peak].burst_time)--;
	}
	for(i=0;i<n;i++)
	{
	p_list[i].turn_around=(p_list[i].ct)-(p_list[i].arrival_time);
	avg_turn_around=avg_turn_around+p_list[i].turn_around;
	p_list[i].wait_t=((p_list[i].turn_around)-a[i]);
	avg_w_t=avg_w_t+p_list[i].wait_t;
	}
	printf("PNO\tAT\tCT\tTA\tWTt\n");
	for(i=0;i<n;i++)
	{
	printf("P%d\t%d\t%d\t%d\t%d\n",p_list[i].p_no,p_list[i].arrival_time,p_list[i].ct,p_list[i].turn_around
	,p_list[i].wait_t);
	 }
	printf("Avg Turn around Time: %f\t\n\n",avg_turn_around);
	printf("Avg Waiting Time :\t %f\t\n",avg_w_t);
}
