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
    float num;
    int count=0;
    scanf("%f",&num);
    
    int IntegerPart=(int)num;
    
    float FractionalPart=num-IntegerPart;
    int loc=DecimalPlaces(num);
    
   printf("In the given fractional number,the integer part is %d and the fractional part is %f \n\n The decimal is present at location %d ",IntegerPart,FractionalPart,loc);
   
   
    
}

