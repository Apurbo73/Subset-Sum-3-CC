#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int N; 
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];

        bool dp[3] = {false, false, false};
        for (int i = 0; i < N; ++i) {
            bool new_dp[3];
            for (int j = 0; j < 3; ++j) new_dp[j] = dp[j];

            int mod_val = A[i] % 3;
            new_dp[mod_val] = true;
            for (int j = 0; j < 3; ++j) {
                if (dp[j]) {
                    int nxt = (j + mod_val) % 3;
                    new_dp[nxt] = true;
                }
            }
            for (int j = 0; j < 3; ++j) dp[j] = new_dp[j];
        }

        cout << (dp[0] ? "Yes\n" : "No\n");
    }
    return 0;
}