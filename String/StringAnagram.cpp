//Check two string are anagram or not
#include<iostream>

using namespace std;

bool isAnagram(string s, string s1) {
    int n[26];
    memset(n , 0, sizeof(n));
    
    if(s.length() != s1.length())
        return false;
    
    for(int i = 0, len = s.length(); i < len; i++) {
        n[s[i] - 'a']++;
        n[s1[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++) {
        if(n[i] > 0 && n[i] % 2 != 0)
            return false;
    }
    return true;
}

int main() {
    string str, str1;
    cin>>str>>str1;
    if(isAnagram(str, str1))
        cout<<"Anagram"<<endl;
    else
        cout<<"Not Anagram"<<endl;

    return 0;
}