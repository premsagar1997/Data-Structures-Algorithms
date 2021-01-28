#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

/** Reverse doubly linked list
 * Complexity: O(N)
 */
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

/** Reverse doubly linked list using stack
 * Complexity: O(N)
 */
void reverseListUsingStack() {
    stack<int> st;
    struct node *temp = head;

    //add elements to the stack
    while(temp != NULL) {
        st.push(temp->data);
        temp = temp->next;
    }

    //popping the elements out and updating doubly linked
    temp = head;
    while(temp != NULL) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
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
    reverseListUsingStack();
    displayList();
    return 0;
}