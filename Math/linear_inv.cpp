ll arr[max_n],pre[max_n],inv[max_n];

void linear_inv(){
    pre[1] = arr[1];
    pre[0] = 1;
    for(ll i=2;i<=n;i++){
        arr[i] = max(1ll,(m*arr[i-1]+k)%mod);
        pre[i] = (pre[i-1]*arr[i])%mod; 
    }
    hehe[n] = fpow(pre[n],mod-2);
    inv[n] = (hehe[n] * pre[n-1])%mod;
    for(ll i=n-1;i>=1;i--){
        hehe[i] = (hehe[i+1]*arr[i+1])%mod;
        inv[i] = (hehe[i] * pre[i-1])%mod;
    }
}