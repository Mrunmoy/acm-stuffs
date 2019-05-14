/* @JUDGE_ID: 59960OQ 485 C "Brute Force" */

/* Solution to ACM UVa Problem 485 - Pascal Triangle ofDeath */
/* Author - Mrunmoy Samal */
/* Date: 16th december 2007 */
/* If you are satisfied with the solution do
   send a mail to mrunmoy@yahoo.com */
/*
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
...
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 210
#define MAX_COL 65
char BigInteger_prev_row[MAX_SIZE][MAX_COL];
char BigInteger_curr_row[MAX_SIZE][MAX_COL];
char ten_raised_to_60[MAX_COL] =
"1000000000000000000000000000000000000000000000000000000000000";
unsigned long prev_row[MAX_SIZE] = { 0 };

void add(int k);
int compareBigInteger(int k);
void convert_prev_row_to_bigInteger(void);

int main()
{
    int n,i,k,done,quit,finished,firsttime;
    unsigned long curr_row[MAX_SIZE] = { 0 };
    int row_print_over = 0;
    char *ptr1;
    char *ptr2;

    //clock_t start = clock();

    done=0;quit=0,finished=0,firsttime=0;

    prev_row[0] = 1;
    curr_row[0] = 1;
    row_print_over = 0;
    printf("1\n");
    n=1;
    while(!quit)
    {
        for(i=0;(i<=n) && (row_print_over!=1);i++)
        {
/********************** PRINTS LONG INTEGER STARTS ******************************************/
            if((i!=0) && (i!=n))
            {
                curr_row[i] = prev_row[i] + prev_row[i-1];
                if(!done)
                   done = (curr_row[i] >= 1000000000); // integer addition limit reached now
                                                 // switch to big integer addition
                printf(" %ld",curr_row[i]);
            }
            else // column 0 or column n
            {
                (i==n)?printf(" 1\n"):printf("1");
                curr_row[i] = 1;
            }
        }
/********** copy current row into previous row for next calculation *************************/
        if(row_print_over!=1)
        {
            for(k=0;k<=n;k++)
                prev_row[k] = curr_row[k];

            if(done==1)
            {
                convert_prev_row_to_bigInteger();
                row_print_over=1; // dont excute the long integer code any more
            }
            n++;
        }
/********************** PRINTS LONG INTEGER ENDS ********************************************/

/********************** PRINTS BIG INTEGER STARTS *******************************************/
        else // start bigInteger addition cuz integer addition exhausted
        {
            // The usual loop starts
            while(finished!=1)
            {
                for(i=0;i<=n;i++)
                {
                    if((i!=0) && (i!=n))
                    {
                        add(i); // cur_row[i] = prev_row[i-1] + prev_row[i];
                        printf(" %s",BigInteger_curr_row[i]);
                        if(!finished)
                            finished = (compareBigInteger(i)==1);
                        // if curr_row[i] > 10 raised to 60
                        // then finish printing the present row and quit
                    }
                    else
                    {
                        (i==n)? printf(" 1\n"):printf("1");

                        BigInteger_curr_row[i][0] = '1';
                        BigInteger_curr_row[i][1] = '\0';
                    }
                }

                for(i=0;i<=n;i++) // prev_row = curr_row;
                {
                    ptr1 = BigInteger_curr_row[i];
                    ptr2 = BigInteger_prev_row[i];
                    while(*ptr2++=*ptr1++);
                }
                n++; // move on to next row
            }
        }
/********************** PRINTS BIG INTEGER ENDS ********************************************/
        if(finished==1)quit=1;
    }
    //printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

    return 0;
}

void convert_prev_row_to_bigInteger(void)
{
    // convert the last row into character array and fill BigInteger_prev_row
    int i,j,k;
    char temp[MAX_COL];
    unsigned long num,unit;
    for(i=0;i<MAX_SIZE;i++)
    {
        j=0;
        // extract digits and put into the character buffer
        num = prev_row[i];
        while(num!=0)
        {
            if(num>=10)
            {
                unit = num % 10;
                temp[j++] = unit + '0';
            }
            else
            {
                unit = num;
                temp[j++] = unit + '0';
            }
            num = num / 10;
        }
        k=j-1;
        for(j=0;k>=0;k--,j++)
        {
            BigInteger_prev_row[i][j] = temp[k];
        }
        BigInteger_prev_row[i][j] = '\0';
    }
}

void add(int k)
{
    int a;
    int b;
    int tot,u,carry;
    int i,j,l,len1,len2;
    char *ptr1,*ptr2,*ptr3;

    ptr1 = BigInteger_prev_row[k-1];
    ptr2 = BigInteger_prev_row[k];
    len1 = strlen(ptr1) - 1;
    len2 = strlen(ptr2) - 1;
    if(len1>len2)
    {
        i = len1;
        j = len2;
        ptr1 = BigInteger_prev_row[k-1];
        ptr2 = BigInteger_prev_row[k];
    }
    else
    {
        i = len2;
        j = len1;
        ptr2 = BigInteger_prev_row[k-1];
        ptr1 = BigInteger_prev_row[k];
    }
    ptr3 = BigInteger_curr_row[k];
    memset(ptr3, '0',MAX_COL);
    l = 0;
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
            ptr3[l] = u + '0';
            ptr3[l+1] = carry + '0';
        }
        else
        {
            ptr3[l] = tot + '0';
            carry = 0;
        }
        l++;
        i--;
    }
    ptr3[l+carry] ='\0';
    len1 = strlen(ptr3) - 1;
    for(l=0;l<=len1/2;l++)
    {
        a = ptr3[l];
        ptr3[l] = ptr3[len1-l];
        ptr3[len1-l] = a;
    }
}

int compareBigInteger(int k)
{
    int len1;
    int len2;
    int i,there_is_a_match,retval=0;

    len1 = strlen(BigInteger_curr_row[k]);
    len2 = strlen(ten_raised_to_60);
    if(len1>len2) // reached the last row
    {
        retval = 1;
    }
    else if(len1==len2) // the lengths are equal
    {
        // now compare the first digit of both if the first digit is same
        // then compare the next digit, which tells us if
        // the BigInteger_curr_row[k] is greater than ten_raised_to_60
        i = 0;
        there_is_a_match = 1;
        while(there_is_a_match && (i<MAX_COL))
        {
           if(BigInteger_curr_row[k][i] == ten_raised_to_60[i])
           {
               retval = 1; // number is equal so we reach last row
           }
           else
           {
               if(BigInteger_curr_row[k][i] > ten_raised_to_60[i])
               {
                   there_is_a_match = 0; // number is greater so we reach last row
                   retval = 1;
               }
               else
               {
                   retval = -1; // number is smaller so continue
               }
           }
           i++; // continue comparing
        }
    }
    else
    {
        retval = -1;
    }
    return retval;
}

