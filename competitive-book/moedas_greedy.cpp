#include <iostream>
#include <vector>
using namespace std;

// GREEDY SOLUTION. DONT WORK

int solucao(moedas,troco){
   melhor = 0;
   int n = moedas.size();
   for(moeda : moedas){
      while(troco > moeda){
         troco-=moeda;
         qtMoedas++;
      }
      if(troco ==0){melhor = qtMoedas;}
   }
   return qtMoedas;
}

int main(){
   int troco;
   cin >> troco;
   vector<int> moedas(troco);
   cout << solucao(moedas,troco);
}