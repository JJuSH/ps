#include<iostream>
#include<vector>

std::vector<int> line[100001];
int N;
bool explored[100001] = {false,};
int parent[100001];

void dfs(int node){
    explored[node] = true;
    for(int i = 0 ; i < line[node].size() ; i++){
        if(explored[line[node][i]] == false){
            parent[line[node][i]] = node;
            dfs(line[node][i]);
        }
    }
    return;
}

int main(){
    std::cin >> N ;
    for(int i = 0 ; i < N-1 ; i++){
        int a, b;
        std::cin >> a >> b;
        line[a].push_back(b);
        line[b].push_back(a);
    }
    dfs(1);
    for(int i = 2 ; i <= N ; i++){
        std::cout << parent[i] << "\n";
    }
    return 0;
}
