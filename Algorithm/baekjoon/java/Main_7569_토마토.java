package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_7569_토마토 {

	static int dx[] = { 0, 0, 1, -1, 0, 0 };
	static int dy[] = { 1, -1, 0, 0, 0, 0 };
	static int dh[] = { 0, 0, 0, 0, 1, -1 };

	static class Node {
		int h;
		int x;
		int y;
		int d;

		public Node(int h, int x, int y, int d) {
			this.x = x;
			this.y = y;
			this.h = h;
			this.d = d;
		}

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int m = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		int h = Integer.parseInt(st.nextToken());

		int[][][] arr = new int[h][n][m];
		boolean[][][] check = new boolean[h][n][m];
		Queue<Node> q = new LinkedList<>();
		int cnt = 0;
		for (int a = 0; a < h; a++) {
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine(), " ");
				for (int j = 0; j < m; j++) {
					arr[a][i][j] = Integer.parseInt(st.nextToken());
					if (arr[a][i][j] == 0)
						cnt++;
					else if (arr[a][i][j] == 1) {
						check[a][i][j] = true;
						q.add(new Node(a, i, j, 0));
					} else
						check[a][i][j] = true;
				}
			}
		}
		if (cnt == 0) {
			System.out.println(0);
			return;
		}
		int ans = 0;
		while (!q.isEmpty()) {
			Node now = q.poll();
			ans = Math.max(ans, now.d);
			for (int i = 0; i < 6; i++) {
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];
				int nh = now.h + dh[i];

				if (nx >= n || nx < 0 || ny >= m || ny < 0 || nh < 0 || nh >= h || check[nh][nx][ny])
					continue;
				check[nh][nx][ny] = true;
				arr[nh][nx][ny] = 1;
				cnt--;
				q.add(new Node(nh, nx, ny, now.d + 1));
			}
		}
		if (cnt == 0)
			System.out.println(ans);
		else
			System.out.println(-1);
	}
}