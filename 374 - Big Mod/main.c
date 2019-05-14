/* Solution to ACM UVa Problem 374 - Big Mod */
/* Author - Mrunmoy Samal Copyright© Material*/
/* Date: 11th April 2007 */
/* If you are satisfied with the solution do 
   send a mail to mrunmoy@yahoo.com */

#include <stdio.h>
#include <ctype.h>

/* main entry point of the code */
main()
{
	/* Function declarations */
	unsigned long bigMod(long b, long p, long m);
    unsigned long r,b,p;
    long m;
    
    while(scanf("%lu%lu%ld",&b,&p,&m)==3)
    {
        r = bigMod(b,p,m);
		/* Print the output*/
        printf("%lu\n",r);
	}
	return 0;
}

/* calculate the big mod  */
unsigned long bigMod(long b, long p, long m)
{
    unsigned long t;
    if(p == 0)
		return 1;
	else if(p%2 == 0)
	{
		t = bigMod(b,p/2,m);
        return ((t*t) % m);
    }
	else
		return ( ((b%m) * bigMod(b,p-1,m)) % m);
}
