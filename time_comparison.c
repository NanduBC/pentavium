#include <stdlib.h>
#include "src_c/trivium_naive.c"
#include "src_c/cavium_naive.c"
#include "src_c/pentavium_naive.c"

int main(int argc, char* argv[]){
	int key[80] = {0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1};
	int iv[80] = {0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0};
	int max_iterations = atoi(argv[1]);
	int keystream[max_iterations];
	printf("TRIVIUM C IMPLEMENTATION\n");
	trivium_keystream_generation(keystream, key, iv, sizeof(keystream)/sizeof(int));
	printf("Keystream generated\n");
	for(int i=0;i<100;++i){
		printf("%d", *(keystream+i));
	}
	printf("\n");

	printf("CAVIUM C IMPLEMENTATION\n");
	cavium_keystream_generation(keystream, key, iv, sizeof(keystream)/sizeof(int));
	printf("Keystream generated\n");
	for(int i=0;i<100;++i){
		printf("%d", *(keystream+i));
	}
	printf("\n");

	printf("PENTAVIUM C IMPLEMENTATION\n");
	pentavium_keystream_generation(keystream, key, iv, sizeof(keystream)/sizeof(int));
	printf("Keystream generated\n");
	for(int i=0;i<100;++i){
		printf("%d", *(keystream+i));
	}
	printf("\n");

	return 0;
}