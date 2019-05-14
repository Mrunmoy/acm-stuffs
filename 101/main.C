/* @JUDGE_ID: 59960OQ 101 C "Brute Force" */
/* Solution to ACM UVa Problem 101 - The Blocks Problem  */
/* Author- Mrunmoy Samal Copyright© Material*/
/* Date: 9th December 2007 */
/* If you are satisfied with the solution do
   send a mail to mrunmoy@yahoo.com */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define QUIT 3
#define MOVE 2
#define PILE 1

#define OVER 4
#define ONTO 5

/* A block must contain:
     - a block stack (of max 25 elements)
     - stack top pointer
     - block on which this block is currently stacked on
*/

struct block_tag
{
    int bStack[25];
    char top;
    char curBlkNum;
    int numElem;
};

typedef struct block_tag aBLOCK;

aBLOCK BLOCKS[25];

int numBlocks;
char cmd1,cmd2;
char cmdA[5],cmdB[5];
int blkA,blkB;

void display(void);
void getCmdTokens(char *cmd);

/* main entry point of the code */
int main()
{
    char get_ip;
    char cmd[18];
    int i,j,k;
    int a,b;
    int orgBlk;
	int match;

    get_ip = 1;

    scanf("%d",&numBlocks);

    for(i=0;i<numBlocks;i++)
    {
        BLOCKS[i].bStack[0] = BLOCKS[i].curBlkNum = i;
        for(j=1;j<numBlocks;j++)
        {
            BLOCKS[i].bStack[j] = 0;
        }
        BLOCKS[i].top = 0;
        BLOCKS[i].numElem = 1;
    }

    while( (get_ip==1) && (scanf("%[^\n]",cmd)==1) )
    {
         //display();
         //fflush(stdin);
         //scanf("%[^\n]",cmd);
         getCmdTokens(cmd);
         i = j = k = 0;
		 match = 0;
		 b = BLOCKS[blkB].curBlkNum;
		 a = BLOCKS[blkA].curBlkNum;
		 
		 if( (a==b) || (blkA==blkB) )
		 {
			 if(cmd1 == QUIT)
			 {
				 get_ip = 0;
				 display();
			 }
		 }
		 else
		 {
			 switch(cmd1)
			 {
				 case QUIT:
					{
						get_ip = 0;
						break;
					}
				 case MOVE:
					{
						switch(cmd2)
						{
							case ONTO:
								{
									for(i=BLOCKS[b].top;(i>=0) && (match==0);i--)
									{
										orgBlk = BLOCKS[b].bStack[i];
										if(blkB != orgBlk)
										{
											BLOCKS[orgBlk].bStack[0] = orgBlk;
											BLOCKS[orgBlk].top = 0;
											BLOCKS[orgBlk].curBlkNum = orgBlk;
											BLOCKS[b].top--;
										}
										else if(blkB == orgBlk)
										{
											for(j=BLOCKS[a].top;(j>=0) && (match==0);j--)
											{
												orgBlk = BLOCKS[a].bStack[j];
												if(blkA != orgBlk)
												{
													BLOCKS[orgBlk].bStack[0] = orgBlk;
													BLOCKS[orgBlk].top = 0;
													BLOCKS[orgBlk].curBlkNum = orgBlk;
													BLOCKS[a].top--;
												}
												else if(blkA == orgBlk)
												{
													BLOCKS[b].top++;
													BLOCKS[b].bStack[BLOCKS[b].top] = blkA;
													BLOCKS[a].bStack[BLOCKS[a].top] = 0;
													BLOCKS[a].top--;
													BLOCKS[blkA].curBlkNum = b;
													match = 1;
												}
											}
										}
									}
									break;
								}
							case OVER:
								{
											for(j=BLOCKS[a].top;(j>=0) && (match==0);j--)
											{
												orgBlk = BLOCKS[a].bStack[j];
												if(blkA != orgBlk)
												{
													BLOCKS[orgBlk].bStack[0] = orgBlk;
													BLOCKS[orgBlk].top = 0;
													BLOCKS[orgBlk].curBlkNum = orgBlk;
													BLOCKS[a].top--;
												}
												else if(blkA == orgBlk)
												{
													BLOCKS[b].top++;
													BLOCKS[b].bStack[BLOCKS[b].top] = blkA;
													BLOCKS[a].bStack[BLOCKS[a].top] = 0;
													BLOCKS[a].top--;
													BLOCKS[blkA].curBlkNum = b;
													match = 1;
												}
											}
											break;
								}
						}
						break;
					}
				 case PILE:
					{
						switch(cmd2)
						{
							case ONTO:
								{
									for(i=BLOCKS[b].top;(i>=0) && (match==0);i--)
									{
										orgBlk = BLOCKS[b].bStack[i];
										if(blkB != orgBlk)
										{
											BLOCKS[orgBlk].bStack[0] = orgBlk;
											BLOCKS[orgBlk].top = 0;
											BLOCKS[orgBlk].curBlkNum = orgBlk;
											BLOCKS[b].top--;
										}
										else if(blkB == orgBlk)
										{
											for(j=BLOCKS[a].top;(j>=0) && (match==0);j--)
											{
												orgBlk = BLOCKS[a].bStack[j];
												if(blkA != orgBlk)
												{
													;
												}
												else if(blkA == orgBlk)
												{
													for(k=j;k<=BLOCKS[a].top;k++)
													{
														BLOCKS[b].top++;
														BLOCKS[b].bStack[BLOCKS[b].top] = BLOCKS[a].bStack[k];
														BLOCKS[BLOCKS[a].bStack[k]].curBlkNum = b;
														BLOCKS[a].bStack[k] = 0;
													}
													match = 1;
													BLOCKS[a].top = j-1;
												}
											}
										}
									}
									break;
								}
							case OVER:
								{
											for(j=BLOCKS[a].top;(j>=0) && (match==0);j--)
											{
												orgBlk = BLOCKS[a].bStack[j];
												if(blkA != orgBlk)
												{
													;
												}
												else if(blkA == orgBlk)
												{
													for(k=j;k<=BLOCKS[a].top;k++)
													{
														BLOCKS[b].top++;
														BLOCKS[b].bStack[BLOCKS[b].top] = BLOCKS[a].bStack[k];
														BLOCKS[BLOCKS[a].bStack[k]].curBlkNum = b;
														BLOCKS[a].bStack[k] = 0;
													}
													match = 1;
													BLOCKS[a].top = j-1;
												}
											}
											 break;
								}
						}
						break;
					}
			 }
         }
    }

    return 0;
}

void display(void)
{
    int i,j;
    for(i=0;i<numBlocks;i++)
    {
        printf("%d: ",i);
        for(j=0;j<=BLOCKS[i].top;j++)
        {
			printf("%d ",BLOCKS[i].bStack[j]);
        }
        printf("\n");
    }
    printf("\n");
}

void getCmdTokens(char *cmd)
{
    sscanf(cmd,"%s %d %s %d",&cmdA,&blkA,&cmdB,&blkB);

	if( strcmp(cmdA,"quit")==0 )
    {
        cmd1 = QUIT;
        return;
    }
    else if( strcmp(cmdA,"move")==0 )
    {
        cmd1 = MOVE;
    }
    else if( strcmp(cmdA,"pile")==0 )
    {
        cmd1 = PILE;
    }

    if( strcmp(cmdB,"onto")==0 )
    {
        cmd2 = ONTO;
    }
    else if( strcmp(cmdB,"over")==0 )
    {
        cmd2 = OVER;
    }
}
