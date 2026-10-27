#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the minimum number of scalar multiplications
int matrixChainOrder(const vector<int>& p) {
    int n = p.size() - 1; // Number of matrices
    
    // dp[i][j] stores the minimum multiplications needed to compute the matrix chain A[i]...A[j]
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // L is the chain length. L = 1 means a single matrix, cost is 0 (already initialized)
    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;

            // Try all possible split points k between i and j-1
            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    // The result for the entire chain of matrices from 1 to n is at dp[1][n]
    return dp[1][n];
}

int main() {
    // Array p[] represents the dimensions of the matrices
    // Example: A1 is 10x20, A2 is 20x30, A3 is 30x40, A4 is 40x30
    vector<int> p = {10, 20, 30, 40, 30};
    
    cout << "Minimum number of multiplications is: " << matrixChainOrder(p) << endl;

    return 0;
}