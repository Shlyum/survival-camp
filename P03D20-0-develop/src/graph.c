#include <math.h>
#include <stdio.h>
#include <string.h>

#include "./parcer.h"

#define X 80
#define Y 25
#define start_line 12

void init_field(int arr[Y][X]);
void draw(int arr[Y][X]);
void stars(int arr[Y][X]);

int main() {
    int arr[Y][X];

    init_field(arr);
    stars(arr);
    draw(arr);
    return 0;
}

void stars(int arr[Y][X]) {
    char str[100];
    fgets(str, 100, stdin);
    int i = 0;
    for (double x = 0; x <= 4.0*M_PI; x += 4.0 * M_PI / 80.0) {
        double res = parcer(str, x);
        int y = round(res * start_line);
        if (y <= start_line && y >= - start_line) {
            arr[start_line - y][i] = '*';
        }
        i++;
    }
}

void init_field(int arr[Y][X]) {
  for (int i = 0; i < Y; i++)
    for (int j = 0; j < X; j++) {
        arr[i][j] = '.';
    }
}

void draw(int arr[Y][X]) {
  for (int i = 0; i < Y; i++) {
    for (int j = 0; j < X; j++) {
      printf("%c", arr[i][j]);
    }
    printf("\n");
  }
}

