//Check a number is power of two or not
#include<iostream>

using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && (n & n-1) == 0;
}

int main() {
    int n;
    cin>>n;

    if(isPowerOfTwo(n))
        cout<<n<<" is power of 2"<<endl;
    else
        cout<<n<<" is not power of 2"<<endl;

    return 0;
}