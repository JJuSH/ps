#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<utility>
#include<stack>
#define INF 987654321
std::vector<std::pair<int , int> > road[1001];
std::vector<int> ans;
std::priority_queue<std::pair<int , int> > q;
std::stack<int> track;
int num_city;
int num_road;
int start, end;
int dist[1001][2]; // 0 : distance , 1 : last update node

void dijk(){
    dist[start][0] = 0;
    dist[start][1] = 0;
    
    q.push(std::make_pair(0, start));
    
    while(q.size() != 0){
        int cur_dist = -q.top().first;
        int cur_node = q.top().second;
        q.pop();
        for(int i = 0 ; i < road[cur_node].size() ; i++){
            if(cur_dist + road[cur_node][i].second < dist[ road[cur_node][i].first][0]){
                dist[ road[cur_node][i].first][0] = cur_dist + road[cur_node][i].second;
                dist[ road[cur_node][i].first][1] = cur_node;
                q.push(std::make_pair( -dist[ road[cur_node][i].first][0] , road[cur_node][i].first));
                
            }
        }
    }
}
void init(){
    for(int i = 0 ; i <= 1000 ; i++){
        dist[i][0] = INF;
    }
}
int main(){
    std::cin >> num_city >> num_road;
    for(int i = 0 ; i < num_road ; i++){
        int a, b, w;
        std::cin >> a >> b >> w;
        road[a].push_back(std::make_pair(b,w));
    }
    std::cin >> start >> end;
    
    init();
    dijk();
    
    int flag = end;
    while(flag != 0){
        track.push(flag);
        flag = dist[flag][1];
    }
    std::cout << dist[end][0] << "\n";
    std::cout << track.size() << "\n";
    while(track.size() != 0){
        std::cout << track.top() << " ";
        track.pop();
    }
    std::cout << "\n";
    return 0;
}
