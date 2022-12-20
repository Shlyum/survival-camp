#include <stdio.h>


int input(int *a);
void output(int *a);
void sort(int *a);

int main() {
    int data[10];
    if (input(data) != 0) {printf("n/a"); return 0;}
    sort(data);
    output(data);
    return 0;
}

int input(int *a) {
    char c; int g = 0;
for (int *p = a; p - a < 10; p++) {
        if ((!scanf("%d%c", p, &c)) || ((c != '\n')&&(c != '\0')&&(c != ' '))) {g++;} }
    if ((c != '\n')&&(c != '\0')) {g++;}
return g;}
void sort(int *a) {
    int *p = a, t;
    for (int m = 0; m < 9; m++)
        for (int n = 0; n < 9-m; n++)
            if ((*(p+n)) > *(p+n+1)) { t = *(p+n);
                *(p+n) = *(p+n+1);
                *(p+n+1) = t;
            }
}
void output(int *a) {
    for (int *p = a; p - a < 10; p++)
        printf("%d ", *p);
}
