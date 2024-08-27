#include <iostream>
#include <vector>
#include <queue>

vector<int> dijkstra(int no_inicial, int n_nos vector<vector<pair<int,int>>> const& adj)
{
    vector<bool> processado(n_nos,false);
    vector<int> dists(n_nos,INF);
    
    priority_queue<pair<int,int>> fila; // prioridade decrescente
    
    dists[no_inicial] = 0;
    fila.push({0,no_inicial});
    
    while(!fila.empty())
    {
        int no1 = fila.top().second; fila.top;
        
        if ( processado[no1] ){ continue; }
        processado[no1] = true;
        
        for(pair<int,int> u : adj[no1])
        {
            int no2 = u.first, peso = u.second;
            if(dists[no1] + peso < dists[no2])
            {
                dists[no2] = dists[no1] + peso;
                fila.push({-dists[no2],no2});
            }
        }
    }
    return dists;
}

void solution(vector<vector<pair<int,int>>>& adj_bi, int n_arestas, int n_nos)
{
    for(int i = 0; i< n_arestas; i++)
    {
    	
    }
}

int main()
{
    int n_nos, n_arestas;
    cin >> n_nos;
    cin >> n_arestas;
    vector<vector<pair<int,int>>> adj_bi(n_arestas*2); // bidirecional
    
    for(int i=0; i<n_arestas; i++){
        int no1,no2,dist;
        cin >> no1 >> no2 >> dist;
        adj_bi[no1].push_back({dist,no2});
        adj_bi[no2].push_back({dist,no1});
    }
    
    solution(adj_bi,n_arestas,n_nos);

}
