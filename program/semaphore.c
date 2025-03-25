#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mutex=1,full=0,empty=3,x=0;
int signal(int s)
{
return (++s);
}
int wait(int s)
{
return (--s);
}
void producer()
{
empty=wait(empty);
mutex=wait(mutex);
x++;
printf("\n Producer Produces the item %d",x);
mutex=signal(mutex);
full=signal(full);
}
void consume()
{
full=wait(full);
mutex=wait(mutex);
printf("\n Consumer consumes the item %d",x);
x--;
mutex=signal(mutex);
empty=signal(empty);
}
void main()
{
int n;
while(1)
{
printf("\n1.Producer\n2.Consumer\n3.Exit\n");
printf("\nEnter your choice: \n");
scanf("%d",&n);
switch(n)
{
case 1:
if((mutex==1)&&(empty!=0))
producer();
else
printf("\nBuffer is Full\n");
break;
case 2:
if((mutex==1)&&(full!=0))
consume();
else
printf("\nBuffer is Empty\n");
break;
case 3:
exit(0);
break;
}
}
}
