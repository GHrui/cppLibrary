typedef int ElementType;

#ifndef _Stack_h
#define _Stack_h

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty(Stack S);  // check the stack is or not empty
int IsFull(Stack S);  // check the stack is or not full
Stack CreateStack(int MaxElements);  // create a stack with MaxElements size
void DisposeStack(Stack S);  // free the stack
void MakeEmpty(Stack S);  // make the stack empty
void Push(ElementType X, Stack S);  // put a element into stack
ElementType Top(Stack S);  // delete the element on the top postion on the stack
void Pop(Stack S);  // dispaly the element on the top postion on the stack
ElementType TopAndPop(Stack S);  // this function combine the functions of Top and Pop function

#endif