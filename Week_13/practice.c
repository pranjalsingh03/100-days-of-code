#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Function to calculate SHA-256 hash
void calculateHash(const char* data, unsigned char* hash) {
    SHA256(data, strlen(data), hash);
}