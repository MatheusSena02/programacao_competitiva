#include <bits/stdc++.h>

using namespace std;

int main() {
    set<char> alfabeto;
    char primeira_letra = 'a';

    for (int i = 0; i < 26; i++) {
        char letra_alfabeto = primeira_letra + i;
        alfabeto.insert(letra_alfabeto);
    }

    int n;
    vector<string> mensagem_original;
    string entrada;

    cin >> n;

    cin.ignore();

    for (int j = 0; j < n; j++) {
        getline(cin, entrada);
        mensagem_original.push_back(entrada);
    }

    for (int k = 0; k <mensagem_original.size(); k++) {
        string mensagem = mensagem_original[k];
        for (int l = 0; l < mensagem.size(); l++) {
            if (alfabeto.contains(tolower(mensagem[l]))) {
                mensagem[l] += 3;
            }
        }
        mensagem_original[k] = mensagem;
    }

    vector<string> mensagem_invertida;

    for (int a = 0; a < mensagem_original.size(); a++) {
        string copia_mensagem = mensagem_original[a];
        string conteudo_copia = copia_mensagem;
        for (int b = conteudo_copia.size();  b >= 0; b--) {
            int contador = conteudo_copia.size() - b;
            copia_mensagem[contador] = conteudo_copia[b - 1];
        }
        mensagem_invertida.push_back(copia_mensagem);
    }


    vector<string> mensagem_final;

    for (int c = 0; c < mensagem_invertida.size(); c++) {
        string texto_invertido = mensagem_invertida[c];
        int tamanho_texto = texto_invertido.size();
        for (int d = tamanho_texto / 2;  d < texto_invertido.size(); d++) {
            texto_invertido[d]--;
        }
        mensagem_final.push_back(texto_invertido);
    }

    for (int f = 0; f < mensagem_final.size(); f++) {
        cout << mensagem_final[f] << endl;
    }
}