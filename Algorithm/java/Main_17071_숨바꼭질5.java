import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int ans = -1;
		int MAX = 500001;
		int [][]d = new int[MAX][2];
		Queue<Integer> q = new LinkedList<>();
		q.add(n);
		q.add(0);
		q.add(0);
		while(!q.isEmpty()) {
			int x = q.poll();
			int t = q.poll();
			int nt = q.poll();
			for(int next : new int[] {x+1, x-1, x*2}) {
				if(next >= 0 && next < MAX && d[next][1-t] == 0) {
					d[next][1-t] = nt+1;
					q.add(next);
					q.add(1-t);
					q.add(nt+1);
				}
			}
		}
		if(n==k) {
			System.out.println(0); 
			return;
		}
		for(int i=0; ; i++) {
			k += i;
			if(k >= MAX) break;
			if(d[k][i%2] != 0 && d[k][i%2] <= i) {
				ans = i;
				break;
			}
		}
		
		System.out.println(ans);
	}
}
