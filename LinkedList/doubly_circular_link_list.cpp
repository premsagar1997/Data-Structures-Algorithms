#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

//create node
struct node* createNode(int x) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->prev = newNode->next = NULL;
    return newNode;
}


/** Task - Insert node at beginning position
 * @param - data to be inserted
 * @return - void
 * Complexity - O(1)
 */
void insertAtBeg(int x) {
    struct node *newNode = createNode(x);
    //if there is no node present in list
    if (head == NULL && tail == NULL) {
        head = tail = newNode;
        head->next = head->prev = newNode;
    } else {
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
}

/** Task - Insert node at end position
 * @param - data to be inserted
 * @return - void
 * Complexity - O(1)
 */
void insertAtEnd(int x) {
    struct node *newNode = createNode(x);
    //if there is no node present in list
    if (head == NULL && tail == NULL) {
        head = tail = newNode;
        head->next = head->prev = newNode;
    } else {
        newNode->prev = tail;
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
        head->prev = tail;
    }
}

/** Task - Insert node at any given position
 * @param - data to be inserted & position at which data should insert
 * @return - void
 * Complexity - O(n)
 */
void insertAfterPosition(int x, int p) {
    
}


/** Task - Delete node from beginning
 * @return - void
 * Complexity - O(1)
 */
void removeFromBeginning() {
    
}

/** Task - Delete node from end position
 * @return - void
 * Complexity - O(1)
 */
void removeFromEnd() {
    
}


/** Task - Delete node from any given postion
 * @return - void
 * Complexity - O(n)
 */
void removeFromPosition(int p) {
    
}

/** Task - display list
 * @return - void
 * Complexity - O(n)
 */
void displayList() {
    //if there is no node present in list
    if (head == NULL && tail == NULL) {
        cout<<"List is empty"<<endl;
    }
    
    struct node * temp = head;
    while (temp != tail) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}

//driver method
int main() {
    int ch, data, pos;
    do {
        cout<<"\nPlease choose option:\n1->Insert At Beginning\n2->Insert At End\n3->Insert After position\n";
        cout<<"4->Delete From Beginning\n5->Delete From End\n6->Remove From Position\n7->Display List\n0->Exit\n";
        cin>>ch;
        switch (ch) {
            case 1:
                cout<<"Enter element: ";
                cin>>data;
                insertAtBeg(data);
                break;
            case 2:
                cout<<"Enter element: ";
                cin>>data;
                insertAtEnd(data);
                break;
            case 3:
                cout<<"Enter element and position: ";
                cin>>data>>pos;
                insertAfterPosition(data, pos);
                break;
            case 4:
                removeFromBeginning();
                break;
            case 5:
                removeFromEnd();
                break;
            case 6:
                cout<<"Enter position: ";
                cin>>pos;
                removeFromPosition(pos);
                break;
            case 7:
                displayList();
                break;
            case 0: break;
            default: cout<<"Invalid option!!!"<<endl;
                break;
        }
    } while(ch != 0);

    return 0;
}
