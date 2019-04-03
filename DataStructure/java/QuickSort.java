package study;

import java.util.Arrays;

/**
 * 퀵 정렬을 구현해보자~!
 * 동작 방식은 다음과 같다.
 * 1.pivot을 임의로 선정한다.
 * 2.선정한 pivot에 대해 왼쪽 파티션은, pivot보다 작은 값! 오른쪽 파티션은, pivot보다 큰 값!
 * 3.왼쪽과 오른쪽 파티션에 대하여, 다시 정렬하는 작업을 실시한다.
 * 4.이러한 작업을 어레이 크기가 0 또는 1일때까지 반복한다!!
 * 1000만개 정렬시 걸리는 시간 : 387ms
 * @author huisam
 *
 */
public class QuickSort {

	private static int SIZE = 10;
	
	/** 배열을 저장할 변수 */
	private int arr[] = new int[SIZE];
	
	/** 객체 생성시 난수 뿌리기 */
	public QuickSort() {
		for (int i = 0; i < SIZE; i++) {
			arr[i] = (int) (Math.random() * 100) + 1;
		}
	}
	
	/**
	 * 배열을 출력할 메서드
	 */
	public void print() {
		System.out.println(Arrays.toString(arr));
	}
	
	/**
	 * 퀵 정렬이 이루어지는 알고리즘
	 * pivot을 가운데로 선정하여 파티션 분할하면 성능을 개선할 수 있다.
	 * @param left
	 * @param right
	 */
	public void quicksort(int left, int right) {
		if (left >= right) {
			return;
		}
		int l = left - 1;
		int r = right + 1;
		int mid = arr[(l+r)/2];
		while (true) {
			while (arr[++l] < mid);
			while (arr[--r] > mid);
			if (l >= r) {
				break;
			}
			int temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
		}
		quicksort(left, l-1);
		quicksort(r + 1, right);
	}
	
	public static void main(String[] args) {
		QuickSort q = new QuickSort();
		long time = System.currentTimeMillis();
		q.quicksort(0, 9);
		System.out.println(System.currentTimeMillis() - time + "ms");
	}
	
}
