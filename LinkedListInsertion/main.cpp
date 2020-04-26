#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node **head, int data) {
    struct Node *temp = *head;
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (temp == NULL) {
        temp = newNode;
        return;
    }
    newNode->next = temp;
    temp = newNode;
    return;
}

void insertAtEnd(struct Node **head, int data) {

    struct Node *temp = *head;

    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return;
}

void insertAfterParticularNode(struct Node *prevNode, int data) {

    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (prevNode == NULL) {
        cout << "Given node can't be NULL" << endl;
        return;
    }
    struct Node *temp = prevNode->next;
    prevNode->next = newNode;
    newNode->next = temp;
    return;
}

void printList(struct Node **head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    struct Node *temp = *head;
    while (temp != NULL) {
        cout << temp->data << " ";
    }


}

int main() {
    //struct Node *element = (struct Node *) malloc(sizeof(struct Node));
    int data;
    struct Node **head = NULL;

    //cin >> data;

    //insertAtBeginning(head, data);

    insertAtEnd(head, 6);

    // Insert 7 at the beginning. So linked list becomes 7->6->NULL
    insertAtBeginning(head, 7);

    // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
    insertAtBeginning(head, 1);

    // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
    insertAtEnd(head, 4);

    // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
    struct Node *temp = *head;
    insertAfterParticularNode(temp->next, 8);

    printf("\n Created Linked list is: ");
    printList(head);


    return 0;
}
