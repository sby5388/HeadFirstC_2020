//
// Created by Administrator on 2020/12/6.
//

#include "encrypt.h"

void encrypt(char *message) {
    while (*message) {

        *message = *message ^ 31;
        message++;
    }
}