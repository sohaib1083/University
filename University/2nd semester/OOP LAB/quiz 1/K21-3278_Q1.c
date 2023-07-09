#include <stdio.h>
#include <string.h>

int checkprime (int n)
{
  int i, flag = 0;


  // 0 and 1 are not prime numbers
  // change flag to 1 for non-prime number
  if (n == 0 || n == 1){
    flag = 1;
  }
  else{
  for (i = 2; i <= n / 2; ++i) {

    // if n is divisible by i, then n is not prime
    // change flag to 1 for non-prime number
    if (n % i == 0) {
      flag = 1;
      break;
    }
  }
  }
  return flag;
}

int main (void)
{
	int i, dig, a;
	char name[50];
	int flag;
	
	fflush(stdin);
	fgets(name, sizeof(name) ,stdin);
	 
	for (i=0; i < strlen(name); i++)
	{
		flag = checkprime(i);
	
	 	if (flag == 0 && i%10 == 3)
	 	{
	 		*(name + i) = '$';
		}
	}
	
	puts(name);
	
	return 0;
}

