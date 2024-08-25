#include <iostream>
#include <vector>
using namespace std;

/* DIAGRAMA DE VORONOI
    dado um conjunto de pontos (sementes)
    o plano é divido em regioes,
    onde cada regiao contem
    TODOS os pontos mais proximos do que QUALQUER outro ponto.

    mas e os infinitos?
    A BORDA! os com x max ou min e y max ou min
    estao na borda, logo nao tem limitacoes.
*/

// 0 <= (x,y) <= 10^4

const int INF = 1e5;
int x_min = INF, y_min = INF;
int x_max = 0, y_max = 0;

void solution(vector<pair<int, int>> capitais, int n_capitais, vector<int> &infinitos)
{
    for (int i = 0; i < n_capitais; i++)
    {
        int x = capitais[i].first;
        int y = capitais[i].second;
        if (x == x_min || x == x_max || y == y_min || y == y_max)
        {
            infinitos.push_back(i + 1); // ONE BASED.
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n_capitais;
    cin >> n_capitais;
    vector<pair<int, int>> capitais(n_capitais);

    for (int i = 0; i < n_capitais; i++)
    {
        int x, y;
        cin >> x >> y;
        capitais[i] = {x, y};

        // CHECAR OS BOUNDERIES
        x_min = min(x_min, capitais[i].first);
        y_min = min(y_min, capitais[i].second);
        x_max = max(x_max, capitais[i].first);
        y_max = max(y_max, capitais[i].second);
    }

    vector<int> infinitos;
    solution(capitais, n_capitais, infinitos);

    for (int x : infinitos)
    {
        cout << x << " ";
    }
}