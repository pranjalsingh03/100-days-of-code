#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void calculateHash(const char* data, unsigned char* hash) {
    SHA256(data, strlen(data), hash);
}