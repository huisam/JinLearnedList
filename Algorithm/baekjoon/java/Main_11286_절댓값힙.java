import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static int length = 0;
	static int []arr = new int[100001];
	
	static boolean abs(int x, int y) {
		if(Math.abs(arr[x]) == Math.abs(arr[y])) return arr[x] > arr[y];
		return Math.abs(arr[x]) > Math.abs(arr[y]);
	}
	
	static void add(int a) {
		arr[++length] = a;
		int i = length;
		while(i > 1 && abs(i/2, i)) {
			int temp = arr[i/2];
			arr[i/2] = arr[i];
			arr[i] = temp;
			i /= 2;
		}
	}
	
	static int pop() {
		if (length == 0) return 0;
		int ret = arr[1];
		arr[1] = arr[length--];
		int i = 1;
		while(i*2 <= length) {
			int left = i*2;
			if(abs(left,left+1)) left++;

			if(Math.abs(arr[i]) < Math.abs(arr[left])) break;
			else if(Math.abs(arr[i]) == Math.abs(arr[left]) && arr[i] < arr[left]) break;

			int temp = arr[left];
			arr[left] = arr[i];
			arr[i] = temp;
			i = left;
		}
		
		return ret;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim());
		for (int tc = 0; tc < t; tc++) {
			int n = Integer.parseInt(br.readLine().trim());
			if(n==0) System.out.println(pop());
			else add(n);
		}
	}
}
