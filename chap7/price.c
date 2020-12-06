//
// Created by Administrator on 2020/12/6.
//
//P343 可变参数

#include <stdio.h>
//todo 使用可变参数时，必须要引用的头文件
#include <stdarg.h>

enum drink {
    MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE
};

double price(enum drink d);

/**
 *
 * @param args 可变参数的长度，也是一个普通的参数
 * @param ...
 * @return
 */
double total(int args, ...);

int main() {
    printf("Price is %.2f\n", total(2, MONKEY_GLAND, MUDSLIDE));
    printf("Price is %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
    printf("Price is %.2f\n", total(1, ZOMBIE));
    return 0;
}


double price(enum drink d) {
    switch (d) {
        case MUDSLIDE:
            return 6.79;
        case FUZZY_NAVEL:
            return 5.31;
        case MONKEY_GLAND:
            return 4.82;
        case ZOMBIE:
            return 5.89;
    }
    return 0;
}

double total(int args, ...) {
    double total = 0.0;
    int i = 0;
    //todo 用于保存可变参数的容器
    va_list ap;
    //可变参数开始
    va_start(ap, args);
    for (; i < args; ++i) {
        //va_arg:取值，第一个参数是可变参数的容器，第二个是可变参数的类型
        enum drink d = va_arg(ap, enum drink);
        total += price(d);
    }
    //可变参数结束
    va_end(ap);

    return total;
}
