//
//  Baekjun2606.cpp
//  
//
//  Created by 주석훈 on 2021/01/21.
//
int num_node;
int num_line;
int line[101][101] = {0};
bool explored[101] = {false};
int count = 0;
#include <stdio.h>
#include <iostream>
void dfs(int node){
    explored[node] = true;
    count++;
    for(int i = 1 ; i <= num_node ; i++){
        if(i == node) continue;
        if(explored[i] == false && line[node][i]){
            dfs(i);
        }
    }
    return;
}


int main(){
    std::cin >> num_node;
    std::cin >> num_line;
    
    for(int i = 1 ; i <= num_line ; i++){
        int a,b;
        std::cin >> a >> b;
        line[a][b] = 1;
        line[b][a] = 1;
    }
    dfs(1);
    std::cout << count - 1<< "\n";
    return 0;
}
