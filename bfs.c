#include <stdio.h>
#include <stdlib.h> 
int adj[10][10],count_v,s=-1,front=-1,rear=-1,queue[100];
void enqueue(int val)
{  
    if(front==-1)
    {
        front=0;
        rear++;
        queue[rear]=val;
     }
     else
     {
        rear++;
        queue[rear]=val;
     }
}
int dequeue()
{  
    int v;
    if(front==rear)
    {
        v=queue[front];
        front=-1;
        rear=-1;
        return(v);
     }
     else
     { 
        v=queue[front];
        front++;
        return(v);
     }
}
void BFS() 
{
    int visit[count_v],i,j,flag,vertex;
    for(i=0;i<count_v;i++)
    {
        visit[i]=0;
    }
    while((s<0)||(s>count_v))
    {
        printf("Enter a source vertex :");
        scanf("%d",&s);
    }
    enqueue(s);
    while(front!=-1)
    {
        vertex=dequeue();                                 //dequeue a vertex from queue
        if(visit[vertex]==0)                              //visit
        {
            printf("%d  ",vertex);
            visit[vertex]=1;
            for(i=0;i<count_v;i++)                    //explore
            {
                if(adj[vertex][i]==1)
                {
                        enqueue(i);
                }
            }

        }
    }
}
int main() 
{
    printf("Enter the no .of vertices of graph :");
    scanf("%d",&count_v);
    printf("Enter the %d X %d Adjacency matrix :",count_v,count_v);
    for(int i=0;i<count_v;i++)
    {
        for(int j=0;j<count_v;j++)
        {
            printf("\nEnter '1' if tere is an edge from %d to %d otherwise enter '0' :",i,j);
            scanf("%d",&adj[i][j]);
        }
            
    }
    for(int i=0;i<count_v;i++)
    {
        for(int j=0;j<count_v;j++)
            printf("%d  ",adj[i][j]);
        printf("\n");   
    }
	BFS();

    return 0;
}
