/*
 * This is interface of stack implementation.
 *
 */

#ifndef STACK_H
#define STACk_H 1

// element data type is configurable
typedef int element_t;

struct _node_t;

typedef struct _node_t node_t;

// each element in the stack is represented by this node.
struct _node_t{
   element_t* elm;
   node_t* next;
};


//stack ADT
typedef struct {
  node_t* head;  // head element of the stack
} stack_t;

/*
 * This method pushes node on top of the list;
 */
int push(stack_t* /*st*/, node_t* /*node*/);

/*
 * This method pops the top of the list;
 */
node_t* pop(stack_t* /*st*/);

#endif
