package dataStructure;

import java.util.Arrays;

/**
 * [ 정렬 알고리즘 ] - Mergesort
 * 시간복잡도 - O(NlogN) - 최악의 경우와 평균이 동일
 * 공간복잡도 - O(N)
 * 분할정복의 대표적인 알고리즘의 예시로, 시간복잡도가 항상 일정하기 유지된다는 것이 장점이다
 * 배열을 나누고 임시배열을 또 따로 만들어야 하는 메모리 낭비가 있지만
 * 안정적으로 이용할 수 있다는 것에 장점을 두고 있다.
 * N이 1백만일 때, 79ms의 시간 소요가 된다!
 * @author huisam
 *
 */
public class MergeSort {
	
	private static int SIZE = 1000000;
	
	/** 배열을 저장할 변수 */
	private int arr[] = new int[SIZE];
	
	/** 정렬할 때 값을 저장할 임시 변수  */
	private int sorted[] = new int[SIZE];
	
	/** 객체 생성시 난수 뿌리기 */
	public MergeSort() {
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
	 * MergeSort 구현 메서드
	 * 1. 왼쪽과 오른쪽을 파티셔닝 한다.
	 * 2. 왼쪽 오른쪽을 나누었으면 정렬하면서 합친다!!
	 */
	public void mergeSort(int start, int end) {
		if(start < end) {
			int mid = (start + end) /2;
			mergeSort(start, mid);
			mergeSort(mid+ 1, end);
			merge(start, mid, end);
		}
	}
	
	/**
	 * 1.왼쪽 배열과 오른쪽 배열에 대하여 순차적으로 값을 비교한다!
	 * 2.더 작은 값이 있다면 임시 배열에 저장하고 인덱스를 늘린다
	 * 3.이러한 작업을 할 수 있을때 까지 반복한다!
	 * 4.마지막에 남은 배열에 모든 원소를 임시 배열에 붙인다!
	 * 5.최종적으로 임시배열을 원래 배열로 복사한다!
	 * @param start 왼쪽 배열의 시작
	 * @param mid 왼쪽 배열의 끝
	 * @param end 오른쪽 배열의 끝
	 */
	private void merge(int start, int mid, int end) {
		
		int i = start; // 왼쪽 인덱스
		int j = mid + 1;  // 오른쪽 인덱스
		int k = start; // 복사할 배열의 인덱스
		while(i <= mid && j <= end) {
			if(arr[i] <= arr[j])
				sorted[k++] = arr[i++];
			else
				sorted[k++] = arr[j++];
		}
		if(mid < i) {
			for (int l = j; l <= end; l++) {
				sorted[k++] = arr[l];
			}
		}
		else {
			for (int l = i; l <= mid; l++) {
				sorted[k++] = arr[l];
			}
		}
		for (int l = start; l <= end; l++) {
			arr[l] = sorted[l];
		}
	}
	
	
	public static void main(String[] args) {
		MergeSort ms = new MergeSort();
//		ms.print();
		long time = System.currentTimeMillis();
		ms.mergeSort(0, 999999);
		System.out.println("걸리는 시간 : " + (System.currentTimeMillis() - time) + "ms");
//		ms.print();
	}
	
}
