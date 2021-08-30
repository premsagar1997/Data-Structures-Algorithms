#include<iostream>
#include<stdlib.h>
#include<stack>

using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/** @return - void
 * Complexity - O(N)
 */
void reverseList() {
    struct node *prevPtr, *currentPtr, *nextPtr;
    prevPtr = NULL;
    currentPtr = nextPtr = head;
    while (nextPtr != NULL) {
        nextPtr = nextPtr->next;
        currentPtr->next = prevPtr;
        prevPtr = currentPtr;
        currentPtr = nextPtr;
    }
    head = prevPtr;
}

void reverseListUsingStack() {
    if(head == NULL)
        return;

    stack<struct node*> st;
    struct node *temp = head;

    while(temp->next != NULL) {
        st.push(temp);
        temp = temp->next;
    }
    head = temp;

    while(!st.empty()) {
        temp->next = st.top();
        st.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

void creatList() {
    int arr[5] = { 10, 20, 30, 40, 50 };
    for(int i = 0; i < 5; i++) {
        struct node *newNode = (struct node *) malloc(sizeof(struct node));
        newNode->data = arr[i];
        newNode->next = head;
        head = newNode;
    }
}

/** @return - void
 * Complexity - O(N)
 */
void displayList() {
    if(head == NULL)
        cout<<"List is empty"<<endl;
    else {
        struct node *temp = head;
        cout<<"List elements are -"<<endl;
        while(temp->next != NULL) {
            cout<<temp->data<<"-->";
            temp = temp->next;
        }
        cout<<temp->data<<"-->NULL"<<endl;
    }
}

int main() {
    creatList();
    displayList();
    reverseList();
    displayList();
    reverseListUsingStack();
    displayList();
    return 0;
}