#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{
    int data;
    struct Element* next;
} Element;

typedef struct Queue
{
    Element* head;
    Element* tail;
    int size;
} Queue;

Element* createElement(int data) {
    Element* element = malloc(sizeof(struct Element));
    element->data = data;
    element->next = NULL;
    return element;
}

Queue* initQueue() {
    Queue* queue = malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->size == 0;
}

void printQueue(Queue* queue) {

    if (! isEmpty(queue)) {    
        Element* head = queue->head;
        
        printf("\n");
        while (head != NULL) {
            printf("%d",head->data);
            if (head->next != NULL) printf(" - ");
            head = head->next;
        }
        printf("\n\n");
    }
    else {
        printf("Queue is empty ...\n");
    }
}

void enqueue(Queue* queque, int data) {
    Element* elem = createElement(data);
    
    if (isEmpty(queque)) {
        queque->head = elem;
        queque->tail = elem;
    }    
    else {
        queque->tail->next = elem;
        queque->tail = elem;
    }
    queque->size++;
}

int dequeue(Queue* queue) {
    if (! isEmpty(queue)){
        Element* temp = queue->head;
        int data = temp->data;
        queue->head = queue->head->next;
        free(temp);
        queue->size--;
        return data;
    }
    else{
        printf("Queue is empty ...\n");
    }
}

void clear(Queue* queue) {
    while (! isEmpty(queue)){
        dequeue(queue);
    }
}


int main(int argc, char const *argv[])
{
    Queue* queue = initQueue();
    
    enqueue(queue,1);
    enqueue(queue,2);
    enqueue(queue,3);
    enqueue(queue,4);
    enqueue(queue,44);
    printQueue(queue);

    printf("head: %d\n", queue->head->data);
    printf("tail: %d\n", queue->tail->data);

    printf("dequeue: %d\n", dequeue(queue));
    printf("dequeue: %d\n", dequeue(queue));
    printQueue(queue);

    clear(queue);
    printQueue(queue); 

    return 0;
}
