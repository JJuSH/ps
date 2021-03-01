#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
int N;
std::vector<std::pair<int, int> > v;
struct compare {
    //연산자 오버로딩
    bool operator()(std::pair<int, int>&a, std::pair<int, int>&b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        else {
            return a.first < b.first;
        }
    }
};

std::priority_queue<int> pq[1001];
  
int main(){
    std::cin >> N;
    int max_day = 0;
    for(int i = 0 ; i < N ; i++){
        int d, w;
        std::cin >> d >> w;
        pq[d].push(w);
        max_day = std::max(max_day, d);
    }
    
    int cur_day = max_day;
    int sum = 0;
    while(cur_day >= 1){
        int loc_maxday;
        int loc_max = -1;
        
        for(int i = cur_day ; i <= max_day ; i++){
            if(pq[i].size() != 0){
                if(pq[i].top() > loc_max){
                    loc_max = pq[i].top();
                    loc_maxday = i;
                }
            }
        }
        if(loc_max == -1){
            cur_day--;
        }
        else{
            sum += pq[loc_maxday].top();
            pq[loc_maxday].pop();
            cur_day--;
        }
    }
    std::cout << sum << "\n";
    return 0;
}
