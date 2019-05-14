/* @JUDGE_ID: 59960OQ 389 C "Brute Force" */

/* Solution to ACM UVa Problem 389 - Basically Speaking */
/* Author- Mrunmoy Samal*/

#include <stdio.h>
#include <ctype.h>

char curBase[10000];
char newBase[10000];
char inpStr[10000];
char outStr[10000];
char errorFlag = 0;

/* Function declarations */
unsigned long long power(long x,long y);
void convertBase(char inBase[], char input[],char outBase[]);

/* main entry point of the code */
int main()
{
    int first_time = 1;
    /* take user input and process, until the
       count number of inputs are taken */
    while(scanf("%s%s%s",&inpStr,&curBase,&newBase)==3)
    {
        /* Reset the error flag */
        errorFlag = 0;
        /* Perform the conversion */
        convertBase(curBase,inpStr,newBase);
        /* Check the error flag */
        if(first_time)
        {
            first_time = 0;
        }
        else
        {
            printf("\n");
        }
        if(errorFlag)
            printf("%7s","ERROR");
        else
            printf("%7s",outStr);
    }
    printf("\n");
    return 0;
}

/* return x (to the power) y */
unsigned long long power(long x,long y)
{
        unsigned long long sum = 1;
        int i=0;;
        for(i=0;i<y;i++)
        {
            sum = sum*x;
        }
        return sum;
}

void convertBase(char inBase[], char input[],char outBase[])
{
    char ch,*ptr = NULL;
    int idx;
    int len1,len2,len3;
    unsigned long long decVal = 0,newVal = 0;
    int digVal = 0;
    int current = 0,next = 0;

    /* calculate the current base string length */
    ptr = inBase;
    for(len1=0;*ptr++;len1++);
    len1--;
    /* calculate the base value in decimal*/
    for(idx=0;idx<=len1;idx++)
        current = current + (inBase[idx] - '0') * power(10,len1-idx);

    /* calculate the new base string length */
    ptr = outBase;
    for(len2=0;*ptr++;len2++);
    len2--;

    /* calculate the base value in decimal */
    for(idx=0;idx<=len2;idx++)
        next = next + (outBase[idx] - '0') * power(10,len2-idx);

    /* calculate the input string length */
    ptr = input;
    for(len3=0;*ptr++;len3++);
    len3--;
    /* convert from current current base to base10 */
    decVal = 0;
    for(idx=0;idx<=len3;idx++)
    {
        ch = input[idx];
        if(ch >= 'A' && ch <= 'Z')
            ch = ch - 7;
        digVal = ch - '0';
        decVal = decVal + digVal * power(current,len3-idx);
    }

    /* Convert from Base10 to the new Base*/
    /* Special Case when the value is zero */
    if(decVal==0)
    {
        outStr[0] = '0';
        outStr[1] = '\0';
    }
    /* Rest of the cases*/
    else
    {
        /* Special Case when the new base is zero */
        if(next==0)
        {
            outStr[0] = '0';
            outStr[1] = '\0';
        }
        else
        {
            for(idx=0;decVal!=0;idx++)
            {
                newVal = decVal % next;
                if(newVal==10)
                {
                     outStr[idx] = 'A';
                }
                else if(newVal==11)
                {
                     outStr[idx] = 'B';
                }
                else if(newVal==12)
                {
                     outStr[idx] = 'C';
                }
                else if(newVal==13)
                {
                     outStr[idx] = 'D';
                }
                else if(newVal==14)
                {
                     outStr[idx] = 'E';
                }
                else if(newVal==15)
                {
                     outStr[idx] = 'F';
                }
                else
                {
                     outStr[idx] = (char)newVal +'0';
                }
                decVal = decVal / next;
            }
            len3 = (idx-1);
            /* check length of output*/
            if(len3>=7)
                errorFlag = 1;

            /* append a null terminator */
            outStr[idx] = '\0';
            /* rev the output to its correct form for output */
            for(idx=0;idx<=len3/2;idx++)
            {
                ch = outStr[idx];
                outStr[idx] = outStr[len3-idx];
                outStr[len3-idx] = ch;
            }
        }
    }
}
