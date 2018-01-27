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
int NumberOfDigits(int num)
{
    int count=0;
    while(round(num)!=0)
    {
        count++;
        num=num%10;
    }
    return count;
}

int* getIntegerPart(double num){
    int i;
    int a[NumberOfDigits(round(num))];
    double rem;
    for(i=0;i<NumberOfDigits(round(num));i++)
    {
        rem=(int)(num) % 10;
        num=num/10;
        a[NumberOfDigits(round(num))-i]=(int)rem;
    }
    return a; 
}
int* getFractionalPart(double num){
    int frac = num -(int)num;
    int b[3];
    int i=0;
    double num1;
    while(num!=(int)num)
    {
        num1=num*10;
        b[i]=round(num);
        i++;
    }
    return b;
    
    
}

int main()
{
    float num;
    int i=0;
    int count=0;
    scanf("%f",&num);
    
    int IntegerPart=(int)num;
    
    float FractionalPart=num-IntegerPart;
    int loc=DecimalPlaces(num);
    int *left,*right;
    left=getFractionalPart(num);
    right=getIntegerPart(num);
    
  // printf("In the given fractional number,the integer part is %d and the fractional part is %.3f \n\n The decimal is present at location %d ",IntegerPart,FractionalPart,loc);
   printf("The digits separated out:\n");
    for(i=0;i<sizeof(getIntegerPart(num))/sizeof(int) - 1;i++){
   printf("%d\t",*(left+sizeof(int)*i));
   }
   for(i=0;i<sizeof(getFractionalPart(num))/sizeof(int) - 1;i++){
   printf("%d\t",*(right+sizeof(int)*i));
   }
  
    
}

