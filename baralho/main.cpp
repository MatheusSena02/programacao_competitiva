#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, p;

    cin >> n;

    vector<int> pontos;

    for (int i = 0; i < n; i++) {
        cin >> p;
        pontos.push_back(p);
    }

    sort(pontos.begin(), pontos.end());

    for (int j = 0; j < pontos.size(); j++) {
        cout << pontos[j] << " ";
    }
}