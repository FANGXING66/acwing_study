/*给定一个字符串 S
，以及一个模式串 P
，所有字符串中只包含大小写英文字母以及阿拉伯数字。
模式串 P
 在字符串 S
 中多次作为子串出现。
求出模式串 P
 在字符串 S
 中所有出现的位置的起始下标。*/
#include<iostream>
#include <algorithm>
using namespace std;
#define MAXZISE 1000010 // 修改 MAXZISE 的值以适应更大的数据范围

int ne[MAXZISE];

void get_next(string a){
    int i = 1, j = 0;
    ne[1] = 0;
    while(i < a.length()){
        if(a[i] == a[j]) i++, j++, ne[i] = j;
        else j = ne[j];
    }
}

int main(){
    string s1, s2;
    int n1, n2;
    cin >> n1 >> s1 >> n2 >> s2;
    get_next(s1);
    int i = 1, j = 1;
    while(i <= s2.length()){
        if(s1[j] == s2[i]) i++, j++;
        else j = ne[j];
        if(j == s1.length() + 1){
            cout << i - s1.length() << " "; // 输出匹配位置的起始下标
            j = ne[j]; // 继续匹配下一个位置
        }
    }
    cout << endl; // 输出换行符
    return 0;
}