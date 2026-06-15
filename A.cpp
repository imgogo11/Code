#include <bits/stdc++.h>
using namespace std;
int a[100], b[100], c[100], ans = 0, n, k;
bool mp[15][15];
void dfs(int i) {
    if (i > n) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j]) {
                cnt++;
            }
        }
        if (cnt == k) {
            ans++;
        }
        return;
    }
    else {
        for (int j = 1; j <= n; j++) {
            if (!a[j] && mp[i][j]) {
                a[j] = 1;
                dfs(i + 1);
                a[j] = 0;
            }
        }

        dfs(i + 1);
    }
}
int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mp[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char x;
            cin >> x;
            if (x == '.') {
                mp[i][j] = 0;
            }
        }
    }
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=n;j++) {
    //         cout<<mp[i][j]<<" \n"[j==n];
    //     }
    // }
    dfs(1);
    printf("%d", ans);
    return 0;
}
