#include <iostream>
using namespace std;
ios_base::sync_with_stdio(false);

// Problema das moedas.
// MSC - Maior Subsequencia Crescente
// Problema da mochila!

void troco(){ 
// qtd minima de numeros p chegar na soma
    int n;
    cin >> n;
    set<int> nums;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        nums.insert(x);
    int objetivo;
    cin >> objetivo;
    vector<int> qt_nums(objetivo+1);
    qt_nums[0] = 0;
    for (int sub = 1; sub <= objetivo; sub++) {
        qt_nums[sub] = inf;
        for (int num : nums) {
            if (sub-num >= 0) {
                qt_nums[sub] = min(qt_nums[sub], qt_nums[sub-num]+1);
            }
        }
    }
    cout << qt_nums[objetivo];
}

void msc(){
// achar a maior sequencia possivel crescente
    int n;
    cin >> n;
    int array[n];
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        array[i] = x;
    vector<int> tam_sub;

    for(int i =0; i<n; i++){
        tam_sub[i] = 1; // caso base
        for(int j = 0; j < i; j++){
            if(array[i] < array[j]){
                tam_sub[j] = max(tam_sub[j],tam_sub[i]+1);
            }
        }
    }
}

int main(){

}
