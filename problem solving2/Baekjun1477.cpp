#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
int N, M, L;

std::vector<int> v;

int main(){
    std::cin >> N >> M >> L;
    v.push_back(0);
    for(int i = 0 ; i < N ; i++){
        int temp;
        std::cin >> temp;
        v.push_back(temp);
    }
    v.push_back(L);
    std::sort(v.begin() , v.end());
    
    int start = 1;
    int end = L - 1;
    int result = 0;
    while(start <= end){
        int mid = (start + end) / 2;
        int cnt = 0;
            for (int i = 0; i < v.size() - 1; i++) {
                int d = v[i + 1] - v[i];
                int val;
                if (d / mid > 0) {
                    if (d%mid == 0)    val = (d / mid) - 1;
                    else val = (d / mid);
                    cnt += val;
                }
            }
        
        if(cnt <= M){
            end = mid - 1;
            result = mid;
        }
        else{
            start = mid + 1;
        }
        
    }
    std::cout << result << "\n";
    return 0;
}
