# Folha de Consulta

## `std::vector` 

### `sort(v.begin(), v.end(), comparator)`

- Para uma função de sort/ordenação, são necessários três parâmetros : 
1. `v.begin()` : Responsável por é um passo depois do último elemento (v = nome do vector);
2. `v.end()` : Responsável por pegar o final do vetor (v = nome do vector);
3. `comparator` : Função, responsável por realizar as comparações dentro do sort. Se `comparar(a,b)` é true, então `comparar(b,a) tem que ser false`. Quando “empata tudo”, tem que retornar `false` pros dois lados. (**necessita ser construída com os parâmetros desejados**) <br> 

- Exemplo de uma função de comparação 
```cpp
bool comparar(const Time& a, const Time& b)
{
    if (a.pontos != b.pontos) //pontos de a e pontos de b são diferentes ? Ok, então vamos comparar os outros parâmetros 
    {
        return a.pontos > b.pontos; //pontos de a é maior que pontos de b ? Se sim, retorne true e coloque a na frente de b. Caso contrário, retorne false e coloque b na frente de a.
    }
    if (a.vitorias != b.vitorias) //vitórias de a e vitórias de b são diferentes ? Ok, então vamos comparar os outros parâmetros
    {
        return a.vitorias > b.vitorias; //vitórias de a é maior que as vitórias de b ? Se sim, retorne true e coloque a na frente de b. Caso contrário retorne false e coloque b na frente de a
    }
    return a.time > b.time; //Se não atender a nenhuma das outras condições, compare a e b. a é maior que b ? Sim, então retorne true e coloque a na frente de b. Caso contrário, retorne false e coloque b a frente de a.
}
```
---

## `cin`

### `cin.getline()`

---

## `std::set`