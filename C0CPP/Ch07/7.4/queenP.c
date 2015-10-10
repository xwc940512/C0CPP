/*************************************************************************
	> File Name: queen.c
	> Author:xwc 
	> Mail: xwc940512@163.com
	> Created Time: 2015年10月07日 星期三 00时40分57秒
 ************************************************************************/

#include<stdio.h>
int n ;
int C[20];
int visit[3][20]={0};
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
            if(!visit[0][i]&&!visit[1][cur+i]&&!visit[2][cur+n-i]){
                C[cur] = i;
                visit[0][i] = visit[1][cur+i] = visit[2][cur+n-i] = 1;
                search(cur+1);
                visit[0][i] = visit[1][cur+i] = visit[2][cur+n-i] = 0;
            }
        }
    }
}
