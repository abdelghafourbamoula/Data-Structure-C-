#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

void printList(struct Node* node) {
    
    while (node != NULL) {
        printf("%d", node->data);

        if(node->next != NULL)
            printf(" -> ");

        node = node->next;
    }
    printf("\n");
}

void printInv(struct Node* head) {
    struct Node* node = head;

    while (node->next != NULL) {
        node = node->next;
    }

    while (node != NULL) {
        printf("%d", node->data);

        if(node->prev != NULL)
            printf(" -> ");

        node = node->prev;
    }
    printf("\n");
}

void push(struct Node** head, int data){
    
    if (*head != NULL) {    
        struct Node* node = createNode(data);
        node->next = (*head);
        (*head)->prev = node;
        (*head) = node;
    }
    else {
        printf("the list is empty ...");
    }
}

void append(struct Node* head, int data){

    while (head->next != NULL){
        head = head->next;
    } 

    struct Node* node = createNode(data);
    node->prev = head;
    node->next = NULL;

    head->next = node;
}

void pop(struct Node** head) {
    if ((*head)->next != NULL && (*head)->prev == NULL) {
        (*head)->next->prev = NULL;
        *head = (*head)->next;
    }
    else {
        printf("The list is empty or has another head ...");
    }
}

void popLast(struct Node* head) {
    while (head->next != NULL) {
        head = head->next;
    }

    head->prev->next = NULL;
    head->prev = NULL;
    free(head);
}

void delete(struct Node* head, int data) {
    if (head->data == data){
        pop(&head);
    }
    else {
        while (head != NULL){

            if (head->data == data) {
                if (head->next == NULL){
                    popLast(head);
                    break;
                }

                head->prev->next = head->next;
                head->next->prev = head->prev;
                head->next = NULL;
                head->prev = NULL;
                free(head);
            }

            head = head->next;
        }    
    } 
}

void insertAfter(struct Node* head, int data, int value) {

    while (head->next != NULL) {
        if (head->data == data) {
            struct Node* node = createNode(value);
            node->next = head->next;
            head->next->prev = node;
            head->next = node;
            node->prev = head;
            return;
        }
        head = head->next;
    }

    if (head->data == data) {
        append(head, value);
    }    
}

void insertBefore(struct Node* head, int data, int value) {
   
    while (head->next != NULL) {
        if (head->data == data) {
            struct Node* node = createNode(value);
            head->prev->next = node;
            node->prev = head->prev;
            node->next = head;
            head->prev = node;
            return;
        }
        head = head->next;
    }
}

void InsertBetween(struct Node* head, int after, int before, int value) {
    while (head->next != NULL) {
        if (head->data == after && head->next->data == before){
            insertAfter(head, after, value);
        }
        head = head->next;
    }
}

int length(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}


int main(int argc, char const *argv[])
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->prev = NULL;
    head->next = second;

    second->data = 2;
    second->prev = head;
    second->next = third;

    third->data = 3;
    third->prev = second;
    third->next = NULL;

    // print List
    printf("Forward: ");
    printList(head);
    printf("Backward: ");
    printInv(head);
    printf("length: %d\n", length(head));

    push(&head, 0);
    printList(head);
    // printInv(head);

    append(head, 4);
    printList(head);

    pop(&head);
    printList(head);
    // printInv(head);

    popLast(head);
    printList(head);

    delete(head,2);
    printList(head);

    insertAfter(head,1,22);
    printList(head);
    insertAfter(head,3,4);
    printList(head);

    insertBefore(head,22,2);
    printList(head);

    InsertBetween(head,1,2,11);
    printList(head);
    InsertBetween(head,3,4,33);
    printList(head);

    return 0;
}