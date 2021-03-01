#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
#define MAX_VER 801
int num_node;
int num_line;
int node1;
int node2;
std::vector<std::pair<int, int> > line[MAX_VER];
std::priority_queue<std::pair<int,int> > q;

int dist[MAX_VER];

void dijk(){
    while(q.size() != 0){
        int cur_node = q.top().second;
        int cur_dist = -q.top().first;
        q.pop();
        
        //dist[cur_node] = cur_dist;
        
        for(int i = 0 ; i < line[cur_node].size() ; i++){
            int distance = dist[line[cur_node][i].first];
            int new_distance = cur_dist + line[cur_node][i].second;
            
            if(new_distance < distance){
                dist[line[cur_node][i].first] = new_distance;
                q.push( std::make_pair( -dist[line[cur_node][i].first], line[cur_node][i].first ) );
                //std::cout << "push " << line[cur_node][i].first ;
            }
        }
    }
}


void print_dist(){
    //std::cout << "\n";
    for(int i = 1 ; i <= num_node ; i++){
        if(dist[i] == INF) std::cout << "INF" << "\n";
        else std::cout << dist[i] << "\n";
    }
}

int calc(int start, int end){
    for(int i = 1 ; i <= num_node ; i++){
        dist[i] = INF;
    }
    q.push(std::make_pair(0,start));
    dist[start] = 0;
    dijk();
    return dist[end];
}

int main(){
    std::cin >> num_node >> num_line ;
    
    for(int i = 0 ; i < num_line ; i++){
        int a, b, w;
        std::cin >> a >> b >> w;
        line[a].push_back(std::make_pair(b,w));
        line[b].push_back(std::make_pair(a,w));
    }
    std::cin >> node1 >> node2;
    int _to1 = calc(1,node1);
    int _to2 = calc(1,node2);
    int _1to2 = calc(node1, node2);
    int _1to_end = calc(node1, num_node);
    int _2to_end = calc(node2, num_node);
    
    int path1 =_to1 + _1to2 + _2to_end;
    int path2 =_to2 + _1to2 + _1to_end;
    
    int ans1 = std::min(_to1 + _1to2 + _2to_end, _to2 + _1to2 + _1to_end);
    int ans2 = std::min(_to1 + _1to2 * 2 + _1to_end, _to2 + 2 * _1to2 + _2to_end);
    int ans = std::min(ans1, ans2);
    
    if(ans >= INF || ans < 0) std::cout << -1 << "\n";
    else std::cout << ans << "\n";
    return 0;
}
