# https://atcoder.jp/contests/abc209/submissions/42314181
from collections import deque
M = 52
MAX = M * M * M
a = 97
A = 65

# 英語の文字列を数字に変換します
# aaa 0
# aab 1
# ...
# aaA 26
# aaZ 51
# ...
# aba 52
# ...
def s2i(str):
  now = 0
  for c in str:
    now *= M
    if c.islower():
      now += ord(c) - a
    else:
      now += ord(c) - A + M // 2
  return now

n = int(input())
S = [input() for _ in range(n)]
g = []
d = []

for i in range(0, MAX+5):
  row = []
  g.append(row)
  d.append(0)

mp = {}

# グラフを作成します  
for s in S:
  t = s[:3]+s[-3:]
  if t in mp:
    continue
  u = s2i(s[:3])
  v = s2i(s[-3:])
  mp[t] = 1
  # 逆向きに辺を貼ります
  g[v].append(u)
  # 出次数をカウントします
  d[u] += 1

  
# 勝ち負けを記録する配列です
# -1 : 負け
# 0 ： 引き分け
# 1 ：負け
judge = []
q = deque()
for i in range(0, MAX+5):
  # はじめは全部引き分けとします
  judge.append(0)
  # 終点の頂点は負けとなります
  if d[i] == 0:
    judge[i] = -1
    # 負けの頂点を探索のqueueに追加します
    q.append(i)

# 探索候補がなくなるまで続けます
while len(q) > 0:
  p = q.pop()
  if judge[p] == -1:
    for e in g[p]:
      # 既に勝ちの頂点として決まっているなら何もしません
      if judge[e] == 1:
        continue
      # 1つでも負けの頂点に遷移できるなら勝ちとなります
      judge[e] = 1
      # 決定した頂点を探索順に追加します
      q.append(e)
  else:
    for e in g[p]:
      # 既に勝ちの頂点と決まっているなら何もしません
      if judge[e] == 1:
        continue
      # 遷移先の候補が1つ減ったので出次数を減らします
      d[e] -= 1
      if d[e] == 0:
        # どこへも行けなくなってしまったら負けが決定します
        judge[e] = -1
        # 決定したら探索順に追加します
        q.append(e)

# 結果をもとに答えていきます
for s in S:
  # ここが少しややこしいです
  # 高橋君が s から始めたということは
  # 青木君が s の末尾 3 文字から開始する　と同義です
  # そのため青木君からみて勝敗はどうでしょうか？を考えます
  v = s2i(s[-3:])
  ans = judge[v]
  if ans == -1:
    # 青木君が -1 ということは高橋君の勝ちです
    print("Takahashi")
  elif ans == 0:
    # 引き分けは一番わかりやすいですね
    print("Draw")
  else:
    # 青木君が 1 なので青木君の価値です
    print("Aoki")