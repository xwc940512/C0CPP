/*************************************************************************
	> File Name: DroppingBalls.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 07 Oct 2015 09:08:00 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
const int MAX = 1000000;
int depth, num, tree[MAX] = {0};


int main(){
    cin >> depth >> num;
    depth--;
    int i, j = 0;
    while(j++ < num){
        i = 1;
        int k = 0;
        while(k++ < depth){
            if(tree[i] == 0) {tree[i] = 1; i = 2 * i;}
            else {tree[i] = 0; i = 2 * i + 1;}
        }
    }
    cout << i << endl;
    return 1;
}
