/* @JUDGE_ID: 59960OQ 10519 C "Brute Force" */

/* Solution to ACM UVa Problem 10519 - !! REALLY STRANGE !!  */
/* Author- Mrunmoy Samal*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1050

char reset_x[MAX_SIZE] =
"0";
/*
struct struct_tag
{
    char LookUp[MAX_SIZE][MAX_SIZE];
    char done[MAX_SIZE];
}LookUpTable;
*/

void add(char *x,char *y,char *z);
void mul_by_10(char *x, int n);
void mul_by_n(char *res,char *x, char n);
void mul(char *x,char *y,char *z);
void substract(char *x,char *y,char *z);
void ReallyStrange(char *result, char *numCircles);

int main()
{
    char n[MAX_SIZE];
    char result[MAX_SIZE];
    clock_t start = clock();

    while(scanf("%s",&n)==1)
    {
        if(strcmp(n,"0")==0)
        {
            printf("1\n");
            continue;
        }
        ReallyStrange(result,n);
        printf("%s\n",result);
    }
    /*printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
    */
    return 0;
}

void add(char *x,char *y,char *z)
{
    int a;
    int b;
    int tot,u,carry;
    int i,j,k,len1;
    char *ptr1,*ptr2,*ptr3;
    if(strlen(y)>=strlen(z))
    {
        i = strlen(y) - 1;
        j = strlen(z) - 1;
        ptr1 = y;
        ptr2 = z;
        ptr3 = x;
    }
    else
    {
        j = strlen(y) - 1;
        i = strlen(z) - 1;
        ptr1 = z;
        ptr2 = y;
        ptr3 = x;
    }

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

void substract(char *x,char *y,char *z)
{
    /* a = b - c */
    int a;
    int b;
    int tot,carry;
    int i,j,k,len1;

    char *ptr1,*ptr2,*ptr3;

    if(strlen(y)>strlen(z))
    {
        i = strlen(y) - 1;
        j = strlen(z) - 1;
        ptr1 = y;
        ptr2 = z;
        ptr3 = x;
    }
    else if( (strlen(y)>=strlen(z)) && (strcmp(y,z)>0) )
    {
        i = strlen(y) - 1;
        j = strlen(z) - 1;
        ptr1 = y;
        ptr2 = z;
        ptr3 = x;
    }
    else
    {
        j = strlen(y) - 1;
        i = strlen(z) - 1;
        ptr1 = z;
        ptr2 = y;
        ptr3 = x;
    }

    k = 0;
    carry =0;
    while(i >= 0)
    {
        a = ptr1[i] - '0' - carry;
        if(j >= 0)
        {
            b = ptr2[j] - '0';
            j--;
        }
        else
        {
            b = 0;
        }
        if(a<b)
        {
            a=a+10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        tot = a - b;
        ptr3[k] = tot + '0';
        k++;
        i--;
    }
    /*if(ptr1 == z)
        x[k++] ='-';*/
    ptr3[k] ='\0';
    len1 = strlen(ptr3) - 1;
    for(k=0;k<=len1/2;k++)
    {
        a = ptr3[k];
        ptr3[k] = ptr3[len1-k];
        ptr3[len1-k] = a;
    }

}

void mul(char *x,char *y,char *z)
{
    int i,len1,T,p;
    char *result,*ptr1,*ptr2;
    char prev_result[MAX_SIZE] = "0";
    char temp[MAX_SIZE] = "0";
    ptr1 = y;
    ptr2 = z;
    result = x;
/*
    for each character in z, multiply with entire y
    shift left the result by one pos depending upon number of values
    remember result
    from next time, repeat step 1,2, add to remembered value, and step 3
*/
    len1 = strlen(ptr2);
    p = 0;
    for(i=len1-1;i>=0;i--) /* for each cahracter in z*/
    {
        //strcpy(result,reset_x);
        /* multiply y by z(i) */
        mul_by_n(temp,ptr1,ptr2[i]);
        if(p!=0)
        {
            mul_by_10(temp,p);
        }
        add(result,prev_result,temp);
        T=0;
        while(prev_result[T]=result[T])T++;
        p++;
    }
}

void mul_by_n(char *res,char *x, char n)
{
    int a,b,tot,carry;
    int len,k;
    int i;
    char temp[MAX_SIZE];
    len = strlen(x) - 1;
    b = n - '0';
    carry = 0;k = 0;
    strcpy(res,reset_x);

    for(i=len;i>=0;i--)
    {
        a = x[i] - '0';
        tot = (a*b)+carry;
        temp[k] = (tot%10) + '0';
        carry = tot/10;
        temp[k+1] = carry + '0';
        k++;
    }

    temp[k+((carry>0)?1:0)] = '\0';
    len = strlen(temp)-1;

    for(i=0;i<=len/2;i++)
    {
        a = temp[i];
        temp[i] = temp[len-i];
        temp[len-i] = a;
    }
    i=0;
    while(res[i]=temp[i])i++;
}

void mul_by_10(char *x, int n)
{
    int i,len = strlen(x);
    for(i=0;i<n;i++)
    {
        x[len++] = '0';
    }
    x[len] = '\0';
}

void ReallyStrange(char *result, char *numCircles)
{
    //f(n) = numCircles^2 - numCircles + 2
    char res1[MAX_SIZE];
    char res2[MAX_SIZE];
    int nZero;
    char *ptr;
    int idx1,idx2;

    mul(res1,numCircles,numCircles);
    add(res2,res1,"2");
    substract(result,res2,numCircles);
    /* Remove all leading zeros in the result */
    if(result[0] == '0')
    {
        nZero = 0;
        ptr = result;
        while(*ptr++ =='0')
        nZero++;
        ptr = result;
        for(idx1=0,idx2=nZero;*ptr++;idx1++,idx2++)
            result[idx1] = result[idx2];
    }
}

