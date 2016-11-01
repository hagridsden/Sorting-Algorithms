#include <stdio.h>
#include <stdlib.h>

#define Trial 100 


void show(int a[], int n)
{ int i;
  for (i=0; i<n; i++)
    printf("%3d: %d\n", i, a[i]);
}

void countingSort(int A[],int size, int max,int *copy, int *comparison )    //assumption numbers are between 0 and k (max)
{
    int B[max+1],i, j;
    
    for(i = 0; i <= max; i++)   //initializing to 0
    {
        (*comparison)++;
            B[i]=0;
            *copy += 1;
    }
    
    for(i = 0; i < size; i++)      // counting occurance of each digit in array
    {
        (*comparison)++;
            B[A[i]]++;
    }
    
    for(i = 1; i < size; i++)
    {
        (*comparison)++;
            B[i] += B[i-1];
             *copy += 1;
    }
    
    for(i = 0, j=0; j<size ; i++)   //sorted array
    {
       while(j < B[i])
        {
            (*comparison)++;
            A[j++] = i ;
             *copy += 1;
        }
    }
   
}


int main(int argc, char *argv[])
{ int *a, seed;			// pointer to the random array
  int size, min = 0, max = 99;	// default range of random values
  int copy = 0, comparison = 0;	// number of copies and comparisons for sorting
  float Tcopy = 0, Tcomp = 0;	
  int i;

  if (argc != 2 && argc != 4)
  { printf("Usage: \nGenerate k random numbers between 0 and 99:\t a.out k\nGenerate k random numbers between a and b:\t a.out k a b\n");
    exit(0);
  } 

  size = atoi (argv[1]);
  if (size <= 0)
  { printf("Cannot generate %d random numbers.\n", size);
    exit(0);
  }

  if (argc == 4)
  { min = atoi (argv[2]);
    max = atoi (argv[3]);
    if (min >= max)
    { printf("invalid range [%d, %d]\n", min, max);
      exit(0);
    }
  }
  
  a = (int *) malloc (size*sizeof(int));
  if (a == NULL)
  { printf("Not enough memory for %d random numbers.\n", size);
    exit(0);
  }

for (seed = 1; seed <=Trial; seed++)
{ srand(seed);

  for (i=0; i<size; i++)
    a[i] = rand()%(max-min+1) + min;
 // printf("Original array:\n");        //
 // show(a,size);                       //

  countingSort(a, size, max, &copy, &comparison);
 // printf("Sorted array:\n");          //
 // show(a,size);                       //

  Tcopy += copy;
  Tcomp += comparison;

//  printf("Seed = %d, copy data %d times, compare data %d times.\n", seed, copy, comparison);
  copy = 0;
  comparison = 0;
}
  printf("Average: copy %.2f times, compare %.2f times.\n", Tcopy/Trial, Tcomp/Trial); 

  return 0;
}
