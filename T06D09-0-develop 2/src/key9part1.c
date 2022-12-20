
#include <stdio.h>
#define NMAX 10
void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers);
int prov(int *buffer, int length);


int main() {
    int data[NMAX], n, data2[NMAX];
    input(data, &n);
    if ((n == -1) || (prov(data, n) == 0)) {printf("n/a"); return 0;}
int n2 = find_numbers(data, n, sum_numbers(data, n), data2);
    output(data2, n2);
    return 0;
}



void input(int *buffer, int *length) {
    char c;
    if (((!scanf("%d%c", length, &c)) || (*length < 0) ||
         (*length > NMAX) || (*length == 0)) || ((c != '\n')&&(c != '\0'))) { *length = -1; }
for (int *p = buffer; p - buffer < *length; p++) {
    if ((!scanf("%d%c", p, &c)) || ((c != '\n')&&(c != '\0')&&(c != ' '))) {
        *length = -1;
}
}
    if (c != '\n') {
        *length = -1;
    }
}




int sum_numbers(int *buffer, int length) {
    int sum = 0;
for (int *p = buffer; p - buffer < length; p++) {
if ((*p != 0)&&(*p%2 == 0)) {
            sum = sum + *p;
}
}
    printf("%d\n", sum);
return sum;
    }
int find_numbers(int *buffer, int length, int number, int *numbers) {
int i = 0;
    for (int *p = buffer; p - buffer < length; p++)
        if ((*p != 0)&&(number % *p == 0))
            *(numbers + i++) = *p;
return i;
}


void output(int *buffer, int length) {
for (int *p = buffer; p - buffer < length; p++)
        printf("%d ", *p);
}

int prov(int *buffer, int length) {
    int count = 0;
    for (int *p = buffer; p - buffer < length; p++)    {
        if (*p%2 == 0) {
            count++;
}
}
if (count == 0)
{ return 0;
} else { return 1;}
}



