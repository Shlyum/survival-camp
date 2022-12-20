#include <stdio.h>
#define NMAX 10
int input(int *a, int *n, int *k);
int output(int *a, int n);
int sdvig(int *a, int n, int k);
int shifttt(int *a, int n, int k);


int main() {
int n, data[NMAX], k;
if (input(data, &n, &k) != 0) {printf("n/a"); return 0;}
sdvig(data, n, k);
    output(data, n);

    return 0; }


int input(int *a, int *n, int *k) {
    char c; int g = 0;
if ((!scanf("%d%c", n, &c)) || (*n < 0) || (*n > NMAX) || (*n == 0) ||
    ((c != '\n')&&(c != '\0'))) {g++;} else {
for (int *p = a; p - a < *n; p++) {
        if ((!scanf("%d%c", p, &c)) || ((c != '\n')&&(c != '\0')&&(c != ' '))) {g++;} }
   // if ((c != '\n') || (c != '\0')) {g++;}
    if ((!scanf("%d%c", k, &c)) || ((c != '\n')&&(c != '\0'))) {g++;}
    return g;} return g;}


int sdvig(int *a, int n, int k) {
            if (k < 0) {
                k = (k % n) + n;
            } else {k = k % n;}
shifttt(a, n, k); return 0;}
int shifttt(int *a, int n, int k) {
for (int j = 0; j < k; j++) {
      int first = *a;
        for (int i = 0; i < n; i++) {
            *(a+i) = *(a + i + 1); }
        *(a + n - 1) = first;
        }
        return 0;
    }

int output(int *a, int n) {
    for (int *p = a; p - a < n; p++)
        printf("%d ", *p);
    return 0; }
