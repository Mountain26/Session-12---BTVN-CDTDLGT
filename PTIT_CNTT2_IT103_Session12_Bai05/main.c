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
Node *removeAt(Node *head,  int index) {
    if (index < 0 || index > 5) {
        printf("Index is out of bounds\n");
        return head;
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    Node* prev = current->prev;
    Node* next = current->next;
    Node* temp = current;
    prev->next = next;
    next->prev = prev;
    free(temp);
    return head;
}
int main() {
    Node* head = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);
    Node* node4 = createNode(40);
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
    int deleteIndex;
    printf("Please enter the index of the node:\n");
    scanf("%d", &deleteIndex);
    head = removeAt(head, deleteIndex);
    printList(head);
    return 0;
}