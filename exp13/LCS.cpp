#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the length of the Longest Common Subsequence
int getLCS(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();

    // Create a 2D DP table initialized to 0
    // dp[i][j] stores the LCS length of s1[0...i-1] and s2[0...j-1]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table bottom-up
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                // If characters match, take the diagonal value and add 1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // If they don't match, take the maximum from top or left cells
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The bottom-right cell contains the length of the LCS
    return dp[m][n];
}

int main() {
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";

    cout << "Length of LCS is: " << getLCS(s1, s2) << endl;

    return 0;
}