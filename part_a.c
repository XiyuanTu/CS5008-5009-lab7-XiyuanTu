#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Preorder traversal: Root -> Left -> Right
void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    
    printf("%d ", root->data);  // Print the data
    preorderTraversal(root->left);  // Traverse left subtree
    preorderTraversal(root->right);  // Traverse right subtree
}

// Inorder traversal: Left -> Root -> Right
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    
    inorderTraversal(root->left);  // Traverse left subtree
    printf("%d ", root->data);  // Print the data
    inorderTraversal(root->right);  // Traverse right subtree
}

// Postorder traversal: Left -> Right -> Root
void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    
    postorderTraversal(root->left);  // Traverse left subtree
    postorderTraversal(root->right);  // Traverse right subtree
    printf("%d ", root->data);  // Print the data
}

int main() {
    // Create the binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->left->left = createNode(8);
    root->left->left->right = createNode(9);
    root->left->right->left = createNode(10);
    root->left->right->right = createNode(11);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->right->left->left = createNode(12);
    root->right->left->right = createNode(13);
    root->right->right->left = createNode(14);
    root->right->right->right = createNode(15);

    printf("Preorder: \n");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder: \n");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder: \n");
    postorderTraversal(root);
    printf("\n");

    free(root);

    return 0;
}
