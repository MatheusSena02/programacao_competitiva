# As moedas de Super Mario — dissecação do `main.cpp`

> Problema (resumo do enunciado): você recebe **N moedas** (cor `C` e valor `V`). No final, recebe um **limite `E`**.  
> Você precisa **imprimir cada moeda com `V >= E`** (na mesma ordem de entrada) e, por último, **imprimir a soma** desses valores. Se não tiver nenhuma, imprime `0`.

---

## O que o seu programa faz (em uma frase)

Ele **guarda todas as moedas**, lê o **limite `E`**, **filtra e imprime** as moedas com valor suficiente e **acumula** a soma final.

---

## Formato de entrada e saída (do jeito que o código espera)

### Entrada
1. Um inteiro `N`  
2. `N` linhas: `C V` (ex.: `Azul 20`)  
3. Um inteiro `E`

### Saída
- Uma linha para **cada moeda** com `V >= E`: `C V`
- Última linha: **soma total** dessas moedas

---

## Estratégia usada

Como `E` só aparece **depois** de ler todas as moedas, você não consegue decidir na hora se uma moeda entra na soma.  
Então você fez o certo: **armazenou tudo em vetores** e só depois comparou com `E`.

---

## Estruturas de dados

Você usa dois vetores paralelos:

- `vector<string> moedaAceita;` → guarda a **cor** (`C`)
- `vector<int> valorAceito;` → guarda o **valor** (`V`)

Isso funciona, mas é um “casal separado”: tem que cuidar pra nunca dessincronizar (ex.: dar push em um e esquecer no outro).  
Mais abaixo eu deixo uma versão mais “blindada” com `pair/struct`.

---

## Fluxo do código (passo a passo)

### 1) Leitura de `N` e preparação
```cpp
int n;
cin >> n;
```

Você inicializa também:

- `int somaMoedas = 0;` → acumulador da soma
- os vetores para armazenar entrada

### 2) Leitura das `N` moedas
```cpp
for (int i = 0; i < n; i++) {
    string entrada;
    cin >> entrada;
    int valor;
    cin >> valor;

    moedaAceita.push_back(entrada);
    valorAceito.push_back(valor);
}
```

Aqui você lê a moeda e joga em memória.  
**Obs.:** `entrada` é a cor da moeda (o nome poderia ser `cor` pra ficar mais claro).

### 3) Leitura do limite `E`
```cpp
cin >> e;
```

Agora sim você sabe quais moedas entram.

### 4) Filtragem + impressão + soma
```cpp
for (int j = 0; j < moedaAceita.size(); j++) {
    if (valorAceito[j] >= e) {
        somaMoedas += valorAceito[j];
        cout << moedaAceita[j] << " " << valorAceito[j] << endl;
    }
}
```

- Percorre todas as moedas
- Se `V >= E`, soma no acumulador e imprime exatamente como o enunciado pede

### 5) Impressão da soma final
```cpp
cout << somaMoedas;
```

Como `somaMoedas` começa em `0`, se nenhuma moeda passar no filtro o programa imprime `0` — **bate com o enunciado**.

---

## Complexidade

- **Tempo:** `O(N)` para ler + `O(N)` para filtrar → **O(N)** no total  
- **Memória:** `O(N)` por armazenar todas as moedas (cor + valor)

Com `N <= 100`, isso é tranquilo demais.

---

## Como compilar e rodar (pra colar no README do repo)

```bash
g++ -std=c++17 -O2 -Wall -Wextra main.cpp -o main
./main < input.txt
```

---

## Teste mental rápido (sanity check)

Se `E = 50` e as moedas forem:
- `Laranja 100`
- `Amarelo 15`
- `Verde 25`

Só a primeira passa, então imprime:
```
Laranja 100
100
```