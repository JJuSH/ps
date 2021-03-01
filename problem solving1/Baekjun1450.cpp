#include<iostream>
#include<vector>
#include<algorithm>
int num_item;
long long int max_weight;
long long int arr[30];
long long int ans = 0;
std::vector<long long int> g1;
std::vector<long long int> g2;

void make_g1(long long int a){
    int size = g1.size();
    for(int i = 0 ; i < size ; i++){
        g1.push_back(g1[i] + a);
    }
}
void make_g2(long long int a){
    int size = g2.size();
    for(int i = 0 ; i < size ; i++){
        g2.push_back(g2[i] + a);
    }
}
int find_index(long long int find){
    long long int margin = max_weight - find;
    
    int start = 0;
    int end = g1.size() - 1;
    
    while(start <= end){
        int mid = (start + end)/2;
        if(g1[mid] <= margin) {
            start = mid + 1;
        }
        else if(g1[mid] > margin) end = mid - 1;
    }
    //std::cout << "find_index " << margin << " " << start << "\n";
    return end + 1;
}
int main(){
    std::cin >> num_item >> max_weight;
    for(int i = 0 ; i < num_item ; i++ ){
        std::cin >> arr[i];
    }
    g1.push_back(0);
    g2.push_back(0);
    int mid = num_item / 2;
    for(int i = 0 ; i < mid ; i++){
        make_g1(arr[i]);
        //std::cout << "makeg1 " << arr[i] << "\n";
    }
    std::sort(g1.begin(), g1.end());
    //for(int i = 0 ; i < g1.size() ; i++){
    //    std::cout << g1[i] << " ";
    //}
    //std::cout << "\n";
    
    
    for(int i = mid ; i < num_item ; i++){
        make_g2(arr[i]);
        //std::cout << "makeg2 " << arr[i] << "\n";
    }
    //for(int i = 0 ; i < g2.size() ; i++){
    //    std::cout << g2[i] << " ";
    //}
    //std::cout << "\n";

    
    for(int i = 0 ; i < g2.size() ; i++){
        if(g2[i] > max_weight) continue;
        ans = ans + find_index(g2[i]);
    }
    
    std::cout << ans << "\n";
    
    
    return 0;
}
