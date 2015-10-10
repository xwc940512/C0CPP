/*************************************************************************
	> File Name: subSet.c
	> Author:xwc 
	> Mail: xwc940512@163.com
	> Created Time: Tue 06 Oct 2015 11:07:38 PM CST
 ************************************************************************/
#include<stdio.h>
void print_subset(int n, int s){
    int i;
    for(i = 0; i < n; i++){
        if(s&1<<i) printf("%d",i);
    }
    printf("\n");
}

void main(){
    int n;
    scanf("%d",&n);
    int i;
    for(i = 0; i < (1<<n); i++){
        print_subset(n,i);
    }
}

