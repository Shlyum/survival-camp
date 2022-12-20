#include <stdio.h>
#include <stdlib.h>

int input(int **a, int *n);
void output(int *a, int n);
void sort(int *a, int n);

int main() {
    int n;
    int *data = NULL;
    if (input(&data, &n) != 0) {printf("n/a"); return 0;}
    sort(data, n);
    output(data, n);
    free(data);
    return 0;
}

int input(int **a, int *n) {
    char c; int g = 0;
    if ((!scanf("%d%c", n, &c)) || (*n < 0) || (*n == 0) || ((c != '\n')&&(c != '\0'))) { g++; }
        *a = malloc(*n * sizeof(**a));
for (int *p = *a; p - *a < *n; p++) {
    if ((!scanf("%d%c", p, &c)) || ((c != '\n')&&(c != '\0')&&(c != ' '))) {g++;} }
    if ((c != '\n')&&(c != '\0')) {g++;}

return g;}
void sort(int *a, int n) {
    int *p = a, t;
    for (int m = 0; m < n-1; m++)
        for (int j = 0; j < n-1-m; j++)
            if ((*(p+j)) > *(p+j+1)) { t = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = t;
            }
}
void output(int *a, int n) {
    for (int *p = a; p - a < n; p++)
        printf("%d ", *p);
        }

