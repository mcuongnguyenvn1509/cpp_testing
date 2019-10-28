#include <stdio.h>
int main()
{
   int var1, var2;
   printf("Input the value of var1:");
   scanf("%d", &var1);
   printf("Input the value of var2:");
   scanf("%d",&var2);
   if (var1 != var2)
   {
	printf("var1 is not equal to var2\n");
	//Nested if else
	if (var1 > var2)
	{
		printf("var1 is greater than var2\n");
	}
	else
	{
		printf("var2 is greater than var1\n");
	}
   }
   else
   {
	printf("var1 is equal to var2\n");
   }
   return 0;
}


#include<stdio.h>

int main()
{
	 int num1, num2, num3;
	 printf("Enter three numbers:\n");
	 scanf("%d%d%d",&num1, &num2, &num3);
	 if(num1>num2)
	 {
		  /* This is nested if-else */
		  if(num1>num3)
		  {
		   	printf("Largest = %d", num1);
		  }
		  else
		  {
		   	printf("Largest = %d", num3);
		  }
	 }
	 else
	 {
		  /* This is nested if-else */
		  if(num2>num3)
		  {
		   	printf("Largest = %d", num2);
		  }
		  else
		  {
		   	printf("Largest = %d", num3);
		  }
	 }
	 return(0);
}
