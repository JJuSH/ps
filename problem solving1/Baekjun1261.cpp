#include<iostream>
#define INF 987654321

int N, M;
int field[100][100];
int visited[100][100];
int min_step;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1 , 1};
void dfs(int r, int c, int step){
    //std::cout << "dfs " << r << " " << c << " " << step << "\n";
    
    visited[r][c] = std::min(visited[r][c], step);
    if(r == N - 1 && c == M - 1) return;
    for(int i = 0 ; i < 4 ; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        if(field[nr][nc] == 0){
            if(visited[nr][nc] > step) dfs(nr, nc, step);
        }
        else{
            if(visited[nr][nc] > step + 1) dfs(nr, nc, step + 1);
        }
    }
}
int main(){
    std::cin >> M >> N;
    for(int i = 0 ; i < N ; i++){
        std::string s;
        std::cin >> s;
        for(int j = 0 ; j < M ; j++){
            field[i][j] = s[j] - 48;
        }
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            visited[i][j] = INF;
        }
    }
    dfs(0,0,0);
    /*
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            std::cout << visited[i][j] << " ";
        }
        std::cout << "\n";
    }
     */
    std::cout << visited[N-1][M-1] << "\n";
    return 0;
}
