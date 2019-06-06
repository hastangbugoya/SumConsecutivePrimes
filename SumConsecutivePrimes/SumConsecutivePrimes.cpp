// SumConsecutivePrimes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

constexpr auto maxvalue = 1000;
constexpr auto sievesize = 1000;

int isprime(int n, int *sieve)
{
	int i;
	for (i = 2; n % i != 0 && i <= n / 2; i++);
	if (i > n / 2)
		return 1;
	else
		return 0;
}

long getnextprime(long n, int *sieve)
{
	n++;
	while (n < 49999 && !sieve[n])
		n++;
	return n;
}

int main()
{
	int primes[sievesize];
	int i, j;
	int startofseries, tailofseries;
	int longestseries = 0, startoflongest, tailoflongest;
	long sum = 0, largestsum = 0;
	long pointer, temp;
	int ctr;
	long long int x;

	for (i = 0; i < sievesize - 1; i++)
		primes[i] = 1;

	for (i = 2; i < sievesize - 1; i++)
	{
		if (primes[i])
		{
			for (j = 2; j * i <= sievesize - 1; j++)
				primes[j*i] = 0;
		}
	}

	for (i = 0; i < sievesize - 1; i++)
	{
		if (primes[i])
			printf("%d\t", i);
	}

	startofseries = 2;
	while (startofseries <= maxvalue)
	{
		ctr = 1;
		sum = startofseries;
		pointer = startofseries;
	
		while (sum <= maxvalue)
		{
			//if (isprime(sum, primes) && sum > largestsum && ctr > 1)
			if (isprime(sum, primes) && ctr > longestseries && ctr > 1)
			{
				longestseries = ctr;
				startoflongest = startofseries;
				tailofseries = pointer;
				largestsum = sum;
			}
			pointer = getnextprime(pointer, primes);
			sum = sum + pointer;
			ctr++;
		}
		temp = getnextprime(startofseries,primes);
		if (temp < sievesize)
			startofseries = temp;
		else
			break;
		printf("\n%d", startofseries);
	}
	printf("\nSUM            >>>> %d", largestsum);
	printf("\nSTARTS AT      >>>> %d", startoflongest);
	printf("\nPRIME NUMBERS  >>>> %d", longestseries);
	printf("\nLAST DIGIT     >>>> %d", tailofseries);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
