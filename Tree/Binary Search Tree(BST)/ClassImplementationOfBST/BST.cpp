// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Tree {
    public:
    int key;
    Tree *left;
    Tree *right;
    
    Tree() {
        key = 0;
        left = NULL;
        right = NULL;
    }
    
    Tree(int key) {
        key = key;
        left = NULL;
        right = NULL;
    }
};

class BST {
    public:
    Tree *root;
    
    BST() {
        root = NULL;
    }
    
    bool isEmpty() {
        return root == NULL;
    }
    
    void insertIterative(Tree *newNode) {
        if (root == NULL) { //no node present in tree
            root = newNode;
            cout<<"Inserted as root"<<endl;
        } else {
            Tree *temp = root;
            while (temp != NULL) {
                if (temp->key == newNode->key) { //no duplicate allowed in BST
                    return;
                } else if (newNode->key < temp->key && temp->left == NULL) {
                    temp->left = newNode;
                    cout<<"Inserted as left child"<<endl;
                    break;
                } else if (newNode->key < temp->key) {
                    temp = temp->left;
                } else if (newNode->key > temp->key && temp->right == NULL) {
                    temp->right = newNode;
                    cout<<"Inserted as right child"<<endl;
                    break;
                } else {
                    temp = temp->right;
                }
            }
        }
    }
    
    void preOrder(Tree *r) {
        if (r == NULL)
            return;
        cout<<r->key<<" ";
        preOrder(r->left);
        preOrder(r->right);
    }
    
    void inOrder(Tree *r) {
        if (r == NULL)
            return;
        inOrder(r->left);
        cout<<r->key<<" ";
        inOrder(r->right);
    }
    
    void postOrder(Tree *r) {
        if (r == NULL)
            return;
        postOrder(r->left);
        postOrder(r->right);
        cout<<r->key<<" ";
    }
};

int main() {
    BST bstObj;
    int option, key;

    do {
        cout<<"1->Insert\n2->Print PreOrder\n3->Print InOrder"<<endl;
        cin>>option;
        switch (option) {
            case 0: {
                cout<<"Exiting program!!!"<<endl;
                break;
            }
            case 1: {
                cout<<"Enter element to insert:- ";
                cin>>key;
                Tree *newNode = new Tree();
                newNode->key = key;
                bstObj.insertIterative(newNode);
                break;
            }
            case 2: {
                bstObj.preOrder(bstObj.root);
                cout<<endl;
                break;
            }
            case 3: {
                bstObj.inOrder(bstObj.root);
                cout<<endl;
                break;
            }
            default:
                cout<<"Wrong option!!!"<<endl;
        }
    } while (option != 0);
    return 0;
}
