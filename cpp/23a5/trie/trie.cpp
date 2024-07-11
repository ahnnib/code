#include <iostream>
#include <string.h>

const int MAX = 1e6;
const int ALB = 10; // thông thường
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
void addString (std::string s){
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
int find(std::string s){
    int node = root;
    for (char c: s){
        c -= 'a';
        if (trie[node].child[c] == 0) return 0;
        node = trie[node].child[c];
        if (trie[node].cnt == 0) return 0;
    }
    return trie[node].cnt;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int n;
    std::cin >> n;
    while (n--)
    {
        std::string s;
        std::cin >> s;
        addString(s);
    }

    int m;
    std::cin >> m;
    while (m--)
    {
        std::string x;
        std::cin >> x;
        std::cout << find(x) << '\n';
    }
}