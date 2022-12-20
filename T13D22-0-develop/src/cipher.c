#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logger.h"
#include "log_levels.h"


int main() {
    FILE* log = log_init("log.txt");
    int a = 0; char k; int b;
    char c[500];
    char c1[50];
    FILE *f;
while (a != -1) {
    scanf("%d%c", &a, &k);
    if (((k != '\n')&&(k != '\0'))) {fflush(stdin);}
    switch (a) {
        case 1: {
            scanf("%s", c1);
            if (((f = fopen(c1, "r")) != NULL)) {
                while (!feof(f)) {
                    if (fgets(c, 10000, f) != NULL) {
                        printf("%s", c); char log_mes[61];
                        sprintf(log_mes, "open file %s\n", c1); logcat(log, log_mes, info);
                    } else { printf("n/a");  }
} printf("\n");
                    fclose(f);
            } else {
                char log_mes[500];
                sprintf(log_mes, "error while opening file %s\n", c1); logcat(log, log_mes, error);
                printf("n/a\n"); *c1 = '\0'; }
                fclose(f);
            break;}
        case 2: {
            if (((f = fopen(c1, "a")) != NULL)) {
            scanf("%s", c);
            fprintf(f, "%s", c);
                fclose(f); char log_mes[64];
                sprintf(log_mes, "changed file %s\n", c1); logcat(log, log_mes, info);
            if (((f = fopen(c1, "r")) != NULL)) {
                while (!feof(f)) {
                    if (fgets(c, 10000, f) != NULL) {
                        printf("%s", c);
                    } else { printf("n/a\n");
                        char log_mes[77];
                        sprintf(log_mes, "error while changing file %s\n", c1); logcat(log, log_mes, error); }
                    }
                fclose(f); printf("\n");}} else {
                    printf("n/a\n"); char log_mes[77]; sprintf(log_mes, "error while opening file %s \n", c1);
                    logcat(log, log_mes, error);}
         break;}
case 3: { scanf("%d", &b);
            char *buffer = malloc(sizeof(char) * 10000);
            FILE *fp = fopen("../src/ai_modules/m1.c", "r+");
long pos = ftell(fp);
        while (fgets(buffer, 500, fp) != NULL) {
            for (int j = 0; buffer[j] != '\0'; j++) {
                buffer[j] = buffer[j] + b; }
            fseek(fp, pos, SEEK_SET);
            fprintf(fp, "%s", buffer);
            fflush(fp);
            pos = ftell(fp); char log_mes[50];
            sprintf(log_mes, "ciphered file m1.c\n"); logcat(log, log_mes, info);
}
fclose(fp);
fp = fopen("../src/ai_modules/m2.c", "r+");
            pos = ftell(fp);
        while (fgets(buffer, 500, fp) != NULL) {
            for (int j = 0; buffer[j] != '\0'; j++) {
                buffer[j] = buffer[j] + b; }
            fseek(fp, pos, SEEK_SET);
            fprintf(fp, "%s", buffer);
            fflush(fp);
            pos = ftell(fp); char log_mes[50];
            sprintf(log_mes, "ciphered file m2.c\n"); logcat(log, log_mes, info);
}
            free(buffer);
            fclose(fp);
    fp = fopen("../src/ai_modules/m1.h", "w");
    char log_mes[50]; sprintf(log_mes, "cleaned file m1.h\n"); logcat(log, log_mes, info);
    fclose(fp);
    fp = fopen("../src/ai_modules/m2.h", "w");
    sprintf(log_mes, "cleaned file m2.h\n"); logcat(log, log_mes, info);
    fclose(fp);
break;}
case -1: {
            break;}
        default: {printf("n/a\n"); break;}}
}log_close(log);
return 0;
}
