#include<iostream>
#define INF 987654321
int N, E;
int par[50];
bool lf[50] = {false}; //false이면 leaf
bool cut(int node){
    if(node == E) return true;
    else if(par[node] == -1) return false;
    else if(par[node] == -INF) return true;
    else return cut(par[node]);
}

int main(){
    std::cin >> N;
    for(int i = 0 ; i < N ; i++) std::cin >> par[i];
    std::cin >> E;
    
    for(int i = 0 ; i < N ; i++) if(cut(i)) par[i] = -INF;
    for(int i = 0 ; i < N ; i++) lf[i] = true;
    for(int i = 0 ; i < N ; i++){
        if(par[i] == -INF) lf[i] = false;
        else if(par[i] != -1) lf[par[i]] = false;
    }
    int count = 0;
    
    for(int i = 0 ; i < N ; i++) if(lf[i] == true) count++;
    
    std::cout << count << "\n";
    return 0;
}
