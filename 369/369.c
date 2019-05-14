/* @JUDGE_ID: 59960OQ 369 C "Brute Force" */

/* Solution to ACM UVa Problem 369 - Combinations   */
/* Author- Mrunmoy Samal*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>


long gcd(long a,long b);
void DivByGCD(long *a, long *b);
long Cnk(int n,int k);

int main()
{
    int k,n;
    /*clock_t start = clock();*/
    int done=0;
    long result;
    while((scanf("%d %d",&n,&k)==2) && !done)
    {
        if(n==0 && k==0)
        {
            done=1;
            continue;
        }
        result = Cnk(n,k);
        printf("%d things taken %d at a time is %ld exactly.\n",n,k,result);
    }
    /*printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
    */
    return 0;
}

long gcd(long a,long b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}

void DivByGCD(long *a, long *b)
{
    long g = gcd(*a,*b);
    *a /= g;
    *b /= g;
}

long Cnk(int n,int k)
{
    long numerator=1;
    long denominator=1;
    long toMul,toDiv,i;

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
