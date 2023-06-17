#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void calculateHash(const char* data, unsigned char* hash) {
    SHA256(data, strlen(data), hash);
}

int verifyBitcoinProfile(const char* username, const char* publicKey, const char* signature) {
    // Concatenate username and publicKey
    char concatenatedData[256];
    snprintf(concatenatedData, sizeof(concatenatedData), "%s%s", username, publicKey);

    // Calculate SHA-256 hash
    unsigned char hash[SHA256_DIGEST_LENGTH];
    calculateHash(concatenatedData, hash);

    // Perform signature verification (Assuming you have a signature verification function)
    if (verifySignature(hash, signature)) {
        printf("Bitcoin profile verified successfully!\n");
        return 1;
    } else {
        printf("Bitcoin profile verification failed.\n");
        return 0;
    }
}