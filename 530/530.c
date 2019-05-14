/* @JUDGE_ID: 59960OQ 530 C "Brute Force" */

/* Solution to ACM UVa Problem 530 -   Binomial Showdown    */
/* Author- Mrunmoy Samal*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

typedef unsigned long uint64;

uint64 gcd(uint64 a,uint64 b);
void DivByGCD(uint64 *a, uint64 *b);
uint64 Cnk(uint64 n,uint64 k);

int main()
{
    uint64 k,n;
    /*clock_t start = clock();*/
    int done=0;
    uint64 result;
    while((scanf("%lu %lu",&n,&k)==2) && !done)
    {
        if(n==0 && k==0)
        {
            done=1;
            continue;
        }
        result = Cnk(n,k);
        printf("%lu\n",result);
    }
    /*printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
    */
    return 0;
}

uint64 gcd(uint64 a,uint64 b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}

void DivByGCD(uint64 *a, uint64 *b)
{
    long g = gcd(*a,*b);
    *a /= g;
    *b /= g;
}

uint64 Cnk(uint64 n,uint64 k)
{
    uint64 numerator=1;
    uint64 denominator=1;
    uint64 toMul,toDiv,i;

    if(k>n/2)
        k = n - k;

    for(i=k;i;i--)
    {
        toMul = n-k+i;
        toDiv = i;
        DivByGCD(&toMul,&toDiv);
        DivByGCD(&numerator,&toDiv);
        DivByGCD(&toMul,&denominator);
        numerator *= toMul;
        denominator *= toDiv;
    }
    return numerator/denominator;
}
