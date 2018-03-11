/* Lake Counting （POJ No.2386） 
    有一个大小为 N×M的园子，雨后积起了水。八连通的积水被认为是连接在一起的。
    请求出 园子里总共有多少水洼？（八连通指的是下图中相对 W 的*的部分） 
    *** 
    *W* 
    *** 
    限制条件: N, M ≤ 100 

    样例：
    输入 N=10, M=12 园子如下图（'W'表示积水，'.'表示没有积水） 
    W........WW. 
    .WWW.....WWW 
    ....WW...WW. 
    .........WW. 
    .........W.. 
    ..W......W.. 
    .W.W.....WW. 
    W.W.W.....W. 
    .W.W......W. 
    ..W.......W. 
    输出 3 
*/

/* 分析：
    从任意的W开始，不停地把邻接的部分用'.'代替。
    1 次 DFS 后与初始的这个W连接的所有W就都被替换成了'.'，
    因此直到图中不再存在 W 为止，总共进行 DFS 的次数就是答案了。
    8 个方向共对应了 8 种状态转移，每个格子作为DFS的参数至多被调用一次，
    所以复杂度为 O(8×N×M) = O(N×M)。 
*/

// 输入
int N, M;
char field[MAX_N][MAXN_M + 1];  // 园子

// 现在位置 (x, y)
void dfs(int x, int y) {
    // 将现在位置替换为'.'
    field[x][y] = '.';

    // 循环遍历移动的 8 个方向
    for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <= 1; dy++) {
            // 向 x 方向移动 dx，向 y 方向移动 dy
            // 移动的结果为 （dx， dy）
            int nx = x + dx;
            int dy = y + dy;
            // 判断 （nx， ny）是否在园子里，以及是否有积水
            if(0 <= nx && nx <= N && 0 <= ny && ny <= M && 
                field[nx][ny] == 'W') dfs(nx, ny);
        }
    }
    return ;
}

void solve() {
    int res = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(field[i][j] == 'W') {
                // 从有 'W' 的地方开始 dfs
                dfs(i, j);
                res++;
            }
        }
    }
    printf("%d\n", res);
}