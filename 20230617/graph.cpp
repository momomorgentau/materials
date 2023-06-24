#include<bits/stdc++.h>
using namespace std;

int main()
{
	// 隣接行列
	vector<vector<bool>>
		g0{
			{false, true,  true,  false},
			{true,  false, true,  false},
			{true,  true,  false, true},
			{false, false, true,  false}
	};

	// 隣接リスト
	vector<vector<int>>
		g1{
			{1, 2},  // 0 番の頂点に繋がっている頂点
			{0, 2},
			{0, 1, 3},
			{2},
	};


	//実際の隣接リストは

	vector<vector<int>> g1_1(4); // 4 は頂点数
	
	//と宣言して

	g1_1[0].emplace_back(1);  // g1 の 0 頂点目に 1 を追加
	
	//のように追加していきます。


	// 繋がっている頂点を処理する
	for (auto e : g1_1[0])
	{
		cout << "頂点 " << e << " になんか処理するよ" << endl;

		/*
		このようにすると
		0 に繋がっている頂点が順番に列挙されます

		今回は 1, 2 の順番になります
		*/
	}
}
