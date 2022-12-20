#include "../code-samples/binary_files_common_functions.h"
#include <stdio.h>
int compare(struct my_struct in1, struct my_struct in2);





int main() {
    char arr[100];
    int n;
    struct my_struct door;
    struct my_struct in2;
    struct my_struct in1;
    struct my_struct in3;
    scanf("%s", arr);
    scanf("%d", &n);
    switch (n) {
case 0: {
    FILE *filename = fopen(arr, "r+b");
    if (filename) { int a = 0;
    a = get_records_count_in_file(filename);
    for (int i = 0; i < a; i++) {
        door = read_record_from_file(filename, i);
        printf("%d %d %d %d %d %d %d %d", door.year, door.mounth,
               door.day, door.hour, door.minute, door.second, door.status, door.code);
        if (i < a-1) printf("\n");
    } fclose(filename); } else {printf("n/a");}break; }
        case 1:  {FILE *file = fopen(arr, "r+b");
if (file) {int b = get_records_count_in_file(file);
                for (int i = 0; i < b; i++) {
                    for (int j = 0; j < b; j++) {
                        in1 = read_record_from_file(file, i);
                        in2 = read_record_from_file(file, j);
                        if (compare(in1, in2) == 1) {swap_records_in_file(file, i , j);}
                    }
                }

            for (int i = b; i > 0; i--) {
                in1 = read_record_from_file(file, i);
                printf("%d %d %d %d %d %d %d %d", in1.year, in1.mounth,
                       in1.day, in1.hour, in1.minute, in1.second, in1.status, in1.code);
                if (i > 1) printf("\n");
} fclose(file);
} else {printf("n/a");}
break; }
case 2: {scanf("%d %d %d %d %d %d %d %d", &in3.year, &in3.mounth,
               &in3.day, &in3.hour, &in3.minute, &in3.second, &in3.status, &in3.code);
            FILE *pfile = fopen(arr, "r+b");
            if (pfile) { int c = get_records_count_in_file(pfile);
               write_record_in_file(pfile, &in3, c);
                for (int i = 0; i < c+1; i++) {
                    for (int j = 0; j < c+1; j++) {
                        in1 = read_record_from_file(pfile, i);
                        in2 = read_record_from_file(pfile, j);
                        if (compare(in1, in2) == 1) {swap_records_in_file(pfile, i , j);}
                    }
                }
                for (int i = c; i > 0; i--) {
                    in1 = read_record_from_file(pfile, i);
                    printf("%d %d %d %d %d %d %d %d", in1.year, in1.mounth,
                           in1.day, in1.hour, in1.minute, in1.second, in1.status, in1.code);
                    if (i > 1) printf("\n");
}
                fclose(pfile);
                } else {printf("n/a");} break;}
        default: printf("n/a");  break; }
return 0;
}

int compare(struct my_struct in1, struct my_struct in2) {
    int res = 0;
    if ((in1.year > in2.year) ||
        ((in1.year == in2.year)&&(in1.mounth > in2.mounth)) ||
        ((in1.year == in2.year)&&(in1.mounth == in2.mounth)&&(in1.day > in2.day)) ||
        ((in1.year == in2.year)&&(in1.mounth == in2.mounth)&&(in1.day == in2.day)&&(in1.hour > in2.hour)) ||
        ((in1.year == in2.year)&&(in1.mounth == in2.mounth)&&
         (in1.day == in2.day)&&(in1.hour == in2.hour)&&(in1.minute > in2.minute)) ||
        ((in1.year == in2.year)&&(in1.mounth == in2.mounth)&&
         (in1.day == in2.day)&&(in1.hour == in2.hour)&&(in1.minute == in2.minute)&&(in1.second > in2.second)))
    {res = 1;}
return res;}
