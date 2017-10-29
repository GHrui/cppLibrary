#include "Stack.h"
#include "Fatal.h"
#include<iostream>

/**
 * Place in implementation file
 * Stack implementation is a linked list with a header
*/
struct Node {
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty (Stack S) {
    return S->Next = NULL;
}

Stack CreateStack (void) {
    Stack S;

    S = malloc(sizoeof(struct Node));
    if (S == NULL) {
        Error("Out of space.");
    }
    MakeEmpty(Stack S);
    return S;
}

void MakeEmpty (Stack S) {
    if (S == NULL) {
        Error("Must use CreateStack first.");
    }
    else {
        while (!IsEmpty(S)) {
            Pop(S);
        }
    }
}

void Push (ElementType X, Stack S) {
    PtrToNode TmpCell;

    TmpCell = malloc(sizeof(Struct Node));
    if (TmpCell == NULL) {
        FatalError("Out of space.");
    }
    else {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

ElementType Top (Stack S) {
    if (!IsEmpty(S)) {
        return S->Next->Element;
    }
    Error("Empty stack.");
    return 0;
}

void Pop (Stack S) {
    PtrToNode FirstCell;

    if (IsEmpty(S)) {
        Error("Empty stack.");
    }
    else {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}