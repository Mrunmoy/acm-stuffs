/* @JUDGE_ID: 59960OQ 10450 C "Brute Force" */

/* Solution to ACM UVa Problem 10450 - World Cup Noise */
/* Author- Mrunmoy Samal*/

#include <stdio.h>
#include <ctype.h>

typedef long long int64;
typedef long int32;
struct struct_tag
{
    int64 LookUp[55];
}LookUpTable;

int64 DC_fib(int64 n);

int main()
{
    int fib; //  1 <= n <= 51
    int32 numScenario;
    int i;
    /*clock_t start = clock();*/
    fib = 55;
    for(i=0;i<=fib;i++)
    {
        LookUpTable.LookUp[i] = DC_fib(i);
    }
    while(scanf("%ld",&numScenario)==1)
    {
        i=1;
        while( (numScenario>0L) && (scanf("%d",&fib)==1) )
        {
            printf("Scenario #%d:",i);
            if(fib==0)
            {
                printf("\n0\n");
            }
            else
            {
                printf("\n%lld\n",LookUpTable.LookUp[fib+2]);
            }
            numScenario--;
            i++;
            printf("\n");
        }
    }
    /* Code you want timed here */
    /*printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);*/
    return 0;
}

int64 DC_fib(int64 n)
{
    int64 i = 1,h = 1,t;
    int64 j = 0,k = 0;
    while (n > 0)
    {
        if (n%2 == 1)
        { // if n is odd
            t = j*h;
            j = i*h + j*k + t;
            i = i*k + t;
        }
        t = h*h;
        h = 2*k*h + t;
        k = k*k + t;
        n = (int64) n/2;
    }
    return j;
}
