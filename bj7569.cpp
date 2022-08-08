#include<bits/stdc++.h>
using namespace std;
int board[102][102][102];
int dist[102][102][102];
queue<pair<pair<int,int>,int>> q;
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int m, n, h;
void bfs(){
	while(!q.empty()){
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		q.pop();
		for(int i = 0; i < 6; i++){
			int nx = a + dx[i];
			int ny = b + dy[i];
			int nz = c + dz[i];
			if(nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
			if(dist[nx][ny][nz] >= 0) continue;
			q.push(make_pair(make_pair(nx,ny),nz));
			dist[nx][ny][nz] = dist[a][b][c] + 1;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n >> h;
	for(int k = 0; k < h; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> board[i][j][k];
				if(board[i][j][k] == 1){
					q.push(make_pair(make_pair(i,j),k));
				}
				if(board[i][j][k] == 0){
					dist[i][j][k] = -1;
				}
			}
		}
	}
	bfs();
	int ans = 0;
	for(int k = 0; k < h; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(dist[i][j][k] == -1){
					cout << "-1\n";
					return 0;
				}
				ans = max(dist[i][j][k], ans);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
