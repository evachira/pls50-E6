#include<stdio.h>
int main()
{
  char oper;
  double num1,num2;
  printf("Dwse arithmo praji arithmo\n");
  scanf("%lf %c %lf", &num1, &oper, &num2);
  switch(oper)
  {
     case '+':
         printf("apotelesma = %.2lf", num1 + num2);
         break;
     case '-':
         printf("apotelesma = %.2lf", num1 - num2);
         break;
     case '*':
         printf("apotelesma = %.2lf", num1 * num2);
         break;
     case '/':
         if (num2!=0)
           printf("apotelesma = %.2lf",num1 / num2);
         else
           printf("Divide with zero is not allowed");
           break;
// Check for wrong operator prajis
     default:
         printf("Wrong operator. Please try again");
  }
  return 0;
}






