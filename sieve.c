#include <stdio.h>
#include <math.h>
#define MAX 1000000

int sieve[(MAX+7)/8];

static inline void set_composite(int value)
{
	sieve[value >> 3] &= ~(1<<(value & 7));
}

static inline int is_prime(int value)
{
	return sieve[value >> 3] & (1<<(value & 7));
}	

void eratosthness(int value)
{
	int sqrt_value;
	int i,j;
	sqrt_value = (int)sqrt(value);
	memset(sieve, 0xff, sizeof(value));
	for(i=2; i<=sqrt_value; i++){
		if(is_prime(i)){
			for(j=i*i;j<value;j+=i){
				set_composite(j);
			}
		}
	}
}
