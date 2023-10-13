int prime[MAXN];
vector<int> p;
void sieve(int n){
    fill(prime+2,prime+n+1,1);
    for(int i=2;i<=n;++i){
        if(prime[i]==1) p.push_back(i);
        for(int j:p){
            if(i*j>n) break;
            prime[i*j]=j; //順便紀錄最小的質因數是誰
            if(i%j==0) break; //表示後面的質數都大於最小質因數了
        }
    }
}