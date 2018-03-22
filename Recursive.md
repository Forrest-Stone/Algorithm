# 递归 #

	1. 半数集

	set(n)定义如下：
	（1）n是set(n)中的元素
	（2）在n的左边添加一个元素，但该自然数不能超过最近添加数的一半
	（3）按此规律添加，直到不能添加为止
	   
	/* 半数集 （NEFU 560) */

	#include <iostream>

	using namespace std;

	int half_set(int n) {
		int num = 1;
		if(n > 1)
			for(int i = 1; i <= n/2; ++i)
				num += half_set(i);
		// else num = 1;
		return num;
	}
		
	int main() {
		int n;
		while(cin >> n) 
			cout << half_set(n) << endl;	
		return 0;
	}


	2. 分书问题

	有编号为1...n的书，准备分给n个人，每个人的阅读兴趣用一个二维数组表示
	1：喜欢这本书
	0：不喜欢这本书
	Like[i][j] = 1 i喜欢j这本书
	Like[i][j] = 0 不喜欢j这本书
	
	/* 分书问题 (NEFU559) */
	 
	#include <iostream>
	#include <cstring>
	
	using namespace std;
	
	const int MAXN = 125;
	int visited[MAXN];		// 保存节点的访问状态
	int state[MAXN][MAXN];	// 保存此二维数组
	int solution[MAXN];	// 保存结果
	int n; 
	
	bool search(int m) {
		if(m == n) return true;
		// 判断第i本书是否已经被选，第m个人是否喜欢第i本书 
		for(int i = 0; i < n; ++i)
			if(!visited[i] && state[m][i]) {
				// 第i本书我选了 
				solution[m] = i + 1;
				visited[i] = 1;
				// 剩下的能否人手一本 
				if(search(m + 1)) return true;
				// 不能的话，就不选择第i本书 
				visited[i] = 0; 
			}
		return false;
	}
	
	int main() {
		while(cin >> n) {
			memset(visited, 0, sizeof(visited));
			memset(solution, 0, sizeof(solution));
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j) 
					cin >> state[i][j];
			if(search(0)) {
				// cout << solution[0] << endl;
				for(int i = 0; i < n; ++i)
					cout << solution[i] << " ";
				cout << endl;
			}
		} 
		return 0;
	}

	3. 方块计算

	有意见长方形的房子，地上铺了白色黑色两种颜色的正方形瓷砖。你站在其中一块黑色瓷砖上，只能向相邻的黑色瓷砖移动；计算你发能到达的黑色瓷砖的最大值；
	. 表示黑色的瓷砖
	# 表示白色的瓷砖
	@ 黑色的瓷砖，表示你站在这篇瓷砖上

	/* 方块计算 （NEFU 561）*/ 
	
	#include <iostream>
	
	using namespace std;
	
	const int MAXN = 31;
	char map[MAXN][MAXN];
	int m, n;
	
	int dfs(int x, int y) {
		int d = 0;
		if(x < 0 || x >= n || y < 0 || y >= m || map[x][y] == '#') return 0;
		if(map[x][y] = '.') {
			d = 1;
			map[x][y] = '#';
		}
		return dfs(x + 1, y) + dfs(x, y + 1) + dfs(x -1, y) + dfs(x, y -1) + d;
	}
	
	int main() {
		while(cin >> m >> n) {
			if(m == 0 && n == 0) break;
			int ans = 0;
			for(int i = 0; i < n; ++i)
				cin >> map[i];
			for(int i = 0; i < n; ++i)
			 	for(int j = 0; j < m; ++j)
			 		if(map[i][j] == '@')
			 			cout << dfs(i, j) << endl; 
		} 
		return 0;
	}
