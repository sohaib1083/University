#include<stdio.h>
#include<stdlib.h>

void reverse (int *intarray, int low, int high, int num)
{
	int temp;
	int i;
	if (low == high ){
		exit(0);
	}
	if (i >= low && i <high)
		temp = *(intarray + high);
		*(intarray + high) = *(intarray + low);
		*(intarray + low) = temp;
		low++;
		
		reverse(intarray, low, high, num);
	}
	
}


int main (void)
{
	int num, low, high;
	int *intarray;
	int i;
	
	printf("Enter lenght of array:");
	scanf("%d", &num);
	do{
	printf("Enter the lowest index:");
	scanf("%d", &low);	
	} while( low < 0 || low > num);

    do{
	printf("Enter the highest index:");
	scanf("%d", &high);
    }while(high < 0 || high <= low || high > num);
	
	intarray = (int *)malloc(num * sizeof(int));
	
	reverse(intarray, low, high, num);
	
	for (i=0; i<num; i++)
	{
		printf("%d, ", *(intarray=i));
	}
}
