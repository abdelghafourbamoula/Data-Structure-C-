#include <stdio.h>
#include <stdlib.h>

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
            if (node->data > data)
                node = node->right;
            else if (node->data < data)
                node = node->left;
            else{
                printf("%d already exist ...\n", data);
                return;
            }        
        }
        node = createNode(data);
        if (temp->data > data)
            temp->right = node;
        else
            temp->left = node;
    }
    else
    {
        tree->head = createNode (data);
    }
    tree->size++;
    tree->edges = tree->size-1;
    
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
    
    return 0;
}
