import java.util.LinkedList;
import java.util.Queue;

/**
 * 방향성이 있고 그래프가 없는 그래프(DAG)에서
 * Node간의 순서를 정렬하기 위하여 사용되는 알고리즘
 * 진입차수가 적은 것부터 시작해서 높은 순서대로 정렬된다!
 * <p>
 * Sample Data
 * 1 -> 2
 * 2 -> 5
 * 3 -> 6
 * 3 -> 7
 * 4 -> 7
 * 5 -> 8
 * 6 -> 8
 * 7 -> 8
 *
 * @author huisam
 */
class TopologicalSort {

    private LinkedList<Integer>[] edge;
    private int degree[];
    private final int size = 10;

    TopologicalSort() {
        edge = new LinkedList[size];
        for (int i = 0; i < size; i++) {
            edge[i] = new LinkedList<>();
        }
        degree = new int[size];
        makeData();
    }

    private void makeData() {
        degree[2]++;
        degree[5]++;
        for (int i = 6; i < 8; i++) {
            degree[i] = 2;
        }
        degree[8] = 3;
        edge[1].push(2);
        edge[2].push(5);
        edge[2].push(6);
        edge[3].push(6);
        edge[3].push(7);
        edge[4].push(7);
        edge[5].push(8);
        edge[6].push(8);
        edge[7].push(8);
    }

    private void printResultQueue(Queue<Integer> resultQ) {
        System.out.println("[위상정렬] 순서");
        while (!resultQ.isEmpty()) {
            System.out.print(resultQ.poll() + " ");
        }
        System.out.println();
    }

    private void sortStart() {
        Queue<Integer> processQ = new LinkedList<>();
        Queue<Integer> resultQ = new LinkedList<>();
        // 진입차수가 0인것부터 시작한다.
        for (int i = 0; i < size; i++) {
            if (degree[i] == 0) {
                processQ.add(i);
            }
        }
        // 모든 노드를 방문할 떄 까지
        while (!processQ.isEmpty()) {
            int now = processQ.poll();
            resultQ.add(now);
            // 다음 방문 노드에 대해 하나씩 방문
            for (int next : edge[now]) {
                // 진입차수를 깍고
                degree[next]--;
                // 진입차수가 0이라면 진행한다.
                if (degree[next] == 0) {
                    processQ.add(next);
                }
            }
        }
        printResultQueue(resultQ);
    }

    public static void main(String[] args) {
        TopologicalSort topologicalSort = new TopologicalSort();
        topologicalSort.sortStart();
    }

}
