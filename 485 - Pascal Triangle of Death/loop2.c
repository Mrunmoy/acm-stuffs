//switch case test
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
    k = x%9;
    switch(k)
    {
        case 3:
        {
            y=x;
            break;
        }
        case 5:
        {
            a=x;
            break;
        }
        case 8:
        {
            z=x;
            break;
        }
        default:
        {
            k=x;
            break;
        }
    }
  }
  printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
  return 0;
}
