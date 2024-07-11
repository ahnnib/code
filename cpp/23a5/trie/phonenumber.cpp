#include <iostream>
#include <string.h>
using namespace std;

#define debug cout << "dfad\n";

const int ALB = 10; // thông thường
const int MAX = 1e5 + 1;
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
    cntNode = 1; // ☠️☠️☠️☠️☠️☠️
    // gốc ở đỉnh 1 đã đươc khởi tạo lại.
}
void addString (string s){
    int node = root;
    trie[node].cnt++;
    for (char c: s){
        c -= '0';
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
bool check(string s){
    int node = root;
    for (int i = 0; i < s.length(); i++){
        char c = s[i] - '0';
        node = trie[node].child[c];
    }
    // chắc chắn trie[node].end == true
    // kiểm tra có con
    if (trie[node].cnt == 1) return true;
    else return false;
    // for (int d = 0; d < ALB; d++)
    //     if (trie[node].child[d] != 0)
    //         return false;
    // return true;
}

string num[MAX + 1];

int main()
{
    short t;
    cin >> t;
    while (t--)
    {
        reset();
        short n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
            addString(num[i]);
            // debug
        }
        bool ok = 1;
        for (int i = 0; i < n; i++)
            if (!check(num[i])) { ok = 0; break; }
        // debug

        cout << (ok ? "YES\n" : "NO\n");
    }
}