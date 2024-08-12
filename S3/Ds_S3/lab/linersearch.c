#include<stdio.h>
int main()
{
int a[10],search,i,found=0,num;
printf("enter the no of elements");
scanf("%d",&num);
printf("enter the elements in array");
for(i=0;i<num;i++)
{
scanf("%d",&a[i]);
}
printf("enter the elements to search");
scanf("%d",&search);
for(i=0;i<num;i++)
{
if(a[i]==search)
{
found=1;
break;
}
}
if(found)
{
printf("the element was found at position %d\n",i+1);
}
else
{
printf("the element was not found \n");
}
return 0;
}
