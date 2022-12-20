#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void add_door_test(struct node* doors_list);
void output_result_add_door_test(int place, struct node* doors_list);
void remove_door_test(struct node* doors_list);
void output_result_remove_door_test(int place, struct node* doors_list);
void print_door_list(struct node* doors_list);
void print_doors(struct node* root);

int main() {
struct door sample_door;
    sample_door.id = 1;
    sample_door.status = 1;
    struct node* doors_list = init(&sample_door);
    add_door_test(doors_list);
    remove_door_test(doors_list);
    destroy(doors_list);
    return 0;
}

void add_door_test(struct node* doors_list) {
    struct door sample_door;
    sample_door.id = 2;
    sample_door.status = 1;
    print_door_list(doors_list);
    printf("\nELEMENT FOR ADD %d,%d;\n", sample_door.id, sample_door.status);
    add_door(doors_list, &sample_door);
    output_result_add_door_test(sample_door.id, doors_list);
}

void output_result_add_door_test(int id, struct node* doors_list) {
    print_door_list(doors_list);
    printf("\n");
    if (find_door(id, doors_list) != NULL) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL");
    }
}
    void remove_door_test(struct node* doors_list) {
    print_door_list(doors_list);
    printf("\nELEMENT FOR DELETE %d,%d;\n", 2, 1);
    remove_door(doors_list->next, doors_list);
    print_door_list(doors_list);
    output_result_remove_door_test(2, doors_list);
}
void print_door_list(struct node* doors_list) {
printf("Cписок:\n");
    print_doors(doors_list);
}

void print_doors(struct node* root) {
    while (root != NULL) {
        printf("%d,%d\n", root->data.id, root->data.status);
        root = root->next;
}
}
void output_result_remove_door_test(int id, struct node* doors_list) {
        printf("\n");
        if (find_door(id, doors_list) == NULL) {
            printf("SUCCESS\n");
        } else {
            printf("FAIL\n");
        }
        }
