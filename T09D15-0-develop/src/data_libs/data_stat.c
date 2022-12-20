#include "data_stat.h"

double max(double *a, int n) {
    double max = *a;
    for (double *p = a; p - a < n; p++) {
        if (*p > max) {max = *p;} }
    return max; }


double min(double *a, int n) {
    double min = *a;
    for (double *p = a; p - a < n; p++) {
        if (*p < min) {
            min = *p; } } return min;
}

double mean(double *a, int n) {
    double sr = 0;
    double oj;
    for (double *p = a; p - a < n; p++) {
        sr = sr + *p;
        }
    oj = sr/n;
    return oj;
}
double variance(double *a, int n) {
    double var = 0;
    double varr;
    for (double *p = a; p - a < n; p++) {
        var = (*p - mean(a, n))*(*p - mean(a, n))+var;
}
    varr = var/n;
    return varr;
}
void sort(double *a, int n) {
    double *p = a, t;
    for (int m = 0; m < n-1; m++)
        for (int j = 0; j < n-1-m; j++)
            if ((*(p+j)) > *(p+j+1)) { t = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = t;
            }
}





