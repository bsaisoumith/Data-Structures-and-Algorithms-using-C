#include<stdio.h>
int main()
{
  // insertion 
  int a[50],size,i,num,pos;
  printf("enter the size");
  scanf("%d",&size);
  printf("enter the elements of array");
  for(i=0;i<size;i++)
  {
    scanf("%d",&a[i]);
  }
  num=10;
  pos=3;
  if(pos<=0 || pos>size+1)
  {
    printf("invalid");
  }
  else
  {
    for(i=size-1;i>=pos;i--)
   {
     a[i+1]=a[i];
   }
  }
  a[pos-1]=num;
  size++;

  // deletion

  pos=2;
  if(pos<=0 || pos>size)
  {
    printf("invalid");
  }
  else
  {
    for(i=pos-1;i<size-1;i++)
    {
      a[i]=a[i+1];
    }
  }
  size--;

  return 0;
}