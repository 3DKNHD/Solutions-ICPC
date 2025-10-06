#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        multiset<int> x, y, z;
        vector<array<int, 3>> points;
        
        for (int i = 0; i < n; i++) {
            string op;
            cin >> op;
            if (op == "ADD") {
                int a, b, c;
                cin >> a >> b >> c;
                points.push_back({a, b, c});
                x.insert(a);
                y.insert(b);
                z.insert(c);
            } else {
                int k;
                cin >> k;
                k--;
                array<int, 3> point = points[k];
                x.erase(x.find(point[0]));
                y.erase(y.find(point[1]));
                z.erase(z.find(point[2]));
            }
            
            if (x.empty()) {
                cout << 0 << '\n';
            } else {
                int x_min = *x.begin();
                int x_max = *x.rbegin();
                int y_min = *y.begin();
                int y_max = *y.rbegin();
                int z_min = *z.begin();
                int z_max = *z.rbegin();
                long long dx = x_max - x_min;
                long long dy = y_max - y_min;
                long long dz = z_max - z_min;
                long long area = 2 * (dx * dy + dx * dz + dy * dz);
                cout << area << '\n';
            }
        }
    }
    
    return 0;
}