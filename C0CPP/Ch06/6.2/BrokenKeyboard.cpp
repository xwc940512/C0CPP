/*************************************************************************
	> File Name: BrokenKeyboard.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 07 Oct 2015 07:22:24 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
const int MAX = 1000;
char s[MAX];
int cur, last, next[MAX];//共有的变量，这样的设定可以减少重复的定义和支出，并不影响相应的结果。

int main(){
    while(cin >> (s+1)){
        int n = strlen(s+1);
        cur = last = 0; 
        int i;
        for(i = 1; i <= n; i++){
            if(s[i] == '['){
                cur = 0; 
            }else if(s[i] == ']'){
                cur = last;
            }else{
                next[i] = next[cur];
                next[cur] = i;
                if(cur == last) last = i;
                cur = i;
            }
        }
        for(i = next[0]; i != 0; i=next[i]){
            cout<<s[i];
        }
        cout<<endl;
        memset(next, 0, sizeof(next));
    }
    return 1;
}
