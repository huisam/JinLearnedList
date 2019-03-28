import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String temp = br.readLine().trim();
		int ans = 1;
		if(temp.charAt(0) == 'c') ans *= 26;
		else ans *= 10;
		
		for (int i = 1; i < temp.length(); i++) {
			if(temp.charAt(i) == 'c') {
				if(temp.charAt(i-1) == 'c') {
					ans *= 25;
				}
				else ans *= 26;
			}
			else {
				if(temp.charAt(i-1) == 'd') {
					ans *= 9;
				}
				else ans *= 10;
			}
		}
		System.out.println(ans);
	}
}
