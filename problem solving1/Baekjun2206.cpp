#include<iostream>
#include<queue>
#include<utility>
#include<string>

int map[1001][1001];
bool visited[1001][1001][2] = {false,};
int N,M;
int step = 1;
std::queue< std::pair<int, int> > q;
std::queue< std::pair<bool, int> > q2;

void bfs(){
    while(q.size() != 0){
        int cur_row = q.front().first;
        int cur_col = q.front().second;
        bool wall = q2.front().first;
        int cur_step = q2.front().second;
        q.pop();
        q2.pop();
        
        if((cur_row == N) && (cur_col == M)){
            step = cur_step;
            break;
        }
        if (cur_step == true){
            
        }
        if(cur_row + 1 <= N && (visited[cur_row + 1][cur_col][0] == false) || (visited[cur_row + 1][cur_col][1] == false)){
            if(map[cur_row+1][cur_col] == 0){
                q.push(std::make_pair(cur_row + 1, cur_col));
                q2.push(std::make_pair(wall, cur_step + 1));
                visited[cur_row + 1][cur_col] = true;
            }
            else if(map[cur_row+1][cur_col] == 1 && wall == true){
                q.push(std::make_pair(cur_row + 1, cur_col));
                q2.push(std::make_pair(false, cur_step + 1));
                visited[cur_row + 1][cur_col] = true;
            }
        }
        
        if(cur_row - 1 >= 1 && visited[cur_row - 1][cur_col] == false){
            if(map[cur_row-1][cur_col] == 0){
                q.push(std::make_pair(cur_row - 1, cur_col));
                q2.push(std::make_pair(wall, cur_step + 1));
                visited[cur_row - 1][cur_col] = true;
            }
            else if(map[cur_row-1][cur_col] == 1 && wall == true){
                q.push(std::make_pair(cur_row - 1, cur_col));
                q2.push(std::make_pair(false, cur_step + 1));
                visited[cur_row - 1][cur_col] = true;
            }
        }
        
        if(cur_col + 1 <= M && visited[cur_row][cur_col + 1] == false){
            if(map[cur_row][cur_col + 1] == 0){
                q.push(std::make_pair(cur_row, cur_col + 1));
                q2.push(std::make_pair(wall, cur_step + 1));
                visited[cur_row][cur_col + 1] = true;
            }
            else if(map[cur_row][cur_col + 1] == 1 && wall == true){
                q.push(std::make_pair(cur_row, cur_col + 1));
                q2.push(std::make_pair(false, cur_step + 1));
                visited[cur_row][cur_col + 1] = true;
            }
        }
        
        if(cur_col - 1 >= 1 && visited[cur_row][cur_col - 1] == false){
            if(map[cur_row][cur_col - 1] == 0){
                q.push(std::make_pair(cur_row, cur_col - 1));
                q2.push(std::make_pair(wall, cur_step + 1));
                visited[cur_row][cur_col - 1] = true;
            }
            else if(map[cur_row][cur_col - 1] == 1 && wall == true){
                q.push(std::make_pair(cur_row, cur_col - 1));
                q2.push(std::make_pair(false, cur_step + 1));
                visited[cur_row][cur_col - 1] = true;
            }
        }
    }
    return;
}

int main(){
    std::cin >> N >> M;
    for(int i = 1 ; i <= N ; i++){
        std::string s;
        std::cin >> s;
        for(int j = 1 ; j <= M ; j++){
            map[i][j] = s[j-1] - 48;
        }
    }
    visited[1][1] = true;
    q.push(std::make_pair(1,1));
    q2.push(std::make_pair(true,step));
    bfs();
    if(visited[N][M] == true){
        std::cout << step << "\n";
    }
    else{
        std::cout << -1 << "\n";
    }
    return 0;
}
