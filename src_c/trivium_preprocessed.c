# 1 "trivium.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "trivium.c"
# 11 "trivium.c"
# 1 "ecrypt-sync.h" 1
# 13 "ecrypt-sync.h"
# 1 "ecrypt-portable.h" 1
# 23 "ecrypt-portable.h"
# 1 "ecrypt-config.h" 1
# 66 "ecrypt-config.h"
# 1 "/usr/lib/gcc/x86_64-linux-gnu/7/include-fixed/limits.h" 1 3 4
# 34 "/usr/lib/gcc/x86_64-linux-gnu/7/include-fixed/limits.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/7/include-fixed/syslimits.h" 1 3 4






# 1 "/usr/lib/gcc/x86_64-linux-gnu/7/include-fixed/limits.h" 1 3 4
# 194 "/usr/lib/gcc/x86_64-linux-gnu/7/include-fixed/limits.h" 3 4
# 1 "/usr/include/limits.h" 1 3 4
# 26 "/usr/include/limits.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 33 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 424 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 427 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 428 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 429 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 425 "/usr/include/features.h" 2 3 4
# 448 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 449 "/usr/include/features.h" 2 3 4
# 34 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 2 3 4
# 27 "/usr/include/limits.h" 2 3 4
# 183 "/usr/include/limits.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/posix1_lim.h" 1 3 4
# 160 "/usr/include/x86_64-linux-gnu/bits/posix1_lim.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/local_lim.h" 1 3 4
# 38 "/usr/include/x86_64-linux-gnu/bits/local_lim.h" 3 4
# 1 "/usr/include/linux/limits.h" 1 3 4
# 39 "/usr/include/x86_64-linux-gnu/bits/local_lim.h" 2 3 4
# 161 "/usr/include/x86_64-linux-gnu/bits/posix1_lim.h" 2 3 4
# 184 "/usr/include/limits.h" 2 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/posix2_lim.h" 1 3 4
# 188 "/usr/include/limits.h" 2 3 4
# 195 "/usr/lib/gcc/x86_64-linux-gnu/7/include-fixed/limits.h" 2 3 4
# 8 "/usr/lib/gcc/x86_64-linux-gnu/7/include-fixed/syslimits.h" 2 3 4
# 35 "/usr/lib/gcc/x86_64-linux-gnu/7/include-fixed/limits.h" 2 3 4
# 67 "ecrypt-config.h" 2
# 24 "ecrypt-portable.h" 2
# 44 "ecrypt-portable.h"
typedef signed char s8;
typedef unsigned char u8;



typedef signed short s16;
typedef unsigned short u16;



typedef signed int s32;
typedef unsigned int u32;



typedef signed long s64;
typedef unsigned long u64;
# 98 "ecrypt-portable.h"
# 1 "ecrypt-machine.h" 1
# 99 "ecrypt-portable.h" 2
# 126 "ecrypt-portable.h"
# 1 "ecrypt-machine.h" 1
# 127 "ecrypt-portable.h" 2
# 150 "ecrypt-portable.h"
# 1 "ecrypt-machine.h" 1
# 151 "ecrypt-portable.h" 2
# 299 "ecrypt-portable.h"
# 1 "ecrypt-machine.h" 1
# 300 "ecrypt-portable.h" 2
# 14 "ecrypt-sync.h" 2
# 54 "ecrypt-sync.h"
typedef struct
{
  u32 keylen;
  u32 ivlen;

  u8 s[40];
  u8 key[10];

} ECRYPT_ctx;
# 73 "ecrypt-sync.h"
void ECRYPT_init(void);






void ECRYPT_keysetup(
  ECRYPT_ctx* ctx,
  const u8* key,
  u32 keysize,
  u32 ivsize);







void ECRYPT_ivsetup(
  ECRYPT_ctx* ctx,
  const u8* iv);
# 150 "ecrypt-sync.h"
void ECRYPT_process_bytes(
  int action,
  ECRYPT_ctx* ctx,
  const u8* input,
  u8* output,
  u32 msglen);
# 188 "ecrypt-sync.h"
void ECRYPT_keystream_bytes(
  ECRYPT_ctx* ctx,
  u8* keystream,
  u32 length);
# 231 "ecrypt-sync.h"
void ECRYPT_process_packet(
  int action,
  ECRYPT_ctx* ctx,
  const u8* iv,
  const u8* input,
  u8* output,
  u32 msglen);
# 12 "trivium.c" 2
# 74 "trivium.c"
void ECRYPT_init(void)
{ }



void ECRYPT_keysetup(
  ECRYPT_ctx* ctx,
  const u8* key,
  u32 keysize,
  u32 ivsize)
{
  u32 i;

  ctx->keylen = (keysize + 7) / 8;
  ctx->ivlen = (ivsize + 7) / 8;

  for (i = 0; i < ctx->keylen; ++i)
    ctx->key[i] = key[i];
}






void ECRYPT_ivsetup(
  ECRYPT_ctx* ctx,
  const u8* iv)
{
  u32 i;

  u32 s11, s12, s13;
  u32 s21, s22, s23;
  u32 s31, s32, s33, s34;

  for (i = 0; i < ctx->keylen; ++i)
    ctx->s[i] = ctx->key[i];

  for (i = ctx->keylen; i < 12; ++i)
    ctx->s[i] = 0;

  for (i = 0; i < ctx->ivlen; ++i)
    ctx->s[i + 12] = iv[i];

  for (i = ctx->ivlen; i < 12; ++i)
    ctx->s[i + 12] = 0;

  for (i = 0; i < 13; ++i)
    ctx->s[i + 24] = 0;

  ctx->s[13 + 24] = 0x70;

  do { // LOAD()
	  (s11) = (((u32)(((ctx->s) + 0)[0]) ) | ((u32)(((ctx->s) + 0)[1]) << 8) | ((u32)(((ctx->s) + 0)[2]) << 16) | ((u32)(((ctx->s) + 0)[3]) << 24));
    (s12) = (((u32)(((ctx->s) + 4)[0]) ) | ((u32)(((ctx->s) + 4)[1]) << 8) | ((u32)(((ctx->s) + 4)[2]) << 16) | ((u32)(((ctx->s) + 4)[3]) << 24));
    (s13) = (((u32)(((ctx->s) + 8)[0]) ) | ((u32)(((ctx->s) + 8)[1]) << 8) | ((u32)(((ctx->s) + 8)[2]) << 16) | ((u32)(((ctx->s) + 8)[3]) << 24));
    (s21) = (((u32)(((ctx->s) + 12)[0]) ) | ((u32)(((ctx->s) + 12)[1]) << 8) | ((u32)(((ctx->s) + 12)[2]) << 16) | ((u32)(((ctx->s) + 12)[3]) << 24));
	  (s22) = (((u32)(((ctx->s) + 16)[0]) ) | ((u32)(((ctx->s) + 16)[1]) << 8) | ((u32)(((ctx->s) + 16)[2]) << 16) | ((u32)(((ctx->s) + 16)[3]) << 24));
    (s23) = (((u32)(((ctx->s) + 20)[0]) ) | ((u32)(((ctx->s) + 20)[1]) << 8) | ((u32)(((ctx->s) + 20)[2]) << 16) | ((u32)(((ctx->s) + 20)[3]) << 24));
	  (s31) = (((u32)(((ctx->s) + 24)[0]) ) | ((u32)(((ctx->s) + 24)[1]) << 8) | ((u32)(((ctx->s) + 24)[2]) << 16) | ((u32)(((ctx->s) + 24)[3]) << 24));
    (s32) = (((u32)(((ctx->s) + 28)[0]) ) | ((u32)(((ctx->s) + 28)[1]) << 8) | ((u32)(((ctx->s) + 28)[2]) << 16) | ((u32)(((ctx->s) + 28)[3]) << 24));
	  (s33) = (((u32)(((ctx->s) + 32)[0]) ) | ((u32)(((ctx->s) + 32)[1]) << 8) | ((u32)(((ctx->s) + 32)[2]) << 16) | ((u32)(((ctx->s) + 32)[3]) << 24));
    (s34) = (((u32)(((ctx->s) + 36)[0]) ) | ((u32)(((ctx->s) + 36)[1]) << 8) | ((u32)(((ctx->s) + 36)[2]) << 16) | ((u32)(((ctx->s) + 36)[3]) << 24));
	  } while (0);



  for (i = 0; i < 4 * 9; ++i)
    {
      u32 t1, t2, t3;

      do { // UPDATE()
		  (t1) = (((s13) << ( 96 - (66))) | ((s12) >> ((66) - 64))) ^ (((s13) << ( 96 - (93))) | ((s12) >> ((93) - 64)));
		  (t2) = (((s23) << ( 96 - (69))) | ((s22) >> ((69) - 64))) ^ (((s23) << ( 96 - (84))) | ((s22) >> ((84) - 64)));
		  (t3) = (((s33) << ( 96 - (66))) | ((s32) >> ((66) - 64))) ^ (((s34) << (128 - (111))) | ((s33) >> ((111) - 96))); ;
		  (t1) ^= ((((s13) << ( 96 - (91))) | ((s12) >> ((91) - 64))) & (((s13) << ( 96 - (92))) | ((s12) >> ((92) - 64)))) ^ (((s23) << ( 96 - (78))) | ((s22) >> ((78) - 64)));
		  (t2) ^= ((((s23) << ( 96 - (82))) | ((s22) >> ((82) - 64))) & (((s23) << ( 96 - (83))) | ((s22) >> ((83) - 64)))) ^ (((s33) << ( 96 - (87))) | ((s32) >> ((87) - 64)));
		  (t3) ^= ((((s34) << (128 - (109))) | ((s33) >> ((109) - 96))) & (((s34) << (128 - (110))) | ((s33) >> ((110) - 96)))) ^ (((s13) << ( 96 - (69))) | ((s12) >> ((69) - 64)));
		  } while (0);
      do { // ROTATE()
		  (s13) = (s12);
		  (s12) = (s11);
		  (s11) = (t3);
		  (s23) = (s22);
		  (s22) = (s21);
		  (s21) = (t1);
		  (s34) = (s33);
		  (s33) = (s32);
		  (s32) = (s31);
		  (s31) = (t2); 
		  } while (0);
    }

  do { // STORE()
	  do {
		  ((ctx->s) + 0)[0] = ((u8)(((s11))) & (0xFFU));
		  ((ctx->s) + 0)[1] = ((u8)(((s11)) >> 8) & (0xFFU));
		  ((ctx->s) + 0)[2] = ((u8)(((s11)) >> 16) & (0xFFU));
		  ((ctx->s) + 0)[3] = ((u8)(((s11)) >> 24) & (0xFFU));
		  } while (0);
	  do { 
		  ((ctx->s) + 4)[0] = ((u8)(((s12))) & (0xFFU));
		  ((ctx->s) + 4)[1] = ((u8)(((s12)) >> 8) & (0xFFU));
		  ((ctx->s) + 4)[2] = ((u8)(((s12)) >> 16) & (0xFFU));
		  ((ctx->s) + 4)[3] = ((u8)(((s12)) >> 24) & (0xFFU));
		  } while (0);
	  do { 
		  ((ctx->s) + 8)[0] = ((u8)(((s13))) & (0xFFU));
		  ((ctx->s) + 8)[1] = ((u8)(((s13)) >> 8) & (0xFFU));
		  ((ctx->s) + 8)[2] = ((u8)(((s13)) >> 16) & (0xFFU));
		  ((ctx->s) + 8)[3] = ((u8)(((s13)) >> 24) & (0xFFU));
		  } while (0);
	  do { 
		  ((ctx->s) + 12)[0] = ((u8)(((s21))) & (0xFFU));
		  ((ctx->s) + 12)[1] = ((u8)(((s21)) >> 8) & (0xFFU));
		  ((ctx->s) + 12)[2] = ((u8)(((s21)) >> 16) & (0xFFU));
		  ((ctx->s) + 12)[3] = ((u8)(((s21)) >> 24) & (0xFFU));
		  } while (0);
	  do {
      ((ctx->s) + 16)[0] = ((u8)(((s22))) & (0xFFU));
      ((ctx->s) + 16)[1] = ((u8)(((s22)) >> 8) & (0xFFU));
      ((ctx->s) + 16)[2] = ((u8)(((s22)) >> 16) & (0xFFU));
      ((ctx->s) + 16)[3] = ((u8)(((s22)) >> 24) & (0xFFU));
      } while (0);
	  do { 
		  ((ctx->s) + 20)[0] = ((u8)(((s23))) & (0xFFU));
		  ((ctx->s) + 20)[1] = ((u8)(((s23)) >> 8) & (0xFFU));
		  ((ctx->s) + 20)[2] = ((u8)(((s23)) >> 16) & (0xFFU));
		  ((ctx->s) + 20)[3] = ((u8)(((s23)) >> 24) & (0xFFU));
		  } while (0);
	  do { 
		  ((ctx->s) + 24)[0] = ((u8)(((s31))) & (0xFFU));
	    ((ctx->s) + 24)[1] = ((u8)(((s31)) >> 8) & (0xFFU));
		  ((ctx->s) + 24)[2] = ((u8)(((s31)) >> 16) & (0xFFU));
		  ((ctx->s) + 24)[3] = ((u8)(((s31)) >> 24) & (0xFFU));
		  } while (0);
	  do { 
		  ((ctx->s) + 28)[0] = ((u8)(((s32))) & (0xFFU));
		  ((ctx->s) + 28)[1] = ((u8)(((s32)) >> 8) & (0xFFU));
		  ((ctx->s) + 28)[2] = ((u8)(((s32)) >> 16) & (0xFFU));
		  ((ctx->s) + 28)[3] = ((u8)(((s32)) >> 24) & (0xFFU));
		  } while (0);
	  do {
		  ((ctx->s) + 32)[0] = ((u8)(((s33))) & (0xFFU));
		  ((ctx->s) + 32)[1] = ((u8)(((s33)) >> 8) & (0xFFU));
		  ((ctx->s) + 32)[2] = ((u8)(((s33)) >> 16) & (0xFFU));
		  ((ctx->s) + 32)[3] = ((u8)(((s33)) >> 24) & (0xFFU));
		  } while (0);
	  do { 
      ((ctx->s) + 36)[0] = ((u8)(((s34))) & (0xFFU));
      ((ctx->s) + 36)[1] = ((u8)(((s34)) >> 8) & (0xFFU));
      ((ctx->s) + 36)[2] = ((u8)(((s34)) >> 16) & (0xFFU));
      ((ctx->s) + 36)[3] = ((u8)(((s34)) >> 24) & (0xFFU));
      } while (0);
    } while (0);
}



void ECRYPT_process_bytes(
  int action,
  ECRYPT_ctx* ctx,
  const u8* input,
  u8* output,
  u32 msglen)
{
  u32 i;

  u32 s11, s12, s13;
  u32 s21, s22, s23;
  u32 s31, s32, s33, s34;

  u32 z;

  do { // LOAD()
    (s11) = (((u32)(((ctx->s) + 0)[0]) ) | ((u32)(((ctx->s) + 0)[1]) << 8) | ((u32)(((ctx->s) + 0)[2]) << 16) | ((u32)(((ctx->s) + 0)[3]) << 24));
    (s12) = (((u32)(((ctx->s) + 4)[0]) ) | ((u32)(((ctx->s) + 4)[1]) << 8) | ((u32)(((ctx->s) + 4)[2]) << 16) | ((u32)(((ctx->s) + 4)[3]) << 24));
    (s13) = (((u32)(((ctx->s) + 8)[0]) ) | ((u32)(((ctx->s) + 8)[1]) << 8) | ((u32)(((ctx->s) + 8)[2]) << 16) | ((u32)(((ctx->s) + 8)[3]) << 24));
    (s21) = (((u32)(((ctx->s) + 12)[0]) ) | ((u32)(((ctx->s) + 12)[1]) << 8) | ((u32)(((ctx->s) + 12)[2]) << 16) | ((u32)(((ctx->s) + 12)[3]) << 24));
    (s22) = (((u32)(((ctx->s) + 16)[0]) ) | ((u32)(((ctx->s) + 16)[1]) << 8) | ((u32)(((ctx->s) + 16)[2]) << 16) | ((u32)(((ctx->s) + 16)[3]) << 24));
    (s23) = (((u32)(((ctx->s) + 20)[0]) ) | ((u32)(((ctx->s) + 20)[1]) << 8) | ((u32)(((ctx->s) + 20)[2]) << 16) | ((u32)(((ctx->s) + 20)[3]) << 24));
    (s31) = (((u32)(((ctx->s) + 24)[0]) ) | ((u32)(((ctx->s) + 24)[1]) << 8) | ((u32)(((ctx->s) + 24)[2]) << 16) | ((u32)(((ctx->s) + 24)[3]) << 24));
    (s32) = (((u32)(((ctx->s) + 28)[0]) ) | ((u32)(((ctx->s) + 28)[1]) << 8) | ((u32)(((ctx->s) + 28)[2]) << 16) | ((u32)(((ctx->s) + 28)[3]) << 24));
    (s33) = (((u32)(((ctx->s) + 32)[0]) ) | ((u32)(((ctx->s) + 32)[1]) << 8) | ((u32)(((ctx->s) + 32)[2]) << 16) | ((u32)(((ctx->s) + 32)[3]) << 24));
    (s34) = (((u32)(((ctx->s) + 36)[0]) ) | ((u32)(((ctx->s) + 36)[1]) << 8) | ((u32)(((ctx->s) + 36)[2]) << 16) | ((u32)(((ctx->s) + 36)[3]) << 24));
    } while (0);




  for (i = 0; i < msglen / 4; ++i)
    {
      u32 t1, t2, t3;

      do { // UPDATE()
        (t1) = (((s13) << ( 96 - (66))) | ((s12) >> ((66) - 64))) ^ (((s13) << ( 96 - (93))) | ((s12) >> ((93) - 64)));
        (t2) = (((s23) << ( 96 - (69))) | ((s22) >> ((69) - 64))) ^ (((s23) << ( 96 - (84))) | ((s22) >> ((84) - 64)));
        (t3) = (((s33) << ( 96 - (66))) | ((s32) >> ((66) - 64))) ^ (((s34) << (128 - (111))) | ((s33) >> ((111) - 96)));
        (do {
          (output + 4 * i)[0] = ((u8)(((((u32)((input + 4 * i)[0]) ) | ((u32)((input + 4 * i)[1]) << 8) | ((u32)((input + 4 * i)[2]) << 16) | ((u32)((input + 4 * i)[3]) << 24)) ^ (t1) ^ (t2) ^ (t3))) & (0xFFU));
          (output + 4 * i)[1] = ((u8)(((((u32)((input + 4 * i)[0]) ) | ((u32)((input + 4 * i)[1]) << 8) | ((u32)((input + 4 * i)[2]) << 16) | ((u32)((input + 4 * i)[3]) << 24)) ^ (t1) ^ (t2) ^ (t3)) >> 8) & (0xFFU));
          (output + 4 * i)[2] = ((u8)(((((u32)((input + 4 * i)[0]) ) | ((u32)((input + 4 * i)[1]) << 8) | ((u32)((input + 4 * i)[2]) << 16) | ((u32)((input + 4 * i)[3]) << 24)) ^ (t1) ^ (t2) ^ (t3)) >> 16) & (0xFFU));
          (output + 4 * i)[3] = ((u8)(((((u32)((input + 4 * i)[0]) ) | ((u32)((input + 4 * i)[1]) << 8) | ((u32)((input + 4 * i)[2]) << 16) | ((u32)((input + 4 * i)[3]) << 24)) ^ (t1) ^ (t2) ^ (t3)) >> 24) & (0xFFU));
          } while (0)); 
        (t1) ^= ((((s13) << ( 96 - (91))) | ((s12) >> ((91) - 64))) & (((s13) << ( 96 - (92))) | ((s12) >> ((92) - 64)))) ^ (((s23) << ( 96 - (78))) | ((s22) >> ((78) - 64)));
        (t2) ^= ((((s23) << ( 96 - (82))) | ((s22) >> ((82) - 64))) & (((s23) << ( 96 - (83))) | ((s22) >> ((83) - 64)))) ^ (((s33) << ( 96 - (87))) | ((s32) >> ((87) - 64)));
        (t3) ^= ((((s34) << (128 - (109))) | ((s33) >> ((109) - 96))) & (((s34) << (128 - (110))) | ((s33) >> ((110) - 96)))) ^ (((s13) << ( 96 - (69))) | ((s12) >> ((69) - 64)));
        } while (0);
      do { // ROTATE()
        (s13) = (s12);
        (s12) = (s11);
        (s11) = (t3);
        (s23) = (s22);
        (s22) = (s21);
        (s21) = (t1);
        (s34) = (s33);
        (s33) = (s32);
        (s32) = (s31);
        (s31) = (t2);
        } while (0);
    }




  i *= 4;

  if (i < msglen)
    {
      u32 t1, t2, t3;

      do { // UPDATE()
        (t1) = (((s13) << ( 96 - (66))) | ((s12) >> ((66) - 64))) ^ (((s13) << ( 96 - (93))) | ((s12) >> ((93) - 64)));
        (t2) = (((s23) << ( 96 - (69))) | ((s22) >> ((69) - 64))) ^ (((s23) << ( 96 - (84))) | ((s22) >> ((84) - 64)));
        (t3) = (((s33) << ( 96 - (66))) | ((s32) >> ((66) - 64))) ^ (((s34) << (128 - (111))) | ((s33) >> ((111) - 96)));
        (z = (t1) ^ (t2) ^ (t3));
        (t1) ^= ((((s13) << ( 96 - (91))) | ((s12) >> ((91) - 64))) & (((s13) << ( 96 - (92))) | ((s12) >> ((92) - 64)))) ^ (((s23) << ( 96 - (78))) | ((s22) >> ((78) - 64)));
        (t2) ^= ((((s23) << ( 96 - (82))) | ((s22) >> ((82) - 64))) & (((s23) << ( 96 - (83))) | ((s22) >> ((83) - 64)))) ^ (((s33) << ( 96 - (87))) | ((s32) >> ((87) - 64)));
        (t3) ^= ((((s34) << (128 - (109))) | ((s33) >> ((109) - 96))) & (((s34) << (128 - (110))) | ((s33) >> ((110) - 96)))) ^ (((s13) << ( 96 - (69))) | ((s12) >> ((69) - 64)));
        } while (0);
      do { // ROTATE()
        (s13) = (s12);
        (s12) = (s11);
        (s11) = (t3);
        (s23) = (s22);
        (s22) = (s21);
        (s21) = (t1);
        (s34) = (s33);
        (s33) = (s32);
        (s32) = (s31);
        (s31) = (t2);
        } while (0);

      for ( ; i < msglen; ++i, z >>= 8)
 output[i] = input[i] ^ ((u8)(z) & (0xFFU));
    }

  do { // STORE()
    do {
      ((ctx->s) + 0)[0] = ((u8)(((s11))) & (0xFFU));
      ((ctx->s) + 0)[1] = ((u8)(((s11)) >> 8) & (0xFFU));
      ((ctx->s) + 0)[2] = ((u8)(((s11)) >> 16) & (0xFFU));
      ((ctx->s) + 0)[3] = ((u8)(((s11)) >> 24) & (0xFFU));
      } while (0);
    do {
      ((ctx->s) + 4)[0] = ((u8)(((s12))) & (0xFFU));
      ((ctx->s) + 4)[1] = ((u8)(((s12)) >> 8) & (0xFFU));
      ((ctx->s) + 4)[2] = ((u8)(((s12)) >> 16) & (0xFFU));
      ((ctx->s) + 4)[3] = ((u8)(((s12)) >> 24) & (0xFFU));
      } while (0);
    do {
      ((ctx->s) + 8)[0] = ((u8)(((s13))) & (0xFFU));
      ((ctx->s) + 8)[1] = ((u8)(((s13)) >> 8) & (0xFFU));
      ((ctx->s) + 8)[2] = ((u8)(((s13)) >> 16) & (0xFFU));
      ((ctx->s) + 8)[3] = ((u8)(((s13)) >> 24) & (0xFFU));
      } while (0);
    do {
      ((ctx->s) + 12)[0] = ((u8)(((s21))) & (0xFFU));
      ((ctx->s) + 12)[1] = ((u8)(((s21)) >> 8) & (0xFFU));
      ((ctx->s) + 12)[2] = ((u8)(((s21)) >> 16) & (0xFFU));
      ((ctx->s) + 12)[3] = ((u8)(((s21)) >> 24) & (0xFFU));
      } while (0);
    do {
      ((ctx->s) + 16)[0] = ((u8)(((s22))) & (0xFFU));
      ((ctx->s) + 16)[1] = ((u8)(((s22)) >> 8) & (0xFFU));
      ((ctx->s) + 16)[2] = ((u8)(((s22)) >> 16) & (0xFFU));
      ((ctx->s) + 16)[3] = ((u8)(((s22)) >> 24) & (0xFFU));
      } while (0);
    do {
      ((ctx->s) + 20)[0] = ((u8)(((s23))) & (0xFFU));
      ((ctx->s) + 20)[1] = ((u8)(((s23)) >> 8) & (0xFFU));
      ((ctx->s) + 20)[2] = ((u8)(((s23)) >> 16) & (0xFFU));
      ((ctx->s) + 20)[3] = ((u8)(((s23)) >> 24) & (0xFFU));
      } while (0);
    do {
			((ctx->s) + 24)[0] = ((u8)(((s31))) & (0xFFU));
			((ctx->s) + 24)[1] = ((u8)(((s31)) >> 8) & (0xFFU));
			((ctx->s) + 24)[2] = ((u8)(((s31)) >> 16) & (0xFFU));
			((ctx->s) + 24)[3] = ((u8)(((s31)) >> 24) & (0xFFU));
			} while (0);
    do {
			((ctx->s) + 28)[0] = ((u8)(((s32))) & (0xFFU));
			((ctx->s) + 28)[1] = ((u8)(((s32)) >> 8) & (0xFFU));
			((ctx->s) + 28)[2] = ((u8)(((s32)) >> 16) & (0xFFU));
			((ctx->s) + 28)[3] = ((u8)(((s32)) >> 24) & (0xFFU));
			} while (0);
    do {
			((ctx->s) + 32)[0] = ((u8)(((s33))) & (0xFFU));
			((ctx->s) + 32)[1] = ((u8)(((s33)) >> 8) & (0xFFU));
			((ctx->s) + 32)[2] = ((u8)(((s33)) >> 16) & (0xFFU));
			((ctx->s) + 32)[3] = ((u8)(((s33)) >> 24) & (0xFFU));
			} while (0);
    do {
			((ctx->s) + 36)[0] = ((u8)(((s34))) & (0xFFU));
			((ctx->s) + 36)[1] = ((u8)(((s34)) >> 8) & (0xFFU));
			((ctx->s) + 36)[2] = ((u8)(((s34)) >> 16) & (0xFFU));
			((ctx->s) + 36)[3] = ((u8)(((s34)) >> 24) & (0xFFU));
			} while (0);
		} while (0);
}