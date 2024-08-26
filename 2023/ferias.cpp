#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// FAZER AS ATIVIDADES ATÉ EU NAO CONSEGUIR MAIS.

// condicao de parada: nao consigo fazer mais nenhuma atividade cansativa e ja fiz todas revigorantes.

int solution(int disposicao, queue<int> cansativas, queue<int> revigorantes, int qtC, int qtR)
{
    int qtAtividades = 0;

    while(!revigorantes.empty())
    {
        if (!cansativas.empty() && disposicao >= cansativas.front())
        {
            disposicao -= cansativas.front();
            cansativas.pop();
            qtAtividades++;
        }
        else
        {
            disposicao += revigorantes.front();
            revigorantes.pop();
            qtAtividades++;
        }
    }
    
    // quando esvaziar a fila de revigorantes talvez eu seja capaz de fazer ainda.
    if (!cansativas.empty() && disposicao >= cansativas.front())
    {
            disposicao -= cansativas.front();
            cansativas.pop();
            qtAtividades++;
    }

    return qtAtividades;
}

int main()
{
    int disposicao, qtC, qtR;
    cin >> disposicao >> qtC >> qtR;
    queue<int> cansativas;
    queue<int> revigorantes;

    for (int i = 0; i < qtC; i++)
    {
        int x;
        cin >> x;
        cansativas.push(x);
    }
    for (int i = 0; i < qtR; i++)
    {
        int x;
        cin >> x;
        revigorantes.push(x);
    }
    cout << solution(disposicao, cansativas, revigorantes, qtC, qtR);
}
