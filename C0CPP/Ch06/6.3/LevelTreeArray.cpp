/*************************************************************************
	> File Name: LevelTreeArray.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 08 Oct 2015 04:41:47 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
using namespace std;

const int MAX = 1000;

int cnt , leftTree[MAX], rightTree[MAX], treeValue[MAX]; 
bool have_value[MAX];

const int root = 1;
bool failed = false;
string s;

vector<int> res;

void newTree(){
    leftTree[root] = rightTree[root] = 0;
    have_value[root] = false;
    cnt = root;
}

int newNode(){
    int u = ++cnt;
    leftTree[u] = rightTree[u] = 0;
    have_value[u] = false;
    return u;  
}

void addNode(int v, int i);

void bfsTree(vector<int>& res); 

int main(){
    stringstream ss;
    newTree();
    while(cin >> s){
        int i;
        string a = "";
        if(s == "()")  break;
        for(i = 1; s[i] != ','; i++){
             a += s[i];
        }
        ss << a;
        int v;
        ss >> v;
        ss.clear();
        addNode(v, i); 
    }
    bfsTree(res);
    if(failed) {cout << -1 << endl; return 1;}
    else{
        for(int i = 0; i < res.size(); i++){
            cout << res[i] << "\t";
        }
        cout << endl;
    }
    return 1;
}

void addNode(int v, int i){
    int u = root;
    for(int j = i + 1; j < s.length() - 1; j++){
        if(s[j] == 'L'){
            if (!leftTree[u]) leftTree[u] = newNode();
            u = leftTree[u];
        }else if(s[j] == 'R'){
            if(!rightTree[u])  rightTree[u] = newNode();
            u = rightTree[u];
        }
    }
    if(have_value[u]) failed = true;
    treeValue[u] = v;
    have_value[u] = true;
}

void bfsTree(vector<int>& res){
    queue<int> tree;
    res.clear();
    tree.push(root);
    while(!tree.empty()){
        int u = tree.front(); tree.pop();
        if(!have_value[u]) {failed = true; return;}
        res.push_back(treeValue[u]);
        if(leftTree[u]) tree.push(leftTree[u]);
        if(rightTree[u]) tree.push(rightTree[u]);
    }
}
