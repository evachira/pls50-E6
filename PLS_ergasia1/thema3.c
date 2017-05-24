#include <stdio.h>
int main()
{
  int num, a, b, c;
  const int t = 2; //dilosi statheras two me timi isi me 2, san const metavliti
  do
    {
       // Dinoume possetive number
       printf("Please give a possetive number\n");
       scanf("%d", &num);
       // check if number is zero or negative and dislay the appropriate message of mistake
       if (num < 0 )
          printf("Wrong number. Prlease give a positive one\n");
    }
  //if the number is possetive
  while(num<= 0);
    //Put the number in metavliti a
    a = num;

  // if number is diaforetikos tou 0
  while (a != 0)
    {
      //Put in metavliti b to ypolipo diairesis tou number me to 2.
      b = a % t;

      //to piliko tis diairesis tou number me to 2 kataxorite jana stin metavliti a.
      a = a /t;

      //Put 0 or 1 stin metavliti c so as to print with putchar.
      //Print number from less important psifio to more important psifio.
           c = ((b == 1) ? 1 : 0);
           putchar('0' + c);
    }
}

