#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int ALB = 26; // thông thường
const int MAX = 1e6 + 1;
struct Node{
    // end: bao nhiêu từ kết thúc tại đây
    // cnt: bao nhiêu từ đi ngang qua đây
    // p: ai là cha nó?
    int end, cnt, p;
    int child[ALB] = {};
    Node(){
        end = cnt = p = 0;
        memset(child, 0, sizeof(child));
    }
};
Node trie[MAX + 1];
int cntNode = 1;
const int root = 1;
void reset(){
    for (int i = 1; i <= cntNode; i++)
        trie[i] = Node();
    cntNode = 1;
    // gốc ở đỉnh 1 đã đươc khởi tạo lại.
}
void addString (string s){
    int node = root;
    trie[node].cnt++;
    for (char c: s){
        c -= 'a';
        if (trie[node].child[c] == 0){
            ++cntNode;
            trie[node].child[c] = cntNode;
            trie[cntNode].p = node;
        }
        node = trie[node].child[c];
        trie[node].cnt++;
    }
    trie[node].end++;
}
bool find(string s){
    int node = root;
    for (char c: s){
        c -= 'a';
        if (trie[node].child[c] == 0) return false;
        node = trie[node].child[c];
        if (trie[node].cnt == 0) return false;
    }
    return (trie[node].end == true);
}
int solve(string s)
{
    return 0;
}

int main()
{
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) cin >> s[i];

    {
        // sort(s, s + n);

        // int ans = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     int l = i+1, r = n-1, mid, res = -1;
        //     while (l <= r) //
        //     {
        //         mid = (l + r) >> 1;
        //         if (s[mid].size() >= s[i].size() && s[mid].substr(0, s[i].size()) == s[i])
        //             l = mid + 1, res = mid;
        //         else r = mid - 1;
        //     }

        //     if (res != -1) ans += res - i;
        // }

        // cout << ans;
    }
    for (int i = 0; i < n; i++)
    {
        addString(s[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (find(s[i])) solve(s[i]);
        else continue;
    }
    cout << trie[1].p;

    /*

    */
}
/*
aa
aa
aab
abc

4
abc
aa
aab
aa

3
*/
