#include<stdio.h>
#define max 22
int main()
{

    int a[max] = { 1,2,3,5,6,7,8,19,23,57,58,63,66,75,87,89,91,101,111,123,126 };
    int i,val1,found;
    while(scanf("%d",&val1)==1)
    {
        i=0;
        found = -1;
        /*
        for(i=0;i<max;)
        {
            if(a[i]<val1)
            {
                i++;
            }
            else
            {
                found = i;
                i=max;
            }
        }*/

        found = -1;
        for(i=0;i<max;)
        {
            if(a[i]<val1)
            {
                i++;
            }
            else
            {
                if(a[i]>val1)
                {
                    i--;
                }
                found = i;
                i=max;
            }
        }
        printf("%d searched and %d found at index %d\n",val1,a[found],found);
    }
    return 0;
}
