#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    int cadeia[n][m];

    int soma = 0;

    if (n >= 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> cadeia[i][j];
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    soma += cadeia[i][j];
                }
            }
        }
    }

    cout << soma << endl;
}