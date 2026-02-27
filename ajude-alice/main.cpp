#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main () {
    double a, b, c;
    cin >> a >> b;

    if (a > b) {
        int ia = a/1;
        int ib = b/1;
        int ic = ia - ib;
        double da = fmod(a, 1);
        double db = fmod(b, 1);
        double dc;
        if (da < db) {
            dc = 0.6 + da - db;
            ic--;
        }else {
            dc = da - db;
        }
        c = ic + dc;
        cout << fixed << setprecision(2) << c << endl;
    }
}