const int P = 1e9 + 7;
#define ll long long
ll fpow(int a, int b) {
    ll ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % P;
        a = a * a % P;
    }
    return ret;
}