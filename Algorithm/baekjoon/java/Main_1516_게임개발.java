import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main{

    static int n;
    static LinkedList<Integer>[] edge;
    static int[] arrTime;
    static int[] degree;
    static Queue<Node> resultQ = new LinkedList<>();
    static PriorityQueue<Node> processQ = new PriorityQueue<>();

    private static class Node implements Comparable<Node> {
        int num;
        int time;

        public Node(int num, int time) {
            this.num = num;
            this.time = time;
        }

        public int compareTo(Node o) {
            return Integer.compare(time, o.time);
        }
    }

    static void topologicalSort() {
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0) {
                processQ.add(new Node(i, arrTime[i]));
            }
        }
        while (!processQ.isEmpty()) {
            Node now = processQ.poll();
            resultQ.add(now);
            for (Integer next : edge[now.num]) {
                degree[next]--;
                if (degree[next] == 0) {
                    processQ.add(new Node(next, now.time + arrTime[next]));
                }
            }
        }
        while (!resultQ.isEmpty()) {
            Node now = resultQ.poll();
            arrTime[now.num] = now.time;
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine().trim());
        edge = new LinkedList[n];
        arrTime = new int[n];
        degree = new int[n];

        for (int i = 0; i < n; i++) {
            edge[i] = new LinkedList<>();
        }

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine().trim());
            int t = Integer.parseInt(st.nextToken());
            arrTime[i] = t;
            while (st.hasMoreTokens()) {
                int from = Integer.parseInt(st.nextToken());
                if (from == -1) break;
                degree[i]++;
                edge[from - 1].add(i);
            }
        }
        topologicalSort();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append(arrTime[i]).append('\n');
        }
        System.out.println(sb);


    }
}
