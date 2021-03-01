#include<iostream>

int N;
int in[100000];
int post[100000];
void transformer(int in_start, int post_start, int len){
    //std::cout << "trans" << in_start << " " << post_start << " " << len << "\n";
    if(len == 0) return;
    if(len == 1){
        std::cout << in[in_start] << " ";
        return;
    }
    int root = post[post_start + len - 1];
    std::cout << root << " ";
    int i;
    for(i = 0 ; i < len ; i++){
        if(in[in_start + i] == root){
            break;
        }
    }
    transformer(in_start, post_start, i);
    transformer(in_start + i + 1, post_start + i, len - i - 1);
    
}
int main(){
    std::cin >> N;
    for(int i = 0 ; i < N ; i++){
        std::cin >> in[i];
    }
    for(int i = 0 ; i < N ; i++){
        std::cin >> post[i];
    }
    transformer(0,0,N);
    std::cout << "\n";
    return 0;
}
