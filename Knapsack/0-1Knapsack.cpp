#include<iostream>
using namespace std;

int max(int x, int y) {
    return x > y ? x : y;
}

void knapsack(int val[], int wt[], int TW, int N) {
    int m[N + 1][TW + 1];

    for(int i = 0; i <= N; i++) {
        for(int w = 0; w <= TW; w++) {
            if(i == 0 || w == 0) {
                m[i][w] = 0;
            } else if(wt[i - 1] <= w) {
                m[i][w] = max(m[i - 1][w], m[i - 1][w - wt[i - 1]] + val[i - 1]);
            } else {
                m[i][w] = m[i - 1][w];
            }
        }
    }

    cout<<"Total Profit: "<<m[N][TW]<<endl;
    int res = m[N][TW];
    int w = TW;
    for(int i = N; i > 0 && res > 0; i--) {
        if(res == m[i - 1][w]) {
            continue;
        } else {
            cout<<wt[i - 1]<<" ";
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
    cout<<endl;
}

int main() {
    int val[] = { 2, 3, 4, 1 };
    int wt[] = { 3, 4, 5, 6 };
    int TW = 8;
    int N = 4;
    knapsack(val, wt, TW, N);
    return 0;
}