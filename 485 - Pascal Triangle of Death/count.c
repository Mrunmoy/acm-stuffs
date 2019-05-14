#include <stdio.h>

int main()
{
  long let, c;
  let = 0;
  while((c=getchar())!='\0')
  {
      if(','==c)
        ++let;
  }

  printf("%ld numbers\n", let);
  return 0;
}
