#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void solution(int idx, vector<int>& baralho_final, vector<vector<int>>& sublistas){

    sublistas.push_back({baralho_final[idx]}); // cria uma nova sublista
    for(int i = idx +1; i<baralho_final.size(); i++){
        if(baralho_final[i] > sublistas.back().back()){
            sublistas.back().push_back(baralho_final[i]);
        }
        else{
            solution(idx,baralho_final,sublistas);
            break;
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> baralho_final(n);

    for(int i = 0; i<n; i++){
        cin >> baralho_final[i];
    } 

    // MAIORES SUBSEQUENCIAS CRESCENTE!
    // achar as sublistas! -> pior dos casos é ter N sublistas ( eu acho).
    
    vector<vector<int>> sublistas;
    solution(0,baralho_final,sublistas);
    
    /*
    sublistas.push_back({baralho_final[0]});
    for(int i = 1; i<n; i++){
        if(sublistas.back().back() > baralho_final[i]){
            sublistas.push_back({baralho_final[i]});
        }
        else{
            sublistas.back().push_back(baralho_final[i]);
        }
    }
    */

    for(int i = 0; i<sublistas.size(); i++){
        for(int j = 0; j < sublistas[i].size(); j++){
            cout << sublistas[i][j] << " ";
        }
        cout << endl;
    }
    
}