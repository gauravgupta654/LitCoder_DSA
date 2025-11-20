#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1000000007;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return; 

    if (m == 0) {
        cout << 0 << endl;
        return;
    }

    vector<long long> T(m + 1, 0);
    T[0] = 1;

    for (int i = 1; i <= m; ++i) {
        if (i >= 1) T[i] = (T[i] + T[i - 1]) % MOD;
        if (i >= 2) T[i] = (T[i] + T[i - 2]) % MOD;
        if (i >= 3) T[i] = (T[i] + T[i - 3]) % MOD;
        if (i >= 4) T[i] = (T[i] + T[i - 4]) % MOD;
    }

    vector<long long> W(m + 1, 0);

    for (int i = 1; i <= m; ++i) {
        long long total_arrangements = power(T[i], n);
        
        long long arrangements_with_crack = 0;
        
        for (int k = 1; k < i; ++k) {
            long long remaining_ways = power(T[i - k], n);
            long long term = (W[k] * remaining_ways) % MOD;
            arrangements_with_crack = (arrangements_with_crack + term) % MOD;
        }

        W[i] = (total_arrangements - arrangements_with_crack + MOD) % MOD;
    }

    cout << W[m] << endl;
}

int main() {
    ios_base::sync_with_st
dio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
                                                                                                                            
