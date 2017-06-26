#include <stdio.h>

//計算する分割数の入力の最大値
#define N 1000

//十分大きなサイズの配列
int dp[N+1][N+1];

int q(int k, int n){
//計算済みの場合は配列の値を返す
  if(dp[k][n] != -1) return dp[k][n];
//そうでない場合は計算結果を配列に保存しておく
  if(k > n) dp[k][n] = q(n, n);
  else dp[k][n] = q(k - 1, n) + q(k, n - k);
  return dp[k][n];
}

int main(){
  int k, n, i;

  scanf("%d", &n);

// q(0,0) = 1 なので配列に解を保存しておく
  dp[0][0] = 1;

// q(0,n) = 0 なので配列に解を保存しておく(省略可)
  for(i = 1; i <= n; i++){
    dp[0][i] = 0;
  }

/*
  それ以外の場合は未計算なので，
  その「しるし」として -1 を代入しておく
*/
  for(k = 1; k <= n; k++){
    for(i = 0; i <= n; i++){
      dp[k][i] = -1;
    }
  }

  printf("%d\n", q(n, n));

  return 0;
}

