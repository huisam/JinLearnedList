import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		boolean[] prime = new boolean[1000001];
		for (int i = 2; i*i <= 1000000; i++) {
			for (int j = i; j*i <= 1000000; j++) {
				prime[j*i] = true; 
			}
		}
		int []num = new int[100000];
		int cnt = 0;
		for (int i = 2; i<= 1000000; i++) {
			if (!prime[i]) num[cnt++] = i;
		}
		int tc = Integer.parseInt(br.readLine().trim());
		StringBuilder sb = new StringBuilder();
		for(int t = 1; t <= tc; t++) {
			int n = Integer.parseInt(br.readLine().trim());
			int ans = 0;
			for (int i = 0; i < cnt && num[i] <= n/2; i++) {
				if (!prime[n - num[i]]) ans++;
			}
			sb.append(ans).append('\n');
		}
		System.out.println(sb);
	}
}
