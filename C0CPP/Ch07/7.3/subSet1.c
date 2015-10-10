/*************************************************************************
	> File Name: subSet1.c
	> Author: 
	> Mail: 
	> Created Time: 2015年10月07日 星期三 00时04分55秒
 ************************************************************************/

#include<stdio.h>
int a;
void print_subset(int* A, int n, int cur){
    int i;
    a++;
    for(i = 0; i < cur; i++){
        printf("%d", A[i]);
        printf("\t");
    }
    printf("\n");
    int s = cur ? A[cur-1] + 1 : 0;
    for(i = s; i < n; i++){
        A[cur] = i;
        print_subset(A, n, cur+1);
    }
}

int main(){
    int A[4]={0,1,2,3};
    print_subset(A, 4, 0);
    printf("++++++++++");
    printf("%d",a);
    printf("\n");
    return 1;
}
