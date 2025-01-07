#include <bits/stdc++.h>
using namespace std;

/*
  Bài toán tóm tắt:
  - Có N điểm (1..N).
  - Mỗi điểm i có 2 "lối đi":
     + left[i]  (đi hướng 'L')
     + right[i] (đi hướng 'R').
  - Có 1 chuỗi M ký tự 'L'/'R' (tour).
  - Lặp chuỗi này K lần, bắt đầu từ điểm 1, hỏi điểm dừng cuối cùng.

  Ý tưởng:
  1) Xây mảng F: F[p] = vị trí cuối nếu xuất phát từ p và đi hết chuỗi M bước (1 tour).
     - Tính bằng cách mô phỏng M bước cho từng p (O(N*M)).
  2) Dùng Binary Lifting (hoặc "nhảy mũ"):
     - jump[0][p] = F[p].
     - jump[i][p] = jump[i-1][ jump[i-1][p] ]  (F^(2^i)(p)).
     - Sau đó áp dụng F^K(1) bằng cách "nhảy" theo bit của K.
*/

static const int MAXN = 1000;   // N <= 1000
static const int MAXM = 500;    // M <= 500
// log2(10^9) ~ 30, dự phòng thêm
static const int MAXLOG = 32;

int main(){
    freopen("traveltc.inp", "r", stdin);
    freopen("traveltc.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long K;
    int N, M;
    cin >> N >> M >> K;  // Đọc N, M, K

    // Mảng lưu nơi đến khi đi 'L' hay 'R'
    vector<int> leftDest(N+1), rightDest(N+1);
    for(int i = 1; i <= N; i++){
        cin >> leftDest[i] >> rightDest[i];
    }

    // Đọc chuỗi M ký tự 'L'/'R'
    vector<char> tour(M);
    for(int i = 0; i < M; i++){
        cin >> tour[i];
    }

    // 1) Xây mảng F[p]: nếu xuất phát từ p, sau 1 tour (M bước) sẽ kết thúc ở đâu?
    vector<int> F(N+1);
    for(int p = 1; p <= N; p++){
        int current = p;
        for(int step = 0; step < M; step++){
            if(tour[step] == 'L'){
                current = leftDest[current];
            } else {
                current = rightDest[current];
            }
        }
        F[p] = current;
    }

    // 2) Xây bảng jump để "nhảy cóc" 2^i lần
    // jump[i][p] = điểm đến khi xuất phát từ p, áp dụng F 2^i lần
    static int jump[MAXLOG][MAXN+1];

    // jump[0][p] = F[p]
    for(int p = 1; p <= N; p++){
        jump[0][p] = F[p];
    }

    // jump[i][p] = jump[i-1][ jump[i-1][p] ]
    for(int i = 1; i < MAXLOG; i++){
        for(int p = 1; p <= N; p++){
            jump[i][p] = jump[i-1][ jump[i-1][p] ];
        }
    }

    // 3) Tìm kết quả sau K lần (K tour)
    int ans = 1;  // bắt đầu từ điểm 1
    long long remain = K;  // còn K lần lặp

    for(int i = 0; i < MAXLOG; i++){
        // Kiểm tra bit i trong K
        if(remain & (1LL << i)){
            ans = jump[i][ans];
        }
    }

    // Kết quả cuối cùng
    cout << ans << "\n";

    return 0;
}
