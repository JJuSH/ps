#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<utility>
#include<vector>
int main(){
    int T;
    scanf("%d", &T);
    for(int i = 0 ; i < T ; i++){
        int N;
        scanf("%d", &N);
        std::vector<std::pair<int, int> > v;
        for(int j = 0 ; j < N ; j++){
            int a, b;
            scanf("%d %d", &a, &b);
            v.push_back(std::make_pair(a, b));
        }
        std::sort(v.begin() , v.end());
        int s = 1;
        int cur_high = v[0].second;
        
        for(int j = 1 ; j < N ; j++){
            if(v[j].second < cur_high){
                s++;
                cur_high = v[j].second;
            }
        }
        
        std::cout << s << "\n";
    }
    return 0;
}
