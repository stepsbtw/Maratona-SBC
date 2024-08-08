// tamanho da MAIOR SUBSEQUENCIA CRESCENTE!
// n = 5, arestas = [1,1,3,3] -1 (one based)
// 2: 5,7 ; 3: 5,7 ; 4: 5,7 ; 5: 5,7,8
// saida: 2,2,2,3.


#include <iostream>
#include <vector>
#include <unordered_map>

void dfs(
    int no,
    std::vector<int>& valor,
    std::unordered_map<int,std::vector<int>>& lista_adj,
    std::vector<int>& resposta,
    std::vector<bool>& visitado,
    std::vector<int>& msc // MAIOR SUBSEQUENCIA CRESCENTE!
){
    
}

void solution(
    std::vector<int>& valor,
    std::unordered_map<int,std::vector<int>>& lista_adj,
    std::vector<int>& resposta
){
    std::vector<bool> visitado(valor.size(),false);
    std::vector<int>msc; // ou LIS -> longest increasing subsequence.

    visitado[0] = true;
    msc.push_back(valor[0]);
    for(auto& filho : lista_adj[0])
        dfs(filho,valor,lista_adj,resposta,visitado,msc);
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> valor(n);
    std::vector<int> resposta(n - 1);
    std::unordered_map<int, std::vector<int>> lista_adj;

    lista_adj.reserve(n);

    for (int i = 1; i < n; i++)
    {
        int j;
        std::cin >> j;
        j--; // one based
        lista_adj[i].push_back(j);
        lista_adj[j].push_back(i);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << lista_adj[i][j];
        }
        std::cout << std::endl;
    }

    for(int i = 0; i<n; i++){
        std::cin >> valor[i];
    }

    solution(valor,lista_adj,resposta);

    std::cout << resposta[0];
    for(int i = 1; i<n-1;i++){
        std::cout << " " << resposta[i];
    }
    std::cout << std::endl;
    

    return 0;
}