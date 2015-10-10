/*************************************************************************
	> File Name: MaxSumS.cpp
	> Author: xwc
	> Mail: xwc940512@163.com
	> Created Time: Thu 08 Oct 2015 08:51:23 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
const int MAX = 1000000;
int A[MAX];
int S[MAX];

int main(){
    int best = A[0];
    int tot = 0;
    S[0] = 1;
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        S[i] = S[i-1] + A[i];
        tot++;
    }
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) {
            best = best > (S[j]-S[i]) ? best : S[j] - S[i];
            tot++;
        }
    cout << "最大的连续的和为：" << best << endl;
    cout << "总共的基本操作数为：" << tot << endl;
    return 1;
}
