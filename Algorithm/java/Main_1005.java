package baekjoon;

import java.util.Scanner;

public class Main_1005 {

	static int []b;
	static int [][]c;
	static int []d;
	static int n;
	
	public static int go(int now) {
		if(d[now] != 0) {
			return d[now]; 
		}
		else {
			int result = 0;
			for (int i = 0; i <= n; i++) {
				if(c[now][i] == 1)
					result = Math.max(go(i), result); 
			}
			return d[now] = result + b[now] ; 
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) {
			n = sc.nextInt();
			int k = sc.nextInt();
			b = new int[n+1]; 
			for (int j = 1; j < n+1; j++) {
				b[j] = sc.nextInt();
			}
			c = new int[n+1][n+1]; 
			d = new int[n+1];
			for (int j = 0; j < k; j++) {
				int before = sc.nextInt();
				int after = sc.nextInt();
				c[after][before] = 1;
			}
			int arrival = sc.nextInt(); 
			System.out.println(go(arrival));
				
		} // end of for
	} // end of main
} // end of class
