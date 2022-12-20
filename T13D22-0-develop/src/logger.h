#ifndef SRC_LOGGER_H_
#define SRC_LOGGER_H_
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "log_levels.h"

FILE *log_init(char *filename);
void log_close(FILE *log_file);
void logcat(FILE *log_file, char* message, enum log_level level);
char* level_str(char* out, enum log_level level);


#endif  //  SRC_LOGGER_H_
