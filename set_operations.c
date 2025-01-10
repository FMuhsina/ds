#include <stdio.h>

#define MAX_UNIVERSAL_SIZE 100 // Define a reasonable maximum universal set size

int MAX_SIZE;
char universalSet[MAX_UNIVERSAL_SIZE];

void bitVector(char set[], int size, int bitString[]) 
{
    for (int i = 0; i < MAX_SIZE; i++) 
        bitString[i] = 0; 
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < MAX_SIZE; j++) 
        {
            if (set[i] == universalSet[j]) 
                bitString[j] = 1;
        }
    }
}
void setComplementArray(int set[],int result[])
{
   for (int i = 0; i < MAX_SIZE; i++) 
   {
       if(set[i]==0)
           result[i] = 1;
       else
           result[i] = 0;
   } 
}

void displaySetArray(int set[]) 
{
    printf("\nSet Representation : {");
    int first = 1;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (set[i] == 1)
        {
            if (!first)
                printf(", ");
            printf("%c", universalSet[i]);
            first = 0;
        }
    }
    printf("}\n");
    printf("Bitvector Representation : ");
    for (int i = 0; i < MAX_SIZE; i++)
    {
        printf("%d", set[i]);
    }
}

// Function to perform Union operation on bit vector arrays
void setUnionArray(int setA[], int setB[], int result[]) 
{
    for (int i = 0; i < MAX_SIZE; i++) 
    {
        result[i] = setA[i] | setB[i];
    }
}

// Function to perform Intersection operation on bit vector arrays
void setIntersectionArray(int setA[], int setB[], int result[]) 
{
    for (int i = 0; i < MAX_SIZE; i++) 
    {
        result[i] = setA[i] & setB[i];
    }
}

// Function to perform Difference operation (setA - setB) on bit vector arrays
void setDifferenceArray(int setA[], int setB[], int result[]) 
{
    for (int i = 0; i < MAX_SIZE; i++) 
    {
        result[i] = setA[i] & (~setB[i]);
    }
}

int main() 
{
    char set1[MAX_UNIVERSAL_SIZE], set2[MAX_UNIVERSAL_SIZE];
    int s1, s2;
    int choice, sd;
    int bitSetA[MAX_UNIVERSAL_SIZE], bitSetB[MAX_UNIVERSAL_SIZE], result[MAX_UNIVERSAL_SIZE];

    printf("Enter number of elements in the universal set: ");
    scanf("%d", &MAX_SIZE);
    if (MAX_SIZE > MAX_UNIVERSAL_SIZE) {
        printf("Error: Maximum universal set size exceeded.\n");
        return 1;
    }

    printf("Enter elements of the universal set: ");
    for (int i = 0; i < MAX_SIZE; i++) 
        scanf(" %c", &universalSet[i]);

    // Input for Set 1
    printf("Enter number of elements in the first set: ");
    scanf("%d", &s1);
    printf("Enter elements of the first set: ");
    for (int i = 0; i < s1; i++) 
        scanf(" %c", &set1[i]);

    // Input for Set 2
    printf("Enter number of elements in the second set: ");
    scanf("%d", &s2);
    printf("Enter elements of the second set: ");
    for (int i = 0; i < s2; i++) 
        scanf(" %c", &set2[i]);

    // Convert sets to bit vectors
    bitVector(set1, s1, bitSetA);
    bitVector(set2, s2, bitSetB);

    // Display the sets
    printf("\nSet 1: ");
    displaySetArray(bitSetA);
    printf("\nSet 2: ");
    displaySetArray(bitSetB);

    // Menu for set operations
    do 
    {
        printf("\n1. Union\n2. Intersection\n3. complement\n4. Set Difference\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                setUnionArray(bitSetA, bitSetB, result);
                printf("\nUnion: ");
                displaySetArray(result);
                break;

            case 2:
                setIntersectionArray(bitSetA, bitSetB, result);
                printf("\nIntersection: ");
                displaySetArray(result);
                break;
                
            case 3:
                printf("\ncomplement of set 1: ");
                setComplementArray(bitSetA,result);
                displaySetArray(result);
                printf("\ncomplement of set 2: ");
                setComplementArray(bitSetB,result);
                displaySetArray(result);
                break;

            case 4:
                do
                {
                    printf("\n1. Set 1 - Set 2\n2. Set 2 - Set 1\n3. Exit\nEnter your choice: ");
                    scanf("%d", &sd);
                    switch (sd)
                    {
                        case 1:
                            setDifferenceArray(bitSetA, bitSetB, result);
                            printf("\nDifference (Set 1 - Set 2): ");
                            displaySetArray(result);
                            break;
                        case 2:
                            setDifferenceArray(bitSetB, bitSetA, result);
                            printf("\nDifference (Set 2 - Set 1): ");
                            displaySetArray(result);
                            break;
                         case 3:
                            printf("Exiting program.\n");
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                }
                while (sd != 3);
                break;
                
            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } 
    while (choice != 5);

    return 0;
}

