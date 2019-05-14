/* @JUDGE_ID: 59960OQ 495 C "Brute Force" */

/* Solution to ACM UVa Problem 495 - Fibonacci Freeze */
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

void add(int fn,int fn_1,int fn_2,char ch);

int main()
{
    int fib; //  0 <= n <= 5000
    int i;
    char *ptrSrc,*ptrTgt,*ptrTgt2;
    clock_t start = clock();
    memset(LookUpTable.done, '0',5000);
    // Initialize minimum known fibonaccis
    LookUpTable.LookUp[0][0] = '0';LookUpTable.LookUp[0][1] = '\0';
    LookUpTable.done[0] = 1;
    LookUpTable.LookUp[1][0] = '1';LookUpTable.LookUp[1][1] = '\0';
    LookUpTable.done[1] = 1;
    LookUpTable.LookUp[2][0] = '1';LookUpTable.LookUp[2][1] = '\0';
    LookUpTable.done[2] = 1;

    while( scanf("%d",&fib)==1 )
    {
        if(fib==0) // special case fib(0)
        {
            printf("The Fibonacci number for 0 is 0\n");

        }
        else if((fib==1) || (fib==2)) // special case fib(1), fib(2)
        {
            printf("The Fibonacci number for %d is 1\n",fib);
        }
        else // other cases cacluate fib(n)
        {
            if(LookUpTable.done[fib] == 1) // if already available, display fib(n)
            {
               printf("The Fibonacci number for %d is %s\n",fib,LookUpTable.LookUp[fib]);
            }
            else
            {
                if( LookUpTable.done[fib-1] == 1 )/* if f(n-1) is available,
                                                   it means f(n-2) is also available */
                {
                    add(fib,fib-1,fib-2,'n');
                    LookUpTable.done[fib] = 1;
                    printf("The Fibonacci number for %d is %s\n",fib,LookUpTable.LookUp[fib]);
                }
                else if( LookUpTable.done[fib-2] == 1) /* if f(n-2) is available
                                                        calculate f(n-1) and f(n) */
                {
                    add(fib-1,fib-2,fib-3,'n');
                    LookUpTable.done[fib-1] = 1;
                    add(fib,fib-1,fib-2,'n');
                    LookUpTable.done[fib] = 1;
                    printf("The Fibonacci number for %d is %s\n",fib,LookUpTable.LookUp[fib]);
                }
                else // neither f(n-1) nor f(n-2) are available so calculate in normal iterative way
                {
                    firsttime=1;
                    result[0] = '1';
                    result[1] = '\0';
                    for(i=0;i<=fib;i++)
                    {
                        add(0,0,0,'i'); // sum = result + prev
                        
						ptrSrc = result;ptrTgt = prev;
                        while(*ptrTgt++=*ptrSrc++); // prev = result
                        ptrSrc = sum;ptrTgt = result;
  					    ptrTgt2 = LookUpTable.LookUp[i];
						while(*ptrTgt2++=*ptrTgt++=*ptrSrc++); // result = sum, fib(i) = sum
						LookUpTable.done[i] = 1; // fib(i) available
                        firsttime = 0;
                    }
                    printf("The Fibonacci number for %d is %s\n",fib,result);
                }
            }
        }
    }
    /* Code you want timed here */
    printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);    // set done to zero first.
    return 0;
}

void add(int fn,int fn_1,int fn_2,char ch)
{
    int a;
    int b,len;
    int tot,u,carry;
    int i,j,k,len1,len2;
    char *ptr1,*ptr2,*ptr3;

    if(ch=='i')
    {
        if(firsttime == 1)
        {
            sum[0] = '0';
            sum[1] = '\0';
			return;
        }
        else
        {
            len1 = strlen(result) - 1;
            len2 = strlen(prev) - 1;
            if(len1>len2)
            {
                i = len1;
                j = len2;
                ptr1 = result;
                ptr2 = prev;
            }
            else
            {
                i = len2;
                j = len1;
                ptr1 = prev;
                ptr2 = result;
            }
            ptr3 = sum;
        }
    }
    else if(ch =='n')
    {
        ptr1 = LookUpTable.LookUp[fn_1];
        ptr2 = LookUpTable.LookUp[fn_2];
        i = strlen(ptr1) - 1;
        j = strlen(ptr2) - 1;
        ptr3 = LookUpTable.LookUp[fn];
    }
    //memset(ptr3, '0',MAX_SIZE);
    k = 0;
    carry =0;
    while(i >= 0)
    {
        a = ptr1[i] - '0';
        if(j >= 0)
        {
            b = ptr2[j] - '0';
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
            ptr3[k] = u + '0';
            ptr3[k+1] = carry + '0';
        }
        else
        {
            ptr3[k] = tot + '0';
            carry = 0;
        }
        k++;
        i--;
    }
    ptr3[k+carry] ='\0';
    len1 = strlen(ptr3) - 1;
    for(k=0;k<=len1/2;k++)
    {
        a = ptr3[k];
        ptr3[k] = ptr3[len1-k];
        ptr3[len1-k] = a;
    }
}
