#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
int V, E;
std::vector<std::pair<int, std::pair<int , int> > > edge;
int par[10001];
long long int sum = 0;
int find(int a){
    if(par[a] == a) return a;
    else{
        int pa = find(par[a]);
        par[a] = pa;
        return par[a] = find(par[a]);
    }
}

void uni(int a, int b){
    int pa = find(a);
    int pb = find(b);
    par[pb] = pa;
}

int main(){
    std::cin >> V >> E;
    for(int i = 1 ; i <= V ; i++){
        par[i] = i;
    }
    for(int i = 0 ; i < E ; i++){
        int A, B, C;
        std::cin >> A >> B >> C;
        edge.push_back(std::make_pair( C , std::make_pair(A , B)));
    }
    sort(edge.begin(), edge.end());
    
    for(int i = 0 ; i < edge.size() ; i++){
        int pa = find(edge[i].second.first);
        int pb = find(edge[i].second.second);
        
        if(pa == pb) continue;
        else{
            uni(edge[i].second.first, edge[i].second.second);
            sum = sum + edge[i].first;
        }
    }
    
    std::cout << sum << "\n";
    
    return 0;
}
