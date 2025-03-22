// Linked list related operations.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int data;
  struct Node* next;
};

void print_list(struct Node* head_ptr){
    int index = 0;
    while(true){
        printf("%d\n", head_ptr->data);
        head_ptr = head_ptr->next;
        index++;
        if (head_ptr == NULL){
            break;
        }
    }
    printf("Linked list traverse is complete");
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

    return 0;
}
