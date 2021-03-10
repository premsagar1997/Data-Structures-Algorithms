#include<iostream>
using namespace std;

/**Tower of Hanoi -
 * Only one disk can be moved from one peg to another peg at a time
 * A disk can be placed only on top of a larger one
 * A disk can be moved from top only
 * @param - N is number of disk, A is "from" peg, B is "using" peg, and C is "to" peg
 * Complexity - O(2^N) where N is number of disk
 */
void towerOfHanoi(int n, char A, char B, char C) {
    if(n == 1) {
        cout<<"Move disk 1 from "<<A<<" -> "<<C<<endl;
        return;
    }

    towerOfHanoi(n-1, A, C, B);
    cout<<"Move disk "<<n<<" from "<<A<<" -> "<<C<<endl;
    towerOfHanoi(n-1, B, A, C);
}

int main() {
    int n = 3;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}