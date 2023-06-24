# 隣接行列
g0 = [
    [False, True,  False, False],
    [True,  False, True,  False],
    [True,  True,  False, True ],
    [False, True,  True,  False],
]

# 隣接リスト
g1_0 = [
    [1, 2],    # 0 番の頂点に繋がっている頂点
    [0, 2],
    [0, 1 ,3],
    [2]
]

# 実際の隣接リストは動的に追加していきます
g1_1 = []
# グラフの準備
for i in range(0, 4):
    row = []
    g1_1.append(row)

g1_1[0].append(1) # g1_1 の 0 頂点目に 1 を追加

# 繋がっている頂点を処理する
for e in g1_1[0]:
	print("頂点 %d になんか処理するよ" % e)

	# このようにすると
	# 0 に繋がっている頂点が順番に列挙されます

	# 今回は 1, 2 の順番になります
