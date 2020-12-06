//
// Created by Administrator on 2020/12/6.
//

#include <stdio.h>
#include "checksum.h"
#include "encrypt.h"

int main() {
    char s[] = "Speak friend and enter";
    encrypt(s);
    printf("Encrypted to '%s'\n", s);
    printf("Checksum is %i\n", checksum(s));
    encrypt(s);
    printf("Decrypted back to '%s'\n", s);
    printf("Checksum is %i\n", checksum(s));
    return 0;
}