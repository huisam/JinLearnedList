import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main{

    static class Node {
        int x;
        int y;
        int t;

        public Node(int x, int y, int t) {
            this.x = x;
            this.y = y;
            this.t = t;
        }
    }

    static int n, m, cnt, ans;
    static int[][] arr;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    static boolean[] checkVirus;
    static ArrayList<Node> virus = new ArrayList<>();

    static void findVirus() {
        boolean check[][] = new boolean[n][n];
        Queue<Node> q = new LinkedList<>();
        for (int i = 0; i < checkVirus.length; i++) {
            if (checkVirus[i]) {
                check[virus.get(i).x][virus.get(i).y] = true;
                q.add(virus.get(i));
            }
        }
        int remain = cnt;
        int cntVirus = 0;
        while (!q.isEmpty()) {
            if (remain == 0)
                break;
            Node now = q.poll();
            cntVirus = Math.max(cntVirus, now.t);
            for (int i = 0; i < 4; i++) {
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || check[nx][ny] || arr[nx][ny] == 1)
                    continue;
                check[nx][ny] = true;
                if (arr[nx][ny] == 0) {
                    remain--;
                    q.add(new Node(nx, ny, now.t + 1));
                } else if (arr[nx][ny] == 2) {
                    q.add(new Node(nx, ny, now.t + 1));
                }
                cntVirus = now.t + 1;
            }
        }
        if (remain == 0)
            ans = Math.min(ans, cntVirus);
    }


    static void go(int idx, int addNum) {
        if (addNum == m) {
            findVirus();
            return;
        }
        if (idx == virus.size()) {
            return;
        }
        checkVirus[idx] = true;
        go(idx + 1, addNum + 1);
        checkVirus[idx] = false;
        go(idx + 1, addNum);
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n][n];
        ans = 987654321;
        cnt = 0;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == 0) cnt++;
                else if (arr[i][j] == 2) {
                    virus.add(new Node(i, j, 0));
                }

            }
        }
        checkVirus = new boolean[virus.size()];
        go(0, 0);
        if (ans == 987654321)
            System.out.println(-1);
        else
            System.out.println(ans);
    }
}
