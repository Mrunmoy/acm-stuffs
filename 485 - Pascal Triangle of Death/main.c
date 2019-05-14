/* @JUDGE_ID: 59960OQ 495 C "Brute Force" */

/* Solution to ACM UVa Problem 485 - Pascal Triangle ofDeath */
/* Author - Mrunmoy Samal */
/* Date: 16th december 2007 */
/* If you are satisfied with the solution do 
   send a mail to mrunmoy@yahoo.com */

#include <stdio.h>
#include <ctype.h>

#define sizeMax 99
/* definition of long integer of 100 digits */
typedef unsigned int LongInteger[sizeMax + 1];

LongInteger TerminatingValue;
//LongInteger PrevRow[];
//LongInteger CurRow[];
/* Addition of two long integers*/
//LongInteger Add(LongInteger a,LongInteger b);
/* Multiplication of two long integers*/
//LongInteger Mul(LongInteger a,LongInteger b);

/* main entry point of the code */
main()
{
	void genPascal(void);

	genPascal();

	return 0;
}

/* Generate Pascal's Triangle */
void genPascal(void)
{
	void copyRow(long *src,long *dest);
	
	int exitFlag = 0;
	int row,col,idx;
	unsigned long prevRow[100],curRow[100];
	//LongInteger series;
	long sum = 0;
	for(idx = 0;idx<sizeMax;idx++)
	{
		if(idx == 0)
			prevRow[idx] = curRow[idx] = 1L;
		else
			prevRow[idx] = curRow[idx] = 0L;
	}
	row = 0;
	while(!exitFlag)
	{
		/* row 0, column 0*/
		if(row==0)
			printf("1\n");
		else
		{
			/* row 1...k, columns 0..(row+1) */
			for(col=0;col<=row;col++)
			{
				/* First column */
				if(col==0)
				{
					printf("1 ");
					curRow[col] = 1;
				}
				/* Last column */
				else if(col==row)
				{
					printf("1\n");
					curRow[col] = 1;
				}
				/* Middle Columns */
				else
				{
					/* value at this point is the sum of the two numbers above it */
					sum = prevRow[col-1] + prevRow[col];
					if(sum>1000000L)
					{
						exitFlag = 1;
						break;
					}
					curRow[col] = sum;
					printf("%-ld ",curRow[col]);
				}
				if(exitFlag)
					break;
			}
		}
		copyRow(curRow,prevRow);
		row++;
	}
}

void copyRow(long *src,long *dest)
{
	int i;
	for(i=0;i<sizeMax;i++)
	{
		dest[i] = src[i];
	}
}
/* Addition of two long integers
//LongInteger Add(LongInteger a,LongInteger b)
{
	LargeInteger res;
	int carry = 0;
	int i;

	for(i=sizeMax;i>=0;i--)
	{
		c = a[i] + b[i] + carry;
		if(c>=10)
		{
			carry = 1;
			res[i] = c % 10;
		}
		else
		{
			carry = 0;
		    res[i] = c;
		}
	}
	return res;
}
Multiplication of two long integers
//LongInteger Mul(LongInteger a,LongInteger b)
{
	
	return res;
}
*/