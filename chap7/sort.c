//
// Created by Administrator on 2020/12/6.
//
//P327
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 矩形
 */
typedef struct {
    int width;
    int height;
} rectangle;

/**
 * 升序排序
 * @param score_a
 * @param score_b
 * @return
 */
int compare_scores(const void *score_a, const void *score_b);


/**
 * 降序排序
 * @param score_a
 * @param score_b
 * @return
 */
int compare_scores_desc(const void *score_a, const void *score_b);

/**
 * 按面积大小排序，从小到大
 * @param score_a
 * @param score_b
 * @return
 */
int compare_areas(const void *score_a, const void *score_b);

/**
 * 按面积大小排序，从大到小
 * @param a
 * @param b
 * @return
 */
int compare_areas_desc(const void *a, void *b);

/**
 * 按字母序排列名字，区分大小写
 * @param score_a
 * @param score_b
 * @return
 */
int compare_names(const void *score_a, const void *score_b);

/**
 * 按逆字母序排列名字，区分大小写。
 * @param a
 * @param b
 * @return
 */
int compare_names_desc(const void *a, const void *b);

int main() {
    int scores[] = {543, 323, 32, 554, 11, 3, 112};
    int i;
    //todo C语言定义的排序函数，参数分别是
    //一个数组指针，数组长度，数组每个元素的长度，用来比较数组中两项数据大小的函数指针（void*指针可以指向任何数据类型）
    //运行结束后，按照排序规则排序好
    //qsort(void *array,size_t length,size_t item_size,int (*compar)(const void *, const void *));
    qsort(scores, 7, sizeof(int), compare_scores_desc);
    puts("These are the scores in order:");
    for (i = 0; i < 7; i++) {
        printf("Score = %i\n", scores[i]);
    }
    char *names[] = {"Karen", "Mark", "Brett", "Molly"};
    qsort(names, 4, sizeof(char *), compare_names);
    puts("These are the names in order:");
    for (i = 0; i < 4; i++) {
        printf("%s\n", names[i]);
    }
    return 0;
}

/**
 * 按整数升序排序
 * @param score_a
 * @param score_b
 * @return
 */
int compare_scores(const void *score_a, const void *score_b) {
    //1.转换为整数指针p
    //2.对指针p进行取值
    int *pA = (int *) score_a;
    int a = *pA;

    int b = *((int *) score_b);
    printf("a = %d,b=%d\n", a, b);
    return a - b;

}

int compare_scores_desc(const void *score_a, const void *score_b) {
    int *pA = (int *) score_a;
    int a = *pA;

    int b = *((int *) score_b);
    //printf("a = %d,b=%d\n", a, b);
    return b - a;
}

int compare_areas(const void *score_a, const void *score_b) {
    //todo struct类型强制转换的时候，并不需要加struct,直接结构体的名字
    rectangle *rectangleA = (rectangle *) score_a;
    int areaA = rectangleA->height * rectangleA->width;

    rectangle *rectangleB = (rectangle *) score_b;
    int areaB = rectangleB->height * rectangleB->width;
    return areaA - areaB;

}

int compare_areas_desc(const void *a, void *b) {
    return compare_areas(b, a);
}

/**
 * 按字母序排列名字，区分大小写
 * @param score_a
 * @param score_b
 * @return
 */
int compare_names(const void *score_a, const void *score_b) {
//    todo 指向指针的指针 ::字符串是字符指针，所以得到的是指针的指针
    char **sa = (char **) score_a;
    char **sb = (char **) score_b;
    //todo 我们要用 * 运算符取得字符串。
    return strcmp(*sa, *sb);

}

int compare_names_desc(const void *a, const void *b) {
    return compare_names(b, a);
}