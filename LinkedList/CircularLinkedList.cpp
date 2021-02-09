#include<iostream>

using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *tail = NULL;

int findLength();
void displayList();

struct node* createNode() {
    return (struct node *)malloc(sizeof(struct node));
}

/** Task: Insert a node at beg of the list
 * Complexity: O(1)
 * @return void
 * @param data-to be inserted
 */
void insertAtBeg(int data) {
    struct node *newNode = createNode();
    newNode->data = data;

    if(tail == NULL) { //if list is empty
        tail = newNode;
        tail->next = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
    cout<<"Node "<<tail->next->data<<" is inserted!!!\n";
}

/** Task: Insert a node at the end of the list
 * Complexity: O(1)
 * @return void
 * @param data-to be inserted
 */
void insertAtEnd(int data) {
    struct node *newNode = createNode();
    newNode->data = data;

    if(tail == NULL) { //if list is empty
        tail = newNode;
        tail->next = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

/** Task: Insert a node at any position
 * Complexity: O(N)
 * @return void
 * @param data-to be inserted and position
 */
void insertAtPos(int data, int pos) {
    struct node *newNode = createNode();
    newNode->data = data;

    if(pos < 1 || pos > findLength()) {
        cout<<"Invalid Position!!!\n";
    } else if(pos == 1) {
        insertAtBeg(data);
    } else if(pos == findLength()) {
        insertAtEnd(data);
    } else {
        int i = 1;
        struct node *temp = tail->next;
        while(i < pos-1) {
            i++;
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

/** Task: Delete a node from beginning of the list
 * Complexity: O(1)
 * @return void
 */
void deleteFromBeg() {
    struct node *temp = tail->next;
    if(tail == NULL) //list is empty
        cout<<"List is empty\n";
    else if(tail == temp) { //if there is one node present in list
        tail = NULL;
        free(temp);
    } else {
        tail->next = temp->next;
        free(temp);
    }
}

/** Task: Delete a node from end of the list
 * Complexity: O(N)
 * @return void
 */
void deleteFromEnd() {
    struct node *current = tail->next;
    if(tail == NULL) //list is empty
        cout<<"List is empty\n";
    else if(current == tail) { //only one node is present in the list
        tail = NULL;
        free(current);
    } else {
        struct node *prev;
        while(current->next != tail->next) {
            prev = current;
            current = current->next;
        }
        prev->next = tail->next;
        tail = prev;
        free(current);
    }
}

/** Task: Delete a node from given position
 * Complexity: O(N)
 * @return void
 * @param position
 */
void deleteFromPos(int pos) {
    if(tail == NULL) //list is empty
        cout<<"List is empty\n";
    else if(pos < 1 || pos > findLength())
        cout<<"Invalid Position!!!\n";
    else if(pos == 1)
        deleteFromBeg();
    else if(pos == findLength())
        deleteFromEnd();
    else {
        struct node *current = tail->next, *nextNode;
        int i = 1;
        while(i < pos-1) {
            i++;
            current = current->next;
        }
        nextNode = current->next;
        current->next = nextNode->next;
        free(nextNode);
    }
}

void displayList() {
    if(tail == NULL) //list is empty
        cout<<"List is empty\n";
    else {
        struct node *temp = tail->next;
        while(temp->next != tail->next) {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<temp->data<<endl;
    }
}

int findLength() {
    if(tail == NULL) //list is empty
        return 0;
    int len = 0;
    struct node *temp = tail->next;
    while(temp->next != tail->next) {
        len++;
        temp = temp->next;
    }
    return len + 1;
}

int main() {
    int ch, data, pos;
    do {
        cout<<"\nPlease choose option:\n1->Insert At Beginning\n2->Insert At End\n3->Insert At position\n";
        cout<<"4->Delete From Beginning\n5->Delete From End\n6->Remove From Position\n7->Display List\n8->Print Length\n0->Exit\n";
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
                insertAtPos(data, pos);
                break;
            case 4:
                deleteFromBeg();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                cout<<"Enter postion: ";
                cin>>pos;
                deleteFromPos(pos);
                break;
            case 7:
                displayList();
                break;
            case 8:
                cout<<"Length: "<<findLength()<<endl;
                break;
            case 0: break;
            default: cout<<"Invalid option!!!"<<endl;
                break;
        }
    } while(ch != 0);
    return 0;
}