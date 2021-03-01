#include<iostream>
#include<vector>
#include<utility>
#include<string.h>
#include<queue>

#define INF 987654321

std::vector<std::pair<int, int> > line[10001];
std::queue<std::pair<int, int> > qu;
int N;
bool explored[10001];
int max_dist, max_idx;

void bfs(){
    while(qu.size() != 0){
        int cur_dist = qu.front().second;
        int cur_node = qu.front().first;
        //std::cout << "while " << cur_node << " " << cur_dist << "\n";
        qu.pop();
        for(int i = 0 ; i < line[cur_node].size() ; i++){
            if(explored[line[cur_node][i].first] == false){
                explored[line[cur_node][i].first] = true;
                qu.push(std::make_pair(line[cur_node][i].first, line[cur_node][i].second + cur_dist));
                if(max_dist < line[cur_node][i].second + cur_dist) {
                    max_dist = line[cur_node][i].second + cur_dist;
                    max_idx = line[cur_node][i].first;
                }
            }
        }
    }
}

int main(){
    std::cin >> N;
    for(int i = 0 ; i < N-1 ; i++){
        int a, b, w;
        std::cin >> a >> b >> w;
        line[a].push_back(std::make_pair(b, w));
        line[b].push_back(std::make_pair(a, w));
    }
    max_dist = 0;
    max_idx = 0;
    qu.push(std::make_pair(1,0));
    memset(explored, 0 , sizeof(explored));
    explored[1] = true;
    bfs();
    
    //std::cout << max_idx << " " << max_dist << "\n";
    
    max_dist = 0;
    qu.push(std::make_pair(max_idx,0));
    memset(explored, 0 , sizeof(explored));
    explored[max_idx] = true;
    bfs();
        
    std::cout << max_dist << "\n";
        
    return 0;
}
