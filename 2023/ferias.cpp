#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int disposicao, queue<int> cansativas, queue<int> revigorantes){
   int qtAtividades=0;
   while(cansativas && revigorantes || disposicao >= 0){
      if(disposicao - cansativas.front()){
         disposicao -= cansativas.front();
         cansativas.pop();
         qtAtividades++;
      }
      else{
         disposicao += revigorantes.front();
         revigorantes.pop();
         qtAtivades++;
      }
   }
}

int main(){
   int disposicao,qtC,qtR;
   cin >> disposicao >> qtC >> qtR;
   queue<int> cansativas(qtC);
   queue<int> revigorantes(qtR);
   
   for(int i =0, i<qtC; i++){
      cin >> cansativas[i];
   }
   for(int i =0; i<qtR; i++){
      cin >> revigorantes[i];
   }
}