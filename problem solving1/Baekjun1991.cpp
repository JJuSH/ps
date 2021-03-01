#include<iostream>
int N;
struct node{
    char data;
    node* left;
    node* right;
};
node arr[28];

void preOrder(node *root){
    std::cout << root->data;
    if(root -> left) preOrder(root->left);
    if(root -> right) preOrder(root->right);

}
void inOrder(node *root){
    if(root -> left) inOrder(root->left);
    std::cout << root->data;
    if(root -> right) inOrder(root->right);

}
void postOrder(node *root){
    if(root -> left) postOrder(root->left);
    if(root -> right) postOrder(root->right);
    std::cout << root->data;

}

int main(){
    std::cin >> N;
    for(int i = 0 ; i < N ; i++){
        char par, l, r;
        std::cin >> par >> l >> r;
        
        int num = par - 'A';
        arr[num].data = par;
        //std::cout << "node " << num << " " << par << " " << &arr[num] << "\n";
        if(l == '.') arr[num].left = NULL;
        else arr[num].left = &arr[l - 'A'];
        //std::cout << "left " << arr[num].left << "\n";
        if(r == '.') arr[num].right = NULL;
        else arr[num].right = &arr[r - 'A'];
        //std::cout << "right " << arr[num].right << "\n";
        
    }
    
    preOrder(arr);
    std::cout << "\n";
    inOrder(arr);
    std::cout << "\n";
    postOrder(arr);
    std::cout << "\n";
    
    return 0;
}
