#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
std::vector<int> tree[50001];
std::vector<std::pair<int, int> > q;
int dp[50001][20];
int d[50001];
bool visited[50001];

int N , M;

void dfs(int node, int depth){
    visited[node] = true;
    d[node] = depth;
    for(int i : tree[node]){
        if(visited[i] == false){
            dp[i][0] = node;
            dfs(i , d[node] + 1);
        }
    }

}

void fill_par(){
    for(int j = 1 ; j < 20 ; j++){
        for(int i = 1 ; i <= N ; i++ ){
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
}

int lca(int x, int y) {
    if (d[x] > d[y])
        std::swap(x, y);
    for (int i = 20; i >= 0; i--) {
        if (d[y] - d[x] >= (1 << i))
            y = dp[y][i];
    }
    if (x == y)return x;
    for (int i = 20; i >= 0; i--) {
        if (dp[x][i] != dp[y][i]) {
            x = dp[x][i];
            y = dp[y][i];
        }
    }
    return dp[x][0];
}

int main(){
    std::cin >> N;
    for(int i = 0 ; i < N-1 ; i++){
        int a, b;
        std::cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1,0);
    fill_par();
    
    std::cin >> M;
    for(int i = 0 ; i < M ; i++){
        int a, b;
        std::cin >> a >> b;
        q.push_back(std::make_pair(a , b));
    }
    for(std::pair<int, int> qry : q) std::cout << lca(qry.first, qry.second);
    
    return 0;
}
