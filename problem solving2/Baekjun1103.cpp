#include<iostream>
#include<string>
#define INF 987654321
int R, C;
int field[51][51];
bool visited[51][51] = {false};
int life[51][51] = {0};
int dr[4] = {-1 , 1 , 0 , 0};
int dc[4] = {0 , 0 , -1 , 1};
int ans = 0;

void dfs(int r, int c, int step){
    //std::cout << "dfs " << r << " " << c << " " << field[r][c] << " " << step << "\n";
    life[r][c] = step;
    ans = std::max(ans, step);
    for(int i = 0 ; i < 4 ; i++){
        int nr = r + field[r][c] * dr[i];
        int nc = c + field[r][c] * dc[i];
        
        if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        else{
            if(visited[nr][nc] == true){
                ans = INF;
            }
            else{
                if(field[nr][nc] != 0 && life[nr][nc] < step + 1){
                    visited[nr][nc] = true;
                    dfs(nr, nc, step + 1);
                    visited[nr][nc] = false;
                }
            }
        }
    }
    visited[r][c] = false;
    return;
    
}
int main(){
    std::cin >> R >> C;
    for(int i = 0 ; i < R ; i++){
        std::string s;
        std::cin >> s;
        for(int j = 0 ; j < C ; j++){
            if(s[j] == 'H'){
                field[i][j] = 0;
            }
            else{
                field[i][j] = s[j] - 48;
            }
        }
    }
    visited[0][0] = true;
    dfs(0 , 0 , 1);
    if(ans == INF) std::cout << -1 << "\n";
    else std::cout << ans << "\n";
    return 0;
}
