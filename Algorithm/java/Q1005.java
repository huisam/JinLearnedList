package baekjoon;

import java.util.Scanner;

public class Q1005 {

	static int []b;
	static int [][]c;
	static int []d;
	static int n;
	
	public static int go(int now) {
		if(d[now] != 0) {
			return d[now]; // dp에 값이 있으면 리턴
		}
		else {
			int result = 0;
			for (int i = 0; i <= n; i++) {
				if(c[now][i] == 1)
					result = Math.max(go(i), result); // 여기로 올 수 있는 모든 경우의수
			}
			return d[now] = result + b[now] ; // 메모이제이션
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) {
			n = sc.nextInt();
			int k = sc.nextInt();
			b = new int[n+1]; // 빌딩걸리는 시간
			for (int j = 1; j < n+1; j++) {
				b[j] = sc.nextInt();
			}
			c = new int[n+1][n+1]; // 건물 규칙 순서
			d = new int[n+1];
			for (int j = 0; j < k; j++) {
				int before = sc.nextInt();
				int after = sc.nextInt();
				c[after][before] = 1;
			}
			int arrival = sc.nextInt(); // 최종 도착지
			System.out.println(go(arrival));
				
		} // end of for
	} // end of main
} // end of class
