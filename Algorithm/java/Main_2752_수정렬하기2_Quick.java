package Baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main_2752_수정렬하기2_Quick {
    static int[] arr;
    static int n;

    static void quicksort(int left, int right) {
        if (left >= right) return;
        int l = left - 1;
        int r = right + 1;
        int mid = arr[(l + r) / 2];
        while (true) {
            while (arr[++l] < mid) ;
            while (arr[--r] > mid) ;
            if (l >= r) break;
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
        }
        quicksort(left, l - 1);
        quicksort(r + 1, right);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine().trim());
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine().trim());
        }
        quicksort(0, n - 1);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append(arr[i]).append('\n');
        }
        System.out.println(sb);
    }
}
