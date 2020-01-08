package Baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

class Main_1012_유기농배추 {

    static int n, m, k;
    static int[][] arr;
    static boolean[][] check;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, 1, -1};

    private static class Node {
        int x, y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static void dfs(int x, int y) {
        Stack<Node> s = new Stack<>();
        check[x][y] = true;
        s.push(new Node(x, y));
        while (!s.isEmpty()) {
            Node now = s.pop();
            for (int i = 0; i < 4; i++) {
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || check[nx][ny] || arr[nx][ny] == 0)
                    continue;
                check[nx][ny] = true;
                s.push(now);
                s.push(new Node(nx, ny));
                break;
            }
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        StringBuilder sb = new StringBuilder();
        for (int t = 1; t <= tc; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            m = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            arr = new int[n][m];
            check = new boolean[n][m];
            while (k-- != 0) {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                arr[y][x] = 1;
            }
            int ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!check[i][j] && arr[i][j] == 1) {
                        ans++;
                        dfs(i, j);
                    }
                }
            }
            sb.append(ans).append('\n');
        }
        System.out.println(sb);
    }
}
