#include <stdio.h>
#include <math.h>
#define NMAX 30

int input(int *a, int *n);
void output(int *a, int n);
int chet(int a);
double mean(int *a, int n);
double variance(int *a, int n);
int menmean(int *a, int n, int j);
int meanplus3(int *a, int n, int h);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {printf("n/a"); return 0;}
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
    int count = 0;
    for (int *p = a; p - a < n; p++) {
        if (((chet(*p)) == 1) && (menmean(a, n, *p) == 1) && (meanplus3(a, n, *p) == 1) && (*p != 0)) {
            printf("%d", *p); count = count+1; break; } }
    if (count == 0) {printf("0");}
}
int chet(int a) {
    if (a%2 == 0) {return 1; }
    return 0; }

int menmean(int *a, int n, int j) {
     if (j >= mean(a, n)) { return 1; }
    return 0;
    }
int meanplus3(int *a, int n, int h) {
if (h <= (mean(a, n)+(3*sqrt(variance(a, n))))) {return 1; }
return 0;  }
double mean(int *a, int n) {
    double sr = 0;
    double oj;
    for (int *p = a; p - a < n; p++) {
        sr = sr + *p;
        }
    oj = sr/n;
    return oj;
}

double variance(int *a, int n) {
    double var = 0;
    double varr;
    for (int *p = a; p - a < n; p++) {
        var = (*p - mean(a, n))*(*p - mean(a, n))+var;
}
    varr = var/n;
    return varr;
}



