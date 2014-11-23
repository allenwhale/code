int N;              // X���I�ƥءA�]����Y���I�ƥ�
int mx[50], my[50]; // X�U�I���t���H�BY�U�I���t���H
int q[50], qf, qb;  // �����AX������
int py[50];         // �����AY������
int lx[50], ly[50]; // vertex labeling
int adj[50][50];    // ��²�L��adjacency matrix

bool match(int r)
{
	while (true)
	{
		// �إ����
		memset(py, -1, sizeof(py));
		for (qf=0, qb=1, q[0]=r; qf<qb; )
			for (int x=q[qf++], y=0; y<N; ++y)
				if (lx[x] + ly[y] == adj[x][y] && py[y] == -1)
				{
					q[qb++] = my[y]; py[y] = x;
					if (my[y] == -1) 
					{
						// ����X�R���|�A�öi���X�R�C
						for (int ty = 0; ty != -1; y = ty)
							ty = mx[x = py[y]], my[y] = x, mx[x] = y;
						return true;
					}
				}

		// ���A���ק��
		int d = 1e9;
		for (int i=0; i<qb; ++i)    // �b�����W��X
			for (int y=0; y<N; ++y) if (py[y] == -1)    // ���b�����W��Y
				if (adj[q[i]][y] != 1e9)
					d = min(d, lx[q[i]] + ly[y] - adj[q[i]][y]);

		if (d == 1e9) break;    // ���s�W����A�L�X�R���|�C

		// �վ�label�A�է��᭫�إ����
		for (int i=0; i<qb; ++i) lx[q[i]] -= d;
		for (int y=0; y<N; ++y) if (py[y] != -1) ly[y] += d;
	}
	return false;
}

int Hungarian()
{
	memset(mx, -1, sizeof(mx));
	memset(my, -1, sizeof(my));

	// ��l��vertex labeling
	memset(lx, 0, sizeof(lx));
	memset(ly, 0, sizeof(ly));
	for (int x=0; x<N; ++x)
		for (int y=0; y<N; ++y)
			lx[x] = max(lx[x], adj[x][y]);

	// �C�ӥ��ǰt�I���իإ����A���X�R���|
	for (int x=0; x<N; ++x)
		if (!match(x))
			mx[x] = -1; // ���I�����ǰt�I

	// ��̤j�v�̤j�ǰt���v��
	int cost = 0;
	for (int x=0; x<N; ++x)
		if (mx[x] != -1)
			cost += adj[x][mx[x]];
	return cost;
}


