#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct BinaryTree
{
    Node* head;
    int size;
} Tree;

Node* createNode(int data) {
    Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}

Tree* initTree() {
    Tree* tree = malloc(sizeof(struct BinaryTree));
    tree->head = NULL;
    tree->size = 0;
    return tree;
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
    Tree* tree = initTree();

    tree->head = createNode(1);
    
    Node* node1 = createNode(2);
    node1->left = createNode(3);
    node1->right = createNode(4);

    tree->head->left = node1;

    Node* node2 = createNode(22);
    node2->left = createNode(33);
    node2->right = createNode(44);

    tree->head->right = node2;
    
    Node* head = tree->head;
    while (head != NULL)
    {
        printf("%d ", head->data);
        if (head->left != NULL)
            head = head->left;
        else             
            head = head->right;
    }
    printf("\n");
    head = tree->head;
    while (head != NULL)
    {
        printf("%d ", head->data);
        if (head->right != NULL)
            head = head->right;
        else
            head = head->left;
    }
    printf("\n");

    print(tree->head);

    return 0;
}
