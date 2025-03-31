#include <stdio.h>
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
    int new_n_elements = arr_ptr->n_elements + 1;
    int* new_head_ptr = (int*)realloc(arr_ptr->head_ptr, new_n_elements * sizeof(int));
    
    *(new_head_ptr + new_n_elements) = element;
    
    
    arr_ptr->head_ptr = new_head_ptr;
    arr_ptr->n_elements = new_n_elements;
}

int get_by_idx(struct DynArrayInt* arr_ptr){

}

int main(){
    
    struct DynArrayInt arr1;
    init_array(&arr1);
    append(&arr1, 11);
    append(&arr1, 12);
    append(&arr1, 13);
    
    printf("Hello World");

    return 0;
}
