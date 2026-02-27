#include <bits/stdc++.h>

using namespace std;

struct Time {
    int time;
    int pontos;
    int vitoria;
};

bool comparator(const Time& a, const Time& b) {
    if (a.pontos != b.pontos) {
        return a.pontos > b.pontos;
    }
    if (a.vitoria != b.vitoria) {
        return a.vitoria > b.vitoria;
    }
    return a.time < b.time;
}

int main() {
    int t, linhas, md, vs;
    vector<Time> times;
    char r;

    cin >> t;
    linhas = (pow(t, 2) - t) / 2;

    //Popular o vector
    for (int a = 0; a  < t; a++) {
        Time equipe;
        equipe.time = a + 1;
        equipe.pontos = 0;
        equipe.vitoria = 0;
        times.push_back(equipe);
    }

    for (int b = 0; b < linhas; b++) {
        cin >> md;
        cin >> vs;
        cin >> r;

        if (r == 'V') {
            for (int c = 0; c < t; c++) {
                if (times[c].time == md) {
                    times[c].pontos += 3;
                    times[c].vitoria++;
                    break;
                }
            }
        }else if (r == 'D') {
            for (int f = 0; f < t; f++) {
                    if (times[f].time == vs) {
                        times[f].pontos += 3;
                        times[f].vitoria++;
                        break;
                    }
                }
        }else {
            for (int i = 0; i < t; i++) {
                if (times[i].time == md) {
                    times[i].pontos++;
                }
                if (times[i].time == vs) {
                    times[i].pontos++;
                }
            }
        }
    }

    sort(times.begin(), times.end(), comparator);

    for (int z = 0; z < times.size(); z++) {
        cout << "Equipe " << times[z].time << ": " << times[z].pontos << "pts " << times[z].vitoria << "v" << endl;
    }
}