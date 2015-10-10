/*************************************************************************
	> File Name: LevelTree.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 08 Oct 2015 12:50:45 PM CST
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
//定义节点的简单结构，包含一个是否重复的bool变量
struct Node{
    bool have_value;
    int v;
    Node   *left, *right;
    Node(): have_value(false),left(NULL),right(NULL){}
};
string s;//string类型的字符串，我们需要包含string的头文件
Node* root = new Node();//是否建立相应的全局变量这个一个问题
bool failed = false;
vector<int> res;

void addNode(int v, int i);
void levelBfs(vector<int> &res);
void removeTree(Node* r);

int main(){
        while(cin >> s){
            if(s =="()") break;
            char a[10] = "";
            int i;
            for(i = 1; s[i] != ','; i++){
                if(48 < s[i] < 57) a[i-1] =  s[i]; 
            }
            int v = atoi(a);
            addNode(v, i);
        }
        levelBfs(res);
        if(failed) cout << -1 << endl;
        else{
            for(int i = 0; i < res.size(); i++){
                cout << res[i] << "\t";
            }
            cout << endl;
        }
    removeTree(root);
    return 1;
}

void addNode(int v, int i){
    Node* u = root;
    for(int j = i + 1; j < s.length(); j++){
            if(s[j] == 'L') {
                if(u->left == NULL) u->left = new Node();
                u = u->left;
            }else if(s[j] == 'R'){
                if(u->right == NULL) u->right = new Node();
                u = u->right;
            }
    }
    if(u->have_value) failed = true;
    u->have_value = true;
    u->v = v;
}

void levelBfs(vector<int> &res){
    queue<Node*> tree;
    res.clear();
    tree.push(root);
    while(!tree.empty()){
        Node* u = tree.front();
        tree.pop();
        if(!u->have_value) {
            failed = true;
            return;
        }
        res.push_back(u->v);
        if(u->left != NULL) tree.push(u->left);
        if(u->right != NULL) tree.push(u->right);
    }
}

void removeTree(Node* r){
    if(root == NULL) return;
    if(root->left == NULL) removeTree(r->left);
    if(root->right == NULL) removeTree(r->right);
    delete r;
}
