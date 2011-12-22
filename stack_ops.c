#include "stack.h"
#include <assert.h>
#include <stdio.h>

node_t *top(stack_t * /*st */ );

int push(stack_t * st, node_t * node)
{

    // check if it is valid stack
    if (st == NULL) {
	return -1;
    }
    // go to the end of the list
    node_t *curr_node = top(st);

    if (curr_node == NULL) {
	st->head = node;
	return 0;
    }
    // append to the end of the list
    curr_node->next = node;
    node->next = NULL;
    return 0;
}

/*
 * This method removes top of the element from the stack
 */
node_t *pop(stack_t * st)
{
    if (st == NULL) {
	return NULL;
    }
    //check if the stack is empty
    if (st->head == NULL) {
	return NULL;
    }
    // get new top of the stack
    node_t *new_top = st->head;
    node_t *top;

    // check if there is only one element in the stack
    if (new_top->next == NULL) {
	top = st->head;
	st->head = NULL;
	return top;
    }

    while (new_top->next->next != NULL) {
	new_top = new_top->next;
    }

    top = new_top->next;
    new_top->next = NULL;

    return top;
}

/*
 * get top of the stack
 */
node_t *top(stack_t * st)
{

    assert(st != NULL);

    // go to the end of the list
    node_t *curr_node = st->head;

    // if stack is not initialized or empty    
    if (curr_node == NULL) {
	return NULL;
    }

    while (curr_node->next != NULL) {
	curr_node = curr_node->next;
    }
    assert(curr_node->next == NULL);
    return curr_node;
}
