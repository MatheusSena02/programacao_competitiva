#include <iostream>
#include <string>
#include <vector> 

using namespace std;

int main()
{
    int n;
    string c;
    int v;
    int e;
    int somaMoedas = 0;
    vector<string> moedaAceita;
    vector<int> valorAceito;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> c;
        cin >> v;
        moedaAceita.push_back(c);
        valorAceito.push_back(v);
    }
    
    cin >> e;
    
    for(int j = 0; j < moedaAceita.size(); j++){
        if(valorAceito[j] >= e){
            somaMoedas += valorAceito[j];
            cout << moedaAceita[j] << " ";
            cout << valorAceito[j] << endl;
        }
    }
    
    cout << somaMoedas << endl;
}
