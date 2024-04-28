#ifndef SHA256_H
#define SHA256_H

#define uchar unsigned char
#define uint unsigned int

typedef struct
{
    uchar data[64];
    uint datalen;
    uint bitlen[2];
    uint state[8];
} SHA256_CTX;

char *SHA256(char *data, long strlen);

#endif /* SHA256_H */