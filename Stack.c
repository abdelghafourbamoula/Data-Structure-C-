#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{
    int data;
    struct Element* next;
} Element;

typedef struct Stack
{
    Element* head;
    int size;
} Stack;

Stack* initStack() {
    Stack* stack = malloc(sizeof(struct Stack));
    stack->head = NULL;
    stack->size = 0;
}

Element* createElement(int data) {
    Element* elem = malloc(sizeof(struct Element));
    elem->data = data;
    elem->next = NULL;
    return elem;
}

int isEmpty(Stack* stack) {
    return stack->size == 0;
}

void printStack(Stack* stack) {

    if (! isEmpty(stack)) {  
        Element* head = stack->head;
        printf("\n");
        while (head != NULL) {
            printf("| %d |\n", head->data);
            head = head->next;
        }
        printf("-----\n\n");
    }
    else {
        printf("Stack is empty ...");
    }
}

void push(Stack* stack, int data) {
    Element* elem = createElement(data);
    elem->next = stack->head;
    stack->head = elem;
    stack->size++;
}

int pop(Stack* stack){
    if (! isEmpty(stack)) {
        Element* temp = stack->head; 
        int data = temp->data;    
        stack->head = stack->head->next;
        stack->size--;
        free(temp);
        return data;
    }
    else {
        printf("Stack is empty ...");
    }
}

int peek(Stack* stack) {
    return stack->head->data;
}

void clear(Stack* stack){
   while (! isEmpty(stack)) {
        pop(stack);
   }
   
   stack = initStack(); 
}


int main(int argc, char const *argv[])
{
    Stack* stack = initStack();
    printf("size: %d - is empty: %d\n", stack->size, isEmpty(stack));

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    printStack(stack);


    printf("poped: %d\n", pop(stack));
    printStack(stack);

    push(stack,5);
    printStack(stack); 
    printf("size: %d\n", stack->size);

    printf("peeked: %d\n", peek(stack));
    printStack(stack);
    printf("size: %d\n", stack->size);

    clear(stack);
    printStack(stack);

    return 0;
}
