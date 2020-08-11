#include <stdio.h>
#include <time.h>
#include "len.h"

typedef unsigned int u32;
typedef unsigned char u8;

void trivium_keystream_generation(int* keystream, int* key, int* iv, long long int iterations){
	int i, j, t1, t2, t3;
	int a[A_LEN];
	int b[B_LEN];
	int c[C_LEN];
	clock_t start_time;
	clock_t init_phase_time;
	clock_t keygen_phase_time;
	long double diff = 0.0;

	// KEY and IV SETUP
	for(i=0;i<KEY_LEN;++i)
		a[i] = key[i];
	for(i=KEY_LEN;i<A_LEN;++i)
		a[i] = 0;
	for(i=0;i<IV_LEN;++i)
		b[i] = iv[i];
	for(i=IV_LEN;i<B_LEN;++i)
		b[i] = 0;
	for(i=0;i<C_LEN-3;++i)
		c[i] = 0;
	for(i=C_LEN-3;i<C_LEN;++i)
		c[i] = 1;

	// Initialization phase
	start_time = clock();
	for(i=1;i<=TRIVIUM_INIT_LEN;++i){
		// Update
		t1 = a[65] ^ a[92];
		t2 = b[68] ^ b[83];
		t3 = c[65] ^ c[110];
		t1 = t1 ^ (a[90] & a[91]) ^ b[76];
		t2 = t2 ^ (b[81] & b[82]) ^ c[87];
		t3 = t3 ^ (c[109] & c[110]) ^ a[68];

		// Rotate
		for(j=A_LEN-1;j>0;--j)
			a[j] = a[j-1];
		for(j=B_LEN-1;j>0;--j)
			b[j] = b[j-1];
		for(j=C_LEN-1;j>0;--j)
			c[j] = c[j-1];
		a[0] = t3;
		b[0] = t1;
		c[0] = t2;
	}
	init_phase_time = clock();
	diff = (long double)(init_phase_time - start_time)/(long double)(CLOCKS_PER_SEC);
	printf("Initialization phase time: %.9Lf seconds  Iteration:%d \n", diff, TRIVIUM_INIT_LEN);

	// Keystream generation phase
	start_time = clock();
	for(i=1;i<=iterations;++i){
		// Update
		t1 = a[65] ^ a[92];
		t2 = b[68] ^ b[83];
		t3 = c[65] ^ c[110];
		keystream[i-1] = t1 ^ t2 ^ t3;
		t1 = t1 ^ (a[90] & a[91]) ^ b[76];
		t2 = t2 ^ (b[81] & b[82]) ^ c[87];
		t3 = t3 ^ (c[109] & c[110]) ^ a[68];

		// Rotate
		for(j=A_LEN-1;j>0;--j)
			a[j] = a[j-1];
		for(j=B_LEN-1;j>0;--j)
			b[j] = b[j-1];
		for(j=C_LEN-1;j>0;--j)
			c[j] = c[j-1];
		a[0] = t3;
		b[0] = t1;
		c[0] = t2;
	}
	keygen_phase_time = clock();
	diff = (long double)(keygen_phase_time - start_time)/(long double)(CLOCKS_PER_SEC);
	printf("Keystream generation phase time: %.9Lf seconds  Iteration:%lld\n", diff, iterations);
}
