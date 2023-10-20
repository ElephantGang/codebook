void do_things(int l, int r) {
    for (int i = l; i <= r; i++)
        // do something
}

void split(vector<int> &qrys, vector<int> &ok, vector<int> &fail) {// 決定 qrys 中的元素該去哪邊
    // 檢查
    vector<int>().swap(qrys); // 釋放記憶體
}

void undo(int l, int r) { // 取消 l, r 的操作
    // undo something
}

void total_BS(int l, int r, vector<Query> &qrys) {
    if (l == r) // 整個 qrys 的答案 = l
    int mid = (l + r) / 2;
    do_things(l, mid); // 做所有 <= mid 時會做的事

    /* 原本二分搜時，我們會做：
    if (check) r = mid;
    else l = mid + 1;
    */ 

    vector<int> lft = qrys 裡需要壓右界的（r = mid，答案在左邊）
    vector<int> rgt = qrys 裡需要壓左屆的（l = mid + 1，答案在右邊）

    total_BS(mid + 1, r, rgt);
    undo_things(l, mid)
    total_BS(l, mid, lft)
}