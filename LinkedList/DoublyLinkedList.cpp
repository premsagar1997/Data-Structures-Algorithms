#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

struct node* createNode() {
    return (struct node*)malloc(sizeof(struct node));
}

int findLength();

/** Task: Insert at beginning
 * @param - data
 * Complexity: O(1)
 */
void insertAtBeg(int data) {
    struct node *newNode = createNode();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    if(head == NULL) {
        head = tail = newNode;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

/** Task: Insert at last
 * @param - data
 * Complexity: O(1)
 */
void insertAtEnd(int data) {
    struct node *newNode = createNode();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    if(head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

/** Task: Insert at given position
 * @param - data and position
 * Complexity: O(N)
 */
void insertAtPos(int data, int pos) {
    struct node *newNode = createNode(), *temp = head;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    if(pos <= 0 || pos > findLength())
        cout<<"Invalid Position!!!"<<endl;
    else if(pos == 1)
        insertAtBeg(data);
    else if(pos == findLength())
        insertAtEnd(data);
    else {
        int i = 1;
        while(i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->next->prev = newNode;
    }
}

/** Task: Delete first node
 * Complexity: O(1)
 */
void deleteFromBeg() {
    if(head == NULL)
        cout<<"List is empty"<<endl;
    else {
        struct node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}

/** Task: Delete last node
 * Complexity: O(1)
 */
void deleteFromEnd() {
    if(head == NULL)
        cout<<"List is empty"<<endl;
    else {
        struct node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
}

/** Task: Delete node from given position
 * @param - position
 * Complexity: O(N)
 */
void deleteFromPos(int pos) {
    if(head == NULL)
        cout<<"List is empty"<<endl;
    else if(pos <= 0 || pos > findLength())
        cout<<"Invalid Position!!!"<<endl;
    else if(pos == 1)
        deleteFromBeg();
    else if(pos == findLength())
        deleteFromEnd();
    else {
        int i = 1;
        struct node *temp = head;
        while(i < pos) {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

/** Task: Display list
 * Complexity: O(N)
 */
void displayList() {
    if(head == NULL)
        cout<<"List is empty"<<endl;
    else {
        struct node * temp = head;
        while(temp != NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

/** Task: Find length of list
 * @return - length of list
 * Complexity: O(N)
 */
int findLength() {
    int len = 0;
    if(head == NULL)
        len = 0;
    else if(head->next == NULL)
        len = 1;
    else {
        struct node *temp = head;
        while(temp != NULL) {
            temp = temp->next;
            len++;
        }
    }
    return len;
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