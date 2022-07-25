#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct binarySearchTree
{
    Node* head;
    int size;
    int edges;
} BST;

Node* createNode(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}

BST* initBST() {
    BST* tree = malloc(sizeof(BST));
    tree->head = NULL;
    tree->size = 0;
    tree->edges = 0;
    return tree;
}

void append(BST* tree, int data) {
    if (tree->head != NULL)
    {
        Node* node = tree->head;
        Node* temp;
        while (node != NULL)
        {
            temp = node;
            if (data < node->data)
                node = node->left;
            else if (data > node->data)
                node = node->right;
            else{
                printf("%d already exist ...\n", data);
                return;
            }        
        }
        node = createNode(data);
        if (data < temp->data)
            temp->left = node;
        else
            temp->right = node;
    }
    else
    {
        tree->head = createNode (data);
    }
    tree->size++;
    tree->edges = tree->size-1;
}

bool search(Node* node, int data) {
    if (node == NULL)   return false;
    else if (node->data == data)    return true;
    else if (node->data < data)     search(node->left, data);
    else    search(node->right, data);
} 

int min(Node* node){
    if (node == NULL) printf("not found ...\n");
    if (node->left == NULL) return node->data;
    else    return min(node->left);    
}

int max(Node* node) {
    if (node == NULL) printf("not found ...\n");
    if (node->right == NULL) return node->data;
    else    return max(node->right);    
}

void print(Node* node) {
    if (node != NULL) {
        print(node->left);
        print(node->right);
        printf("%d ", node->data);       
    }
}


int main(int argc, char const *argv[])
{
    BST* tree = initBST();

    append(tree,30);
    append(tree,20);
    append(tree,40);
    append(tree,34);
    append(tree,10);
    append(tree,25);
    append(tree,50);
    append(tree,31);
    
    print(tree->head);
    printf("\nsize: %d - edges: %d\n", tree->size, tree->edges);
    
    printf("search 33 : ");
    search(tree->head, 25)==true ? printf("true") : printf("false");
    printf("\nsearch 46 : ");
    search(tree->head, 46)==true ? printf("true") : printf("false");
    printf("\n");

    printf("min: %d\n", min(tree->head));
    printf("max: %d\n", max(tree->head));

    return 0;
}
