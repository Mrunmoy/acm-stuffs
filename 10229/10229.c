/* @JUDGE_ID: 59960OQ 10229 C "Brute Force" */

/* Solution to ACM UVa Problem 10229 - Modular Fibonacci */
/* Author - Mrunmoy Samal */
/* Date: 16th december 2007 */
/* If you are satisfied with the solution do
   send a mail to mrunmoy@yahoo.com */

/*
F(0) = 0
F(1) = 1
F(i) = F(i-1) + F(i-2) for i>1

M(n) = F(n) % 2 (raised_to) m

0 <= n <= 2147483647 and 0 <= m <= 20
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

typedef unsigned long long int64;
typedef unsigned long int32;

/*int64 ModFib(int64 n,int m);*/
int64 DC_Fib(int64 n,int m);

int32 powers_of_2[] =
{
    1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576
  //0,1,2,3,4 ,5 ,6 ,7  ,8  ,9  ,10  ,11  ,12  ,13  ,14   ,15   ,16   ,17    ,18    ,19    ,20
};

int main()
{
    int m;
    int64 n,result;
    while(scanf("%llu %d",&n,&m)==2)
    {
        result = DC_Fib(n,m);
        printf("%llu\n",result);
    }
    return 0;
}
/*
int32 temp[] = {0,1,1,2,3,5,8};
int64 ModFib(int64 n,int m)
{
    int64 res = 0UL;
    int32 val = powers_of_2[m];;
    if(n<=6)
    {
        return (int64)(temp[n]%val);
    }
    else
    {
        
        res = ((8*ModFib(n-5,m))%val + (5*ModFib(n-6,m))%val) % val;
        //printf("%ld\n",res);
        return res;
    }
}
*/

int64 DC_Fib(int64 n,int m)
{
    int64 i=1,h=1,t;
    int64 jp=0,j=0,k=0;
    int64 v = powers_of_2[m];
    int64 modfib = 0;
    while (n > 0)
    {
        if (n%2 == 1) // if n is odd
        {
            t = j*h;
            jp = j;
            j = (i*h + j*k + t);
            modfib = ((((i)%v)*((h)%v))%v + (((jp)%v)*((k)%v))%v + (t%v))%v;
            i = i*k + t;
        }
        t = h*h;
        h = 2*k*h + t;
        k = k*k + t;
        n = (int32) n/2;
    }
    return modfib;
}

