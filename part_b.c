#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Structure for a queue node
struct QueueNode {
    struct Node* data;
    struct QueueNode* next;
};

// Structure for a queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isQueueEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to enqueue a node
void enqueue(struct Queue* queue, struct Node* node) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = node;
    newNode->next = NULL;
    
    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue a node
struct Node* dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue))
        return NULL;
    
    struct QueueNode* frontNode = queue->front;
    struct Node* data = frontNode->data;
    queue->front = frontNode->next;
    
    if (queue->front == NULL)
        queue->rear = NULL;
    
    free(frontNode);
    return data;
}

// Breadth-first traversal
void breadthFirstTraversal(struct Node* root) {
    if (root == NULL)
        return;
    
    struct Queue* queue = createQueue();
    enqueue(queue, root);
    
    while (!isQueueEmpty(queue)) {
        struct Node* node = dequeue(queue);
        printf("%d ", node->data);
        
        if (node->left != NULL)
            enqueue(queue, node->left);
        
        if (node->right != NULL)
            enqueue(queue, node->right);
    }
    
    printf("\n");
    free(queue);
}

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

    breadthFirstTraversal(root);

    free(root);

    return 0;
}
