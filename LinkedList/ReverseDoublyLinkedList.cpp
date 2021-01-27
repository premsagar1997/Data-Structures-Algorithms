#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

void reverseList() {
    struct node *current, *nextNode;
    current = head;
    while(current != NULL) {
        nextNode = current->next;
        current->next = current->prev;
        current->prev = nextNode;
        current = nextNode;
    }
    //reverse head and tail
    current = head;
    head = tail;
    tail = current;
}

void createList() {
    for(int i = 1; i <= 10; i++) {
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = i;
        newNode->prev = NULL;
        newNode->next = NULL;
        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
}

void displayList() {
    struct node *temp = head;
    if(head == NULL)
        return;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    createList();
    displayList();
    reverseList();
    displayList();
    return 0;
}