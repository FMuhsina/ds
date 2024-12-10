#include<stdio.h>
char set1[26],set2[26],u={a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};
int s1,s2; 
char bit_vector(set)
{
	
}
void Union(set1,set2)
int main()
{ 	
	int choice,n=1;
	printf("Enter number of elements of First set : ");
	scanf("%d",&s1);
	printf("Enter First set : ");
	for(i=0;i<s1;i++)
		scanf("%c",&set1[i]);
	printf("Enter number of elements of second set : ");
	scanf("%d",&s2);
	printf("Enter second set : ");
	for(i=0;i<s2;i++)
		scanf("%c",&set2[i]);
	do
	{
		printf("\n 1.Union\n 2.Intersection\n 3.Complement\n 4.Set Difference\n 5.Exit\n Enter your 	choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				Union();
		     		break;
			case 2:
				Intersection();
		     		break;
			case 3:
				Complement();
		     		break;
		     	case 4:
				Set_Difference();
		     		break;
			case 5:
				return 0;
			default:
				printf("invalid choice");
		}
	}
	while(n==1);
	return 0;	
	
}
