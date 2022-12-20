#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "data_process.h"
#include "../data_libs/data_stat.h"
#include "../data_libs/data_io.h"
int main() {
    double *data;
    int n;
    scanf("%d", &n);
    // Don`t forget to allocate memory !
    data = malloc(n*sizeof(double));
    input(data, n);

    if (normalization(data, n))
        output(data, n);
    else
        printf("ERROR");
    free(data);
    return 0;}
