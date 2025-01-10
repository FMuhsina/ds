#include<stdio.h>
int size,rank[50];

void Make_Set(int x)
{
    rank[x] = -1;
}

int Find_Set(int x)
{
    if (rank[x] == 999)
    {
        printf("Element %d is not part of any set.\n", x);
        return -1;
    }

    int index = x;
    while (rank[index] >= 0)
        index = rank[index];

    return index;
}

void Weighted_Union(int x, int y)
{
    int index1 = Find_Set(x);
    int index2 = Find_Set(y);

    if (index1 ==-1 || index2 == -1)
    {
        printf("Union operation failed. One or both elements are not part of any set.\n");
        return;
    }

    if (index1 == index2)
    {
        printf("%d and %d belong to the same disjoint set. No need for union.\n", x, y);
    }
    else
    {
        if (rank[index1] <= rank[index2])
        {
            rank[index1] += rank[index2];
            rank[index2] = index1;
        }
        else
        {
            rank[index2] += rank[index1];
            rank[index1] = index2;
        }
    }
}

void Display_Set(int s)
{
    for (int i = 0; i < s; i++)
        printf("%d  ", rank[i]);
    printf("\n");
}

int main()
{
    int size, element, element1, element2, choice;

    printf("Enter the number of disjoint sets to be made: ");
    scanf("%d", &size);
    
    // Initialize the rank array
    for (int i = 0; i < size; i++)
        rank[i] = 999;

    do
    {
        printf("\n1. Make set\n2. Union\n3. Find set\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element to be made: ");
                scanf("%d", &element);
                if (element >= 0 && element < size)
                {
                    Make_Set(element);
                    printf("Current Disjoint sets: ");
                    Display_Set(size);
                }
                else
                {
                    printf("Invalid element. Please enter a value between 0 and %d.\n", size - 1);
                }
                break;

            case 2:
                printf("Enter the first element to be joined: ");
                scanf("%d", &element1);
                printf("Enter the second element to be joined: ");
                scanf("%d", &element2);
                if ((element1 >= 0 && element1 < size) && (element2 >= 0 && element2 < size))
                {
                    Weighted_Union(element1, element2);
                    printf("Current Disjoint sets: ");
                    Display_Set(size);
                }
                else
                {
                    printf("Invalid elements. Please enter values between 0 and %d.\n", size - 1);
                }
                break;

            case 3:
                printf("Enter the element to find its set: ");
                scanf("%d", &element);
                if (element >= 0 && element < size)
                {
                    int setRepresentative = Find_Set(element);
                    if (setRepresentative != -1)
                        printf("The set representative for element %d is: %d\n", element, setRepresentative);
                }
                else
                {
                    printf("Invalid element. Please enter a value between 0 and %d.\n", size - 1);
                }
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    while (choice != 4);

    return 0;
}

