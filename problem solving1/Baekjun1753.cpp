#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
#define MAX_VER 20001
int num_node;
int num_line;
int start_node;
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
                std::cout << "push " << line[cur_node][i].first ;
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

int main(){
    std::cin >> num_node >> num_line ;
    std::cin >> start_node;
    
    for(int i = 0 ; i < num_line ; i++){
        int a, b, w;
        std::cin >> a >> b >> w;
        line[a].push_back(std::make_pair(b,w));
    }
    for(int i = 1 ; i <= num_node ; i++){
        dist[i] = INF;
    }
    q.push(std::make_pair(0,start_node));
    dist[start_node] = 0;
    dijk();

    print_dist();
    return 0;
}
