//
// Created by Administrator on 2020/12/6.
//
//P338 使用函数指针数组
#include <stdlib.h>
#include <stdio.h>

enum response_type {
    DUMP, SECOND_CHANCE, MARRIAGE
};

typedef struct {
    char *name;
    enum response_type type;
} response;

/**
 * 丢弃，分手？
 * @param r
 */
void dump(response r);

/**
 * 第二次机会
 * @param r
 */
void second_chance(response r);

void marriage(response r);

//函数指针数组
void (*replies[])(response) = {dump, second_chance, marriage};


int main() {
    response r[] = {
            {"Mike",    DUMP},
            {"Luis",    SECOND_CHANCE},
            {"Matt",    SECOND_CHANCE},
            {"William", MARRIAGE}
    };
    int i;
    for (i = 0; i < 4; ++i) {
//        todo
        replies[r[i].type](r[i]);
    }
    return 0;
}


void dump(response r) {
    printf("Dear %s,\n", r.name);
    puts("Unfortunately your last date contacted us to");
    puts("say that they will not be seeing you again");
}

void second_chance(response r) {
    printf("Dear %s,\n", r.name);
    puts("Good news: your last date has asked us to");
    puts("arrange another meeting. Please call ASAP.");
}

void marriage(response r) {
    printf("Dear %s,\n", r.name);
    puts("Congratulations! Your last date has contacted");
    puts("us with a proposal of marriage.");
}