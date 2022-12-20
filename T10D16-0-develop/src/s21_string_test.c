#include <stdio.h>
#include "s21_string.h"
void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();


int main() {
    #ifdef STRLEN_TESTS
    s21_strlen_test();
    #endif  // STRLEN_TESTS
    #ifdef STRCMP_TESTS
    s21_strcmp_test();
    #endif  // STRCMP_TESTS
    #ifdef STRCPY_TESTS
    s21_strcpy_test();
    #endif  // STRCPY_TESTS
    #ifdef STRCAT_TESTS
    s21_strcat_test();
    #endif  // STRCAT_TESTS
    #ifdef STRCHR_TESTS
    s21_strchr_test();
    #endif  // STRCHR_TESTS
    #ifdef STRSTR_TESTS
    s21_strstr_test();
    #endif  // STRSTR_TESTS

return 0;}


void s21_strlen_test() {
    char *str1 = "The";
    char *str2 = "";
    char *str3 = "The dog has been selectively bred over millennia for various behaviors";
    char *str4 = "8";
    printf("%s\n", str1);
    printf("%d\n", s21_strlen(str1));
    if (s21_strlen(str1) == 3) { printf("SUCCESS\n");
    } else { printf("FAIL\n"); }
    printf("%s\n", str2);
    printf("%d\n", s21_strlen(str2));
    if (s21_strlen(str2) == 0) { printf("SUCCESS\n");
    } else { printf("FAIL\n"); }
    printf("%s\n", str3);
    printf("%d\n", s21_strlen(str3));
    if (s21_strlen(str3) == 70) { printf("SUCCESS\n");
    } else { printf("FAIL\n"); }
    printf("%s\n", str4);
    printf("%d\n", s21_strlen(str4));
    if (s21_strlen(str4) == 1) { printf("SUCCESS\n");
    } else { printf("FAIL\n"); }
}
    void s21_strcmp_test() {
    char *str5 = "qwer";
    char *str6 = "qwer";
    char *str7 = "AAA";
    char *str8 = "AAA";
    char *str9 = "The";
    char *str13 = "The";
    char *str11 = "The dog has been selectively bred over millennia for various behaviors";
    char *str14 = "The dog has been selectively bred over millennia for various behaviors";
    printf("%s\n%s\n", str5, str6);
    printf("%d\n", s21_strcmp(str5, str6));
        if (s21_strcmp(str5, str6) == 0) { printf("SUCCESS\n");
        } else { printf("FAIL\n"); }
    printf("%s\n%s\n", str7, str8);
    printf("%d\n", s21_strcmp(str7, str8));
        if (s21_strcmp(str7, str8) == 0) { printf("SUCCESS\n");
        } else { printf("FAIL\n"); }
    printf("%s\n%s\n", str13, str9);
    printf("%d\n", s21_strcmp(str13, str9));
        if (s21_strcmp(str13, str9) == 0) { printf("SUCCESS\n");
        } else { printf("FAIL\n"); }
    printf("%s\n%s\n", str11, str14);
    printf("%d\n", s21_strcmp(str11, str14));
        if (s21_strcmp(str11, str14) == 0) { printf("SUCCESS\n");
        } else { printf("FAIL\n"); }
}
    void s21_strcpy_test() {
        char str12[100] = "!@#$@%#^$&%*^&%$##";
        char str10[100] = "Hello World";
        char str17[100] = "THE";
        char str20[100] = "AAA";
        char str1[100] = "!";
        char str2[100] = "QWERFDSA";
        printf("%s\n%s\n", str12, str10);
        s21_strcpy(str12, str10);
        printf("%s\n%s\n", str12, str10);
        if (*str12 == *str10) { printf("SUCCESS\n");
        } else { printf("FAIL\n"); }
        printf("%s\n%s\n", str17, str20);
        s21_strcpy(str17, str20);
        printf("%s\n%s\n", str17, str20);
        if (*str17 == *str20) { printf("SUCCESS\n");
        } else { printf("FAIL\n"); }
        printf("%s\n%s\n", str1, str2);
        s21_strcpy(str1, str2);
        printf("%s\n%s\n", str1, str2);
        if (*str1 == *str2) { printf("SUCCESS\n");
        } else { printf("FAIL\n"); }
}

void s21_strcat_test() {
    char str1[] = "hello";
    char str2[] = " world!";
    char str3[] = "hello world!";
    char str4[] = "QWER";
    char str5[] = "LLL";
    char str6[] = "!!!@#!$@";
    char str7[] = "TY";
    char str8[] = "QWERTY";
    char str9[] = "LLL!!!@#!$@";
    printf("%s\n", str1);
    printf("%s\n", str2);
    s21_strcat(str1, str2);
    printf("%s\n", str1);
    if (s21_strcmp(str1, str3) == 0) { printf("SUCCESS\n");
    } else { printf("FAIL\n"); }
    printf("%s\n", str4);
    printf("%s\n", str7);
    s21_strcat(str4, str7);
    printf("%s\n", str4);
    if (s21_strcmp(str4, str8) == 0) { printf("SUCCESS\n");
    } else { printf("FAIL\n"); }
    printf("%s\n", str5);
    printf("%s\n", str6);
    s21_strcat(str5, str6);
    printf("%s\n", str5);
    if (s21_strcmp(str5, str9) == 0) { printf("SUCCESS\n");
    } else { printf("FAIL\n"); }
}

void s21_strchr_test() {
    char str1[] = "0163456769";
    char str2[] = "9999999999999999999999999999999999999999999999999999";
    char str3[] = "SUPER";
    int ch1 = '7';
    int ch2 = '9';
    int ch3 = 'P';
    char *ach;
    printf("%s\n", str1);
    printf("%c\n", ch1);
    ach = s21_strchr(str1, ch1);
    printf("%ld\n", ach-str1+1);
    if (ach-str1+1 == 8) { printf("SUCCESS\n");
    } else { printf("FAIL\n"); }
    printf("%s\n", str2);
    printf("%c\n", ch2);
    ach = s21_strchr(str2, ch2);
    printf("%ld\n", ach-str2+1);
    if (ach-str2+1 == 1) { printf("SUCCESS\n");
    } else { printf("FAIL\n"); }
    printf("%s\n", str3);
    printf("%c\n", ch3);
    ach = s21_strchr(str3, ch3);
    printf("%ld\n", ach-str3+1);
    if (ach-str3+1 == 3) { printf("SUCCESS\n");
    } else { printf("FAIL\n"); }
}

void s21_strstr_test() {
    char str1[] = "1233345hello";
    char sub[] = "345";
    char str2[] = "345hello";
    char str3[] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    char sub1[] = "A";
    char str4[] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    char str5[] = "!@#$%^&*()(*&^%$#";
    char sub2[] = "$%^&";
    char str6[] = "$%^&*()(*&^%$#";
    printf("%s\n", str1);
    printf("%s\n", sub);
    printf("%s\n", s21_strstr(str1, sub));
    if (s21_strcmp(s21_strstr(str1, sub), str2) == 0) { printf("SUCCESS\n");
    } else { printf("FAIL\n"); }
    printf("%s\n", str3);
    printf("%s\n", sub1);
    printf("%s\n", s21_strstr(str3, sub1));
    if (s21_strcmp(s21_strstr(str3, sub1), str4) == 0) { printf("SUCCESS\n");
    } else { printf("FAIL\n"); }
    printf("%s\n", str5);
    printf("%s\n", sub2);
    printf("%s\n", s21_strstr(str5, sub2));
    if (s21_strcmp(s21_strstr(str5, sub2), str6) == 0) { printf("SUCCESS\n");
    } else { printf("FAIL\n"); }
}
