package test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Stack;

public class Solution_5550_나는개구리로소이다_홍휘진 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine().trim());
go:		for (int t = 1; t <= tc; t++) {
			String now = br.readLine().trim();
			ArrayList<Stack<Character>> s = new ArrayList<>();
			for (int i = 0; i < 500; i++) {
				s.add(new Stack<>());
			}
			int idx = 0;
			int ans = 0;
			for (int i = 0; i < now.length(); i++) {
				char here = now.charAt(i);
				boolean find = false;
				switch (here) {
				case 'c':
					for (int j = 0; j < idx; j++) {
						if(s.get(j).isEmpty()) {
							s.get(j).push(here);
							find = true;
							break;
						}
					}
					if(!find)
						s.get(idx++).push(here);
					break;
				case 'r':
					for (int j = 0; j < idx; j++) {
						if(!s.get(j).isEmpty() && s.get(j).peek() == 'c') {
							s.get(j).push(here);
							find = true;
							break;
						}
					}
					if(!find) {
						System.out.println("#" + t + " " + -1);
						continue go;
					}
					break;
				case 'o':
					for (int j = 0; j < idx; j++) {
						if(!s.get(j).isEmpty() && s.get(j).peek() == 'r') {
							s.get(j).push(here);
							find = true;
							break;
						}
					}
					if(!find) {
						System.out.println("#" + t + " " + -1);
						continue go;
					}
					break;
				case 'a':
					for (int j = 0; j < idx; j++) {
						if(!s.get(j).isEmpty() && s.get(j).peek() == 'o') {
							s.get(j).push(here);
							find = true;
							break;
						}
					}
					if(!find) {
						System.out.println("#" + t + " " + -1);
						continue go;
					}
					break;
				case 'k':
					for (int j = 0; j < idx; j++) {
						if(!s.get(j).isEmpty() && s.get(j).peek() == 'a') {
							s.get(j).clear();
							find = true;
							break;
						}
					}
					if(!find) {
						System.out.println("#" + t + " " + -1);
						continue go;
					}
					break;
				}
				ans = Math.max(ans, idx);
			}
			for (int i = 0; i < idx; i++) {
				if(!s.get(i).isEmpty()) {
					System.out.println("#" + t + " " + -1);
					continue go;
				}
			}
			System.out.println("#" + t + " " + ans);
		} // end of for
	}
}
