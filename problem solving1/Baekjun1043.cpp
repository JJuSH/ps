#include<iostream>
#include<vector>
int par[51];
int N, M;
int K;
bool know[51] = {false};

std::vector<int> v[51];

int find(int a){
    if(par[a] == a) return par[a];
    else{
        int pa = find(par[a]);
        par[a] = pa;
        return par[a];
    }
}

void uni(int a, int b){
    int pa = find(a);
    int pb = find(b);
    
    if(pa == pb) return;
    else{
        if(know[pa] == true) par[pb] = pa;
        else if(know[pb] == true) par[pa] = pb;
        else par[pb] = pa;
        return;
    }
}

void print_par(){
    std::cout << "print _ par -------" << "\n";
    for(int i = 1 ; i <= N ; i++){
        std::cout << i << " " << find(i) << "\n";
    }
}

int main(){
    std::cin >> N >> M;
    std::cin >> K;
    for(int i = 1 ; i <= N ; i++){
        par[i] = i;
    }
    for(int i = 0 ; i < K ; i++){
        int temp;
        std::cin >> temp;
        know[temp] = true;
    }
    for(int i = 0 ; i < M ; i++){
        int num_per_party;
        std::cin >> num_per_party;
        for(int j = 0 ; j < num_per_party ; j++){
            int people;
            std::cin >> people;
            v[i].push_back(people);
        }
    }
    int count = 0;
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < v[i].size() - 1 ; j++){
            uni(v[i][j], v[i][j + 1]);
        }
    }
    //print_par();
    for(int i = 0 ; i < M ; i++){
        bool flag = true;
        for(int j = 0 ; j < v[i].size() ; j++){
            if(know[find(v[i][j])]) flag = false;
        }
        if(flag) count++;
    }
    
    
    std::cout << count << "\n";
    return 0;
}
