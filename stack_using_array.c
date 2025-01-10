#include<stdio.h>
int stack[100],size,top=-1;  
void push ()  
{  
    int val;      
    if (top == size-1 )   
        printf("\n Overflow\n");   
    else   
    {  
    printf("Enter the value :");  
    scanf("%d",&val);         
    top = top +1;   
    stack[top] = val;   
    }   
}   

void pop ()   
{   
    if(top == -1)   
        printf("\nUnderflow\n");  
    else
    {
        printf("The popped element is %d",stack[top]);
        top = top -1;           
    }
}   
void traversal()  
{  
    int i;
    if(top == -1)    
        printf("\nStack is empty\n");
    else
    {
        printf("Stack elements are :");
        for (i=top;i>=0;i--)   
            printf("%d  ",stack[i]);
    }
}  
int main()
{ 	
    int choice,n=1;
    printf("Enter the size of stack :");
    scanf("%d",&size);
    do
    {
        printf("\n 1.Traversal\n 2.Push\n 3.Pop\n 4.Exit\n Enter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                traversal();
                    break;
            case 2:
                push();
                    break;
            case 3:
                pop();
                    break;
            case 4:
                return 0;
            default:
                printf("Invalid choice");
        }
    }
    while(n==1);
    return 0;	

}