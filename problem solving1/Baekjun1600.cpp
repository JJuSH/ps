#include<iostream>
#include<queue>
#include<utility>
#define INF 987654321
int K, W, H;
int field[201][201];
int visited[201][201][30] = {0};
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int dr_n[8] = {-2, -2, 2, 2, -1, 1, -1, 1};
int dc_n[8] = {-1, 1, -1, 1, -2, -2, 2, 2};
std::queue<std::pair<std::pair<int, int> , std::pair<int ,int> > > q; //coord, break_left, step;

void bfs(){
    while(q.size() != 0){
        int cur_r = q.front().first.first;
        int cur_c = q.front().first.second;
        int cur_break = q.front().second.first;
        int cur_step = q.front().second.second;
        
        visited[cur_r][cur_c][cur_break] = cur_step;
        q.pop();
        if(cur_r == H - 1 && cur_c == W - 1) break;
        if(cur_break == 0){
            for(int i = 0 ; i < 4 ; i++){
                int nr = cur_r + dr[i];
                int nc = cur_c + dc[i];
                
                if(nr > H - 1 || nr < 0 || nc > W - 1 || nc < 0) continue;
                if(visited[nr][nc][cur_break] == 0 && field[nr][nc] == 0){
                    q.push(std::make_pair(std::make_pair(nr, nc) , std::make_pair(cur_break, cur_step + 1)));
                    visited[nr][nc][cur_break] = cur_step + 1;
                }
            }
        }
        else{
            for(int i = 0 ; i < 8 ; i++){
                int nr = cur_r + dr_n[i];
                int nc = cur_c + dc_n[i];
                if(nr > H - 1 || nr < 0 || nc > W - 1 || nc < 0) continue;
                if(visited[nr][nc][cur_break - 1] == 0 && field[nr][nc] == 0){
                    q.push(std::make_pair(std::make_pair(nr, nc) , std::make_pair(cur_break - 1, cur_step + 1)));
                    visited[nr][nc][cur_break - 1] = cur_step + 1;
                }
            }
            
            for(int i = 0 ; i < 4 ; i++){
                int nr = cur_r + dr[i];
                int nc = cur_c + dc[i];
                
                if(nr > H - 1 || nr < 0 || nc > W - 1 || nc < 0) continue;
                if(visited[nr][nc][cur_break] == 0 && field[nr][nc] == 0){
                    q.push(std::make_pair(std::make_pair(nr, nc) , std::make_pair(cur_break, cur_step + 1)));
                    visited[nr][nc][cur_break] = cur_step + 1;
                }
            }
        }
    }
}
int main(){
    std::cin >> K;
    std::cin >> W >> H;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j ++){
            std::cin >> field[i][j];
        }
    }
    q.push(std::make_pair(std::make_pair(0, 0) , std::make_pair(K, 1)));
    bfs();
    int ans = INF;
    for(int i = 0 ; i <= K ; i++){
        if(visited[H-1][W-1][i] == 0) continue;
        ans = std::min(ans, visited[H-1][W-1][i] - 1);
    }
    if(ans == INF) std::cout << -1 << "\n";
    else std::cout << ans << "\n";
    
    return 0;
}
