/*************************************************************************
	> File Name: queen.c
	> Author: 
	> Mail: 
	> Created Time: 2015年10月07日 星期三 00时40分57秒
 ************************************************************************/

#include<stdio.h>
int n ;
int C[20];
int tot = 0;
void search(int cur);
int main(){
    scanf("%d",&n);
    search(0);
    printf("%d\n",tot);
    return 1;
}
void search(int cur){
    if(cur == n) {
        tot++;
        printf("第%d个摆法：\n\n",tot);
        int m;
        for(m = 0; m < n; m++){
            int k;
            for(k = 0; k < n; k++){
                if(C[m] == k) printf("*");
                else printf(" ");
            }
            printf("\n");
        }
    }
    else{
        int i;
        for(i = 0; i < n; i++){
            int ok = 1;
            C[cur] = i;
            int j;
            for(j = 0; j < cur; j++){
                if(C[cur] == C[j] || C[cur]-C[j] == cur - j || C[cur]- C[j] == j - cur){
                    ok = 0; break;
                } 
            }
            if(ok) search(cur+1);
        }
    }
}
