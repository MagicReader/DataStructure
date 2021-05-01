//1.直接法  O(m*n)
int Index(SSTring S,SSTring T,int pos){
        //返回子串T在主串S中第pos个字符之后的位置。若不存在，则函数值为0。
        //其中，T非空，1<=pos<=StrLength(S)
        i = pos;    j = 1;
        while(i<=S[0] && j<=T[0]){
            if(S[i] == T[j]){ ++i; ++j;}
            else{ i=i-j+2;  j=1;}   //回溯指针
        }
}

//2.KMP算法【P82图示】   O(m+n) 
/*发生"失配"时，不需回溯i指针，j指针回退到next[j]所指示的位置重新进行比较，
并且当j退至零时，指针i和指针j需同时增1。
(即若主串的第i个字符和模式的第1个字符不等，应从主串第i+1个字符起重新进行匹配。)*/
int Index_KMP(SString S,SString T,int pos){
        //利用模式串T的next或nextval数组，求T在主串S中第pos个字符之后的位置的KMP算法。
        //其中，T非空，1<=pos<=StrLength(S)
        i = pos; j = 1;
        while (i<=S[0] && j<=T[0]){
            if(j==0 || s[i]==T[j]){++i;++j;}    //继续比较后继字符
            else j = next[j];   //模式串向右移动
        }
        if(j>T[0]) return i-T[0];   //匹配成功
        else return 0;
}