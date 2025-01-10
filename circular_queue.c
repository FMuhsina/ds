#include<stdio.h>
int front=-1,rear=-1,queue[100],size;
void enqueue()
{ 
    int val;
    if((front==0&&rear==size-1)||(front==rear+1))
        printf("\nQueue is full.\n");
    else
    {
        printf("\nEnter the value to be inserted :");  
        scanf("%d",&val); 
        if(front==-1)
        {
            front=0;
            rear++;
            queue[rear]=val;
         }
         else if(rear==size-1)
         {
            rear=0;
            queue[rear]=val;
         }
        else
        {
            rear++;
            queue[rear]=val;
        }
    }
}
void dequeue()
{ 
    if(front==-1)
        printf("\nQueue is empty.\n");
    else
    { 
        if(front==rear)
        {
            printf("Deleted Element is %d.\n",queue[front]);
            front=-1;
            rear=-1;
         }
         else if(front==size-1)
         { 
            printf("Deleted Element is %d.\n",queue[front]);
            front=rear;
         }
        else
        {
            printf("Deleted Element is %d.\n",queue[front]);
            front++;
        }
    }
}
void traversal()  
{  
    int i; 
    if(front == -1)   
    {  
        printf("\nQueue is empty\n");  
    } 
    else
    { 
        if(rear>=front)
        {
            printf("\nElements in Queue :");
            for (i=front;i<=rear;i++)   
                printf(" %d\n",queue[i]);  
        }
        else
        {
            printf("\nElements in Queue :\n");
            for (i=front;i<=size-1;i++)   
                printf(" %d\n",queue[i]); 
            for (i=0;i<=rear;i++)   
                printf(" %d\n",queue[i]); 
        }
    } 
}  
int main()
{ 	
    int choice,n=1;
    printf("Enter the size of Queue :");
    scanf("%d",&size);
    do
    {
        printf(" 1.Traversal\n 2.ENQUEUE\n 3.DEQUEUE\n 4.Exit\n Enter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                traversal();
                    break;
            case 2:
                enqueue();
                    break;
            case 3:
                dequeue();
                    break;
            case 4:
                return 0;
            default:
                printf("invalid choice");
        }
    }
    while(n==1);
    return 0;	

}
