#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool check(unsigned long n)
{
  printf("%lu\n", n);
  printf("%lu\n", n / 10000);
  printf("%lu\n", n % 10000);
  int values[] = { 
    n / 1000000000 % 10,
    n / 100000000 % 10,
    n / 10000000 % 10,
    n / 1000000 % 10,
    n / 100000 % 10,
    n / 10000 % 10,
    n / 1000 % 10,
    n / 100 % 10,
    n / 10 % 10,
    n / 1 % 10,
  };
  //int values[] = {1,2,3,4,5,6,7,8,9,0};
  
  for(int i = 0; i < 10; i++)
  {
    printf("%d, ", values[i]);
  }
  printf("\n");
}
int main()
{
  int arr[] = {0,1,2,3,4,5,6,7,8,9};

  int a,b,c,d,e,f,g,h,i,j;

  for(a = 0; a < 10; a++)
  {
    for(b = 0; b < 10; b++)
    {
      for(c = 0; c < 10; c++)
      {
	for(d = 0; d < 10; d++)
	{
	  for(e = 0; e < 10; e++)
	  {
	    for(f = 0; f < 10; f++)
	    {
	      for(g = 0; g < 10; g++)
	      {
		for(h = 0; h < 10; h++)
		{
		  for(i = 0; i < 10; i++)
		  {
		    for(j = 0; j < 10; j++)
		    {
		       unsigned long n = 
			      1000000000*a + 100000000*b + 10000000*c +
			      1000000*d + 100000*e + 10000*f + 1000*g +
			      100*h + 10*i + j;
		       if(check(n)) printf("%lu", n);
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }    

}
