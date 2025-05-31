#include<stdio.h>
#include<stdlib.h>

struct pixel
{
	int red;
	int green;
	int blue;
};


int main (void)
{
	
	struct pixel a[3][5];
	int i, j;
	
	for (i=0; i<3; i++)
	{
		for (j=0; j<5; j++)
		{
			a[i][j].blue = rand()%255;
			a[i][j].green = rand()%255;
			a[i][j].red= rand()%255;	
		}
	}
	
printf("*******original image**********\n");

	
	// printing
	for (i=0; i<3; i++)
	{
		for (j=0; j<5; j++)
		{
			printf(" (%d,%d,%d) ", a[i][j].blue, a[i][j].green, a[i][j].red);	
		}
		printf("\n");
	}

printf("\n\n");

struct pixel b[3][5];



// storing in the second array
	for (i=0; i<3; i++)
	{
		for (j=0; j<5; j++)
		{
			b[i][j].blue = a[i][j].blue;
			b[i][j].green = a[i][j].green;
			b[i][j].red = a[i][j].red;	
		}
	}


printf("******* Rotated image**********\n");

	// printing
	for (i=0; i<5; i++)
	{
		for (j=0; j<3; j++)
		{
			printf(" (%d,%d,%d) ", b[j][i].blue, b[j][i].green, b[j][i].red);	
		}
		printf("\n");
	}	



	
}
