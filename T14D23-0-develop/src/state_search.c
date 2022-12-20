#include "../code-samples/binary_files_common_functions.h"
#include <stdio.h>
int main() {
    char arr[100];
    struct my_struct door;
    scanf("%s", arr);
    FILE *filename = fopen(arr, "r+b");
    if (filename) {
        int y; int m; int d;
        if (!scanf("%d.%d.%d", &d, &m, &y)) {printf("n/a");
} else {
    int a = 0;
    a = get_records_count_in_file(filename);
    for (int i = 0; i < a; i++) {
        door = read_record_from_file(filename, i);
        if (y == door.year && m == door.mounth && d == door.day) { printf("%d", door.code); }
        break;
    } fclose(filename);
        }} else {printf("n/a");}
    return 0;}
