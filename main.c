#include <stdio.h>
#include <stdlib.h>

const FIRST_DIGIT = 1;
const SECOND_DIGIT = 0;

int ctoi(const char c) {
    return c - '0';
}

void print_cpf(const int* digits) {
    for (int i = 0; i < 11; ++i) {
        printf("%d", digits[i]);
        if (i > 0) {
            if ((i + 1) % 9 == 0) {
                printf("-");
            } else if ((i + 1) % 3 == 0) {
                printf(".");
            }
        }
    }
}

int get_cpf_digit(const int* cpf, int decal) {
    int d = 0;
    for (int i = decal; i <= 9; ++i) {
        d += cpf[i - decal] * i;
    }
    return (d % 11) % 10;
}

void cpf_calculator() {
    char* cpf = "123456789";

    int digits[11] = {
        ctoi(cpf[0]), ctoi(cpf[1]), ctoi(cpf[2]),
        ctoi(cpf[3]), ctoi(cpf[4]), ctoi(cpf[5]),
        ctoi(cpf[6]), ctoi(cpf[7]), ctoi(cpf[8]),
        0, 0
    };

    digits[9] = get_cpf_digit(digits, FIRST_DIGIT);
    printf("first digit: %d\n", digits[9]);

    digits[10] = get_cpf_digit(digits, SECOND_DIGIT);
    printf("second digit: %d\n", digits[10]);

    print_cpf(digits);

    printf("\n\n");
}

void cpf_bt() {
    char* fds = "123";
    char* lds = "09";

    int digits[11] = {
        ctoi(fds[0]), ctoi(fds[1]), ctoi(fds[2]),
        0, 0, 0, 0, 0, 0,
        ctoi(lds[0]), ctoi(lds[1])
    };

    for (int i = 0; i <= 999999; ++i) {
        digits[3] = i % 1000000 / 100000;
        digits[4] = i % 100000 / 10000;
        digits[5] = i % 10000 / 1000;
        digits[6] = i % 1000 / 100;
        digits[7] = i % 100 / 10;
        digits[8] = i % 10 / 1;

        int d = get_cpf_digit(digits, FIRST_DIGIT);

        if (digits[9] == d) {
            d = get_cpf_digit(digits, SECOND_DIGIT);

            if (digits[10] == d) {
                print_cpf(digits);
                printf("\n");
            }
        }
    }
}

int main() {
    cpf_calculator();
    cpf_bt();

    return 0;
}
