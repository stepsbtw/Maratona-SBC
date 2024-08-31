#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 1 <= n <= 10^9

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<pair<int,int>> pulos;
	
	for(int i = 0; i < m; i++){
		int x, e;
		cin >> x >> e;
		pulos.push_back({x,e});	
	}
	
	// x = pedra(dist), k = qt energia, sum = soma das distancias ate aqui
	vector<vector<int>> valor(n+1,vector<int>(k+1,0));
	for(int e = 0; e <= k; e++){
		valor[1][e] = 1;
	}
	
	for(int x = 2; x <= n; x++){
		for(int e = 0; e <= k; e++){
			for(pair<int,int> pulo : pulos){
				int x0 = pulo.first, e0 = pulo.second;
				if(x-x0 >= 1 && e + e0 <= k){
					valor[x][e] += valor[x-x0][e+e0];
					valor[x][e] %= 1000000000;
				}
			}
		}
	}
	
	cout << valor[n][0];
	
}
