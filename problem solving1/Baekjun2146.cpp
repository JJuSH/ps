#include<iostream>
#include<queue>
#include<utility>
#include<string.h>
#define INF 987654321
int N;
int field[100][100];
int field_copy[100][100];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int visited[100][100] = {0};
int cont = 1;
int min_step = INF;
std::queue<std::pair<std::pair<int, int> ,int> > q[10001];

void print_result(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(visited[i][j] == -INF) std::cout << "*" << " ";
            else std::cout << visited[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int bfs(int cont, std::queue<std::pair<std::pair<int, int> ,int> > &qu ){
    memset(field_copy, 0 , sizeof(field_copy));
    while(qu.size() != 0){
        int cur_r = qu.front().first.first;
        int cur_c = qu.front().first.second;
        int cur_step = qu.front().second;
        qu.pop();
        //std::cout << "while " << cur_r << " " << cur_c << "\n";
        field_copy[cur_r][cur_c] = cur_step;
        
        for(int i = 0 ; i < 4 ; i++){
            int nr = cur_r + dr[i];
            int nc = cur_c + dc[i];
            
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            
            if(visited[nr][nc] != cont && visited[nr][nc] != 0) return cur_step;
            
            if(visited[nr][nc] == 0 && (field_copy[nr][nc] == 0 || field_copy[nr][nc] > cur_step + 1 )){
                qu.push(std::make_pair(std::make_pair(nr, nc), cur_step + 1));
                field_copy[nr][nc] = cur_step + 1;
            }
        }
    }
    //std::cout << "error " << "\n";
    return INF;
}

void dfs(int r, int c, int cont){
    visited[r][c] = cont;
    q[cont].push(std::make_pair(std::make_pair(r, c), 0));
    for(int i = 0 ; i < 4 ; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if(field[nr][nc] == 1 && visited[nr][nc] == 0){
            dfs(nr, nc, cont);
        }
    }
}

int main(){
    std::cin >> N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            std::cin >> field[i][j];
        }
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(visited[i][j] == 0 && field[i][j] == 1){
                dfs(i,j,cont);
                cont++;
            }
        }
    }
    for(int i = 1 ; i < cont ; i++){
        min_step = std::min(min_step, bfs(i , q[i]));
    }
    //std::cout << "result--------" << "\n";
    std::cout << min_step << "\n";
    return 0;
}
