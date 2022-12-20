#include <stdio.h>
#include "s21_string.h"

int s21_strlen(char *str) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
        }
    return count;}

int s21_strcmp(char *str1, char *str2) {
    for (; *str1&&*str1 == *str2; str1++, str2++) {
    }
    return *str1-*str2;
}

char *s21_strcpy(char *str1, const char *str2) {
    char *tmp = str1;
    while ((*str1++ = *str2++) != '\0') {
    }
    return tmp;
}

char *s21_strcat(char *destination, const char *sourse) {
    int i, j;
    for (i = 0; destination[i] != '\0'; i++)
    for (j = 0; sourse[j] != '\0'; j++) {
            destination[i + j] = sourse[j];
        }
    destination[i + j] = '\0';
    return destination;
}

char *s21_strchr(char* str, int c) {
while (*str != '\0') {
            if (*str == c)
                return str;
            else
                str++;
        }
        return NULL;
    }
char *s21_strstr(char *str, char *sub_str) {
for(int i = 0; str[i] != '\0'; i++) {
int tem = i;
        int j = 0;
        while (str[i++] == sub_str[j++]) {
            if (sub_str[j] == '\0') {
                return &str[tem];
            }
        }
        i = tem;
    }

    return NULL;
}
