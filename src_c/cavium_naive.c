#include <stdio.h>
#include <time.h>
#include "len.h"

typedef unsigned int u32;
typedef unsigned char u8;

/**
 * CAvium rules
 * 0 --> 30
 * 1 --> 60
 * 2 --> 90
 * 3 --> 120
 * 4 --> 150
 * 5 --> 180
 * 6 --> 210
 * 7 --> 240
 */
int three_neighborhood_CA(int s_minus_one, int s, int s_plus_one, int rule_number){
	int z = -1;
    if(rule_number == 0)
        z = s_minus_one ^ s ^ s_plus_one ^ (s & s_plus_one);
    else if(rule_number == 1)
        z = s_minus_one ^ s;
    else if(rule_number == 2)
        z = s_minus_one ^ s_plus_one;
    else if(rule_number == 3)
        z = s_minus_one ^ (s & s_plus_one);
    else if(rule_number == 4)
        z = s_minus_one ^ s ^ s_plus_one;
    else if(rule_number == 5)
        z = s_minus_one ^ s ^ (s & s_plus_one);
    else if(rule_number == 6)
        z = s_minus_one ^ s_plus_one ^ (s & s_plus_one);
    else if(rule_number == 7)
        z = s_minus_one;
	else
		printf("Invalid rule_number");
	return z;
}

void apply_to_3CA_blocks(int* reg, int* temp_reg, int len){
	for(int i=0;i<len;i++){
		if(i==0)
			temp_reg[i] = three_neighborhood_CA(0, reg[i], reg[i+1], i%8);
		else
			temp_reg[i] = three_neighborhood_CA(reg[i-1], reg[i], reg[i+1], i%8);
	}
}

void cavium_keystream_generation(int* keystream, int* key, int* iv, long long int iterations){
	int i, j, t1, t2, t3;
	int a[A_LEN];
	int b[B_LEN];
	int c[C_LEN];
	int temp_a[A_LEN];
	int temp_b[B_LEN];
	int temp_c[C_LEN];
	clock_t start_time;
	clock_t curr_time;
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

		//Appy CA
		apply_to_3CA_blocks(a, temp_a, A_LEN);
		apply_to_3CA_blocks(b, temp_b, B_LEN);
		apply_to_3CA_blocks(c, temp_c, C_LEN);

		for(j=1;j<A_LEN;++j)
			a[j] = temp_a[j-1];
		for(j=1;j<B_LEN;++j)
			b[j] = temp_b[j-1];
		for(j=1;j<C_LEN;++j)
			c[j] = temp_c[j-1];
		a[0] = t3;
		b[0] = t1;
		c[0] = t2;
	}
}
