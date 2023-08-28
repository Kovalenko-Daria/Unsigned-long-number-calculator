#include "calc.h"

int input(int *buffer, int *length) {
    printf("Enter a number: ");
    char sym, num;
    int amount = 0, f = 1, was_nums = 0, was_zer = 0;
    while (f) {
        if (scanf("%c%c", &num, &sym) == 2 && '0' <= num && num <= '9' && (sym == 32 || sym == 10)) {
            int n = num - '0';
            if (n == 0 && was_nums == 0) {
                was_zer = 1;
            }
            if ((n == 0 && was_nums != 0) || n != 0) {
                buffer[amount] = n;
                was_nums = 1;
                amount++;
            }
        } else {
            f = 0;
            break;
        }
        if (sym == 10) {
            if (amount == 0 && was_zer) {
                *length = 1;
                buffer[0] = 0;
            } else if (amount != 0) {
                *length = amount;
            } else {
                f = 0;
            }
            break;
        }
    }
    return f;
}

void reverse_output(int *buffer, int length) {
    for (int *p = buffer + length - 1; p != buffer - 1; p--) {
        if (p - buffer == 0) {
            printf("%d", *p);
        } else {
            printf("%d ", *p);
        }
    }
    if (length == 0) {
        printf("0");
    }
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int ost = 0, amount = 0;
    for (int i = 0; i < len1; i++) {
        if (i < len2) {
            int sum = buff1[len1 - 1 - i] + buff2[len2 - 1 - i] + ost;
            ost = sum / 10;
            result[i] = sum % 10;
        } else {
            int sum = buff1[len1 - 1 - i] + ost;
            ost = sum / 10;
            result[i] = sum % 10;
        }
        amount++;
    }
    if (ost != 0) {
        result[len1] = ost;
        amount++;
    }
    *result_length = amount;
}

int sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int f = 1, zan = 0, amount = 0;
    for (int i = 0; i < len1; i++) {
        if (i < len2) {
            int min = buff1[len1 - 1 - i] - buff2[len2 - 1 - i] - zan;
            if (min < 0) {
                min = buff1[len1 - 1 - i] - buff2[len2 - 1 - i] + 10 - zan;
                zan = 1;
            } else {
                zan = 0;
            }
            result[i] = min;
            amount++;
        } else {
            int min = buff1[len1 - 1 - i] - zan;
            if (min < 0) {
                min = buff1[len1 - 1 - i] - zan + 10;
                zan = 1;
            } else {
                zan = 0;
            }
            result[i] = min;
            amount++;
        }
    }
    if (zan != 0) {
        f = 0;
    } else {
        for (int i = amount - 1; result[i] == 0; i--) {
            amount--;
        }
    }
    *result_length = amount;
    return f;
}