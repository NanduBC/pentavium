#include "trivium_naive.c"
#include "cavium_naive.c"
#include "pentavium_naive.c"

int main(){
	int key[80] = {0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1};
	int iv[80] = {0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0};
	static int keystream[1000];
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