#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/** Method 1 - Middle of the linked list
 * Traverse linked list using 2 pointes - move first pointer by one and move second pointer by two
 * When second pointer reaches the end, first pointer will reach the middle of the linked list
 * Complexity - O(N/2)
 */
void findMiddle() {
    if(head != NULL) {
        struct node *ptr1 = head, *ptr2 = head;
        while(ptr2 != NULL && ptr2->next != NULL) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
        }
        cout<<"Middle element of the linked list: "<<ptr1->data<<endl;
    }
}

/** Method 2 - Initialize mid pointer by head pointer and maintain a counter with initial value of 0
 * While traversing, increment counter by 1 and change mid to mid->next whenever the counter value is odd
 * In this way mid will move only half of the length of linked list
 * Complexity - O(N)
 */
void middleOfList() {
    if(head != NULL) {
        struct node *mid = head, *temp = head;
        int count = 0;
        while(temp != NULL) {
            if(count % 2 != 0)
                mid = mid->next;
            count++;
            temp = temp->next;
        }
        cout<<"Middle element of the linked list: "<<mid->data<<endl;
    }
}

void createList() {
    int arr[] = { 6, 5, 4, 3, 2, 1 };
    for(int i = 0; i < 6; i++) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = arr[i];
        newNode->next = head;
        head = newNode;
    }
}

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
    createList();
    displayList();
    findMiddle();
    middleOfList();
    return 0;
}