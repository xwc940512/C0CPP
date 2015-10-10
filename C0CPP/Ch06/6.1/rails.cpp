/*************************************************************************
	> File Name: rails.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 07 Oct 2015 02:15:29 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

const int MAX = 1000;

int n;
int target[MAX];
 
int main(){
    while(cin >> n){
        int A = 1, B = 0;
        int i;
        stack<int> s; 
        for(i = 0; i < n; i++){
            cin >> target[i];
        }
        int ok = 1;
        while(B < n){
            if(target[B] == A) {A++; B++;}
            else if(!s.empty() && target[B] == s.top()) {B++; s.pop();}
            else if(A <= n) s.push(A++);
            else {ok = 0; break;}
        }
        if(ok) cout<< "yes";
        else cout<<"no";
    }
    return 1;
}
