#include <stdlib.h>
#include "./parcer.h"
#include "./function.h"

/*
 sin = S
 cos = C
 tan = T
 ctg = K
 sqrt = Q
 ln = L
 */

struct node {
  char c;
  struct node *Next;
};

int priora(char);
struct node* push(struct node*, char);
struct node* pop(struct node*, char*);

double parcer(char str[100], double x) {
  struct node *Stack = 0;
  char a, PN[100];
  int i = 0, j = 0;
  while (str[i] != '\0') {
    if (str[i] == ')') {
        if (NULL != Stack) {
            while ((Stack -> c) != '(') {
                Stack = pop(Stack, &a);
                if (!Stack) {
                    a = '\0';
                } else {
                    PN[j++] = a;
                    PN[j++] = ' ';
                }
            }
        }
    }
    if ((str[i] == 's' && str[i+1] == 'i'
       && str[i+2] == 'n' && str[i+3] == '(')) {
        Stack = push(Stack, 'S');
        PN[j++] = ' ';
    }
    if ((str[i] == 'c' && str[i+1] == 'o'
       && str[i+2] == 's' && str[i+3] == '(')) {
        Stack = push(Stack, 'C');
        PN[j++] = ' ';
    }
    if ((str[i] == 't' && str[i+1] == 'a'
       && str[i+2] == 'n' && str[i+3] == '(')) {
        Stack = push(Stack, 'T');
        PN[j++] = ' ';
    }
    if ((str[i] == 'c' && str[i+1] == 't'
      && str[i+2] == 'g' && str[i+3] == '(')) {
        Stack = push(Stack, 'K');
        PN[j++] = ' ';
    }
    if ((str[i] == 's' && str[i+1] == 'q'
      && str[i+2] == 'r' && str[i+3] == 't' && str[i+4] == '(')) {
        Stack = push(Stack, 'Q');
        PN[j++] = ' ';
    }
    if ((str[i] == 'l' && str[i+1] == 'n' && str[i+2] == '(')) {
        Stack = push(Stack, 'L');
        PN[j++] = ' ';
    }
    if (str[i] == '^') {
        Stack = push(Stack, '^');
        PN[j++] = ' ';
      }
    if (str[i] == 'x') {
        PN[j++] = str[i];
        PN[j++] = ' ';
    }
    if (str[i] == '-' && (str[i - 1] == '(' || i == 0))
        PN[i] = '~';
    if ((str[i] >= '0' && str[i] <= '9')
      && (str[i+1] >= '0' && str[i+1] <= '9')) {
        PN[j++] = str[i];
    } else if (str[i] >= '0' && str[i] <= '9') {
        PN[j++] = str[i];
        PN[j++] = ' ';
    }
    if (str[i] == '(' )
        Stack = push(Stack, str[i]);
    if ( str[i] == '+' || str[i] == '-' || str[i] == '*'
      || str[i] == '/' || str[i] == 'S' || str[i] == 'C'
      || str[i] == 'T' || str[i] == 'K' || str[i] == 'L'
      || str[i] == 'Q') {
      while (Stack != NULL && priora(Stack -> c) >= priora(str[i])) {
          Stack = pop(Stack, &a);
          PN[j++] = a;
          PN[j++] = ' ';
      }
        Stack = push(Stack, str[i]);
    }
    i++;
  }
  while (Stack !=NULL) {
      Stack = pop(Stack, &a);
      PN[j++] = a;
  }
    PN[j] = '\0';
  return function(PN, x);
}

int priora(char a) {
    int res;

    if (a == 'Q')
        res = 5;
    if (a == 'S' || a == 'C' || a == 'T'
        || a == 'L' || a == 'K' || a == '^')
        res = 4;
    if (a == '*' || a == '/')
        res = 3;
    if (a == '-' || a == '+')
        res = 2;
    if (a == '(')
        res = 1;
    if (a == '~')
        res = 0;

    return res;
}

struct node* push(struct node *Stack, char s) {
  struct node *new = (struct node*)malloc(sizeof(struct node));
  new -> c = s;
  new -> Next = Stack;
  return new;
}

struct node* pop(struct node *Stack, char *s) {
  struct node *old = Stack;
  *s = Stack -> c;
    Stack = Stack -> Next;
  free(old);
  return Stack;
}

