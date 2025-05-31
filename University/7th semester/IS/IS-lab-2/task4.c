/* task4.c */
#include <stdio.h>
#include <openssl/bn.h>

void printBN(char *msg, BIGNUM * a)
{
/* Use BN_bn2hex(a) for hex string
* Use BN_bn2dec(a) for decimal string */
char * number_str = BN_bn2hex(a);
printf("%s %s\n", msg, number_str);
OPENSSL_free(number_str);
}


int main ()
{
BN_CTX *ctx = BN_CTX_new();

BIGNUM *n = BN_new();
BIGNUM *d = BN_new();
BIGNUM *M1 = BN_new();
BIGNUM *M2 = BN_new();
BIGNUM *S1 = BN_new();
BIGNUM *S2 = BN_new();

//Assigning values for d and n
BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");

//Assign the first message in hex

BN_hex2bn(&M1, "2049206f776520796f752024323030302e");

//Sign the first message S1 = M1^d mod n
BN_mod_exp(S1, M1, d, n, ctx);
printBN("Signature for 'I owe you $2000.: '", S1);


//Assign the second message in hex
BN_hex2bn(&M2, "2049206f776520796f752024333030302e");

//Sign the second message S2 = M2^d mod n
BN_mod_exp(S2, M2, d, n, ctx);
printBN("Signature for 'I owe you $3000.: '", S2);

return 0;
}
