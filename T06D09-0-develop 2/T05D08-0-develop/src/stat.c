#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {printf("n/a"); return 0;}
    output(data, n);
       output_result(max(data, n),
                     min(data, n),
                     mean(data, n),
                     variance(data, n));


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

int max(int *a, int n) {
    int max = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p > max) {max = *p;} }
    return max; }

int min(int *a, int n) {
    int min = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p < min) {
            min = *p; } } return min;
}

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

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
    printf("%d ", max_v);
    printf("%d ", min_v);
    printf("%.6lf ", mean_v);
    printf("%.6lf ", variance_v);
}












