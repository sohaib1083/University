#include <stdio.h>

// proto-types
int add(int x , int y);

int sub(int x , int y);

int mul(int x , int y);

int div(int x , int y);



int main()
{
	int x = 0 , y = 0 , result = 0 , input = 0;
	
	int (*cal[5])(int , int) = { 0 , add , sub , mul , div };
	

	printf("\n\tPress 1 for Addition\n\tPress 2 for Substraction\n\tPress 3 for Multiplication\n\tPress 4 for Division\n\tPress 5 for Exit\n");
	scanf("%d" , &input) ;
	
	if (input >= 1 && input <= 4)
	{
		printf("Please Enter Two Numbers: ");
		scanf("%d%d" , &x , &y);
		
		result = cal[input](x , y);
		
		if (input == 1)
		{
		printf("The Addition of %d + %d is : %d\n" , x , y ,  result) ;
		}
		else if (input == 2)
		{
		printf("The Subtraction of %d - %d is : %d\n" , x , y ,  result) ;
		}
		else if (input == 3)
		{
		printf("The Muliplication of %d * %d is : %d\n" , x , y ,  result) ;
		}
		else if (input == 4)
		{
		printf("The Division of %d / %d is : %d\n" , x , y ,  result) ;
		}
	}
	else if (input == 5)
	{
		printf("Exiting............\n");
	}
	else if (input == 0)
	{
		printf("Exiting.............\n");
	}
	else 
	{
		printf("Wrong input.......\n");
	}
}

int add(int x , int y)
{
	return x + y;
}
int sub(int x , int y)
{
	return x - y;
}
int mul(int x , int y)
{
	return x * y;
}
int div(int x , int y)
{
	return x / y;
}
