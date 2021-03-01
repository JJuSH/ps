#include<iostream>
#include<stdio.h>
int num_city;
int num_travel;
int par[201];
bool ans = true;
int find(int a){
    if(par[a] == a) return a;
    else{
        int pa = find(par[a]);
        par[a] = pa;
        return pa;
    }
}
void uni(int a, int b){
    int pa = find(a);
    int pb = find(b);
    par[pb] = pa;
}
void print_par(){
    for(int i = 1 ; i <= num_city ; i++){
        std::cout << par[i] << " ";
    }
    std::cout << "\n";
}
int main(){
    scanf("%d", &num_city);
    scanf("%d", &num_travel);
    for(int i = 0 ; i <= num_city ; i++){
        par[i] = i;
    }
    for(int i = 1 ; i <= num_city ; i++){
        for(int j = 1 ; j <= num_city ; j++){
            int temp;
            scanf("%d", &temp);
            if(temp == 1) uni(i,j);
        }
    }
    int dest;
    scanf("%d" , &dest);
    for(int i = 1 ; i < num_travel ; i++){
        int temp;
        scanf("%d", &temp);
        if(find(dest) != find(temp)){
            ans = false;
            break;
        }
        else{
            dest = temp;
        }
    }
    if(ans) printf("YES\n");
    else printf("NO\n");
    
    //print_par();
    
    return 0;
}
