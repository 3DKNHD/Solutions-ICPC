#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
#define MAX_N 1000000

long long fact[MAX_N + 1];
long long inv_fact[MAX_N + 1];

long long bp(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    
    inv_fact[MAX_N] = bp(fact[MAX_N], MOD - 2, MOD);
    for (int i = MAX_N - 1; i >= 0; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precompute_factorials();
    
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        
        vector<vector<int>> freq(26, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int c = 0; c < 26; c++) {
                freq[c][i] = freq[c][i - 1];
            }
            int idx = s[i - 1] - 'a';
            freq[idx][i]++;
        }
        
        int q;
        cin >> q;
        
        while (q--) {
            string type;
            cin >> type;
            
            if (type == "INSIDE") {
                int l, r;
                string w;
                cin >> l >> r >> w;
                
                int len = r - l + 1;
                if (w.length() != len) {
                    cout << "NO\n";
                    continue;
                }
                
                vector<int> freq_s(26, 0);
                for (int c = 0; c < 26; c++) {
                    freq_s[c] = freq[c][r] - freq[c][l - 1];
                }
                
                vector<int> freq_w(26, 0);
                for (char c : w) {
                    freq_w[c - 'a']++;
                }
                
                if (freq_s == freq_w) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            } 
            else {
                int l, r;
                cin >> l >> r;
                
                int len = r - l + 1;
                long long result = fact[len];
                for (int c = 0; c < 26; c++) {
                    int cnt = freq[c][r] - freq[c][l - 1];
                    result = result * inv_fact[cnt] % MOD;
                }
                cout << result << "\n";
            }
        }
    }
    
    return 0;
}