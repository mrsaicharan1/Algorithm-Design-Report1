#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int DecimalPlaces(float num){
    int count=0;
    while(round(num)!=0)
    {
        count++;
        num=num/10;
      
    }
    return count;
}
int main()
{
   float num,value;
    int count=0;
    int i;
    int a[100],b[100],asize=0,bsize=0;
    scanf("%f",&num);
    
    int IntegerPart=floor(num);
    
    float FractionalPart=num-IntegerPart;
    int loc=DecimalPlaces(num);
    
  
   
   for(i=0;IntegerPart!=0;i++)
   {
       
       
       value = IntegerPart%10;
       
       a[i]=value;
       
       asize++;
       IntegerPart=floor(IntegerPart/10);
   }
   for(i=0;(int)FractionalPart!=FractionalPart;i++)
   {
       FractionalPart=FractionalPart*10;
       value=floor(FractionalPart);
   
       b[i]=value;
       bsize++;
       FractionalPart=FractionalPart-floor(FractionalPart);
       
   }
   printf("The separated digits are:\n");
   for(i=0;i<asize;i++)
   {
       printf("%d ",a[asize-i-1]);
   }
   for(i=0;i<bsize;i++)
   {
       printf("%d ",b[i]);
   }
   
   printf("\nDecimal location at %d",loc);
    
}
