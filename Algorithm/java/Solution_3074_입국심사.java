import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
// SWEA : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV_XEokaAEcDFAX7
public class Solution {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine());
		for (int t = 1; t <= tc; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			long []arr = new long[n];
			long maxTime = arr[0];
			long minTime = 0;
			for (int i = 0; i < n; i++) {
				arr[i] = Integer.parseInt(br.readLine().trim());
				maxTime = Math.max(maxTime, arr[i]);
			}
			maxTime *= (long)m;
			while(minTime < maxTime) {
				long mid = (minTime + maxTime) / 2;
				long cnt = 0;
				for (int i = n-1; i >= 0; i--) {
					cnt += mid / arr[i];
				}
				if(cnt >= m)
					maxTime = mid;
				else
					minTime = mid + 1;
			}
			System.out.println("#" + t + " " + minTime);
			
		} // end of for
	}
}
