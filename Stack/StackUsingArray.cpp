#include<iostream>
using namespace std;

#define N 10
int stack[N];
int top = -1;

/** Operation: Push element into stack
 * @param data
 * @return void
 * Complexity: O(1)
 */
void push(int data) {
    if(top == N-1) //check for overflow condition
        cout<<"Overflow"<<endl;
    else
        stack[++top] = data;
}

/** Operation: Remove top element from stack
 * @return void
 * Complexity: O(1)
 */
void pop() {
    if(top == -1)
        cout<<"Underflow"<<endl;
    else {
        int item = stack[top];
        top--;
        cout<<"Popped item: "<<item<<endl;
    }
}

/** Operation: Return top element from stack
 * @return void
 * Complexity: O(1)
 */
void peek() {
    if(top == -1)
        cout<<"Underflow"<<endl;
    else {
        int item = stack[top];
        cout<<"Peek item: "<<item<<endl;
    }
}

/** Operation: Display stack's element
 * @return void
 * Complexity: O(N)
 */
void display() {
    if(top == -1)
        cout<<"Underflow"<<endl;
    else {
        cout<<"Stack elements: ";
        for(int i = top; i >= 0; i--)
            cout<<stack[i]<<endl;
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