/* Solution to ACM UVa Problem 355 - The Bases are loaded */
/* Author- Mrunmoy Samal Copyright© Material*/
/* Date: 10th April 2007 */
/* If you are satisfied with the solution do 
   send a mail to mrunmoy@yahoo.com */

#include <stdio.h>
#include <ctype.h>

/* structure for holding the input data  */
struct dataTag {
        int curBase;
        int newBase;
        char inp[11];
        char out[41];
        int length;
        unsigned int errorFlag;
        unsigned int charFlag;
} inputData[1];

/* index of the input data array */
int index;

/* Function declarations */
void getInput(int idx);
int BaseFault(int idx);
void convertBase(int idx);

/* main entry point of the code */
main()
{
	int count,K;
	/* how many number of inputs are to be given? */
	scanf("%d",&count);

	/* Initialize data buffer index */
	index=0;

	/* take user input and process, until the 
	   count number of inputs are taken */
	for(index=0;index<count;index++)
	{

		/* Get the user input*/
        getInput(index);
        convertBase(index);
	}

	for(K=0;K<count;K++)
	{
		/* Check the user input & set the error flag*/
        if(BaseFault(K))
            printf("%s is an illegal base %d number\n",inputData[K].inp,inputData[K].curBase);
        else
            printf("%s base %d = %s base %d\n",inputData[K].inp,inputData[K].curBase,inputData[K].out,inputData[K].newBase);
	}
	return 0;
}

/* Get the three input values  */
void getInput(int idx)
{
        int ch,k;
        inputData[idx].charFlag = 0;

        /* ignore the leading blanks */
        while( isspace(ch = getchar()) );

        /* save the current base */
        if(isdigit(ch))
        {
                for( inputData[idx].curBase=0;isdigit(ch);ch=getchar() )
                        inputData[idx].curBase = 10 * (inputData[idx].curBase) + (ch - '0');
        }

        /* ignore the middle blanks */
        while( isspace(ch = getchar()) );

        /* save the new base */
        if(isdigit(ch))
        {
                for( inputData[idx].newBase=0;isdigit(ch);ch=getchar() )
                        inputData[idx].newBase = 10 * (inputData[idx].newBase) + (ch - '0');
        }

        /* ignore the middle blanks */
        while( isspace(ch = getchar()) );
        k=0;
        
        /* Read in the 10 character input */
    for(k=0;(isxdigit(ch) && k<10);ch=getchar())
        {
                if(isdigit(ch))
                {
                        inputData[idx].inp[k++] = ch;
                }
                else if(isupper(ch))
                {
                        inputData[idx].charFlag = 1;
                        inputData[idx].inp[k++] = ch;
                }
                else
                {
                        inputData[idx].errorFlag = 1;
                        inputData[idx].inp[k++] = ch;
        }
        }
        inputData[idx].inp[k] = '\0';
}

/* Check if the given number is of the given base */
int BaseFault(int idx)
{
        int digVal,i;
        char ch = 1;

        for(i=0;(i<10 && ch != '\0');i++)
        {
                ch = inputData[idx].inp[i];
                if(isdigit(ch))
                {
                        digVal = ch - '0';
                        if(inputData[idx].curBase < digVal)
                                return 1;
                }
                else
                {
                        digVal = 10 + ch - 'A';
                        if(inputData[idx].curBase < digVal)
                                return 1;
                }
        }
        return 0;
}

void convertBase(int idx)
{
        int BaseValue(int idx);
        int decVal,i,newVal;
        int len = 0;
        char temp;
        decVal = BaseValue(idx);

        /* Convert from Base10 to the newBase*/
        
        for(i=0;decVal!=0;i++)
    {
        newVal = decVal % (inputData[idx].newBase);
        if(newVal==10)
                {
                        inputData[idx].out[i] = 'A';
                        //printf("A");
                }
                else if(newVal==11)
                {
                        inputData[idx].out[i] = 'B';
                        //printf("B");
                }
                else if(newVal==12)
                {
                        inputData[idx].out[i] = 'C';
                        //printf("C");
                }
                else if(newVal==13)
                {
                        inputData[idx].out[i] = 'D';
                        //printf("D");
                }
                else if(newVal==14)
                {
                        inputData[idx].out[i] = 'E';
                        //printf("E");
                }
                else if(newVal==15)
                {
                        inputData[idx].out[i] = 'F';
                        //printf("F");
                }
                else
                {
                        inputData[idx].out[i] = newVal +'0';    
                        //printf("%d",newVal);
                }
                decVal = decVal/inputData[idx].newBase;
                
    }
        len = (i-1);
        inputData[idx].out[i] = '\0';
        
        for(i=0;i<=len/2;i++)
        {
                temp = inputData[idx].out[i];
                inputData[idx].out[i] = inputData[idx].out[len-i];
                inputData[idx].out[len-i] = temp;
        }
        
}

int BaseValue(int idx)
{
        int power(int x,int y);
        int i = 0;
        int digVal = 0;
        int sum = 0;
        char ch;
        int numSize = 0;
        
        while( (ch = inputData[idx].inp[i++]) != '\0')
        {
                numSize++;
        }
        numSize--;
        
        inputData[idx].length = numSize;
        /* extract the digits of the number */
        for(i=0;i<=numSize;i++)
        {
                ch = inputData[idx].inp[i];
                if(isdigit(ch))
                {
                        digVal = ch - '0';
                }
                else
                {
                        digVal = 10 + ch - 'A';
                }
                sum = sum + digVal*power(inputData[idx].curBase,(numSize-i));
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