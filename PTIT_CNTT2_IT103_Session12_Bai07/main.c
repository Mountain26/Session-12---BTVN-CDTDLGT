#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d<-->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
Node* sortList(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    int swapped;
    Node* currentNode;
    Node* lastNode = NULL;

    do {
        swapped = 0;
        currentNode = head;

        while (currentNode->next != lastNode) {
            if (currentNode->data > currentNode->next->data) {
                int temp = currentNode->data;
                currentNode->data = currentNode->next->data;
                currentNode->next->data = temp;
                swapped = 1;
            }
            currentNode = currentNode->next;
        }
        lastNode = currentNode;
    } while (swapped);

    return head;
}
int main() {
    Node* head = createNode(40);
    Node* node2 = createNode(20);
    Node* node3 = createNode(10);
    Node* node4 = createNode(80);
    Node* node5 = createNode(50);
    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;
    printf("Mang ban dau:\n");
    printList(head);
    sortList(head);
    printf("Mang sau khi da sap xep:\n");
    printList(head);
    return 0;
}