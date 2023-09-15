inline ll read(){
    ll x=0,f=0;
    char ch = getchar();
    if(ch==EOF)
        return 0;
    while(ch<'0'||ch>'9')f|=ch=='-',ch=getchar();
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return f?-x:x;
}

inline void print(ll x,bool bk = false) {
    if(x<0){
        putchar('-');
        x = -x;
    }
    if(x==0){
        if(!bk)putchar('0');
        return;
    }
    print(x/10,true);
    putchar((x-10*(x/10))^'0');
}