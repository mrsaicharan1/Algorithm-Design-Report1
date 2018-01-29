#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int digit;
    struct node *next;
} *start=NULL;

struct node* addstart();
struct node* addend();
void display();

int main()
{
    int intpart,dig,count;
    float given,x,decpart;
    scanf("%f",&given);
    intpart=(int) given;
    decpart=given-intpart;
    count=0;
    while(1)
    {
        dig=intpart%10;
        if(dig>0)
            start=addstart(dig);
        else
            start=addstart(-1*dig);
        count++;
        intpart=intpart/10;
        if(intpart==0)
            break;
    }
    while(1)
    {
        given=given*10;
        dig=((int)given)%10;
        if(dig>0)
            start=addend(dig);
        else
            start=addend(-1*dig);
        if(given-(int)given == 0)
            break;
    }
    display();
    printf("Point is %d from the beginning\n",count);

}
struct node* addstart(int k)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->digit=k;
    temp->next=start;
    start=temp;
    return start;
}
struct node* addend(int k)
{
    struct node *ptr,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->digit=k;
    temp->next=NULL;
    ptr=start;
    if(ptr==NULL)
    {
        start=temp;
        return start;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        return start;
    }
}
void display()
{
    struct node *ptr;
    ptr=start;
    while(ptr->next!=NULL)
    {
        printf("%d ",ptr->digit);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->digit);
    return;
}

