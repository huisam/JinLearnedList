package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_2455 {
	public static void main(String[] args) throws IOException {
		// use buffer Reader -> 80ms
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int input = 1; // 탄사람
		int output; // 내린사람
		int max_people = 0;
		int now_people = 0;
		while(input!=0) {
			String []tt = br.readLine().split(" ");
			output = Integer.valueOf(tt[0]);
			input = Integer.valueOf(tt[1]);
			now_people += input - output;
			max_people = Math.max(max_people, now_people);
		}
		System.out.println(max_people);
	}
}
