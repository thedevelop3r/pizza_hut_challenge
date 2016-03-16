#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmpfunc(const void * a, const void * b)
{
  return (*(int*)a - *(int*)b );
}

int check(int *values)
{ 
  // get numbers along the way
  unsigned long numbers[10];
  for(int i = 0; i < 10; i++)
  {
    if(i > 0) numbers[i] = numbers[i-1] * 10 + (unsigned long) values[i];
    else numbers[i] = (unsigned long) values[i];
  }

  // sort the values
  qsort(values, 10, sizeof(int), cmpfunc);

  // check for duplicate values
  for(int i = 0; i < 10; i++)
  {
    // search for value
    int * item = (int *) bsearch(&i, values, 10, sizeof(int), cmpfunc);

    // detect duplicate
    if(item != NULL) 
    {
      if((int) (item-values) >= 1)
	if(values[(int) (item-values)-1] == *item) return false;
      if((int) (item-values) <= 9)
	if(values[(int) (item-values)+1] == *item) return false;
    }
  }

  // check for divisibility
  for(int i = 1; i <= 10; i++)
  {
    if(numbers[i-1] % i != 0) return false; 
  }

  return true;
}

int main()
{
  int arr[] = {2,0,7,6,5,4,3,2,7,0};

  printf("%d\n", check(arr));

  int a,b,c,d,e,f,g,h,i,j;
  
  
  for(a = 0; a < 10; a++)
  {
    for(b = 0; b < 10; b++)
    {
      for(c = 0; c < 10; c++)
      {
	for(d = 0; d < 10; d++)
	{
	  e = 5;
	    for(f = 0; f < 10; f++)
	    {
	      for(g = 0; g < 10; g++)
	      {
		for(h = 0; h < 10; h++)
		{
		  for(i = 0; i < 10; i++)
		  {
		    j = 0;
		      int values[] = {a,b,c,d,e,f,g,h,i,j};
		      if(check(values))
			printf("%lu\n", a*1000000000ul + b*100000000ul +
			       c*10000000ul + d*1000000ul + e*100000ul +
			       f*10000ul + g*1000ul + h*100ul + i*10ul + j);
		  }
		}
	      }
	    }
	}
      }
    }
  }    
  
}
