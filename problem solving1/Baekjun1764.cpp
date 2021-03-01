#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
int N, M;
std::vector<std::string> d;
std::vector<std::string> b;
std::vector<std::string> ans;

bool binary_search(int start, int end, std::string &target){
    if(start == end){
        if(d[start] == target) return true;
        else return false;
    }
    else if(start > end) return false;
    else{
        int mid = (start + end) / 2;
        if(d[mid] == target) return true;
        if(d[mid] > target) return binary_search(start, mid - 1, target);
        else return binary_search(mid + 1, end, target);
    }
}
int main(){
    std::cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        std::string s;
        std::cin >> s;
        d.push_back(s);
    }
    for(int i = 0 ; i < M ; i++){
        std::string s;
        std::cin >> s;
        b.push_back(s);
    }
    std::sort(d.begin() , d.end());
    std::sort(b.begin() , b.end());
    
    for(std::string s : b) if(binary_search(0 , N-1 , s)) ans.push_back(s);
    std::sort(ans.begin(), ans.end());
    std::cout << int(ans.size()) << "\n";
    for(std::string s : ans) std::cout << s << "\n";
    return 0;
}
