/* @JUDGE_ID: 59960OQ 495 C "Brute Force" */

/* Solution to ACM UVa Problem 495 - Fibonacci Freeze */
/* Author- Mrunmoy Samal*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1050

char result[MAX_SIZE];
char sum[MAX_SIZE];
char prev[MAX_SIZE];
struct struct_tag
{
    char LookUp[5001][MAX_SIZE];
    char done[5001];
}LookUpTable;

char stored_fib[15][1050] = {
"12586269025"
,
"354224848179261915075"
,
"280571172992510140037611932413038677189525"
,
"222232244629420445529739893461909967206666939096499764990979600"
,
"176023680645013966468226945392411250770384383304492191886725992\
896575345044216019675"
,
"139423224561697880139724382870407283950070256587697307264108962\
948325571622863290691557658876222521294125"
,
"110433070572952242346432246767718285942590237357555606380008891\
875277701705731473925618404421867819924194229142447517901959200"
,
"874708149557528462039784130175713273423672409676973810742304325\
925275019112903776556282271508784273316931933691091936723307775\
27943718169105124275"
,
"6928308186422471713629007768132851827339912438520482071896604059\
7691435587278383112277161967532530675374170857404743017623467220\
361778016172106855838975759985190398725"
,
"54877108839480000051413673948383714443800519309123592724494953427\
03981120106434123495438752152539061550494909218744121824667910473\
1442473022013980160407007017175697317900483275246652938800"
,
"4346655768693745643568852767504062580256466051737178040248172908\
9536555417949051890403879840079255169295922593080322634775209689\
6232398733224711616429964409065331879382989696499285160037044761\
37795166849228875"
,
"4224696333392304878706725602341482782579852840250681098010280137\
3143085843701307072241235996391415110884460875389096036076401947\
1164359602927198331259873732625355580260699158591522949245390499\
8722256795316982874482472992263901833716778060607011615497886719\
8798583114688708762645973690867228840236544222952433479644801395\
1534956297208765265606952980649984197744872015561280266540455417\
1717881930324025204312082516817125"
,
"4106158863079712603335683787192671052201251086373692524088854309\
2690558427411340373133049166085004456083003683570694227458856936\
2145476502674373045446852160486606292497360503469773453733196887\
4058472552900820490869075126220590545421958897580311092226708492\
7479385953913331837124479554314761107327624006673793408519173181\
0993201706776838934766764778739502174470268627820918553842225858\
3064083016618629003582668572382102358025043519514729979196765240\
0478423637645334726836415264834624584057321424141993791724291860\
2639810097866942392015404620153818671425739835074851396421139982\
713640679581178458198658692285968043243656709796000"
,
"3990947343500442279208124809496091260079257098282025785262887632\
6523051818641373433549136769424132442293969306537520118273879628\
0254432353703622509554356541715928979667908648144582231419142725\
9089746847218037063969533444966265031287473556092629824624940416\
8309064214351044459077749425236777660809226095151852052781352975\
4494825658383698091837717874396608251405028243431319117112963924\
5713886748659392354417789373542860223821224915656463145250765860\
3400012003685322984838488962351492632577755354452904049241294565\
6625194172350200498738738786027313792078932123354234848734690830\
5455632989416726281869259981520958251727796505906823554313945937\
5028276851221435815957374273143824422909416395375178739268544368\
1268942409791353221760803747809980106577107756258560415940784954\
1172423656024259775918554382479833246791961359866700302599371527\
4875"
,
"3878968454388325633701916308325905312082127714646245106160597214\
8955501390440370970108229164622106694792934528588829738134831020\
0895498294036143015691147893836421656394410691021450563413370655\
8656238254656700712525929903854933813928836378347518908762970712\
0333370529231076930085180938498018038478139967488817655546537882\
9164426891298038461377896902150229308247566634622492307188332480\
3280375039130352903304505842701147635242270210934637699104006714\
1748832984228914912731040543287532980442736768229772449877498745\
5569190770388063704683279481135897373999311010621930814901857081\
5397854379195305617510761053075688783766033667355445258844886241\
6192105534574936758978490279882343510235998446639348532564119522\
2185956306047536464547076033090242080638258492915645287629157575\
9142343809142302917491088984155209854432486594079793571316841692\
8680395453095453886981146650820668628974206393234384884652409887\
4239587380197699382031717420893226546887936400263079778005875912\
967138963421425257911687275560036031137054775472460463998758804\
6985178408674382863125"
};

int firsttime = 1;

void add(int fn,int fn_1,int fn_2,char ch);

int main()
{
    int fib; //  0 <= n <= 5000
    int i,j;
    char *ptrSrc,*ptrTgt,*ptrTgt2;
    //clock_t start = clock();

    // set done to zero first.
    memset(LookUpTable.done, '0',5000);
    // Initialize minimum known fibonaccis
    LookUpTable.LookUp[0][0] = '0';LookUpTable.LookUp[0][1] = '\0';
    LookUpTable.done[0] = 1;
    LookUpTable.LookUp[1][0] = '1';LookUpTable.LookUp[1][1] = '\0';
    LookUpTable.done[1] = 1;
    LookUpTable.LookUp[2][0] = '1';LookUpTable.LookUp[2][1] = '\0';
    LookUpTable.done[2] = 1;
    ptrSrc = stored_fib[0];
    ptrTgt = LookUpTable.LookUp[50];
    while(*ptrTgt++=*ptrSrc++);
    LookUpTable.done[50] = 1;
    for(i=100,j=1;i<=1000;i+=100,j++)
    {
        ptrSrc = stored_fib[j];
        ptrTgt = LookUpTable.LookUp[i];
        while(*ptrTgt++=*ptrSrc++);
        LookUpTable.done[i] = 1;
    }
    for(i=2000,j=11;i<=5000;i+=1000,j++)
    {
        ptrSrc = stored_fib[j];
        ptrTgt = LookUpTable.LookUp[i];
        while(*ptrTgt++=*ptrSrc++);
        LookUpTable.done[i] = 1;
    }

    while( scanf("%d",&fib)==1 )
    {
        if(fib==0) // special case fib(0)
        {
            printf("The Fibonacci number for 0 is 0\n");

        }
        else if((fib==1) || (fib==2)) // special case fib(1), fib(2)
        {
            printf("The Fibonacci number for %d is 1\n",fib);
        }
        else // special cases of 100,200,300.. already calculated and stored for faster reference
             if( (fib==50)||(fib==100)||(fib==200)||(fib==300)||(fib==400)||
                 (fib==500)||(fib==600)||(fib==700)||(fib==800)||(fib==900)||
                 (fib==1000)||(fib==2000)||(fib==3000)||(fib==4000)||(fib==5000)
               )
        {
            printf("The Fibonacci number for %d is %s\n",fib,LookUpTable.LookUp[fib]);
        }
        else // other cases cacluate fib(n)
        {
            if(LookUpTable.done[fib] == 1) // if already available, display fib(n)
            {
               printf("The Fibonacci number for %d is %s\n",fib,LookUpTable.LookUp[fib]);
            }
            else
            {
                if( LookUpTable.done[fib-1] == 1 ) /* if f(n-1) is available,
                                                   it means f(n-2) is also available */
                {
                    add(fib,fib-1,fib-2,'n');
                    LookUpTable.done[fib] = 1;
                    printf("The Fibonacci number for %d is %s\n",fib,LookUpTable.LookUp[fib]);
                }
                else if( LookUpTable.done[fib-2] == 1) /* if f(n-2) is available
                                                        calculate f(n-1) and f(n) */
                {
                    add(fib-1,fib-2,fib-3,'n');
                    LookUpTable.done[fib-1] = 1;
                    add(fib,fib-1,fib-2,'n');
                    LookUpTable.done[fib] = 1;
                    printf("The Fibonacci number for %d is %s\n",fib,LookUpTable.LookUp[fib]);
                }
                else // neither f(n-1) nor f(n-2) are available so calculate in normal iterative way
                {
                    firsttime=1;
                    result[0] = '1';
                    result[1] = '\0';
                    for(i=0;i<=fib;i++)
                    {
                        add(0,0,0,'i'); // sum = result + prev

                        ptrSrc = result;ptrTgt = prev;
                        while(*ptrTgt++=*ptrSrc++); // prev = result
                        ptrSrc = sum;ptrTgt = result;
                        ptrTgt2 = LookUpTable.LookUp[i];
                        while(*ptrTgt2++=*ptrTgt++=*ptrSrc++); // result = sum, fib(i) = sum
                        LookUpTable.done[i] = 1; // fib(i) available
                        firsttime = 0;
                    }
                    printf("The Fibonacci number for %d is %s\n",fib,result);
                }
            }
        }
    }
    /* Code you want timed here */
    //printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);    for(i=0;i<=5000;)

    return 0;
}

void add(int fn,int fn_1,int fn_2,char ch)
{
    int a;
    int b,len;
    int tot,u,carry;
    int i,j,k,len1,len2;
    char *ptr1,*ptr2,*ptr3;

    if(ch=='i')
    {
        if(firsttime == 1)
        {
            sum[0] = '0';
            sum[1] = '\0';
            return;
        }
        else
        {
            len1 = strlen(result) - 1;
            len2 = strlen(prev) - 1;
            if(len1>len2)
            {
                i = len1;
                j = len2;
                ptr1 = result;
                ptr2 = prev;
            }
            else
            {
                i = len2;
                j = len1;
                ptr1 = prev;
                ptr2 = result;
            }
            ptr3 = sum;
        }
    }
    else if(ch =='n')
    {
        ptr1 = LookUpTable.LookUp[fn_1];
        ptr2 = LookUpTable.LookUp[fn_2];
        i = strlen(ptr1) - 1;
        j = strlen(ptr2) - 1;
        ptr3 = LookUpTable.LookUp[fn];
    }
    //memset(ptr3, '0',MAX_SIZE);
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

