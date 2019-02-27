import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static char[][] map;
	static int ans,n,m;
	static int[] dx = { 0, 0, -1, 1 };
	static int[] dy = { 1, -1, 0, 0 };

	static class Node {
		int x;
		int y;
		int dist;

		Node(int x, int y, int dist) {
			this.x = x;
			this.y = y;
			this.dist = dist;
		}
	}

	static void bfs(boolean[][] check, int x, int y) {
		Queue<Node> q = new LinkedList<Node>();
		check[x][y] = true;
		q.add(new Node(x,y,0));
		while(!q.isEmpty()) {
			Node now = q.poll();
			ans = Math.max(ans, now.dist);
			for (int i = 0; i < 4; i++) {
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];
				if(nx < 0 || nx >= n || ny < 0 || ny >= m )
					continue;
				if(map[nx][ny] == 'W' || check[nx][ny])
					continue;
				check[nx][ny] = true;
				q.add(new Node(nx, ny, now.dist+1));
			}
		}
	}

	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			map = new char[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = br.readLine().toCharArray();
			}
			boolean[][] check; 
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (map[i][j] == 'L') {
						check = new boolean[n][m];
						bfs(check, i, j);
					}
				}
			}
			System.out.println(ans);
		} catch (Exception e) {
		}
	}
}
