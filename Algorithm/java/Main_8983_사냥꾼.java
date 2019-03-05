import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main{
	
	static int []ms;
	// lower_bound binarySearch
	static int binarySearch(int v) {
		int left = 0;
		int right = ms.length - 1;
		
		while(left < right) {
			int mid = (left + right) / 2;
			if(ms[mid] == v)
				return mid;
			else if(ms[mid] >= v) {
				right = mid;
			}
			else
				left = mid + 1;
		}
		return right + 1;
	}
	
	static int calc(int fromX, int goX, int goY) {
		return Math.abs(fromX - goX) + goY;
	}
	
	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int m,n,l;
			m = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(st.nextToken());
			l = Integer.parseInt(st.nextToken());
			ms = new int[m];
			st = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < m; i++) {
				ms[i] = Integer.parseInt(st.nextToken());
			}
			Arrays.sort(ms);
			int ans = 0;
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine(), " ");
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				int prox = binarySearch(x);
				if(prox > 0  && calc(ms[prox - 1], x, y) <= l) {
					ans++;
				}
				else if(prox < m &&calc(ms[prox],x,y) <= l)
					ans++;
				else if(prox != 0 && calc(ms[prox - 1],x,y) <= l)
					ans++;
				else if(prox != 1 && prox != 0 && calc(ms[prox - 2],x,y) <= l)
					ans++;
			}
			
			System.out.println(ans);
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
