//if..else Test
#include <stdio.h>
#include <time.h>

int main()
{
  int x,y,z,a,k;
  clock_t start = clock();

  while(scanf("%d",&x)==1)
  {
    y = x%3;
    z = x%5;
    a = x%8;
    k = x%7;
    if(k==a)
    {
        y=x;
    }
    else if(k==z)
    {
        a=x;
    }
    else if(k==y)
    {
        z=x;
    }
    else
    {
        k=x;
    }
  }
  printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

  return 0;
}
