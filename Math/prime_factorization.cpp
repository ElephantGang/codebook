typedef __int128 ll;
vector<ll> vv;

/* fastoi here */

ll abs(ll x){
    return (x>0?x:-x);
}
ll power(ll x,ll y,ll p){
    ll res = 1;
    x = x % p;
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
bool miillerTest(ll d, ll n){
    ll a = 2 + rand () % (n - 4);
    ll x = power(a, d, n);
    if (x == 1  || x == n-1)
        return true ;
    while (d != n-1){
        x = (x * x) % n;
        d *= 2;
        if (x == 1) return false ;
        if (x == n-1) return true ;
    }
    return false ;
}
bool isPrime(ll n, ll k){
    if (n <= 1 || n == 4) return false ;
    if (n <= 3) return true ;
    ll d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    for (ll i = 0; i < k; i++)
        if (!miillerTest(d, n))
            return false ;
    return true ;
}
ll func(ll t,ll c,ll x) {
	return (t*t+c)%x;
}
ll Pollard_Rho(ll x) {
      ll t = 0;
      ll c = rand() % (x - 1) + 1;
      for (int i = 1; i < 1145; ++i) t = func(t, c, x);
      ll s = t;
      int step = 0, goal = 1;
      ll val = 1;
      for (goal = 1;; goal <<= 1, s = t, val = 1) {
            for (step = 1; step <= goal; ++step) {
                  t = func(t, c, x);
                  val = val * abs(t - s) % x;
                  if (!val) return x;
                  if (step % 127 == 0) {
                        ll d = __gcd(val, x);
                        if (d > 1) return d;
                  }
            }
            ll d = __gcd(val, x);
            if (d > 1) return d;
      }
}
void prefactor(ll &n, vector<ll> &v) {
      ll prime[12] = {2,3,5,7,11,13,17,19,23,29,31,37};
	for(int i=0;i<12;++i) {
		while(n%prime[i]==0) {
			v.push_back(prime[i]);
			n/=prime[i];
		}
	}
}
void comfactor(const ll &n, vector<ll> &v) {
	if(isPrime(n,15)) {
		v.push_back(n);
		return;
	}
	ll d = Pollard_Rho(n);
	comfactor(d,v);
	comfactor(n/d,v);
}
void Factor(const ll &x, vector<ll> &v) {
	ll n = x;
	if(n==1) { puts("Factor 1"); return; }
	prefactor(n,v);
	if(n==1) return;
	comfactor(n,v);
	sort(v.begin(),v.end());
}
void AllFactor(const ll &n,vector<ll> &v) {
	vector<ll> tmp;
	Factor(n,tmp);
	v.clear();
	v.push_back(1);
	ll len;
	ll now=1;
	ll lentmp = tmp.size();
	for(int i=0;i<lentmp;++i) {
		if(i==0 || tmp[i]!=tmp[i-1]) {
			len = v.size();
			now = 1;
		}
		now*=tmp[i];
		for(int j=0;j<len;++j)
			v.push_back(v[j]*now);
	}
}
void prime_factorization(){
      srand(time(NULL));
      ll n = read();
      AllFactor(n,vv);
      sort(vv.begin(),vv.end());
      for(auto i:vv){
          print(i); putchar(' ');
      }
}