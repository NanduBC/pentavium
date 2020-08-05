#include <stdio.h>
#include <time.h>

#define KEY_LEN 80
#define IV_LEN 80
#define A_LEN 93
#define B_LEN 84
#define C_LEN 111
#define INIT_LEN 1152

typedef unsigned int u32;
typedef unsigned char u8;

void trivium_keystream_generation(int* keystream, int* key, int* iv, long long int iterations){
	int i, j, t1, t2, t3;
	int a[A_LEN];
	int b[B_LEN];
	int c[C_LEN];
	clock_t start_time;
	clock_t curr_time;
	long double diff = 0.0;
	printf("%lld\n", iterations);

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

	start_time = clock();
	for(i=1;i<=iterations;++i){
		if (i==32 || i==144 || i==1152 ||i==iterations){
			curr_time = clock();
			diff = (long double)(curr_time- start_time)/(long double)(CLOCKS_PER_SEC);
			printf("Time taken for %d th iteration: %.9Lf seconds\n", i, diff);
		}
		//Update
		t1 = a[65] ^ a[92];
		t2 = b[68] ^ b[83];
		t3 = c[65] ^ c[110];
		keystream[i-1] = t1 ^ t2 ^ t3;
        t1 = t1 ^ (a[90] & a[91]) ^ b[76];
        t2 = t2 ^ (b[81] & b[82]) ^ c[87];
        t3 = t3 ^ (c[109] & c[110]) ^ a[68];

		//Rotate
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
}

int main(){
	int key[80] = {0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1};
	int iv[80] = {0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0};
	static int keystream[100000000];
	printf("TRIVIUM C IMPLEMENTATION\n\n");
	trivium_keystream_generation(keystream, key, iv, sizeof(keystream)/sizeof(int));
	printf("Keystream generated\n");
	for(int i=0;i<100;++i){
		printf("%d", *(keystream+i));
	}
	printf("\n");
	return 0;
}