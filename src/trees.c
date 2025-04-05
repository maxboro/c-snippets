// Simple binary tree implementation
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node {
    struct Node* child_left_ptr;
    struct Node* child_right_ptr;
    struct Node* parent_ptr;
    int id;
};

void init_node(struct Node* node_ptr, int id){
    if (node_ptr == NULL){
        fprintf(stderr, "Cannot init node, NULL pointer provided.\n");
        return;
    }
    node_ptr->child_left_ptr = NULL;
    node_ptr->child_right_ptr = NULL;
    node_ptr->parent_ptr = NULL;
    node_ptr->id = id;
}

bool connect_nodes(struct Node* child_ptr, struct Node* parent_ptr){
    if (child_ptr == NULL || parent_ptr == NULL){
        fprintf(stderr, "Cannot connect nodes, NULL pointer provided.\n");
        return false;
    }

    if (child_ptr->parent_ptr != NULL){
        fprintf(stderr, "This child node already has parent.\n");
        return false;
    }

    if (parent_ptr->child_left_ptr == NULL){
        parent_ptr->child_left_ptr = child_ptr;
    } else if (parent_ptr->child_right_ptr == NULL){
        parent_ptr->child_right_ptr = child_ptr;
    } else {
        fprintf(stderr, "This parent node already has both child node.\n");
        return false;
    }
    
    child_ptr->parent_ptr = parent_ptr;
    return true;
}

void show_parents_chain(struct Node* node_ptr){
    if (node_ptr == NULL){
        fprintf(stderr, "Cannot show parents, NULL pointer provided.\n");
        return;
    }

    while (node_ptr != NULL){
        printf("Node with id %d\n", node_ptr->id);
        node_ptr = node_ptr->parent_ptr;
    }
    printf("\n");
}

int main()
{
    struct Node node_1;
    init_node(&node_1, 11);
    
    struct Node node_2;
    init_node(&node_2, 12);

    struct Node node_3;
    init_node(&node_3, 13);

    struct Node node_4;
    init_node(&node_4, 14);

    connect_nodes(&node_2, &node_1);
    connect_nodes(&node_3, &node_2);
    connect_nodes(&node_4, &node_1);
    
    printf("Chain from node_4 and up:\n");
    show_parents_chain(&node_4);

    printf("Chain from node_3 and up:\n");
    show_parents_chain(&node_3);
    return 0;
}
