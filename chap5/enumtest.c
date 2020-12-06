//
// Created by Administrator on 2020/12/5.
//
//P256
#include <stdio.h>

typedef enum {
    COUNT, POUNDS, PINS
} unit_of_measure;

typedef union {
    short count;
    float weight;
    float volume;
} quantity;

typedef struct {
    const char *name;
    const char *country;
    quantity amount;
    unit_of_measure units;
} fruit_order;

void display(fruit_order order) {
    printf("This order contains ");
    if (order.units == PINS) {
        printf("%2.2f pints of %s\n", order.amount.volume, order.name);
    } else if (order.units == POUNDS) {
        printf("%2.2f lbs of %s\n", order.amount.weight, order.name);
    } else {
        printf("%i %s\n", order.amount.count, order.name);
    }

}

int main() {
//    todo 需要加一个.来引用amount -->  .amount.count
    fruit_order apples = {"apples", "England", .amount.count = 144, COUNT};
    fruit_order strawberries = {"strawberries", "Spain", .amount.weight = 17.6, POUNDS};
    fruit_order oj = {"Orange juice", "USA", .amount.volume=10.5, PINS};
    display(apples);
    display(strawberries);
    display(oj);

    return 0;
}