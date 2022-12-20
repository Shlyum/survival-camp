#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct node* init(struct door* door) {
        struct node* A = malloc(sizeof(struct node));
        A->data.id = door->id;
        A->data.status = door->status;
        A->next = NULL;
    return A;
}
struct node* add_door(struct node* elem, struct door* door) {
    if (elem != NULL) {
    struct node* p = elem->next;
        elem->next = malloc(sizeof(struct node));
        elem->next->data.id = door->id;
        elem->next->data.status = door->status;
        elem->next->next = p;
    }
    return elem;
}
struct node* find_door(int door_id, struct node* root) {
    struct node* p = NULL; struct node* tmp = root;
    if (tmp != NULL) {
        while ((tmp->next != NULL)&&(tmp->data.id != door_id)) {
            tmp = tmp->next;
            if (tmp->data.id == door_id) p = tmp; }
    }
    return p;
}
struct node* remove_door(struct node* elem, struct node* root) {
    struct node* ans = root;
    if (root != NULL) { if (root == elem) {ans = root->next; free(root);} else {
        while ((root->next != NULL)&&(root->next != elem))
      root = root->next;
        if (root->next != NULL) {
        root->next = elem->next;
            free(elem);
    }
    }
    }
        return ans; }
void destroy(struct node* root) {
    while (root != NULL) {
        struct node* p = root->next;
        free(root);
        root = p;
    }
}
