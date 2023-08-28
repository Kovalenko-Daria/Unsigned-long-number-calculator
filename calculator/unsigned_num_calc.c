#include "calc.h"

int main() {
    int n1, n2, data1[LEN], data2[LEN];
    if (input(data1, &n1) && input(data2, &n2)) {
        int pln, mn, plus[LEN + 1], min[LEN];
        printf("The sum of these numbers is ");
        if (n1 >= n2) {
            sum(data1, n1, data2, n2, plus, &pln);
        } else {
            sum(data2, n2, data1, n1, plus, &pln);
        }
        reverse_output(plus, pln);
        printf("\n");
        if (n1 < n2) {
            printf("Second number is more than first one so unsigned substraction cannot be computed");
        } else {
            if (sub(data1, n1, data2, n2, min, &mn)) {
                printf("The subtraction of these numbers is ");
                reverse_output(min, mn);
            } else {
                printf("Second number is more than first one so unsigned subtraction cannot be computed");
            }
        }
    } else {
        printf("Error in input");
    }
    return 0;
}