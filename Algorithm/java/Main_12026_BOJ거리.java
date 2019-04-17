import java.util.*;

public class Main {
	
	static int n;
	static String s;
	static int[]d;
	
	static char nextChar(char now) {
		if(now == 'B') return 'O';
		else if(now == 'O') return 'J';
		else return 'B';
	}
	
	static int go(int index) {
		if(index == n-1)
			return 0;
		if(d[index] != -1)
			return d[index];
		char next = nextChar(s.charAt(index));
		int ans = -1;
		for(int i = index + 1; i < n; i++) {
			if(s.charAt(i) == next) {
				int temp = go(i);
				int dist = (i-index)*(i-index);
				if(temp != -1) {
					if(ans == -1 || ans > temp + dist)
						ans = dist + temp;
				}
			}
		}
		d[index] = ans;
		return ans;
		
	}
	
	public static void main(String []args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		s = sc.next();
		d = new int[n];
		for(int i = 0 ; i < n; i ++)
			d[i] = -1;
		System.out.println(go(0));
	}
}
