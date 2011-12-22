/*
 * This is a driver program
 */
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv[])
{

    // create stack
    stack_t st;
    st.head = NULL;

    // create 3 nodes and push them on the stack
    node_t *first_node = (node_t *) malloc(sizeof(node_t));
    first_node->elm = (int *) malloc(sizeof(int));
    *first_node->elm = 10;
    first_node->next = NULL;

    node_t *second_node = (node_t *) malloc(sizeof(node_t));
    second_node->elm = (int *) malloc(sizeof(int));
    *second_node->elm = 20;
    second_node->next = NULL;


    node_t *third_node = (node_t *) malloc(sizeof(node_t));
    third_node->elm = (int *) malloc(sizeof(int));
    *third_node->elm = 30;
    third_node->next = NULL;

    push(&st, first_node);
    push(&st, second_node);
    push(&st, third_node);

    // pop 2 elements
    node_t *topa;
    topa = pop(&st);

    assert(topa != NULL);
    assert(*topa->elm == 30);

    topa = pop(&st);
    assert(topa != NULL);
    assert(*topa->elm == 20);

    // create 1 node 
    node_t *fourth_node = (node_t *) malloc(sizeof(node_t));
    fourth_node->elm = (int *) malloc(sizeof(int));
    *fourth_node->elm = 50;
    fourth_node->next = NULL;

    push(&st, fourth_node);

    // pop 2 elements 
    topa = pop(&st);

    assert(topa != NULL);
    assert(*topa->elm == 50);

    topa = pop(&st);
    assert(topa != NULL);
    assert(*topa->elm == 10);

    // ensure stack is empty
    topa = pop(&st);
    assert(topa == NULL);

    free(first_node->elm);
    free(first_node);
    free(second_node->elm);
    free(second_node);
    free(third_node->elm);
    free(third_node);
    free(fourth_node->elm);
    free(fourth_node);
    return 0;
}
