#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<utility>
#include<algorithm>
int T, N, M;
int count = 0;
std::vector<std::pair<int ,int > > req;
bool took[1001] = {false,};
void fit(int end, int start){
    for(int i = start ; i <= end ; i++){
        if(took[i] == false){
            took[i] = true;
            count++;
            break;
        }
    }
}
bool compare(const std::pair<int , int> &a , const std::pair<int , int> &b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
int main(){
    scanf("%d", &T);
    for(int i = 0 ; i < T ; i++){
        count = 0;
        req.clear();
        memset(took , false, sizeof(took));
        scanf("%d %d", &N, &M);
        for(int i = 0 ; i < M ; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            req.push_back(std::make_pair(b, a));
        }
        std::sort(req.begin(), req.end() , compare);
        for(std::pair<int , int> p : req){
            fit(p.first, p.second);
        }
        std::cout << count << "\n";
    }
    return 0;
}
