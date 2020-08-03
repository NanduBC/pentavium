typedef unsigned int u32;
typedef struct
{
  u32 keylen;
  u32 ivlen;

  u8 s[40];
  u8 key[10];

} ECRYPT_ctx;
void trivium()