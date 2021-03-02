#include<iostream>
#include<vector>
#include<string.h>
int N, M;
int count = 0;
bool visited[101];
std::vector<int> v[101];
int owner[101] = {0};
bool bm(int per){
    visited[per] = true;
    
    unsigned int sz = v[per].size();
    for(int i = 0 ; i < sz ; i++){
        int to = v[per][i];
        if(owner[to] == 0 || !visited[owner[to]] && bm(owner[to])){
            owner[to] = per;
            return true;
        }
    }
    return false;
}
int main(){
    std::cin >> N >> M;
    for(int i = 0 ; i < M ; i++){
        int a, b;
        std::cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i = 1 ; i <= N ; i++){
        memset(visited, false, sizeof(visited));
        if(bm(i)) count++;
    }
    std::cout << count << "\n";
    
    return 0;
}
