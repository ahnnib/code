#include <iostream>
#include <cstring>
using namespace std;

const int ALB = 33; // thông thường
const int MAX = 1e6+33;
struct Node{
    // end: bao nhiêu từ kết thúc tại đây
    // cnt: bao nhiêu từ đi ngang qua đây
    // p: ai là cha nó?
    // depth: độ sâu của đồ thị (tiền tố chung)
    int end, cnt, p;
    int child[ALB] = {};
    Node(){
        end = cnt = p  = 0;
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
        c -= 'A';
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

long long answer = 0;
void dfs(int node, int depth){
    if (node == 0) return;
    long long coef = 1ll * depth * trie[node].cnt;
    answer = max(answer, coef);

    for (int i = 0; i < ALB; i++)
        dfs(trie[node].child[i], depth + 1);
}

short t;
short test_cases = 1;
void solve()
{
    int n;
    cin >> n;
    string adn[n];
    for (int i = 0; i < n; i++)
        cin >> adn[i],
        addString(adn[i]);

    dfs(1, 0);
    cout << "Case " << test_cases << ": " << answer << '\n';

    reset(); test_cases++; answer = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--)
    {
        solve();
    }
}