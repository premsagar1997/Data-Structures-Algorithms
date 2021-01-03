//Reverse String
#include<iostream>

using namespace std;

int main() {
    string str;
    cin>>str;
    
    for(int i = 0, len = str.length(); i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }

    cout<<str<<endl;

    return 0;
}