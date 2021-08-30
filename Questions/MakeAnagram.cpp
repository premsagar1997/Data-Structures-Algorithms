// Minimum number of Manipulations required to make two Strings Anagram Without Deletion of Character

#include <iostream>
using namespace std;

int makeAnagram(string s1, string s2) {
    int count = 0;
    int aux[26];

    for (int i = 0; i < 26; i++) {
        aux[i] = 0;
    }

    for (int i = 0; i < s1.length(); i++)
        aux[s1[i] - 'a']++;

    for (int i = 0; i < s2.length(); i++)
        aux[s2[i] - 'a']--;

    for (int i = 0; i < 26; ++i)  {
        if (aux[i] != 0)
            count += abs(aux[i]);
    }
    return count % 2 == 0 ? count / 2 : (count / 2) + 1;
}

int main() {
    cout<<makeAnagram("tea", "tae")<<endl;
    return 0;
}