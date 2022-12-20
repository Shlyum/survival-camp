#include <stdio.h>
#include <string.h>
#include "logger.h"
#include "log_levels.h"
#include <time.h>


FILE *log_init(char *filename) {
    return fopen(filename, "a");
}

void log_close(FILE *log_file) {
    fclose(log_file);
}

void logcat(FILE *log_file, char* message, enum log_level level) {
    char a[8];
    char c = fgetc(log_file);
    if (c != EOF) fprintf(log_file, "\n");
    time_t timer = time(NULL);
    char buffer[10];
    struct tm* tm_info = localtime(&timer);
    strftime(buffer, 10, "%H:%M:%S", tm_info);
    fprintf(log_file, "[%s]-%s-%s", level_str(a, level), buffer, message);
}

char* level_str(char* out, enum log_level level) {
switch (level) {
case 0: {
    out = "DEBUG"; break; }
case 1: {
    out = "TRACE"; break;
}
case 2: {
    out = "INFO"; break;
}
case 3: {
    out = "WARNING"; break;
}
case 4: {
    out = "ERROR"; break;
}
    default: break;}
    return out; }
