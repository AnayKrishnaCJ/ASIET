#include<stdio.h>
#include<string.h>
void main()
{
	int n,pr[100],bt[100],wt[100],tt[100];
	float avg_tt,avg_wt;
	int pid[100];
	printf("Enter the Enter no.of process:\n");
	scanf("%d", &n);
	printf("Enter the pid, priority and burst time for each\n");
	for(int i=0;i<n;i++)
	{
		printf("pid, priority and burst time of process %d:\n", i);
		scanf("%d\n",&pid[i]);
		scanf("%d\n",&pr[i]);
		scanf("%d",&bt[i]);
	}
	for(int i =1;i<=n;i++)
	{
		for(int j=0;j<n-i;j++){
			if(bt[j]>bt[j+1])
			{
				int temp;
				temp=pid[j];
				pid[j]=pid[j+1];
				pid[j+1]=temp;
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				temp=pr[j];
				pr[j]=pr[j+1];
				pr[j+1]=temp;
				
			}
		}
	}
	for(int i =1;i<=n;i++)
	{
		for(int j=0;j<n-i;j++){
			if(pr[j]>pr[j+1])
			{
				int temp;
				temp=pid[j];
				pid[j]=pid[j+1];
				pid[j+1]=temp;
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				temp=pr[j];
				pr[j]=pr[j+1];
				pr[j+1]=temp;
				
			}
		}
	}
	wt[0]=0;
	for(int i=1; i<=n;i++){
		wt[i]=bt[i-1]+wt[i-1];
		
	}
	avg_wt=0;
	for(int i=0; i<n;i++){
		avg_wt=avg_wt+wt[i];
	}
	avg_wt=avg_wt/n;
	avg_tt=0;
	for(int i=0; i<n;i++){
		tt[i]=wt[i]+bt[i];
	}
	for(int i=0; i<n;i++){
		avg_tt=tt[i]+avg_tt;
	}
	avg_tt=avg_tt/n;
	printf("\nAverage wait time=\t%f", avg_wt);
	printf("\nAverage turn around time=\t%f\n", avg_tt);
	printf("|_______________________________________________________________________________________________________________________________|\n");
	printf("|	pid	|	burst time	|	priority		|	turn around time	|	wait time	|\n");
	printf("|_______________|_______________________|_______________________________|_______________________________|_______________________|\n");
	for(int i=0;i<n;i++)
	{
		printf("|_______________|_______________________|_______________________________|_______________________________|_______________________|\n");
		printf("|	p%d	|	    %d    	|	      %d      		|	        %d        	|	    %d   	|\n", pid[i],bt[i],pr[i],tt[i],wt[i]);
		printf("|_______________|_______________________|_______________________________|_______________________________|_______________________|\n");
	}
	printf("\n");
	printf("GANT CHART\n");
	for(int i=0;i<n;i++)
		printf("____________");
	printf("\n");
	for(int i=0;i<n;i++)
	{
		printf("|    P%d    |", pid[i]);
		
	}
	printf("\n");
	for(int i=0;i<n;i++)
		printf("____________");
	printf("\n");
	for(int i=0;i<n;i++)
		printf("___________%d", wt[i]);
}
