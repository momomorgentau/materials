#include<bits/stdc++.h>
using namespace std;

int main()
{
	// �אڍs��
	vector<vector<bool>>
		g0{
			{false, true,  true,  false},
			{true,  false, true,  false},
			{true,  true,  false, true},
			{false, false, true,  false}
	};

	// �אڃ��X�g
	vector<vector<int>>
		g1{
			{1, 2},  // 0 �Ԃ̒��_�Ɍq�����Ă��钸�_
			{0, 2},
			{0, 1, 3},
			{2},
	};


	//���ۂ̗אڃ��X�g��

	vector<vector<int>> g1_1(4); // 4 �͒��_��
	
	//�Ɛ錾����

	g1_1[0].emplace_back(1);  // g1 �� 0 ���_�ڂ� 1 ��ǉ�
	
	//�̂悤�ɒǉ����Ă����܂��B


	// �q�����Ă��钸�_����������
	for (auto e : g1_1[0])
	{
		cout << "���_ " << e << " �ɂȂ񂩏��������" << endl;

		/*
		���̂悤�ɂ����
		0 �Ɍq�����Ă��钸�_�����Ԃɗ񋓂���܂�

		����� 1, 2 �̏��ԂɂȂ�܂�
		*/
	}
}
