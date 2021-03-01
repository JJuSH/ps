#include<iostream>
#include<utility>
#include<vector>
#include<stdio.h>
#include<queue>
std::vector<int> vec;
std::queue<bool> ans;
int num_node, num_op;
int find(int a){
    if(a == vec[a]){
        return a;
    }
    else{
        int p = find(vec[a]);
        vec[a] = p;
        return p;
    }
}
void uni(int a, int b){
    int pa = find(a);
    int pb = find(b);
    
    vec[pb] = pa;
    
}
int main(){
    std::cin >> num_node >> num_op;
    
    for(int i = 0 ; i <= num_node ; i++){
        vec.push_back(i);
    }
    for(int i = 0 ; i < num_op ; i++){
        int op, a, b;
        scanf("%d %d %d", &op, &a, &b);
        if(op == 0){
            uni(a,b);
        }
        else if(op == 1){
            if(find(a) == find(b)) ans.push(true);
            else ans.push(false);
        }
    }
    while(ans.size() != 0){
        if(ans.front()) printf("YES\n");
        else printf("NO\n");
        ans.pop();
    }
    return 0;
}
