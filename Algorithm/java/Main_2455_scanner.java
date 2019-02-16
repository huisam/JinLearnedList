package baekjoon;

import java.util.Scanner;

public class Main_2455_scanner {
	public static void main(String[] args) {
		// use scanner -> 108ms
		Scanner sc = new Scanner(System.in);
		int input = 1; // 탄사람
		int output; // 내린사람
		int max_people = 0;
		int now_people = 0;
		while(input!=0) {
			output = sc.nextInt();
			input = sc.nextInt();
			now_people += input - output;
			max_people = Math.max(max_people, now_people);
		}
		System.out.println(max_people);
	}
}


