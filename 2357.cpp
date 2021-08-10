//2042세그먼트 트리 
#include <iostream>
#include <algorithm>
#include <vector>
#define FIO ios::sync_with_stdio(NULL); cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;

int N, M, K, h = 1;
vector<ll> tree;
vector<ll> num;
ll query(int L, int R, int node, int nodeL, int nodeR) {
	if (L <= nodeL && nodeR <= R) return tree[node];
	if (nodeR < L || R < nodeL) return 0;

	int mid = (nodeL + nodeR) / 2;
	return query(L, R, node * 2, nodeL, mid) + query(L, R, node * 2 + 1, mid + 1, nodeR);




}
void update(int idx, ll value) {
	idx += h;
	tree[idx] = value;
	while (idx) {
		idx /= 2;
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];

	}



}


int main(void) {
	FIO;
	cin >> N >> M >> K;
	while (N > h) h <<= 1;
	tree.resize(h * 2);
	num.resize(N + 1);

	for (int i = 0; i < N; i++) {
		cin >> num[i];
		update(i, num[i]);
	}

	for (int i = 0; i < M + K; i++) {
		ll a, b;
		ll c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(b - 1, c);

		}
		else {
			//구간합 구하기
			cout << query(b, c, 1, 1, h) << "\n";
			//구간 시작, 구간 끝, 루트번호, 조사 범위

		}

	}
	return 0;
}