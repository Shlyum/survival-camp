#include "data_io.h"
#include <stdio.h>

void input(double *a, int n) {
for (double *p = a; p - a < n; p++) {
    scanf("%lf", p);
} }


void output(double *a, int n) {
    for (double *p = a; p - a < n; p++) {
        printf("%.2lf", *p);
        if ((p-a) < (n-1)) printf(" ");
    }
        }

