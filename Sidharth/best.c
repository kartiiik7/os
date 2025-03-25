#include <stdio.h>
#define max 25
int i,j,k=0,nb,nf,temp=0,lowest=999,flag=0;
void bestfit(int b[],int f[])
{
for(i=1;i<=nf;i++)
{
for(j=1;j<=nb;j++)
{
temp=b[j]-f[i];
if(temp>=0)
{
if(lowest>temp)
{
k=j;
lowest=temp;
}
}
}
if(lowest!=999)
printf("\nFile Size %d is put in %d partition\n",f[i],b[k]);
else
printf("\nFile Size %d must wait",f[i]);
b[k]=lowest;
lowest=999;
}
}
int main()
{
int b[max],f[max];
printf("\nMemory Management Scheme-Best Fit");
printf("\nEnter the number of blocks:");
scanf("%d",&nb);
printf("\nEnter the number of files:");
scanf("%d",&nf);
printf("\nEnter the size of the blocks:\n");
for(i=1;i<=nb;i++)
{
printf("Block %d:",i);
scanf("%d",&b[i]);
}
printf("Enter the size of the files:\n");
for(i=1;i<=nf;i++)
{
printf("File %d:",i);
scanf("%d",&f[i]);
}
bestfit(b,f);
return 0;
}

