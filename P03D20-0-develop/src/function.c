#include <stdlib.h>
#include <math.h>
#include "./function.h"
#include <stdio.h>

double function(const char PN[100], double x) {
  double mini_stack[100];
  int end = 0;
  int w = 0;
  int i = 0;

    while (end == 0) {
        int symbol = PN[i];
        if (symbol != '\0') {
            switch (symbol) {
                case  ' ':
                    break;
                case '+':
                    mini_stack[w-2] = mini_stack[w-2] + mini_stack[w-1];
                    w--;
                    break;
                case '-':
                    mini_stack[w-2] = mini_stack[w-2] - mini_stack[w-1];
                    w--;
                    break;
                case '*':
                    mini_stack[w-2] = mini_stack[w-2] * mini_stack[w-1];
                    w--;
                    break;
                case '/':
                    mini_stack[w-2] = mini_stack[w-2] / mini_stack[w-1];
                    w--;
                    break;
                case 'S':
                    mini_stack[w-1] = sin(mini_stack[w-1]);
                    break;
                case 'C':
                    mini_stack[w-1] = cos(mini_stack[w-1]);
                    break;
                case 'T':
                    mini_stack[w-1] = tan(mini_stack[w-1]);
                    break;
                case 'K':
                    mini_stack[w-1] = 1.0/tan(mini_stack[w-1]);
                    break;
                case 'Q':
                    mini_stack[w-1] = sqrt(mini_stack[w-1]);
                    break;
                case 'L':
                    mini_stack[w-1] = log(mini_stack[w-1]);
                    break;
                case '^':
                    mini_stack[w-1] = pow(mini_stack[w-2], mini_stack[w-1]);
                    break;
                case 'x':
                    mini_stack[w] = x;
                    w++;
                    break;
                default:
                    if (symbol >= '0' && symbol <= '9') {
                        char buffer[10];
                        int j = 0, flag = 0;
                        double e = 1;
                        if (PN[i] == '.')
                            i++;
                        while (PN[i + j] != ' ') {
                            if (PN[i + j] == '.')
                                flag = 1;
                            if (flag == 1)
                                e /= 10.;
                            buffer[j] = PN[i + j];
                            j++;
                        }
                        i += j;
                        buffer[j + 1] = '\0';
                        mini_stack[w] = atof(buffer);
                        mini_stack[w] *= e;
                        w++;
                    }
                break;
            }
    } else {
        end = 1;
        }
        i++;
  }

  return mini_stack[w-1];
}
