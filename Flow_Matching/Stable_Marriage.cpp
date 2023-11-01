// 演算法筆記
1. N位男士各自向自己最喜愛的女士求婚。
2. N位女士各自從自己的求婚者中，挑最喜愛的那位男士訂婚，但是往後可背約。
   沒有求婚者的女士，就只好等等。
3. 失敗的男士們，只好各自向自己次喜愛的女士求婚。
4. N位女士各自從自己的求婚者中，挑最喜歡的那位男士訂婚，但是往後可背約。
   已訂婚卻有更喜愛的男士求婚的女士，就毀約，改為與此男士訂婚。
   沒有求婚者的女士，就只好再等等。
5. 重複3. 4.直到形成N對伴侶為止。
// Jinkela
queue<int> Q; 
for ( i : 所有考生 ) {
    設定在第0志願;
    Q.push(考生i);
}
while(Q.size()){
    當前考生=Q.front();Q.pop(); 
    while ( 此考生未分發 ) {
        指標移到下一志願;
        if ( 已經沒有志願 or 超出志願總數 ) break;
        計算該考生在該科系加權後的總分;
        if ( 不符合科系需求 ) continue;
        if ( 目前科系有餘額 ) {
            依加權後分數高低順序將考生id加入科系錄取名單中;
            break;
        }
        if ( 目前科系已額滿 ) {
            if ( 此考生成績比最低分數還高 ) {
                依加權後分數高低順序將考生id加入科系錄取名單;
                Q.push(被踢出的考生);
            }
        }
    }
}
