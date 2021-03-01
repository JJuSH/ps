#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#define INF 987654321
int field[50][50];
int map_bfs[50][50];
bool permu[10];
int ans = INF;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0 ,0 ,-1, 1};

int N, M;

std::vector<std::pair<int ,int> > seed;
std::queue<std::pair<std::pair<int, int>  ,int> > q;
std::vector<int> perm;

int bfs(const std::vector<int> &p ){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(field[i][j] == 1) map_bfs[i][j] = -INF;
            else if(field[i][j] == 2) map_bfs[i][j] = -1;
            else map_bfs[i][j] = 0;
        }
    }
    for(int v : p){
        q.push(std::make_pair(seed[v] , 1));
        map_bfs[seed[v].first][seed[v].second] = 1;
    }
    
    while(q.size() != 0){
        int cur_r = q.front().first.first;
        int cur_c = q.front().first.second;
        int cur_day = q.front().second;
        
        map_bfs[cur_r][cur_c] = cur_day;
        q.pop();
        
        for(int i = 3 ; i >= 0 ; i--){
            int nr = cur_r + dr[i];
            int nc = cur_c + dc[i];
            
            if(nr > N - 1 || nr < 0 || nc > N - 1 || nc < 0 ) continue;
            
            if(map_bfs[nr][nc] == 0 || map_bfs[nr][nc] > cur_day + 1){
                map_bfs[nr][nc] = cur_day + 1;
                q.push(std::make_pair(std::make_pair(nr, nc), cur_day + 1));
            }
            else if(map_bfs[nr][nc] == -1){
                map_bfs[nr][nc] = cur_day + 1;
                q.push(std::make_pair(std::make_pair(nr, nc), cur_day + 1));
            }
        }
    }
    
    int max_day = 1;
    bool flag = true;
    //std::cout << "----------bfs result----------" << "\n";
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(max_day < map_bfs[i][j] && field[i][j] != 2) max_day = map_bfs[i][j];
            if(map_bfs[i][j] == 0) flag = false;
            //if(map_bfs[i][j] == -INF) std::cout << "*" << " " ;
            //else std::cout << map_bfs[i][j] << " ";
        }
        //std::cout << "\n";
    }
    //std::cout << "----------bfs result----------" << "\n";
    
    if(flag) return max_day - 1;
    else return INF;
}

void comb(int n, int r, int cur_size, int cur_pos){
    if(cur_size == r){
        //std::cout << "found!" << "\n";
        //for(int a : perm) std::cout << a << " ";
        //std::cout << "\n";
        int day = bfs(perm);
        ans = std::min(ans, day);
        //std::cout << "bfs result : " << day << " new ans : " << ans << "\n";
    }
    else{
        while(cur_pos < n){
            perm.push_back(cur_pos);
            comb(n, r, cur_size + 1, cur_pos + 1);
            perm.pop_back();
            cur_pos++;
        }
    }
}

int main(){
    std::cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            std::cin >> field[i][j];
            if(field[i][j] == 2) seed.push_back(std::make_pair(i,j));
        }
    }
        
    unsigned int seed_num = seed.size();
    comb(seed_num,M, 0, 0);
    
    if(ans != INF) std::cout << ans << "\n";
    else std::cout << -1 << "\n";
    
    return 0;
}
