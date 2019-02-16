package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_2512_예산 {
	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			int n = Integer.parseInt(br.readLine());
			int[] num = new int[n];
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < num.length; i++) {
				num[i] = Integer.parseInt(st.nextToken());
			}
			int m = Integer.parseInt(br.readLine());
			Arrays.sort(num);
			int left = 0;
			int right = num[n-1];
			while(left <= right) {
				int mid = (left + right)/2;
				int sum = 0;
				for (int i = 0; i < num.length; i++) {
					if (num[i] <= mid)
						sum += num[i];
					else {
						sum += mid;
					}
				}
				if (sum <= m) {
					left = mid + 1;
				}
				else
					right = mid - 1;
			}
			System.out.println(left-1);
			

		} catch (Exception e) {
		}
	}
}
