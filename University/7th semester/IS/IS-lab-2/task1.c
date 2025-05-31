/* task1.c */
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
BIGNUM *p = BN_new();
BIGNUM *q = BN_new();
BIGNUM *e = BN_new();
BIGNUM *n = BN_new();
BIGNUM *phi_n = BN_new();
BIGNUM *d = BN_new();
BIGNUM *one = BN_new();
BIGNUM *p_min_1 = BN_new();
BIGNUM *q_min_1 = BN_new();


//Assigning hex values to p,q and e
BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
BN_hex2bn(&e, "0D88C3");

//Calculate n = p * q
BN_mul(n, p, q, ctx);
printBN("n = p * q = ", n);

//Calculate phi(n) = (p-1) * (q - 1) 
BN_dec2bn(&one, "1");
BN_sub(p_min_1, p, one);
BN_sub(q_min_1, q, one);
BN_mul(phi_n, p_min_1, q_min_1, ctx);
printBN("phi(n) = ", phi_n);

//Calculating d = e^-1(mod phi(n))
BN_mod_inverse(d, e, phi_n, ctx);
printBN("Private Key d = ", d);
}
