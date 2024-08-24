#include <iostream>
#include <vector>
#include <set>
#include <algorithm> // min e max
using namespace std;


// Problema das moedas.
// MSC - Maior Subsequencia Crescente
// Problema da mochila!

const int INF = 1e9;

int coin_change(set<int> nums, int objetivo){  // qtd minima de numeros p chegar na soma

	vector<int> qt_nums(objetivo+1, INF);
	qt_nums[0] = 0; // (caso base)

	for (int sub = 1; sub <= objetivo; sub++) {
		for (int num : nums) {
			if (sub - num >= 0) {
				qt_nums[sub] = min(qt_nums[sub], qt_nums[sub-num]+1);
			}
		}
	}

	return qt_nums[objetivo] == INF? -1 : qt_nums[objetivo]; // se infinito, não é possivel formar a soma.
}

int maior_subsequencia_crescente(vector<int> nums, int n_nums){

	vector<int> tamanho_sub(n_nums,1); // (caso base)

	for(int i =0; i<n_nums; i++){
		for(int j = 0; j < i; j++){
			if(nums[i] > nums[j]){
				tamanho_sub[i] = max(tamanho_sub[i], tamanho_sub[j]+1);
			}
		}
	}

	return *max_element(tamanho_sub.begin(),tamanho_sub.end());
}


vector<vector<bool>> mochila(vector<int> pesos, int max_soma, int n_pesos){

	vector<vector<bool>> possiveis_somas(max_soma + 1,vector<bool>(n_pesos+1, false));
	possiveis_somas[0][0] = true; // (caso base)

	for(int i = 1; i < n_pesos; i++){
		for(int soma = max_soma; soma >= 0; soma--){

			if(possiveis_somas[soma][i-1]){
				possiveis_somas[soma][i] = true; // caso ja funcionava, ainda funciona
			}
			
			if(soma - pesos[i-1] >= 0){
				if(possiveis_somas[soma-pesos[i-1]][i-1]){
					possiveis_somas[soma][i] = true;
				}
			}

		}
	}

	return possiveis_somas;
}