#include "Stack.h"
#include "Fatal.h"
#include<iostream>

/**
 * Place in implementation file
 * Stack implementation is a dynamically allocated array
*/
#define EmptyTOS -1  // if stack is empty, and its top postion is -1
#define MinStackSize 5

struct StackRecord {
    int Capacity;  // size of the stack
    int TopOfStack;
    int *Array;
};

Stack CreateStack (int MaxElements) {
    Stack S;

    if (MaxElements < MinStackSize) {
        Error("Stack size is Small.");
    }
    S = malloc(sizeof(struct StackRecord));
    if (S == NULL) {
        FatalError("Out of space!");
    }
    S->Array = malloc(sizeof(ElementType) * MaxElements);
    if (S->Array == NULL) {
        FatalError("Out of space!");
    }
    S->Capcity = MaxElements;
    MakeEmpty(S);

    return S;
}

void DisposeStack (Stack S) {
    if(S != NULL) {
      free(S->Array);
      free(S);  
    }
}

int IsEmpty (Stack S) {
    return S->TopOfStack == EmptyTOS;
}

void MakeEmpty (Stack S) {
    S->TopOfStack = EmptyTOS;
}

void Push (ElementType X, Stack S) {
    if (IsFull(S)) {
        Error("Full stack.");
    }
    else {
        S->Array[++S->TopOfStack] = X;
    }
}

ElementType Top (Stack S) {
    if (!IsEmpty(S)) {
        return S->Array[S->TopOfStack];
    }
    Error("Empty stack.");
    return 0;
}

void Pop (Stack S) {
    if (IsEmpty(S)) {
        Error("Empty stack.");
    }
    else {
        --(S->TopOfStack);
    }
}

ElementType TopAndPop (Stack S) {
    if (!IsEmpty(S)) {
        return S->Array[(S->TopOfStack)--];
    }
    Error("Empty stack.");
    return 0;
}