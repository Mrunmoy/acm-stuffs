#include<stdio.h>

void mult_one(int result[],int num[],int multiplier);
void addShifted(int result[],int k[],int temp[]);
void mult_ten(int result[],int num[],int p);

int main()
{
    int res[500];
    int ten[5] = {1, 10, 100, 1000, 10000};
    int k[500];
    int prev_temp[500];
    int temp[500];
    int a[3] = {3,8,7};
    int b[4] = {5,9,3,6};
    int i,p,j,len;

    for(i=0;i<((sizeof(k))/(sizeof(k[0])));i++)
    {
        k[i]=0;
        prev_temp[i] = 0;
    }

    for(i=2,p=0;i>=0;i--,p++)
    {
        for(i=0;i<((sizeof(res))/(sizeof(res[0])));i++)
        {
            res[i]=0;
        }
        mult_one(temp,b,a[i]);
        if(p==0)
        {
            addShifted(res,k,temp);
        }
        else
        {
            mult_ten(k,temp,p);
            addShifted(res,k,prev_temp);
        }
        j=0;
        len = ((sizeof(res))/(sizeof(res[0])));
        while(j<len)
        {
            k[j]=res[j];
            j++;
        }
    }

    for(i=0;i<((sizeof(a))/(sizeof(a[0])));i++)
    {
        printf("%d",a[i]);
    }
    printf(" * ");
    for(i=0;i<((sizeof(b))/(sizeof(b[0])));i++)
    {
        printf("%d",b[i]);
    }
    printf(" = ");
    for(i=0;i<((sizeof(res))/(sizeof(res[0])));i++)
    {
        printf("%d",res[i]);
    }
    return 0;
}

void mult_ten(int result[],int num[],int p)
{
    int j,i,len;
    len = (sizeof(num))/(sizeof(num[0]));
    j=0;
    while(j<len)
    {
        result[j] = num[j];
        j++;
    }
    for(i=0;i<p;i++)
    {
        result[j++] = 0;
    }
}
void mult_one(int result[],int num[],int multiplier)
{
    int len = (sizeof(num))/(sizeof(num[0]));
    int i,k,a,carry = 0;
    int tot;
    k=0;
    for(i=len;i>=0;i--)
    {
        a = num[i];
        tot = (a*multiplier) + carry;
        result[k++] = tot % 10;
        carry = tot / 10;
    }
}

void addShifted(int result[],int k[],int temp[])
{
    int i,j,m,carry,a,b,tot;
    int *ptr1,*ptr2;
    int len1 = (sizeof(k))/(sizeof(k[0]));
    int len2 = (sizeof(temp))/(sizeof(temp[0]));
    ptr1 = k;
    ptr2 = temp;
    if(len1<len2)
    {
        ptr1 = temp;
        ptr2 = k;
        i = len1;
        len1 = len2;
        len2 = i;
    }
    carry = 0;m=0;
    for(i=len1,j=len2;i>=0;)
    {
        a = ptr1[i];
        if(j>=0)
        {
            b = ptr2[j];
            j--;
        }
        else
        {
            b = 0;
        }
        tot = a + b + carry;
        result[m++] = tot % 10;
        carry = tot / 10;
        i--;
    }
    len1 = (sizeof(result))/(sizeof(result[0])) - 1;
    for(m=0;m<=len1/2;m++)
    {
        a = result[m];
        result[m] = result[len1-m];
        result[len1-m] = a;
    }
}
