// Linked list related operations.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int data;
  struct Node* next;
};

// print list in format "[1; 2; 3]""
void print_list(struct Node* head_ptr){
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
int len(struct Node* head_ptr){
    int length = 0;
    while(head_ptr != NULL){
        head_ptr = head_ptr->next;
        length++;
    }
    return length;
}

void append(struct Node* head_ptr, int value){
    struct Node* node_ptr = malloc(sizeof(struct Node));
    if (node_ptr == NULL) { //check if malloc succeeded
        fprintf(stderr, "New node memory allocation failed\n");
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

int main()
{
    struct Node head;
    head.data = 11;
    
    struct Node el1;
    head.next = &el1;
    el1.data = 12;
    
    struct Node el2;
    el1.next = &el2;
    el2.data = 13;
    el2.next = NULL;
    
    print_list(&head);
    printf("Length: %d\n", len(&head));
    
    append(&head, 14);
    append(&head, 15);
    printf("Length after appends: %d\n", len(&head));
    print_list(&head);

    return 0;
}
