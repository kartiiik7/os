#include <stdio.h>
int main()
{
int reference [50],frame[50],fsize,i,j,flag=0,c=0,n,fault=0,k,recent[50],temp,flag1=0;
float miss,hit;
printf("Enter the number of references:");
scanf("%d",&n);
printf("Enter the references:");
for(i=0;i<n;i++)
scanf("%d",&reference[i]);
printf("Enter the frame size:");
scanf("%d",&fsize);
for(i=0;i<fsize;i++)
{
fault++;
frame[i]=reference[i];
recent[i]=reference[i];
c++;
}
recent[c]=0;
for(i=fsize;i<n;i++)
{
for(k=0;k<c;k++)
{
if(reference[i]==recent[k])
{
flag1=1;
break;
}
}
if(flag1==1)
{
temp=recent[k];
for(j=k;j<c;j++)
recent[j]=recent[j+1];
recent[c-1]=temp;
}
else
{
recent[c]=reference[i];
c++;
recent[c]=0;
}
flag1=0;
for(j=0;j<fsize;j++)
{
if(frame[j]==reference[i])
flag=1;
}
if(flag!=1)
{
fault++;
for(k=0;k<c;k++)
{
for(j=0;j<fsize;j++)
{
if(recent[k]==frame[j])
{
frame[j]=reference[i];
goto end;
}
}
}
}
end:
flag=0;
}
printf("Total number of fault=%d\n",fault);
miss=((float)fault/n)*100;
hit=((float)(n-fault)/n)*100;
printf("Total number of references = %d\n",n);
printf("Miss ratio=%.2f\n",miss);
printf("No.of Hits=%d\n",(n-fault));
printf("Hit ratio=%.2f\n",hit);
return 0;
}
