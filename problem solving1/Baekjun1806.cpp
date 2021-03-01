#include<iostream>
int l,r;
long long int arr[100000];
int N;
int cur_sum;
int target;
int ans;

void tp(){
    while(r <= N){
        if(cur_sum > target){
            if(r - l < ans){
                ans = r - l;
            }
            l++;
            cur_sum = cur_sum - arr[l-1];
        }
        else if(cur_sum < target){
            r++;
            cur_sum = cur_sum + arr[r-1];
        }
        else{
            if(r - l < ans){
                ans = r - l;
            }
            r++;
            cur_sum = cur_sum + arr[r-1];
        }
    }
    
}

int main(){
    std::cin >> N >> target;
    for(int i = 0 ; i < N ; i++){
        std::cin >> arr[i];
    }
    l = 0;
    r = 1;
    cur_sum = arr[0];
    ans = N + 1;
    tp();
    if(ans != N + 1) std::cout << ans << "\n";
    else std::cout << 0 << "\n";
    return 0;
}
