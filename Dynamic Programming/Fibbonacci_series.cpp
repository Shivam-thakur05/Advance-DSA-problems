#include <iostream>
using namespace std;

int fibb(int n,int dp[]) {
    if (n == 0) return n;
    if (n == 1) return n;
    if(dp[n] != -1) dp[n];
    
    dp[n] = fibb(n-1,dp)+fibb(n-2,dp);
    
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    int dp[n+1];
    for (int i = 0; i < n; ++i) {
        cout << fibb(i,dp) << " ";
    }
    return 0;
}
