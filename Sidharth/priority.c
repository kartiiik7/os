#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Process
{
 int id,at,bt,ct,tat,wt,rt,pt;
};
int findshortest(struct Process p[],int n,int currentTime)
{
 int index=-1,pt=INT_MAX;
 for(int i=0;i<n;i++)
 {
  if(p[i].at<=currentTime&&p[i].rt!=0)
  {
   if(p[i].pt<pt)
   {
    pt=p[i].pt;
    index=i;
   }
  }
 }
 return index;
}
void Srtf(struct Process p[],int n)
{
int completed=0,currentTime=0;
float tot_tat=0,tot_wt=0;
while(completed<n)
{
int ind=findshortest(p,n,currentTime);
if(ind==-1)
{
currentTime++;
}
else{
p[ind].rt--;
currentTime++;
if(p[ind].rt==0)
{
completed++;
p[ind].ct=currentTime;
p[ind].tat=p[ind].ct-p[ind].at;
p[ind].wt=p[ind].tat-p[ind].bt;
tot_tat+=p[ind].tat;
tot_wt+=p[ind].wt;
}
}
}
printf("PID\tAT\tBT\tCT\tTAT\tWT\tPT\n");
for(int i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].pt);
}
printf("Average TAT=%f\n",tot_tat/n);
printf("Average WT=%f\n",tot_wt/n);
}
void main()
{
int n;
printf("Enter the number of process:");
scanf("%d",&n);
struct Process p[n];
printf("Enter the Arrival time(AT) and Burst Time(BT) and Priority(P) \n");
for(int i=0;i<n;i++)
{
p[i].id=i+1;
printf("P%d(AT,BT,P):",p[i].id);
scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].pt);
p[i].rt=p[i].bt;
}
Srtf(p,n);
}


