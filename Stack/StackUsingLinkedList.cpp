//Stack Using Linked List
#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

/** Operation: Push element into stack
 * @param data
 * @return void
 * Complexity: O(1)
 */
void push(int data) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

/** Operation: Remove top element from stack
 * @return void
 * Complexity: O(1)
 */
void pop() {
    if(top == NULL) {
        cout<<"Underflow"<<endl;
    } else {
        struct node *temp = top;
        top = top->next;
        cout<<"Popped element is "<<temp->data<<endl;
        free(temp);
    }
}

/** Operation: Return top element from stack
 * @return void
 * Complexity: O(1)
 */
void peek() {
    if(top == NULL) {
        cout<<"Underflow"<<endl;
    } else {
        cout<<"Peek element is "<<top->data<<endl;
    }
}

/** Operation: Display stack's element
 * @return void
 * Complexity: O(N)
 */
void display() {
    struct node *temp = top;
    if(top == NULL) {
        cout<<"Underflow"<<endl;
        return;
    }

    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main() {
    int ch, data;
    do {
        cout<<"\n1->Push\n2->Pop\n3->Peek\n4->Display\n0->Exit\n";
        cin>>ch;
        switch (ch){
            case 1:
                cout<<"Enter element: ";
                cin>>data;
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            default: cout<<"Invalid choice!!!"<<endl;
                break;
        }
    } while(ch != 0);
    return 0;
}