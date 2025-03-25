#include <stdio.h>
struct Process{
int id,at,bt,ct,tat,wt;
};
void main()
{
int n;
float tot_tat=0,tot_wt=0;
float avg_tat,avg_wt;
printf("Enter the no.of process:");
scanf("%d",&n);
struct Process p[n],temp;
printf("Enter the Arrival time and Burst time of the process:");
for (int i=0;i<n;i++)
{
p[i].id=i+1;
printf("P%d(AT,BT):",i+1);
scanf("%d%d",&p[i].at,&p[i].bt);
}
for(int i=0;i<n-1;i++)
{
for(int j=0;j<n-i-1;j++)
{
if(p[j].at>p[j+1].at)
{
temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;
}
}
}
p[0].ct=p[0].at+p[0].bt;
p[0].tat=p[0].ct-p[0].at;
p[0].wt=p[0].tat-p[0].bt;
tot_tat=p[0].tat;
tot_wt=p[0].wt;
for(int i=1;i<n;i++)
{
if(p[i].at>p[i-1].ct)
{
p[i].ct=p[i].at+p[i].bt;
}
else{
p[i].ct=p[i-1].ct+p[i].bt;
}
p[i].tat=p[i].ct-p[i].at;
p[i].wt=p[i].tat-p[i].bt;
tot_tat=tot_tat+p[i].tat;
tot_wt=tot_wt+p[i].wt;
}
avg_tat=tot_tat/n;
avg_wt=tot_wt/n;
printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
for(int i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
}
printf("Average TAT=%f\nAverage WT=%f",avg_tat,avg_wt);
}


