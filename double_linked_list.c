#include<stdio.h>  
#include<stdlib.h>
struct node   
{  
	struct node *prev; 
	int data;  
	struct node *next;   
}; 
struct node *head; 
struct node *create_node (int data)
{
	struct node *newnode;
	newnode=malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;
}
void insertion_beginning(struct node *ptr)
{
	if(head==NULL)
	{ 
		head=ptr; 
	} 
	else
	{  
		head->prev=ptr;
        ptr->next = head;
		head=ptr; 
	} 
	 printf("\nnode inserted\n"); 
} 
void insertion_last(struct node *ptr)
{
	struct node *temp;
	if(head == NULL)  
	{    
		head = ptr;  
	}  
	else  
	{  
		temp = head;  
		while(temp->next!=NULL)  
		{  
			temp = temp->next;  
		}  
		temp->next = ptr;  
		ptr ->prev=temp;    
	} 
	 printf("\nnode inserted\n"); 
} 
void insertion_specified(struct node *ptr)
{
	struct node *temp; 
	int loc,i;  
	temp=head;  
	printf("Enter the location");  
	scanf("%d",&loc);  
	for(i=1;i<loc-1;i++)  
	{  
		temp = temp->next;  
		if(temp == NULL)  
		{  
			printf("\n There are less than %d elements", loc);  
			return;  
		}  
	}  
	ptr->next = temp->next;  
	ptr -> prev = temp;  
	temp->next = ptr;  
	ptr->next->prev=ptr;  
	printf("\nnode inserted\n");  
} 
void deletion_beginning()
{
	struct node *ptr;  
	if(head == NULL)  
	{  
		printf("\n UNDERFLOW");  
	}  
	else if(head->next == NULL)  
	{  
		head = NULL;   
		free(head);  
		printf("\nnode deleted\n");  
	}  
	else  
	{  
		ptr = head;  
		head = head -> next;  
		head -> prev = NULL;  
		free(ptr);  
		printf("\nnode deleted\n");  
	}
} 
void deletion_last()
{
	struct node *ptr;  
	if(head == NULL)  
	{  
		printf("\n UNDERFLOW");  
	}  
	else if(head->next == NULL)  
	{  
		head = NULL;   
		free(head);   
		printf("\nnode deleted\n");  
	}  
	else   
	{  
		ptr = head;   
		while(ptr->next != NULL)  
		{  
			ptr = ptr -> next;   
		}  
		ptr -> prev -> next = NULL;   
		free(ptr);  
		printf("\nnode deleted\n");  
	}
} 
void deletion_specified()
{
	struct node *ptr;  
	int val;  
	printf("\n Enter the data to be deleted : ");  
	scanf("%d", &val);  
	ptr = head;  
	if(head == NULL)  
	{  
		printf("\n UNDERFLOW");  
	}
	else
	{
		while(ptr -> data != val)
		{  
			ptr = ptr -> next; 
		}
		if(ptr->data==val)
		{
            if(head==ptr)
            {
                deletion_beginning();
            }
            else if(ptr->next==NULL)
            {
               deletion_last(); 
            }
            else
            {
                ptr->prev->next = ptr -> next; 
                ptr -> next->prev = ptr -> prev;
                free(ptr);
            }
			printf("\nnode deleted\n"); 
		}
		else
			printf("\nCan't delete node! node not found\n"); 						
	}  
} 
void display()
{
	struct node *ptr;
	ptr = head;   
	if(ptr == NULL)  
	{  
		printf("\nEmpty List\n");  
	} 
	else
	{
		printf("\n printing values...\n");   
		while(ptr != NULL)  
		{  
			printf("%d\n",ptr->data);  
			ptr=ptr->next;  
		} 
	}
} 
void search()
{
	struct node *ptr;  
	int item,i=1,flag=0;  
	ptr = head;   
	if(ptr == NULL)  
	{  
		printf("\nEmpty List\n");  
	} 
	else  
	{
		printf("\nEnter item which you want to search?\n");   
		scanf("%d",&item); 
		while (ptr!=NULL)
		{
			if(ptr->data == item) 
			{
				flag=1;
				printf("\nitem found at location %d ",i);  
				break; 
			}
			i=i+1;
			ptr = ptr -> next; 
		}
		if(flag==0)  
		{  
			printf("\nItem not found\n");  
		} 
	}
} 
int main()
{
	int choice =0,item,pos;  
	while(choice != 9)   
	{
		 printf("\n\n*********Main Menu*********\n");  
	       printf("\nChoose one option from the following list ...\n");  
	       printf("\n===============================================\n"); 
		printf("\n 1.Traversal\n 2.Insertion\n 3.Deletion\n 4.Search\n 5.Exit\n  :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				display();
		     		break;
			case 2:
				printf("\nEnter the item which you want to insert :");  
            			scanf("%d",&item); 
				struct node *newnode;
				newnode=create_node(item);
				printf("\nChoose one option from the following list ...\n"); 
            			printf(" 1.At Front\n 2.At End\n 3.At Any Where\n");
				scanf("%d",&pos);
				switch(pos)
				{
					case 1:
						insertion_beginning(newnode);
		     				break;
		     			case 2:
						insertion_last(newnode);
		     				break;
		     			case 3:
						insertion_specified(newnode);
		     				break;
		     			default:
						printf("invalid choice");
				}
		     		break;
			case 3:
				printf("\nChoose one option from the following list ...\n"); 
            			printf(" 1.From Front\n 2.From End\n 3.From Any Where\n");
				scanf("%d",&pos);
				switch(pos)
				{
					case 1:
						deletion_beginning();
		     				break;
		     			case 2:
						deletion_last();
		     				break;
		     			case 3:
						deletion_specified();
		     				break;
		     			default:
						printf("invalid choice");
				}
		     		break;
			case 4:
				search();
				break;
			case 5:
        printf("Exiting...... ");
				return;
			default:
				printf("invalid choice");
		}
	}
  return(0);
}
