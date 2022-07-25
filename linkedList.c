#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};


void printList(struct Node* node){
    while (node != NULL)
    {
        printf("%d -> ", node->data);

        if (node->next == NULL){
            printf("null\n");
        }
        
        node = node->next;
    }
    
}

void push( struct Node** head, int data){
    if (head != NULL){
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = (*head);
        (*head) = new_node;
    }
    else{
        printf("the list is empty ...");
    }
}

void insertAfter(struct Node* prev_node, int data){
    if (prev_node != NULL) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }
    else {
        printf("the previous node could not be null ...");
    }
}

void insertAfterValue(struct Node* node, int prev, int data){
    while(node != NULL){
        if(node->data == prev){
            struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->data = data;
            new_node->next = node->next;
            node->next = new_node;
            break;
        }
        node = node->next;
    } 
    
}

void append(struct Node* node, int data){
    
    while(node->next != NULL){
        node = node->next;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    node->next = new_node;
}

void pop(struct Node** head){
    struct Node* first = *head;

    if (first->next != NULL){
        *first = *first->next;
    }
    else {
        printf("the list is empty ...");
    }
}

void popLast(struct Node* head){

    while (head != NULL){
        if (head->next->next == NULL) {
            struct Node* temp = head->next;
            head->next = NULL;    
            free(temp);
        }

        head = head->next;
    }
}

void delete(struct Node* head, int data) {

    if (head!=NULL && head->data==data) {
        free(head);
        return;
    }
    
    while (head->next != NULL) {
        if(head->next->data == data){
            struct Node* temp = head->next;
            head->next = head->next->next;
            free(temp);
            break;
        }
        
        head = head->next;
    } 
}

void deleteCenter(struct Node* head) {
    int length = 0;
    struct Node* node = head;

    while (node != NULL) {
        length ++;
        node = node->next;
    }
    
    if (length > 2) {
        int i=0;

        while (head != NULL) {  
            if (i == length/2 - 1) {
                struct Node* temp = head->next;
                head->next = head->next->next;
                free(temp);
                break;
            }
            i++;
            head = head->next;
        }
    }
    else {
        printf("the list should have more than a2 elements for delete the center ...");
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
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    second->data = 2;
    third->data = 3;

    head->next = second;
    second->next = third;
    third->next = NULL;

    printList(head);
    printf("length: %d\n", length(head));

    // insert on the first 
    push(&head, 0);
    printList(head);

    // insert after node
    insertAfter(second,22);
    printList(head);

    //  insert after value 
    insertAfterValue(head,1,33);
    printList(head);

    // append at the end 
    append(head, 4);
    printList(head);

    // pop first element
    pop(&head);
    printList(head);

    // pop last element 
    popLast(head);
    printList(head);

    // delete the middle node 
    deleteCenter(head);
    printList(head);

    // delete value 
    delete(head, 33);
    printList(head);


    return 0;
}
