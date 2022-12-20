#ifndef CODE_SAMPLES_BINARY_FILES_COMMON_FUNCTIONS_H_
#define CODE_SAMPLES_BINARY_FILES_COMMON_FUNCTIONS_H_
#include <stdio.h>
struct my_struct{
    int year;
    int mounth;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
};


struct my_struct read_record_from_file(FILE *pfile, int index);
void write_record_in_file(FILE *pfile, const struct my_struct *record_to_write, int index);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);
#endif  //  CODE_SAMPLES_BINARY_FILES_COMMON_FUNCTIONS_H_
