/* Solution to ACM UVa Problem 355 - The Bases are loaded */
/* Author- Mrunmoy Samal */

#include <stdio.h>
#include <ctype.h>

char curBase[50];
char newBase[50];
char inpStr[50];
char outStr[50];

unsigned long long power(long x,long y);
int BaseFault(char base[],char inp[]);
void convertBase(char inBase[], char input[],char outBase[]);

main()
{
    int idx1,idx2,nZero;
    char *ptr = NULL;

    while(scanf("%s%s%s",&curBase,&newBase,&inpStr)==3)
    {
        /* Remove all leading zeros in the inputs
         Remove Leading zeros frmo curBase

        if(curBase[0] == '0')
        {
            nZero = 0;
            ptr = curBase;
            while(*ptr++ =='0')
            nZero++;
            ptr = curBase;
            for(idx1=0,idx2=nZero;*ptr++;idx1++,idx2++)
                curBase[idx1] = curBase[idx2];
        }

         Remove Leading zeros frmo newBase

        if(newBase[0] == '0')
        {
            nZero = 0;
            ptr = newBase;
            while(*ptr++ =='0')
                nZero++;
            ptr = newBase;
            for(idx1=0,idx2=nZero;*ptr++;idx1++,idx2++)
                newBase[idx1] = newBase[idx2];
        }
         Remove Leading zeros frmo inpStr

        if(inpStr[0] == '0')
        {
            nZero = 0;
            ptr = inpStr;
            while(*ptr++ =='0')
                nZero++;
            ptr = inpStr;
            for(idx1=0,idx2=nZero;*ptr++;idx1++,idx2++)
                inpStr[idx1] = inpStr[idx2];
        }*/


        /* Check for base fault, if there are illegal characters
           print error message */
        if(BaseFault(curBase,inpStr))
            printf("%s is an illegal base %s number\n",inpStr,curBase);
        /* else proceed for processing*/
        else
        {
            convertBase(curBase,inpStr,newBase);
            printf("%s base %s = %s base %s\n",inpStr,curBase,outStr,newBase);
        }
    }
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

/* Check if the given number is of the given base */
int BaseFault(char base[],char input[])
{
    int digVal,idx;
    int len1,len2;
    char ch,*ptr;
    int current;

    /* Initialize the current base value */
    current = 0;

    /* calculate the base string length */
    ptr = base;
    for(len1=0;*ptr++;len1++);
    len1--;
    /* calculate the base value */
    for(idx=0;idx<=len1;idx++)
        current = current + (base[idx] - '0') * power(10,len1-idx);

    /* calculate the input string length */
    ptr = input;
    for(len2=0;*ptr++;len2++);

    digVal = 0;
    /* check if current base is less that any of teh digits in teh input string*/
    for(idx=0;idx<len2;idx++)
    {
        ch = input[idx];
        if(ch >= 'A' && ch <= 'Z')
            ch = ch - 7;
        digVal = ch - '0';
        /* If so, then there is a illegal digit in the input string */
        if(digVal >= current)
            return 1;
    }
    /* Else there is no illegal digits in the input string */
    return 0;
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
    /* calculate the base value */
    for(idx=0;idx<=len1;idx++)
        current = current + (inBase[idx] - '0') * power(10,len1-idx);

    /* calculate the new base string length */
    ptr = outBase;
    for(len2=0;*ptr++;len2++);
    len2--;

    /* calculate the base value */
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
    /* Special Case */
    if(decVal==0)
    {
        outStr[0] = '0';
        outStr[1] = '\0';
    }
    /* Rest of the cases*/
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
