// https://atcoder.jp/contests/abc209/submissions/42314398

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

// �z�肳����ސ��A����\�ߗp�ӂ��Ă����܂�
const int M = 52;
const int MAX = M * M * M;
/// <summary>
/// ������𒸓_�ԍ��ɒ����܂�
/// </summary>
/// <param name="s">������</param>
/// <returns>���_�ԍ�</returns>
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
	vector<vector<int>> r(MAX); // �t�����̃O���t
	vector<int> d(MAX); // �o����
	map<P, int> mp;
	rep(i, n)
	{
		// ������𒸓_�ԍ��ɕϊ����܂�
		int u = s2i(s[i].substr(0, 3));
		int v = s2i(s[i].substr(s[i].size() - 3));
		// ���ɂȂ����Ă���Ȃ珈�����s���܂���
		if (mp.count(make_pair(u, v))) continue;
		mp[make_pair(u, v)]++;
		// �t�����ɐڑ����܂�
		r[v].emplace_back(u);
		// �o���������Z���܂�
		d[u]++;
	}
	// ���s���L�^����z��
	// 1 ; ����
	// 0 : ��������
	// -1 : ����
	vector<int> judge(MAX, 0); // ���߂͑S�Ĉ��������Ƃ��܂�
	queue<int> q;

	rep(i, MAX)
	{
		// �o������0 �������m�肵�Ă��钸�_���L�^���܂�
		if (d[i] == 0)
		{
			// �T�����ɒǉ����܂�
			q.emplace(i);
			judge[i] = -1;
		}
	}

	// �T������ӏ��������Ȃ�܂ŏ������s���܂�
	while (!q.empty())
	{
		int a = q.front();
		q.pop();

		// �����̏ꍇ
		if (judge[a] == -1)
		{
			for (const auto& e : r[a])
			{
				if (judge[e] == 1) continue;
				// ��ł������̒��_�ɑJ�ڂ���Ȃ珟���ł�
				judge[e] = 1;
				q.emplace(e);
			}
		}
		// �����̏ꍇ
		else
		{
			for (const auto& e : r[a])
			{
				if (judge[e] == 1) continue;
				// �q�����Ă��钸�_�̏o�������P���炵�܂�
				d[e]--;
				// ���炵�����ʂǂ��ւ������Ȃ��Ȃ��Ă��܂����畉���ƌ��肵�܂�
				if (d[e] == 0)
				{
					judge[e] = -1;
					// ���̒T�����Ԃɒǉ����܂�
					q.emplace(e);
				}
			}
		}
	}

	rep(i, n)
	{
		// ������������₱�����ł�
		// �����N�� s ����n�߂��Ƃ������Ƃ�
		// �،N�� s �̖��� 3 ��������J�n����@�Ɠ��`�ł�
		// ���̂��ߐ،N����݂ď��s�͂ǂ��ł��傤���H���l���܂�
		string tmp = s[i].substr(s[i].size() - 3);
		int ans = judge[s2i(tmp)];

		switch (ans)
		{
		case -1:
			// �،N�� -1 �ł��̂ō����N�̏����ł�
			cout << "Takahashi" << endl;
			break;
		case 0:
			// ���������͈�ԕ�����₷���ł���
			cout << "Draw" << endl;
			break;
		case 1:
			// �،N�� 1 �ł��̂ł��̂܂ܐ،N�̏����ł�
			cout << "Aoki" << endl;
			break;
		}
	}


	return 0;
}
