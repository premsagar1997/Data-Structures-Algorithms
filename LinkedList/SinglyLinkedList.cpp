#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node * createNode() {
    return (struct node *) malloc(sizeof(struct node));
}

/** @param - data to be inserted
 * @return - void
 * Complexity - O(1)
 */
void insertAtBeginning(int data) {
    struct node *newNode = createNode();
    newNode->data = data;
    if(head == NULL) //if there is no node present in linked list
        newNode->next = NULL;
    else
        newNode->next = head;
    head = newNode;
}

/** @param - data to be inserted
 * @return - void
 * Complexity - O(N)
 */
void insertAtEnd(int data) {
    struct node *newNode = createNode();
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL) //if there is no node present in linked list
        head = newNode;
    else {
        struct node *temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    } 
}

/** @param - data to be inserted and position
 * @return - void
 * Complexity - O(N)
 */
void insertAfterPosition(int data, int pos) {
    struct node *newNode = createNode();
    newNode->data = data;
    if(head == NULL) { //if there is no node present in linked list
        newNode->next = NULL;
        head = newNode;
    } else {
        int i = 1;
        struct node *temp = head;
        while(i < pos) {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

/** @return - void
 * Complexity - O(1)
 */
void removeFromBeginning() {
    if(head == NULL) //List is empty
        cout<<"List is empty"<<endl;
    else {
        struct node *temp = head;
        if(head->next == NULL) //If there is 1 node present
            head = NULL;
        else //If more than 1 node are present
            head = head->next;
        free(temp);
    }
}

/** @return - void
 * Complexity - O(N)
 */
void removeFromEnd() {
    if(head == NULL) //List is empty
        cout<<"List is empty"<<endl;
    else {
        struct node *temp = head, *prev;
        if(head->next == NULL) //If there is 1 node present
            head = NULL;
        else {
            while(temp->next != NULL) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
        }
        free(temp);
    }
}

/** @param - value to be deleted
 * @return - void
 * Complexity - O(N)
 */
void removeSpecific(int value) {
    if(head == NULL) //List is empty
        cout<<"List is empty"<<endl;
    else {
        struct node *temp = head, *prev;
        while(temp->data != value) {
            if(temp->next == NULL) {
                cout<<"Node not found"<<endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        if(head == temp) //if element present at beginning
            head = temp->next;
        else
            prev->next = temp->next;
        free(temp);
    }
}

/** @param - position
 * @return - void
 * Complexity - O(N)
 */
void removeFromPosition(int pos) {
    if(head == NULL) //List is empty
        cout<<"List is empty"<<endl;
    else if(pos == 1)
        removeFromBeginning();
    else {
        struct node *temp = head, *nextNode;
        int i = 1;
        while(i < pos-1) {
            temp = temp->next;
            i++;
            if(temp->next == NULL) {
                cout<<"Position not found"<<endl;
                return;
            }
        }
        nextNode = temp->next;
        temp->next = nextNode->next;
        free(nextNode);
    }
}

/** @return - void
 * Complexity - O(N)
 */
void display() {
    if(head == NULL)
        cout<<"List is empty"<<endl;
    else {
        struct node *temp = head;
        cout<<"List elements are -"<<endl;
        while(temp != NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
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
    int ch, data, pos;
    do {
        cout<<"\nPlease choose option:\n1->Insert At Beginning\n2->Insert At End\n3->Insert After position\n";
        cout<<"4->Delete From Beginning\n5->Delete From End\n6->Delete Specific\n7->Remove From Position\n8->Display List\n9->Exit\n";
        cin>>ch;
        switch (ch) {
            case 1:
                cout<<"Enter element: ";
                cin>>data;
                insertAtBeginning(data);
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
                cout<<"Enter element to be deleted: ";
                cin>>data;
                removeSpecific(data);
                break;
            case 7:
                cout<<"Enter position: ";
                cin>>pos;
                removeFromPosition(pos);
                break;
            case 8:
                displayList();
                break;
            case 9: break;
            default: cout<<"Invalid option!!!"<<endl;
                break;
        }
    } while(ch != 9);

    return 0;
}