typedef long long LL;
inline LL mul(LL a,LL b,LL m){//a*b%m
    return (a%m)*(b%m)%m;
}

template<typename T> bool isprime(T n, int num=3) { //num = 3,7
    int sprp[3] = {2,7,61}; //int範圍可解
    //int llsprp[7] = {2,325,9375,28178,450775,9780504,1795265022}; //至少unsigned long long範圍
    if(n==2) return true;
    if(n<2 || n%2==0) return false;
    //n-1 = u * 2^t
    int t = 0;  T u = n-1;
    while(u%2==0) u >>= 1, t++;
    for(int i=0; i<num; i++) {
        T a = sprp[i]%n;
        if(a==0 || a==1 || a==n-1) continue;
        T x = fpow(a,u,n);
        if(x==1 || x==n-1) continue;
        for(int j=1; j<t; j++) {
            x = mul(x,x,n);
            if(x==1) return false;
            if(x==n-1) break;
        }
        if(x!=n-1) return false;
    } return true;
}
