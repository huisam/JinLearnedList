import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static int ans;
	
	static void pelindrom(StringBuilder sb) {
		sb.append("#");
		int n = sb.length();
		int []a = new int[n];
		int r = 0;
		int p = 0;
		for(int i = 0; i < n; i++) {
			if (i <= r) a[i] = Math.min(a[(2*p)-i], r - i);
			else a[i] = 0;
			while(i - a[i] - 1 >= 0 && i + a[i] + 1 < n && sb.charAt(i-a[i]-1) == sb.charAt(i + a[i] + 1)) 
				a[i]++;
			if (r < i + a[i]) {
				r = i + a[i];
				p = i;
			}
		}
		for (int i = 0; i < a.length; i++) {
			ans = Math.max(ans, a[i]);
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String a = br.readLine().trim();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < a.length(); i++) {
			sb.append("#").append(a.charAt(i));
		}
		pelindrom(sb);
		
		System.out.println(ans);
	}
}
