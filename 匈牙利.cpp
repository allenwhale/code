int N;              // X的點數目，也等於Y的點數目
int mx[50], my[50]; // X各點的配對對象、Y各點的配對對象
int q[50], qf, qb;  // 交錯樹，X的部分
int py[50];         // 交錯樹，Y的部分
int lx[50], ly[50]; // vertex labeling
int adj[50][50];    // 精簡過的adjacency matrix

bool match(int r)
{
	while (true)
	{
		// 建交錯樹
		memset(py, -1, sizeof(py));
		for (qf=0, qb=1, q[0]=r; qf<qb; )
			for (int x=q[qf++], y=0; y<N; ++y)
				if (lx[x] + ly[y] == adj[x][y] && py[y] == -1)
				{
					q[qb++] = my[y]; py[y] = x;
					if (my[y] == -1) 
					{
						// 找到擴充路徑，並進行擴充。
						for (int ty = 0; ty != -1; y = ty)
							ty = mx[x = py[y]], my[y] = x, mx[x] = y;
						return true;
					}
				}

		// 找到適當的修改值
		int d = 1e9;
		for (int i=0; i<qb; ++i)    // 在交錯樹上的X
			for (int y=0; y<N; ++y) if (py[y] == -1)    // 不在交錯樹上的Y
				if (adj[q[i]][y] != 1e9)
					d = min(d, lx[q[i]] + ly[y] - adj[q[i]][y]);

		if (d == 1e9) break;    // 未新增等邊，無擴充路徑。

		// 調整label，調完後重建交錯樹
		for (int i=0; i<qb; ++i) lx[q[i]] -= d;
		for (int y=0; y<N; ++y) if (py[y] != -1) ly[y] += d;
	}
	return false;
}

int Hungarian()
{
	memset(mx, -1, sizeof(mx));
	memset(my, -1, sizeof(my));

	// 初始化vertex labeling
	memset(lx, 0, sizeof(lx));
	memset(ly, 0, sizeof(ly));
	for (int x=0; x<N; ++x)
		for (int y=0; y<N; ++y)
			lx[x] = max(lx[x], adj[x][y]);

	// 每個未匹配點嘗試建交錯樹，找擴充路徑
	for (int x=0; x<N; ++x)
		if (!match(x))
			mx[x] = -1; // 此點為未匹配點

	// 算最大權最大匹配的權重
	int cost = 0;
	for (int x=0; x<N; ++x)
		if (mx[x] != -1)
			cost += adj[x][mx[x]];
	return cost;
}


