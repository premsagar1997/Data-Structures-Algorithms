//String Palindrome
#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    bool flag = true;
    for (int i = 0, len = str.length(); i < len/2; i++) {
        if(str[i] != str[len-i-1]) {
            flag = false;
            break;
        }
    }
    if(flag)
        cout<<"Palindrome"<<endl;
    else
        cout<<"Not Palindrome"<<endl;
    
    return 0;
}