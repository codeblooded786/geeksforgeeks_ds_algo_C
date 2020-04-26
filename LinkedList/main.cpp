#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void printList(struct Node **p) {

    struct Node *z = *p;

    while (z != NULL) {
        cout << z->data << endl;
        z = z->next;
    }
}

int main() {

    struct Node *head = (struct Node *) malloc(sizeof(Node));
    struct Node *second = (struct Node *) malloc(sizeof(Node));
    struct Node *third = (struct Node *) malloc(sizeof(Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printList(&head);

    return 0;
}
