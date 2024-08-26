#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int INF = 1e9;

// int vector<int> dijkstra(int no_inicial, int n_nos, vector<vector<pair<int, int>>> adj) {
vector<int> dijkstra(int no_inicial, int n_nos, vector<vector<pair<int, int>>> const& adj)
{
    // encontrar os menores caminhos possiveis para todo os nós ou um especifico.
    vector<bool> processado(n_nos, false);
    vector<int> dists(n_nos, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila;
    // priority queue inversa!

    dists[no_inicial] = 0;
    fila.push({0, no_inicial});

    while (!fila.empty())
    {
        int no1 = fila.top().second; fila.pop();

        // if (no1 == no_destino){ return dist[no1] }; // caso queira parar no no_destino
        if (processado[no1]){ continue; }
        processado[no1] = true;

        for (pair<int, int> u : adj[no1])
        {
            int no2 = u.first, peso = u.second;
            if (dists[no1] + peso < dists[no2])
            {
                dists[no2] = dists[no1] + peso;
                fila.push({dists[no2], no2});
            }
        }
    }
    // return -1; // caso nao tenha caminho para o no_destino
    return dists;
}

// int bellman_ford(int no_inicial, int no_destino, int n_nos, vector<tuple<int,int,int>> arestas){
vector<int> bellman_ford(int no_inicial, int n_nos, vector<tuple<int, int, int>> const& arestas)
{
    vector<int> dists(n_nos, INF);
    dists[no_inicial] = 0;

    for (int i = 0; i < n_nos - 1; i++)
    {
        for (tuple<int, int, int> a : arestas)
        {
            int x, y, dist;
            tie(x, y, dist) = a;
            if (dists[y] < INF)
            {
                dists[y] = min(dists[y], dists[x] + dist);
            }
        }
    }
    // return dists[no_destino];
    return dists;
}

void dfs(int inicial, vector<vector<int>> const& adj, vector<bool> &visitado)
{
    if (visitado[inicial]){ return; }
    visitado[inicial] = true;

    for (int no : adj[inicial])
    {
        dfs(no, adj, visitado);
    }
}

// versao pro topological sort, retorna um elemento do array dfs
void dfs(int inicial, vector<vector<int>> const& adj, vector<bool>& visitado, vector<int>& output)
{
    if (visitado[inicial]){ return;}
    visitado[inicial] = true;

    for (int no : adj[inicial]) 
    {
        if (!visited[no]) 
        { 
            dfs(no,adj,visitado,output);
        }
    }
    output.push_back(inicial);
}

// versao pro KOSARAJU
void dfs(int inicial, vector<vector<int>> const& adj, vector<bool>& visitado, stack<int>& pilha){
    
    if(visitado[inicial]){ return; }
    visitado[inicial] = true;

    for (int no : adj[inicial]) 
    {
        if (!visited[no])
        {
            dfs(no, adj, visitado, pilha);
        }
    }
    pilha.push(inicial);
}

void dfs_transposto(int inicial, vector<vector<int>> const& adj_transposto, vector<bool>& visitado, vector<int>& subconjunto)
{
    visitado[inicial] = true;
    subconjunto.push_back(inicial);
    for (int no : adj_transposto[inicial]) {
        if (!visited[no]) {
            dfs_transposto(no, adj_transposto, visitado, subconjunto);
        }
    }
}

// cria o array dfs e ordena (DYNAMIC PROGRAMMING)
vector<int> topological_sort(int n, vector<vector<int>> const& adj)
{
    vector<bool> visitado(n,false);
    vector<int> output(n);

    // DFS em todos os nós.
    for (int i = 0; i < n; i++) 
    {
        if (!visitado[i])
        {
            dfs(i,adj,visitado,output);
        }
    }
    return reverse(output.begin(), output.end());
}

// KOSARAJU - lista de adj dos subconjuntos (componentes) fortemente conectados
void fortemente_conectados(int n, vector<vector<int>> const& adj)
{
    stack<int> pilha;
    vector<bool> visitado(n,false);
    vector<vector<int>> output(n);

    // DFS em todos os nós.
    for(int i = 0; i < n; i++)
    {
        if(!visitado[i])
        {
            dfs(i,adj,visitado,pilha);
        }
    }

    vector<vector<int>> adj_transposto(n);
    transpor_grafo(n,adj,adj_transposto);
    
    fill(visitado.begin(),visitado,end(),false); // reiniciar o visitados
    while(!pilha.empty())
    {
        int no = pilha.top(); pilha.pop();
        if (!visited[no])
        {
            vector<int> subconjunto;
            dfs_transposto(no, adj_transposto, visitado, subconjunto);
            // COMPONENTE(subconjunto) FORTEMENTE CONECTADO!
        }
    }
}

void transpor_grafo(int n, vector<vector<int>> const& adj, vector<vector<int>> const& adj_transposto)
{
    for (int i = 0; i < n; ++i)
    {
        for (int no : adj_transposto[i])
        {
            adj_transposto[no].push_back(i);
        }
    }
}

void bfs(int inicial, vector<vector<int>> const& adj, vector<bool> &visitado)
{
    queue<int> fila;
    // vector<int> distancia;

    visitado[inicial] = true; // caso comece em outro no, pode alterar.
    // distancia[inicial] = 0;   // nao precisa comecar pelo zero.
    fila.push(inicial);

    while (!fila.empty())
    {
        int atual = fila.front();
        fila.pop();
        for (int no : adj[atual])
        {
            if (visitado[no]){ continue; }

            visitado[no] = true;
            fila.push(no);
        }
    }
}
