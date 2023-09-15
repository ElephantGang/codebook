/* i:number of integer points interior to the polygon
b:the number of integer points on its boundary (including both vertices and points along the sides). 
Then the area A of this polygon is: A = i + b/2 - 1 */
 
pair<ll, ll> operator-(const pair<ll, ll>& a, const pair<ll, ll>& b) {
	return {a.first - b.first, a.second - b.second};
}

int n;
pair<ll, ll> p[100010];
 
ll Pick() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> p[i].first >> p[i].second;
	p[n] = p[0];
	ll area = 0;
	for(int i = 0; i < n; ++i)
		area += p[i].first * p[i + 1].second - p[i].second * p[i + 1].first;
	area = abs(area);
	ll b = 0;
	for(int i = 0; i < n; ++i) {
		pair<ll, ll> v = p[i + 1] - p[i];
		b += abs(__gcd(v.first, v.second));
	}
	ll a = (area + 2 - b) / 2;
	return a;
}