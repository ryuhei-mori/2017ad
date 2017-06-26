#include <stdio.h>

//計算する分割数の入力の最大値
#define N 1000

//十分大きなサイズの配列
int dp[N+1];

int main(){
  int k, n, i;
  scanf("%d", &n);

// q(0,0) = 1 なので配列に解を保存しておく
  dp[0] = 1;

// q(0,n) = 0 なので配列に解を保存しておく(省略可)
  for(i = 1; i <= n; i++){
    dp[i] = 0;
  }

  for(k = 1; k <= n; k++){
    for(i = k; i <= n; i++){
      dp[i] += dp[i - k];
    }
  }
  printf("%d\n", dp[n]);

  return 0;
}

