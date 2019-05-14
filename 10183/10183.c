/* @JUDGE_ID: 59960OQ 10183 C "Brute Force" */

/* Solution to ACM UVa Problem 10183 - How many Fibs? */
/* Author- Mrunmoy Samal*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define EQ 0
#define GT 1
#define LT -1

#define MAX_SIZE 484
#define MAX_COL 102
char result[MAX_COL];
char sum[MAX_COL];
char prev[MAX_COL];
struct struct_tag
{
    char LookUp[MAX_SIZE][MAX_COL];
}LookUpTable;

char a_fib[MAX_COL] =
"1000000000000000000000000000000000000000000000000000\
0000000000000000000000000000000000000000000000000";
char b_fib[MAX_COL] =
"1000000000000000000000000000000000000000000000000000\
0000000000000000000000000000000000000000000000000";

int firsttime = 1;

int add(void);
int compareBigInteger(int k,char ch);

int main()
{
    int fib; //  0 <= n <= 5000
    int i,j,count,eqA,eqB,done,found;
    char *ptrSrc,*ptrTgt,*ptrTgt2;
    /*clock_t start = clock();*/
    fib = 483;
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
    }
    done=0;
    firsttime=1;
    while(!done)
    {
        count = 0;
        scanf("%s %s",&a_fib,&b_fib);
        if((a_fib[0] =='0') && (b_fib[0]=='0'))
        {
            done=1;
        }
        else
        {
            if(compareBigInteger(0,'c')==EQ)
            {
                found = 0;
                i=2;
                while(i<=fib)
                {
                    eqA = compareBigInteger(i,'a');
                    if(eqA==EQ)
                    {
                        found = 1;
                        i = MAX_SIZE;
                    }
                    else
                    {
                        i++;
                    }
                }
                if(found)count=1;
            }
            else
            {
                i=2;
                while(i<=fib)
                {
                    eqA = compareBigInteger(i,'a');
                    if(eqA==LT)
                    {
                        i++;
                    }
                    else
                    {
                        j = i;
                        i=MAX_SIZE;
                        count=1;
                    }
                }

                while(j<=fib)
                {
                    eqB = compareBigInteger(j,'b');
                    if(eqB==LT)
                    {
                        j++;
                        count++;
                    }
                    else
                    {
                        if(eqB==GT)
                        {
                            j--;
                            count--;
                        }
                        j=MAX_SIZE;
                    }
                }
            }
            if(firsttime)
            {
                printf("%d",count);
                firsttime=0;
            }
            else
            {
                printf("\n%d",count);
            }
        }
    }
    /* Code you want timed here */
    /*printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);*/
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

/*
Returns 1 if Lookup[i] > val
       -1 if Lookup[i] < val
       0 if equal
*/

int compareBigInteger(int k,char ch)
{
    int len1;
    int len2;
    int i,there_is_a_match,retval=0;
    char *ptr1,*ptr2;

    len1 = strlen(LookUpTable.LookUp[k]);
    if(ch =='a')
    {
        len1 = strlen(LookUpTable.LookUp[k]);
        len2 = strlen(a_fib);
        ptr1 = LookUpTable.LookUp[k];
        ptr2 = a_fib;
    }
    else if(ch=='b')
    {
        len1 = strlen(LookUpTable.LookUp[k]);
        len2 = strlen(b_fib);
        ptr1 = LookUpTable.LookUp[k];
        ptr2 = b_fib;
    }
    else
    {
        len1 = strlen(a_fib);
        len2 = strlen(b_fib);
        ptr1 = a_fib;
        ptr2 = b_fib;
    }

    if(len1>len2) // value is > than lookuptable value
    {
        retval = GT;
    }
    else if(len1==len2) // the lengths are equal
    {
        // now compare the first digit of both if the first digit is same
        // then compare the next digit, which tells us if
        // the BigInteger_curr_row[k] is greater than ten_raised_to_60
        i = 0;
        there_is_a_match = 1;
        retval = 0;
        while(there_is_a_match && (i<len1))
        {
           if( (ptr1[i] == ptr2[i]) && (retval==EQ) )
           {
               retval = EQ; // number is equal so we reach last row
               i++; // continue comparing
           }
           else
           {
               if(ptr1[i] > ptr2[i])
               {
                   there_is_a_match = 0; // number is greater so we reach last row
                   retval = GT;
               }
               else
               {
                   there_is_a_match = 0;
                   retval = LT; // number is smaller so continue
               }
           }
        }
    }
    else
    {
        retval = LT;
    }
    return retval;
}

/*
int binSrch(int k,char ch)
{
    int response,i,j;
    int len1,len2;
    int found = 0;
    char *ptr1,*ptr2;

    if(ch=='a')
    {
        cmpResult = strcmp(LookUpTable.LookUp[k],a_fib);
        ptr1 = LookUpTable.LookUp[k];
        ptr2 = a_fib;
    }
    else
    {
        cmpResult = strcmp(LookUpTable.LookUp[k],b_fib)
        ptr1 = LookUpTable.LookUp[k];
        ptr2 = b_fib;
    }

    while(!found)
    {

        if(cmpResult==0)
        {
            i=0;
            while(i<MAX_COL)
            {
                if((ptr1[i]==ptr2[i]) && response==0)
                {
                    i++;
                }
                else if(ptr1[i]>ptr2[i])
                {
                    response = 1;
                }
                else
                {
                    response = -1;
                }
            }

        }
        else if(cmpResult>1)
        {

        }
        else
        {
            found = 1;
            response = -1;
        }

    }
    return response;
}

*/
