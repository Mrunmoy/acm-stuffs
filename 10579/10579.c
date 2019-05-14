/* @JUDGE_ID: 59960OQ 10579 C "Brute Force" */

/* Solution to ACM UVa Problem 10579 - Problem E: Fibonacci Numbers */
/* Author- Mrunmoy Samal*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1050

char result[MAX_SIZE];
char sum[MAX_SIZE];
char prev[MAX_SIZE];
struct struct_tag
{
    char LookUp[5001][MAX_SIZE];
    char done[5001];
}LookUpTable;

int firsttime = 1;

int add(void);

int main()
{
    int fib; //  0 <= n <= 5000
    int i;
    char *ptrSrc,*ptrTgt,*ptrTgt2;
    //clock_t start = clock();

    fib = 4790;
    result[0] = '1';
    result[1] = '\0';

    for(i=0;i<=fib;i++)
    {
        add(); // sum = result + prev
        ptrSrc = result;ptrTgt = prev;
        while(*ptrTgt++=*ptrSrc++); // prev = result
        ptrSrc = sum;ptrTgt = result;
        ptrTgt2 = LookUpTable.LookUp[i];
        while(*ptrTgt2++=*ptrTgt++=*ptrSrc++); // result = sum, fib(i) = sum
        LookUpTable.done[i] = 1; // fib(i) available
    }

    while( scanf("%d",&fib)==1 )
    {
        printf("%s\n",LookUpTable.LookUp[fib]);
    }
    /* Code you want timed here */
    //printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);    for(i=0;i<=5000;)

    return 0;
}

int add(void)
{
    int a;
    int b;
    int tot,u,carry;
    int i,j,k,len1;

    if(firsttime)
    {
        sum[0] = '0';
        sum[1] = '\0';
        firsttime=0;
        return 0;
    }

    i = strlen(result) - 1;
    j = strlen(prev) - 1;

    k = 0;
    carry =0;
    while(i >= 0)
    {
        a = result[i] - '0';
        if(j >= 0)
        {
            b = prev[j] - '0';
            j--;
        }
        else
        {
            b = 0;
        }
        tot = a + b + carry;
        if(tot>=10)
        {
            u = tot%10;
            carry = tot/10;
            sum[k] = u + '0';
            sum[k+1] = carry + '0';
        }
        else
        {
            sum[k] = tot + '0';
            carry = 0;
        }
        k++;
        i--;
    }
    sum[k+carry] ='\0';
    len1 = strlen(sum) - 1;
    for(k=0;k<=len1/2;k++)
    {
        a = sum[k];
        sum[k] = sum[len1-k];
        sum[len1-k] = a;
    }
    return 1;
}

