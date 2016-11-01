#include <stdio.h>

void swap(int *a, int *b)
{
        *a = *a + *b;
        *b = *a - *b;
        *a = *a - *b;
}

void insertionSort(int n, int A[])
{
    for(int i=0;i<n;i++)
    {
            for(int j=i;j>0;j--)
            {
                    if(A[j]<A[j-1])
                        swap(&A[j],&A[j-1]);
            }
           
            printf("\nIteration number %d : ",i+1);
             for(int k=0;k<n;k++)
                {
                    printf("%d",A[k]);
                }
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in array : ");
	scanf("%d",&n);
    int A[n];
    printf("\nEnter an int array of %d numbers:",n);
    
    for(int i=0;i<n;i++)
    {
            scanf("%d",&A[i]);
    }

    insertionSort(n,A);
   
    printf("\nSorted array is:\n");
    for(int i=0;i<n;i++)
    {
            printf("%d",A[i]);
    }
    
    return 0;
}
