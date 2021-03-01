#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#define INF 987654321
std::vector<std::pair<int ,int > > line[1001];
std::priority_queue<std::pair<int, int> > q;
int V, E;
int start, end;
int dist[1001];
bool visited[1001];
void dijk(){
    while(q.size() != 0){
        int cur_dist = -q.top().first;
        int cur_node = q.top().second;
        //std::cout << "while " << cur_dist << " " << cur_node << "\n";
        q.pop();
        int num_line = line[cur_node].size();
        visited[cur_node] = true;
        for(int i = 0 ; i < num_line ; i++){
            if((dist[line[cur_node][i].first] > cur_dist + line[cur_node][i].second) && (visited[line[cur_node][i].first] == false)){
                dist[line[cur_node][i].first] = cur_dist + line[cur_node][i].second;
                q.push(std::make_pair(-dist[line[cur_node][i].first] , line[cur_node][i].first));
            }
        }
    }
}
int main(){
    std::cin >> V;
    std::cin >> E;
    for(int i = 0 ; i < E ; i++){
        int a, b, w;
        std::cin >> a >> b >> w;
        line[a].push_back(std::make_pair(b,w));
        //line[b].push_back(std::make_pair(a,w));
    }
    std::cin >> start >> end;
    
    for(int i = 1 ; i <= V ; i++){
        dist[i] = INF;
        visited[i] = false;
    }
    
    q.push(std::make_pair(0,start));
    dist[start] = 0;
    visited[start] = true;
    dijk();
    
    //for(int i = 1 ; i <= V ; i++){
    //    std::cout << dist[i] << " ";
    //}
    std::cout << dist[end] << "\n";
    
    return 0;
}
