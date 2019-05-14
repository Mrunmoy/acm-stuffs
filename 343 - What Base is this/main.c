/* Solution to Problem 343 - What Base is this? */
/* Author- Mrunmoy Samal */

#include <stdio.h>
#include <ctype.h>

struct dataTag {
	long M,N;
	long BaseValOfM[37];
	long BaseValOfN[37];
	unsigned int charFlagM;
	unsigned int charFlagN;
	long minBaseM;
	long minBaseN;
} inputData[100];

int index;

long power(long x,long y);
long get_ints(long *m,long *n);
long BaseValue(long base,long num);
long findMinBase(long num, unsigned int flag);

main()
{

	int base1,base2;

	int i, L, K;
	int count = 1,flag;
	
	unsigned int found = 0;
	
	/* scanf("%d",&count); */
	index=0;
	for(index=0;index<count;index++)
	{
		/* if(index==0)
			count = 0; */
		inputData[index].charFlagM = 0;
		inputData[index].charFlagN = 0;
		flag = get_ints(&inputData[index].M,&inputData[index].N);
		
		/* Find the smallest base of the numbers based on 
		   the type of input (character or number) */
		inputData[index].minBaseM = findMinBase(inputData[index].M,inputData[index].charFlagM);
		inputData[index].minBaseN = findMinBase(inputData[index].N,inputData[index].charFlagN);

		/* Find the different base values of the numbers */
		for(i=inputData[index].minBaseM;i<37;i++)
		{
			/* If the input is a character then it has the same vaue in all bases */
			if(inputData[index].charFlagM)
			{
				inputData[index].BaseValOfM[i] = inputData[index].M;
			}
			/* else calculate the values in different bases */
			else
			{
				inputData[index].BaseValOfM[i] = BaseValue(i,inputData[index].M);
			}
		}
		for(i=inputData[index].minBaseN;i<37;i++)
		{
			/* If the input is a character then it has the same vaue in all bases */
			if(inputData[index].charFlagN)
			{
				inputData[index].BaseValOfN[i] = inputData[index].N;
			}
			/* else calculate the values in different bases */
			else
			{
				inputData[index].BaseValOfN[i] = BaseValue(i,inputData[index].N);
			}
		}
		if(!flag)
		{
			index=count;
			break;
		}
		else
		{
			count++;
		}
	}
	count;
	for(K=0;K<count;K++)
	{
		found = 0;
		for(i=inputData[K].minBaseM;i<37;i++)
		{
			for(L=inputData[K].minBaseN;L<37;L++)
			{
				if(inputData[K].BaseValOfM[i] == inputData[K].BaseValOfN[L])
				{
					found = 1;
					base1 = i;
					base2 = L;
					break;
				}
			}
			if(found)
				break;
		}
		if(found)
		{
			/* format output as per input types  */
			if( (inputData[K].charFlagM == 1) && (inputData[K].charFlagN == 1) )
				printf("%c (base %ld) = %c (base %d)\n",inputData[K].M + 'A' - 10,base1,inputData[K].N + 'A' - 10,base2);
			else if( (inputData[K].charFlagM == 1) && (inputData[K].charFlagN == 0) )
				printf("%c (base %ld) = %ld (base %d)\n",inputData[K].M + 'A' - 10,base1,inputData[K].N,base2);
			else if( (inputData[K].charFlagM == 0) && (inputData[K].charFlagN == 1) )
				printf("%ld (base %ld) = %c (base %ld)\n",inputData[K].M,base1,inputData[K].N + 'A' - 10,base2);
			else
				printf("%ld (base %ld) = %ld (base %ld)\n",inputData[K].M,base1,inputData[K].N,base2);
		}
		else
		{
			/* format output as per input types  */
			if( (inputData[K].charFlagM == 1) && (inputData[K].charFlagN == 1) )
				printf("%c is not equal to %c in any base 2..36\n",inputData[K].M + 'A' - 10,inputData[K].N + 'A' - 10);
			else if( (inputData[K].charFlagM == 1) && (inputData[K].charFlagN == 0) )
				printf("%c is not equal to %ld in any base 2..36\n",inputData[K].M + 'A' - 10,inputData[K].N);
			else if( (inputData[K].charFlagM == 0) && (inputData[K].charFlagN == 1) )
				printf("%ld is not equal to %c in any base 2..36\n",inputData[K].M,inputData[K].N + 'A' - 10);
			else
				printf("%ld is not equal to %ld in any base 2..36\n",inputData[K].M,inputData[K].N);
		}
	}


	return 0;
}

/* Find the minimum base */
long findMinBase(long num,unsigned int flag)
{
	long base = 2;
	long quo,rem;

	if(flag)
	{
		if( (num>=10) && (num<=35) )
		{
			base = num+1;
			return base;
		}
	}
	else
	{
		quo = num;
		while(quo != 0)
		{
			rem = quo % 10;
			if(rem >= base)
				base = rem + 1;
			quo = quo / 10;
		}
	}
	return base;
}

/* return two integers  */
long get_ints(long *m,long *n)
{
	int ch;

	/* ignore the leading blanks */
	while( isspace(ch = getchar()) );

	/* save the first number */
	if(isdigit(ch))
	{
		for( *m=0;isdigit(ch);ch=getchar() )
			*m = 10 * (*m) + (ch - '0');
	}
	else if(isalpha(ch) && isupper(ch))
	{
		*m = 10 + ch - 'A';
		inputData[index].charFlagM = 1;
	}
	
	/* ignore the middle blanks */
	while( isspace(ch = getchar()) );

	/* save teh second number  */
	if(isdigit(ch))
	{
		for( *n=0;isdigit(ch);ch=getchar() )
			*n = 10 * (*n) + (ch - '0');
	}
	else if(isalpha(ch) && isupper(ch))
	{
		inputData[index].charFlagN = 1;
		*n = 10 + ch - 'A';
	}
	if(ch==EOF)
	{
		/* printf("\nEOF\n"); */
		return 0;
	}
	else
		return 1;
}

long BaseValue(long base,long num)
{
	int buf[20];
	long quo = 1, rem = 0;
	int i = 0;
	int n = 0;
	long sum = 0;
	/* extract the digits of the number */
	
	quo = num;
	while(quo!=0)
	{
		rem = quo%10;
		buf[i++] = rem;
		quo = quo/10;
	}
	n = i;

	/* calculate the value of the number in "base" system */
	for(i=0;i<n;i++)
	{
		sum = sum + buf[i]*power(base,i);
	}
	return sum;
}

/* return x (to the power) y */
long power(long x,long y)
{
	long sum = 1;
	int i=0;;
	for(i=0;i<y;i++)
	{
		sum = sum*x;
	}
	return sum;
}