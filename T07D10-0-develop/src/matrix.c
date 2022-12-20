#include <stdio.h>
#include <stdlib.h>
#define NMAX 100
#define MMAX 100
int input1(int *M, int *N);
void output(int M, int N, int **data);
int** alloc2(int M, int N);
int** alloc3(int M, int N);
int** alloc4(int M, int N);
void free1(int **a);
void free3(int **a, int M);
void free2(int **a);
void full(int M, int N, int **data);
void fullstat(int M, int N, int data1[][100]);
void outputstat(int M, int N, int data1[][100]);
int chmode();

int main() {
    int data1[100][100]; int N; int M; int **data;
int choise = chmode();
    if (choise != -1) {
        if (input1(&M, &N) != 0) {choise = -1;} }
switch (choise) {
        case 1 :
        if ((N > 100) || (M > 100))  {printf("n/a"); break; }
            printf("Введите матрицу:\n");
            fullstat(M, N, data1);
    outputstat(M, N, data1);
            break;
    case 2 :

printf("Введите матрицу:\n");
data = alloc2(M, N);
            full(M, N, data);
    output(M, N, data);
    free1(data);
    break;


case 3 :
    printf("Введите матрицу:\n");
data = alloc3(M, N);
full(M, N, data);
output(M, N, data);
free2(data);
    break;
    case 4 :
         printf("Введите матрицу:\n");
    data = alloc4(M, N);
         full(M, N, data);
    output(M, N, data);
    free3(data, M);
        break;


        default : printf("n/a"); break;
    }
    return 0; }
    int chmode() {
        int ch = 0;
        char c;
        printf("Привет! Выбери способ создания матрицы:\n1.Static\n2.dynamic\n3.dynamic\n4.dynamic\n");
        if (!scanf("%d%c", &ch, &c) || ((c != '\n')&&(c != '\0'))) {ch = -1;}
        if ((ch != 1)&&(ch != 2)&&(ch != 3)&&(ch != 4))  {ch = -1;}
        return ch;}

void output(int M, int N, int **data) {
    for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++)
    { printf("%d ", data[i][j]); }
        printf("\n"); }
}


void free1(int **a) {
    free(a); }

void free2(int **a) {
    free(*a);
    free(a);
}

void free3(int **a, int M) {
    for (int i = 0; i < M; i++)
        free(a[i]);
    free(a);
}
int input1(int *M, int *N) {
    printf("Введите размеры матрицы:\n");
    int g = 0; char c;
    if ((!scanf("%d %d%c", M, N, &c)) || (*N <= 0) || (*M <= 0) || ((c != '\n')&&(c != '\0'))) {g++;}
    return g;}

int** alloc2(int M, int N) {
    int** a = malloc((M)*(N)*sizeof(int) + M * sizeof(int*));
int *ptr = (int*)(a+M);
    for (int i = 0; i < M; i++) {
        (a)[i] = ptr + N*i; }
return a;}

void full(int M, int N, int **data) {
    for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++)
        scanf("%d", &data[i][j]);
    }
}

int** alloc3(int M, int N) {
    int** a = malloc(M*sizeof(int*));
    int* b = malloc(M*N*sizeof(int));
    for (int i = 0; i < M; i++)
        (a)[i] = b + N*i;
    return a;}
    int** alloc4(int M, int N) {
        int **a = malloc(M*sizeof(int*));
        for (int i = 0; i < M; i++)
            (a)[i] = malloc(N*sizeof(int));
return a;}

void fullstat(int M, int N, int data1[][100]) {
    for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++)
        scanf("%d", &data1[i][j]);
}
}

void outputstat(int M, int N, int data1[][100]) {
    for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++)
    printf("%d ", data1[i][j]);
        printf("\n"); }
}
