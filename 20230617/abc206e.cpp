// https://atcoder.jp/contests/abc209/submissions/42314398

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

// 想定される種類数、個数を予め用意しておきます
const int M = 52;
const int MAX = M * M * M;
/// <summary>
/// 文字列を頂点番号に直します
/// </summary>
/// <param name="s">文字列</param>
/// <returns>頂点番号</returns>
/// aaa : 0
/// aab : 1
/// ...
/// aaz : 25
/// aaA : 26
/// ...
/// aaZ : 51
/// aba : 52
/// ...
int s2i(string s)
{
	int u = 0;
	for (const auto& c : s)
	{
		u *= M;
		if ('a' <= c && c <= 'z') u += c - 'a';
		else u += (c - 'A') + M / 2;
	}
	return u;
}

int main()
{
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<vector<int>> r(MAX); // 逆方向のグラフ
	vector<int> d(MAX); // 出次数
	map<P, int> mp;
	rep(i, n)
	{
		// 文字列を頂点番号に変換します
		int u = s2i(s[i].substr(0, 3));
		int v = s2i(s[i].substr(s[i].size() - 3));
		// 既につながっているなら処理を行いません
		if (mp.count(make_pair(u, v))) continue;
		mp[make_pair(u, v)]++;
		// 逆向きに接続します
		r[v].emplace_back(u);
		// 出次数を加算します
		d[u]++;
	}
	// 勝敗を記録する配列
	// 1 ; 勝ち
	// 0 : 引き分け
	// -1 : 負け
	vector<int> judge(MAX, 0); // 初めは全て引き分けとします
	queue<int> q;

	rep(i, MAX)
	{
		// 出次数が0 負けが確定している頂点を記録します
		if (d[i] == 0)
		{
			// 探索順に追加します
			q.emplace(i);
			judge[i] = -1;
		}
	}

	// 探索する箇所が無くなるまで処理を行います
	while (!q.empty())
	{
		int a = q.front();
		q.pop();

		// 負けの場合
		if (judge[a] == -1)
		{
			for (const auto& e : r[a])
			{
				if (judge[e] == 1) continue;
				// 一つでも負けの頂点に遷移するなら勝ちです
				judge[e] = 1;
				q.emplace(e);
			}
		}
		// 勝ちの場合
		else
		{
			for (const auto& e : r[a])
			{
				if (judge[e] == 1) continue;
				// 繋がっている頂点の出次数を１つ減らします
				d[e]--;
				// 減らした結果どこへもいけなくなってしまったら負けと決定します
				if (d[e] == 0)
				{
					judge[e] = -1;
					// 次の探索順番に追加します
					q.emplace(e);
				}
			}
		}
	}

	rep(i, n)
	{
		// ここが少しややこしいです
		// 高橋君が s から始めたということは
		// 青木君が s の末尾 3 文字から開始する　と同義です
		// そのため青木君からみて勝敗はどうでしょうか？を考えます
		string tmp = s[i].substr(s[i].size() - 3);
		int ans = judge[s2i(tmp)];

		switch (ans)
		{
		case -1:
			// 青木君が -1 ですので高橋君の勝ちです
			cout << "Takahashi" << endl;
			break;
		case 0:
			// 引き分けは一番分かりやすいですね
			cout << "Draw" << endl;
			break;
		case 1:
			// 青木君が 1 ですのでそのまま青木君の勝ちです
			cout << "Aoki" << endl;
			break;
		}
	}


	return 0;
}
