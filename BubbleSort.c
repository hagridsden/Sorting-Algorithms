#include <stdio.h>

void swap(int *a,int *b)
{
        *a=*a+*b;
        *b=*a-*b;
        *a=*a-*b;
 }
void bubbleSort(int n, int A[])
{
        int swapped;
    
        for(int i=0;i<n-1;i++)
        {
            swapped=0;
            for(int j=0;j<n-i;j++)  //sorting from front
            {
                  if(A[j]>A[j+1])
                   {
                        swap(&A[j],&A[j+1]);
                        swapped = 1;
                    }   
            }
            
            printf("\nIteration number %d : ",i+1);
            for(int k=0;k<n;k++)
                {
                    printf("%d",A[k]);
                }
             
            if(swapped == 0)
                {  
                    printf("\nBreaking as no number was swapped!");
                    break;
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

    
    bubbleSort(n,A);
   
    printf("\nSorted array is:\n");
    for(int i=0;i<n;i++)
    {
            printf("%d",A[i]);
    }
    
}