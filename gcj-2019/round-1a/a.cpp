#include <bits/stdc++.h>
using namespace std;
struct Trie
{
	Trie *ch[26];
	int num;
	bool end;
};
void insert(Trie *tr, char *s)
{
	int len = strlen(s);
	for (int i = len-1; i>=0; i--)
	{
		if (tr->ch[s[i] - 'A'] == NULL)
		{
			tr->ch[s[i] - 'A'] = new Trie();
		}
		tr = tr->ch[s[i] - 'A'];
	}
	tr->end = true;
	tr->num++;
}
int dfs(Trie *tr)
{
	if (tr == NULL)
		return 0;
	for (int i = 0; i < 26; i++)
	{
		tr->num += dfs(tr->ch[i]);
	}
	return tr->num;
}
Trie *root;
int dfs2(Trie *tr)
{
	if (tr == NULL)
		return 0;
	int num = tr->num;
	int ans = 0;
	for (int i = 0; i < 26; i++)
	{
		int tmp = dfs2(tr->ch[i]);
		ans += tmp;
		num -= tmp;
	}
	if (num >= 2 && tr != root)
	{
		ans += 2;
	}
	return ans;
}
char in[110];
int Solve()
{
	int N;
	scanf("%d", &N);
	root = new Trie();
	for (int i = 0; i < N; i++)
	{
		scanf("%s", in);
		insert(root, in);
	}
	dfs(root);
	int ans = dfs2(root);
	return ans;
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		printf("Case #%d: %d\n", t, Solve());
	}
	return 0;
}