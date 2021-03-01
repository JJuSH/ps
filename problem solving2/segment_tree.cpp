#include<iostream>
#include<vector>

std::vector<int> arr;
std::vector<int> seg_tree;
int seg[1000001];

int init(int start, int end, int node ){
    if(start == end) return seg[node] = arr[start];
    else{
        int mid = start + end / 2;
        return seg[node] = init(start, mid, 2*node) + init(mid + 1 , end, 2*node + 1);
    }
}

void change(int node, int start, int end, int index, int diff){
    if(!(index <= end && index >= start)) return;
    seg[node] += diff;
    else{
        if(start != end){
            int mid = start + end / 2;
            change(node * 2, start, mid, index, diff);
            change(node * 2 + 1 , mid + 1 , end, index, diff);
        }
    }
}

int sum(int left, int right, int start, int end, int node){
    if(
}
int main(){
    return 0;
}
