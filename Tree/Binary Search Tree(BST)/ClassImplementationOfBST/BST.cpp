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
        } else {
            Tree *temp = root;
            while (temp != NULL) {
                if (temp->key == newNode->key) { //no duplicate allowed in BST
                    return;
                } else if (newNode->key < temp->key && temp->left == NULL) {
                    temp->left = newNode;
                    break;
                } else if (newNode->key < temp->key) {
                    temp = temp->left;
                } else if (newNode->key > temp->key && temp->right == NULL) {
                    temp->right = newNode;
                } else {
                    temp = temp->right;
                }
            }
        }
    }
};

int main() {
    BST bstObj;
    int option, key;
    
    do {
        cin>>option;
        switch (option) {
            case 0: {
                cout<<"Exiting program!!!"<<endl;
                break;
            }
            case 1: {
                cout<<"Enter element to insert:- ";
                cin>>key;
                Tree *newNode = new Tree(key);
                bstObj.insertIterative(newNode);
                break;
            }
            default:
                cout<<"Wrong option!!!"<<endl;
        }
    } while (option != 0);
    return 0;
}
