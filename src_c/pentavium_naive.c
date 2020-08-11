#include <stdio.h>
#include <time.h>
#include "len.h"

typedef unsigned int u32;
typedef unsigned char u8;

int ca_rule_order[8] = {2, 0, 1, 3, 0, 2, 3, 1};
short int five_neighborhood_CA[4][2][2][2][2][2];
/**
 * CAvium rules
 * 0 --> 1721342310
 * 1 --> 2523490710
 * 2 --> 1452976485
 * 3 --> 1520018790
 */
int tabulate_five_neighborhood_CA(){
	for(short int j=0;j<2;++j){
		for(short int k=0;k<2;++k){
			for(short int l=0;l<2;++l){
				for(short int m=0;m<2;++m){
					for(short int n=0;n<2;++n){
						for(short int i=0;i<4;++i){
							if(i == 0)
								five_neighborhood_CA[i][j][k][l][m][n] = j ^ k ^ m ^ n;
							else if(i == 1)
								five_neighborhood_CA[i][j][k][l][m][n] = j ^ k ^ l ^ m ^ n;
							else if(i == 2)
								five_neighborhood_CA[i][j][k][l][m][n] = n ^ (m & l) ^ (m & k) ^ l ^ j ^ 1;
							else if(i == 3)
								five_neighborhood_CA[i][j][k][l][m][n] = n ^ (m & k) ^ (l & k) ^ k ^ j;
						}
					}
				}
			}
		}
	}
}

void apply_to_5CA_blocks(int* reg, int* temp_reg, int len){
	for(int i=0;i<len-1;i++){
		int rule_number = ca_rule_order[i % 8];
		if(i== 0)
			temp_reg[i] = five_neighborhood_CA[rule_number][0][0][reg[i]][reg[i+1]][reg[i+2]];
		else if(i== 1)
			temp_reg[i] = five_neighborhood_CA[rule_number][0][reg[i-1]][reg[i]][reg[i+1]][reg[i+2]];
		else if(i== (len - 2))
			temp_reg[i] = five_neighborhood_CA[rule_number][reg[i-2]][reg[i-1]][reg[i]][reg[i+1]][0];
		else
			temp_reg[i] = five_neighborhood_CA[rule_number][reg[i-2]][reg[i-1]][reg[i]][reg[i+1]][reg[i+2]];
	}
}

void pentavium_keystream_generation(int* keystream, int* key, int* iv, long long int iterations){
	int i, j, t1, t2, t3;
	int a[A_LEN];
	int b[B_LEN];
	int c[C_LEN];
	int temp_a[A_LEN];
	int temp_b[B_LEN];
	int temp_c[C_LEN];
	clock_t start_time;
	clock_t init_phase_time;
	clock_t keygen_phase_time;
	long double diff = 0.0;

	//Create look up table
	tabulate_five_neighborhood_CA();

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
	for(i=1;i<=PENTAVIUM_INIT_LEN;++i){
		// Update
		t1 = a[65] ^ a[92];
		t2 = b[68] ^ b[83];
		t3 = c[65] ^ c[110];
		t1 = t1 ^ (a[90] & a[91]) ^ b[76];
		t2 = t2 ^ (b[81] & b[82]) ^ c[87];
		t3 = t3 ^ (c[109] & c[110]) ^ a[68];

		// Apply CA
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
	init_phase_time = clock();
	diff = (long double)(init_phase_time - start_time)/(long double)(CLOCKS_PER_SEC);
	printf("Initialization phase time: %.9Lf seconds  Iteration:%d \n", diff, PENTAVIUM_INIT_LEN);

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

		// Apply CA
		apply_to_5CA_blocks(a, temp_a, A_LEN);
		apply_to_5CA_blocks(b, temp_b, B_LEN);
		apply_to_5CA_blocks(c, temp_c, C_LEN);

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
	keygen_phase_time = clock();
	diff = (long double)(keygen_phase_time - start_time)/(long double)(CLOCKS_PER_SEC);
	printf("Keystream generation phase time: %.9Lf seconds  Iteration:%lld\n", diff, iterations);
}
