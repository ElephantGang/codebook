for(int i=0;i<N;i++){
    dp[i] = arr[i];
}
for(int i=0;i<22;i++){
    for(int j=0;j<=(1<<22);j++){
        if(j&(1<<(i)))
            dp[j] = max(dp[j],dp[j^(1<<i)]);
    }
}