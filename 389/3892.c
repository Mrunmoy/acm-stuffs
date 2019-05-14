/* @JUDGE_ID: 59960OQ 389 C "Brute Force" */

/* Solution to ACM UVa Problem 389 - Basically Speaking */
/* Author- Mrunmoy Samal Copyright© Material*/
/* Date: 10th April 2007 */
/* If you are satisfied with the solution do
   send a mail to mrunmoy@yahoo.com */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct inputTag
{
    char inp[80];
    char out[20];
    int curBase;
    int newBase;
    char errorFlag;
    char curLen;
    char newLen;
};

typedef struct inputTag INPUT_DATA;

INPUT_DATA inputData;

/* Function declarations */
void stripLeadingZeros(char *str);
void convertBase(void);

/* main entry point of the code */
main()
{
    while( scanf("%s %d %d",&inputData.inp,&inputData.curBase,&inputData.newBase)==3)
    {
        stripLeadingZeros(inputData.inp);
		printf("%s\n",inputData.inp);
        convertBase();
        /* Check the user input & set the error flag
        if(inputData.errorFlag)
            printf("%7s\n","ERROR");
        else
            printf("%7s\n",inputData.out);*/
    }
    return 0;
}

void stripLeadingZeros(char *str)
{
    int inpLen=0,curLen=0;
    char *ptr = str;
    inpLen = strlen(str);

    while((*ptr == '0'))
    {
        ptr++;
        curLen++;
    }
    if(curLen < inpLen)
    {
        while(*str = *ptr)
        {
            ptr++;str++;
        }
    }
    else
    {
        str[0] = '0';
        str[1] = '\0';
    }
}

void convertBase(void)
{
        int GetBase10Value(void);
        int decVal,i,newVal;
        int len = 0;
        char temp;
        decVal = GetBase10Value();

        /* Convert from Base10 to the newBase*/
		if(inputData.newBase !=0)
		{
			for(i=0;decVal!=0;i++)
			{
					newVal = decVal % (inputData.newBase);
					if(newVal==10)
					{
							inputData.out[i] = 'A';
							//printf("A");
					}
					else if(newVal==11)
					{
							inputData.out[i] = 'B';
							//printf("B");
					}
					else if(newVal==12)
					{
							inputData.out[i] = 'C';
							//printf("C");
					}
					else if(newVal==13)
					{
							inputData.out[i] = 'D';
							//printf("D");
					}
					else if(newVal==14)
					{
							inputData.out[i] = 'E';
							//printf("E");
					}
					else if(newVal==15)
					{
							inputData.out[i] = 'F';
							//printf("F");
					}
					else
					{
							inputData.out[i] = newVal +'0';
							//printf("%d",newVal);
					}
					decVal = decVal/inputData.newBase;

			}
		}

        len = (i-1);

        if(len<7)
            inputData.errorFlag = 0;
        else
            inputData.errorFlag = 1;

        inputData.out[i] = '\0';

        for(i=0;i<=len/2;i++)
        {
                temp = inputData.out[i];
                inputData.out[i] = inputData.out[len-i];
                inputData.out[len-i] = temp;
        }

}

int GetBase10Value(void)
{
        int power(int x,int y);
        int i = 0;
        int digVal = 0;
        int sum = 0;
        char ch;
        int numSize = strlen(inputData.inp);

        /* extract the digits of the number */
        for(i=0;i<=numSize;i++)
        {
                ch = inputData.inp[i];
                if(isdigit(ch))
                {
                        digVal = ch - '0';
                }
                else
                {
                        digVal = 10 + ch - 'A';
                }
                sum = sum + digVal*power(inputData.curBase,(numSize-i));
        }
        //printf("\nBase 10 value:%d\n",sum);
        return sum;
}

/* return x (to the power) y */
int power(int x,int y)
{
        int sum = 1,i=0;;
        for(i=0;i<y;i++)
        {
                sum = sum*x;
        }
        return sum;
}