#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct DynArrayInt {
    int* head_ptr;
    int n_elements;
};

void init_array(struct DynArrayInt* arr_ptr){
    arr_ptr->head_ptr = NULL;
    arr_ptr->n_elements = 0;
}

void append(struct DynArrayInt* arr_ptr, int element){
    if (arr_ptr->head_ptr == NULL){
        arr_ptr->head_ptr = (int*)malloc(sizeof(int));
        if (arr_ptr->head_ptr == NULL){
            fprintf(stderr, "Memory weren't allocated successfully\n");
        }
        *(arr_ptr->head_ptr) = element;
        arr_ptr->n_elements = 1;
        printf("Element added at %p\n", arr_ptr->head_ptr);
    } else {
        int new_n_elements = arr_ptr->n_elements + 1;
        int* new_head_ptr = (int*)realloc(arr_ptr->head_ptr, new_n_elements * sizeof(int));
        if (new_head_ptr == NULL){
            fprintf(stderr, "Memory weren't reallocated successfully\n");
        }
        *(new_head_ptr + new_n_elements - 1) = element;
        printf("Element added at %p\n", new_head_ptr + new_n_elements - 1);
        
        
        arr_ptr->head_ptr = new_head_ptr;
        arr_ptr->n_elements = new_n_elements;
    }
}

bool get_by_idx(struct DynArrayInt* arr_ptr, int index, int* output){
    if (index < 0){
        fprintf(stderr, "Index cannot be negative.\n");
        return false;
    } else if (index >= arr_ptr->n_elements) {
        fprintf(stderr, "Index out of bound.\n");
        return false;
    } else {
        *output = *(arr_ptr->head_ptr + index);
        return true;
    }
}

int main(){
    
    struct DynArrayInt arr1;
    init_array(&arr1);
    append(&arr1, 11);
    append(&arr1, 12);
    append(&arr1, 13);
    
    // Getting values by index
    int output_0;
    if (get_by_idx(&arr1, 0, &output_0)){
        printf("Value at index 0: %d\n", output_0);
    }

    int output_1;
    if (get_by_idx(&arr1, 1, &output_1)){
        printf("Value at index 1: %d\n", output_1);
    }

    int output_2;
    if (get_by_idx(&arr1, 2, &output_2)){
        printf("Value at index 2: %d\n", output_2);
    }

    int output_3;
    if (get_by_idx(&arr1, 3, &output_3)){
        printf("Value at index 3: %d\n", output_3);
    }
    
    return 0;
}
