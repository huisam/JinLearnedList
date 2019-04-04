package study;

import java.util.Arrays;

/**
 * 기초 정렬 방법중의 하나인 Insertion Sort를 구현한다
 * 이 정렬 방법이 살아남은 이유는
 * 최선의 경우가 O(N)이고, 메모리를 덜 잡아먹는 특징 때문이다!
 * 물론 최악은 O(N^2)이지만, N이 작을 때는 효율적이다
 * 분할 정복의 경우, 함수를 호출하는 과정 때문에 작은 값의 데이터에는
 * 배보다 배꼽이 더 커버리게 되는데
 * 이때는 Insertion Sort를 이용하면 성능이 개선된다!
 * 10,000 개 데이터 정렬시 걸리는 시간 : 25ms
 * 100,000 개 데이터 정렬시 걸리는 시간 : 2216ms ( 데이터 분포에 따라 시간은 바뀜 )
 * @author huisam
 *
 */
public class InsertionSort {
	
	private static int SIZE = 100000;
	
	/** 배열을 저장할 변수 */
	private int arr[] = new int[SIZE];
	
	/** 객체 생성시 난수 뿌리기 */
	public InsertionSort() {
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
	 * 1.1번부터 끝 인덱스의 원소를 key값으로 한다!
	 * 2.해당 key값보다 큰 값이 나올 때까지 원소를 한칸씩 땡긴다.
	 * 3.인덱싱이 끝난 자리에 key값을 집어 넣는다!
	 * 최악의 시간복잡도 O(N^2)
	 * 최선의 시간복잡도 O(N)
	 * 공간복잡도 O(1)
	 */
	public void insertionSort() {
		for (int i = 1; i < SIZE; i++) {
			int key = arr[i];
			int j = i - 1;
			for (; j >= 0 && key < arr[j]; j--) {
				arr[j+1] = arr[j];	
			}
			arr[j+1] = key;
		}
	}
	
	public static void main(String[] args) {
		InsertionSort is = new InsertionSort();
//		is.print();
		long time = System.currentTimeMillis();
		is.insertionSort();
		System.out.println(System.currentTimeMillis() - time + "ms");
//		is.print();
	}
	
	
}
