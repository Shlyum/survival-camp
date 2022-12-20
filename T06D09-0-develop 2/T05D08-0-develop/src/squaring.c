#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
int n, data[NMAX];
if (input(data, &n) == 1) {printf("n/a"); return 0;}
squaring(data, n);
output(data, n);
return 0;
}

int input(int *a, int *n) {
char c;
if (((!scanf("%d%c", n, &c)) || (*n < 0) || (*n > NMAX)) || ((c != '\n')&&(c != '\0'))) {return 1;}
for (int *p = a; p - a < *n; p++) {
        if ((!scanf("%d%c", p, &c)) || ((c != '\n')&&(c != '\0')&&(c != ' '))) {return 1;} }
    if (c != '\n') {return 1;}
return 0;}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++)
        printf("%d ", *p);
        }

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++)
        *p = *p**p;
        }


