// Linked list related operations.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int data;
  struct Node* next;
};

// print list in format "[1; 2; 3]""
void print_list(const struct Node* head_ptr){
    printf("[");
    while(head_ptr != NULL){
        printf("%d", head_ptr->data);
        head_ptr = head_ptr->next;
        if (head_ptr != NULL){
             printf("; ");
        }
    }
    printf("]\n");
}

// calculate len of linked list
int len(const struct Node* head_ptr){
    int length = 0;
    while(head_ptr != NULL){
        head_ptr = head_ptr->next;
        length++;
    }
    return length;
}

void append(struct Node* head_ptr, int value){
    if (head_ptr == NULL){
        fprintf(stderr, "Cannot append to NULL node\n");
        return;
    }

    struct Node* node_ptr = malloc(sizeof(struct Node));
    if (node_ptr == NULL) { //check if malloc succeeded
        fprintf(stderr, "New node memory allocation failed\n");
        return;
    }
    node_ptr->data = value;
    node_ptr->next = NULL;
    
    while(true){
        if (head_ptr->next == NULL){
            head_ptr->next = node_ptr;
            break;
        }
        head_ptr = head_ptr->next;
    }
}

// clean up the memory allocated on heap
void free_list(struct Node* head_ptr){
    while(head_ptr != NULL){
        struct Node* node_to_free = head_ptr;
        head_ptr = head_ptr->next;
        free(node_to_free);
    }
}

// Get value by index
int get_by_index(const struct Node* head_ptr, int get_index){
    for (int idx = 0; idx < get_index; idx++){
        head_ptr = head_ptr->next;
        if (head_ptr == NULL){
            fprintf(stderr, "Index out of bound: %d\n", get_index);
            return 0;
        }
    }
    int value = head_ptr->data;
    return value;
}

// Get value by index - bound safe version
bool get_by_index_safe(const struct Node* head_ptr, int get_index, int* value){
    for (int idx = 0; idx < get_index; idx++){
        head_ptr = head_ptr->next;
        if (head_ptr == NULL){
            fprintf(stderr, "Index out of bound: %d\n", get_index);
            return false;
        }
    }

    *value = head_ptr->data;
    return true;
}

int main(){
    struct Node* head_ptr = malloc(sizeof(struct Node));
    if (!head_ptr) {
        fprintf(stderr, "Failed to allocate head\n");
        return 1;
    }
    head_ptr->data = 11;
    head_ptr->next = NULL;
    
    // Manual approach for simplicity
    struct Node* el1 = malloc(sizeof(struct Node));
    if (!el1) {
        fprintf(stderr, "Failed to allocate el1\n");
        return 1;
    }
    head_ptr->next = el1;
    el1->data = 12;
    
    struct Node* el2 = malloc(sizeof(struct Node));
    if (!el2) {
        fprintf(stderr, "Failed to allocate el2\n");
        return 1;
    }
    el1->next = el2;
    el2->data = 13;
    el2->next = NULL;
    
    print_list(head_ptr);
    printf("Length: %d\n", len(head_ptr));
    
    append(head_ptr, 14);
    append(head_ptr, 15);
    printf("Length after appends: %d\n", len(head_ptr));
    print_list(head_ptr);

    printf("index 0: %d\n", get_by_index(head_ptr, 0));
    printf("index 1: %d\n", get_by_index(head_ptr, 1));
    printf("index 2: %d\n", get_by_index(head_ptr, 2));
    printf("index 4: %d\n", get_by_index(head_ptr, 4));
    printf("index 5: %d\n", get_by_index(head_ptr, 5)); // index out of bound

    int value_at_4;
    if (get_by_index_safe(head_ptr, 4, &value_at_4)){
        printf("safe get index 4: %d\n", value_at_4);
    }

    int value_at_5;
    if (get_by_index_safe(head_ptr, 5, &value_at_5)){
        // will not be executed
        printf("safe get index 5: %d\n", value_at_5);
    }

    free_list(head_ptr);

    return 0;
}
