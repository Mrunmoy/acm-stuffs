/* @JUDGE_ID: 59960OQ 100 C "Brute Force" */
/* Solution to ACM UVa Problem 101 -  The 3n + 1 problem   */
#include<stdio.h>
#include <time.h>

typedef unsigned long uint32;

/* main entry point of the code */
int main(void)
{
    uint32 max,x,y;
    uint32 I,n;
    uint32 count=1UL;
    uint32 CycleLength(uint32 n);
    /*clock_t start = clock();*/
    while(scanf("%lu %lu",&x,&y)==2)
    {
        max = 0;
        for(I=(y + ((x - y) & -(x < y)));I<=(x - ((x - y) & -(x < y)));I++)
        {
            count = 1UL;
            n=I;
            if(n!=1L)
            {
                while(n!=1)
                {
                    if(n%2==0)
                    {
                        n=(n>>1);
                    }
                    else
                    {
                        n = n*3+1;
                    }
                    count++;
                }
            }
           // cl = CycleLength(I);
            max = max - ((max - count) & -(max < count));
        }
        printf("%lu %lu %lu\n",x,y,max);
    }
    /*printf("Time elapsed: %f\n", ((double)clock() - (double)start) / CLOCKS_PER_SEC);*/
    return 0;
}

uint32 CycleLength(uint32 n)
{
    uint32 count=1UL;

    if(n==1L)
        return 1UL;
    else
    {
        while(n!=1)
        {
            if(n%2==0)
            {
                n=(n>>1);
            }
            else
            {
                //n=(n<<1) + n + 1;
                n = n*3+1;
            }
            count++;
        }
    }
    return count;
}
