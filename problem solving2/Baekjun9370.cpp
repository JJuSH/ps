#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 987654321
#define MAX_VER 2001
int case_num;
int num_ver;
int num_road;
int num_cand;
int start;
int mid1, mid2;
int mid_dist;

std::vector<std::pair<int, int> > road[MAX_VER];
std::priority_queue<std::pair<int,int> > q;
std::vector<std::pair<int,int> > cand;
std::vector<int> v[100];
int dist[MAX_VER];

void dijk(){
    while(q.size() != 0){
        int cur_node = q.top().second;
        int cur_dist = -q.top().first;
        q.pop();
        
        //dist[cur_node] = cur_dist;
        
        for(int i = 0 ; i < road[cur_node].size() ; i++){
            int distance = dist[road[cur_node][i].first];
            int new_distance = cur_dist + road[cur_node][i].second;
            
            if(new_distance < distance){
                dist[road[cur_node][i].first] = new_distance;
                q.push( std::make_pair( -dist[road[cur_node][i].first], road[cur_node][i].first ) );
            }
        }
    }
}

int calc(int start, int end){
    for(int i = 1 ; i <= num_ver ; i++){
        dist[i] = INF;
    }
    q.push(std::make_pair(0,start));
    dist[start] = 0;
    dijk();
    return dist[end];
}

void clear(){
    cand.clear();
    for(int i = 0 ; i < MAX_VER ; i++){
        road[i].clear();
    }
}

int main(){
    std::cin >> case_num;
    for(int j = 0 ; j < case_num ; j++){
        clear();
        
        std::cin >> num_ver >> num_road >> num_cand;
        std::cin >> start >> mid1 >> mid2;
        
        for(int i = 0 ; i < num_road ; i++){
            int a, b, w;
            std::cin >> a >> b >> w;
            road[a].push_back(std::make_pair(b,w));
            road[b].push_back(std::make_pair(a,w));
            
            if((mid1 == a && mid2 == b) || (mid2 == a && mid1 == b)) mid_dist = w;
        }
        for(int i = 0 ; i < num_cand ; i++){
            int temp;
            std::cin >> temp;
            cand.push_back(std::make_pair(temp,0));
        }
        
        int _to1 = calc(start,mid1);
        int _to2 = calc(start,mid2);
        
        
        for(int i = 0 ; i < cand.size() ; i++){
            int _1to_cand = calc(mid1,cand[i].first);
            int _2to_cand = calc(mid2,cand[i].first);
            
            int path1 = _to1 + mid_dist + _2to_cand;
            int path2 = _to2 + mid_dist + _1to_cand;
            
            int right = calc(start, cand[i].first);
            
            int ans = std::min(path1,path2);
            
            if(ans >= INF || ans < 0) cand[i].second = INF;
            else cand[i].second = ans;
            
            if(cand[i].second > right) cand[i].second = INF;
            
            
        }
        
        std::sort(cand.begin(), cand.end());
        
        for(int i = 0 ; i < cand.size() ; i++){
            if(cand[i].second < INF) {
                v[j].push_back(cand[i].first);
            }
        }
    }
    
    for(int i = 0 ; i < case_num ; i++){
        for(int j = 0 ; j < v[i].size() ; j++){
            std::cout << v[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
