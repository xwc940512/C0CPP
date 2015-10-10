/*************************************************************************
	> File Name: oilDeposits.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 07 Oct 2015 08:17:27 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
const int MAX = 1000;
int m, n, idx[MAX][MAX];
string pic[MAX];

void dfs(int r, int c, int id);

int main(){
    while(cin >> m >> n && m && n){
        int count = 0;
        memset(idx, 0, sizeof(idx));
        for(int i = 0; i < m; i++) cin >>pic[i];
        for(int i = 0; i < m; i++){
            int j;
            for(j = 0; j < n; j++)
                if(pic[i][j] == '@' && idx[i][j] == 0) dfs(i, j, ++count);
        }
        cout<< count - 1 << endl;
    }
    return 1;
}

void dfs(int r, int c, int id){
    if(r < 0 || r >= m || c < 0 || c >= n) return;
    if(idx[r][c] || pic[r][c] != '@') return;
    idx[r][c] = id;
    int dr;
    for(dr = -1; dr <= 1; dr++){
        int dc;
        for(dc = -1; dc <= 1; dc++){
            if(!dc || !dr) dfs(r+dr, c+dc, id);
        }
    }
    }
