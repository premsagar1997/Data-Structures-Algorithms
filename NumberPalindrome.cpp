//Number Palindrome
#include<iostream>

using namespace std;

int main() {
    int n, tempN, rem, revN = 0;
    cin>>n;
    tempN = n;

    while(tempN != 0) {
        rem = tempN % 10;
        revN = revN * 10 + rem;
        tempN /= 10;
    }

    if(revN == n)
        cout<<"Palindrome"<<endl;
    else
        cout<<"Not Palindrome"<<endl;

    return 0;
}