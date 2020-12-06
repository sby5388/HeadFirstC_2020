//
// Created by Administrator on 2020/12/6.
//

#include "checksum.h"

int checksum(char *message) {
    int c = 0;
    while (*message) {
        c += c ^ (int) (*message);
        message++;
    }
    return c;
}