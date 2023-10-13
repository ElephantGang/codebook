/** 普通 BIT ，為了加速打字只支援 1-based **/
const int MAXN = ? ;  // 開全域加速打字
#define lowbit(x & (-x))


template<typename T>
struct Fenwick_Tree { // 1 based
    // 二維：陣列開二維，修改跟查詢就是對 (x, y) 各自 +- lowbit
    T arr[MAXN];
    void init(int _n = MAXN) {
        for (int i = 0; i < _n; i++)
            arr[i] = 0;
    }
    void update(int i, T val) {
        for (; i < MAXN; i += lowbit(i))
            arr[i] += val;
    }
    T query(int i) {
        T ret = 0;
        for (; i; i -= lowbit(i))
            ret += arr[i];
        return ret;
    }
};
