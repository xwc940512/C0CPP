/*************************************************************************
	> File Name: MaxSum.cpp
	> Author: xwc
	> Mail: xwc940512@163.com
	> Created Time: Thu 08 Oct 2015 08:33:34 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
const int MAX = 1000000;
int A[MAX] = {0};
int main(){
    int tot = 0;
    int best = A[0];
    int numIter;
    cin >> numIter;
    for(int i = 0; i < numIter; i++){
        for(int j = i; j < numIter; j++){
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum += A[k]; tot++;
            }
            if (sum > best)      best = sum;
        }
    }
    cout << "最大和为best:" << best << endl; 
    cout << "基本操作数为：" << tot << endl;
    return 1;
}
