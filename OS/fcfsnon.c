#include<stdio.h>
void main()
{
 int i,n,p[20],at[20],bt[20],wt[20],ct[20],tt[20];
 float avrg_wt=0,avrg_tt=0;
 printf("Enter the no of processes:");
 scanf("%d",&n);
 
 printf("burst time for each process:\n");
 for(i=0;i<n;i++)
 {
   p[i]=i+1;
   printf("p%d:",i+1);
   scanf("%d",&bt[i]);
 }
 wt[0]=0;
 for(i=1;i<n;i++)
 {
  wt[i]=wt[i-1]+bt[i-1];
  avrg_wt += wt[i];
 }
 avrg_wt/=n;
 for(i=0;i<n;i++)
 {
  tt[i]=wt[i]+bt[i];
  avrg_tt += tt[i];
 }
 avrg_tt/=n;
 printf("\nprocess\tburst time\twaiting time\tturnaround\n");
 for(i=0;i<n;i++)
 {
   printf("%d\t\t%d\t\t%d\t\t%d\t\t\n",p[i],bt[i],wt[i],tt[i]);
  }
  printf("\naverage waiting time:%.2f",avrg_wt);
  printf("\naverage turnaround time:%.2f\n",avrg_tt);
 
  printf("GANT CHART\n");
  for(i=0;i<n;i++)
  {
    printf("-------------");
  }
  printf("\n");
  for(i=0;i<n;i++)
  {
    printf("|    p%d    |",p[i]);
  }
  printf("\n");
  for(i=0;i<n;i++)
  {
    printf("-------------");
  }
  printf("\n");
   for(i=0;i<n;i++)
  {
    printf("           %d",wt[i]);
   }
   printf("\n");
  
}
  
 
 
