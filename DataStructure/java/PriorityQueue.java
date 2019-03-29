package test;
/**
 * Max Heap 구현 --> Min Heap은 삽일하고 제거할때 -기호를 붙이면 됨!!
 * Heap은 항상 [반정렬] 상태를 유지한다!!
 * => 다시 말해서, 큰 값이 depth가 깊을 수 있고, 작은 값이 depth가 작을 수 있다.
 * Heap의 왼쪽 자식 노드의 index는 left = parent * 2
 * Heap의 오른쪽 자식 노드의 index는 right = parent *2 + 1;
 * @author huisam
 * 
 * 최대 힙 문제 : https://www.acmicpc.net/problem/11279
 * 
 */
public class PriorityQueue {
	
	/** 배열의 크기를 저장할 인덱스,, 코드 구조는 보기좋게 1번째부터 시작 */
	private int length = 0;
	
	/** heap을 나타낼 배열,, 0번째 인덱스는 비운다*/
	private int []arr = new int[1000];
	
	/**
	 * x와 y의 인덱스 위치의 원소를 스왑한다
	 * @param x
	 * @param y
	 */
	private void swap(int x, int y) {
		int temp = arr[x];
		arr[x] = arr[y];
		arr[y] = temp;
	}
	
	/**
	 * 힙 내부구조를 보여주기 위한 배열
	 */
	public void print() {
		System.out.print("(");
		for (int i = 1; i < length; i++) {
			System.out.print(arr[i] + ", ");
		}
		System.out.println(arr[length] + ")");
	}
	
	/**
	 * x인덱스의 부모 index는 자신의 값에서 /2된 값이다
	 * @param x
	 * @return x/2
	 */
	private int parent(int x) {
		return x/2;
	}
	
	/**
	 * 원소를 삽입할 때, 맨 뒤에 삽입을 한뒤
	 * 부모보다 값이 높으면 해당 원소를 서로 스왑한다.
	 * 이러한 작업을 할 수 있을 때까지 반복한다.
	 * 시간복잡도 O(logN)
	 * @param a 추가하는 값
	 */
	public void add(int a) {
		arr[++length] = a;
		int i = length;
		while(i > 1 && arr[parent(i)] < arr[i]) {
			swap(parent(i), i);
			i = parent(i);
		}
	}
	
	/**
	 * 1.최대 원소를 제거한다
	 * 2.마지막에 있는 원소를 루트로 가져온다
	 * 3.(자식노드의 값 중 최대값)보다 부모가 크면, 큰 자식노드와 교환한다 => 없으면 로직 종료
	 * 4.더이상 교환이 불가능할 때까지 간다. ( i*2 까지라는 것은 왼쪽자식이 하나라도 있으면 교환을 시도한다는 것 )
	 * 시간복잡도 O(logN)
	 * @return Heap의 최대값, 비어있으면 -1
	 */
	public int pop() {
		if(length == 0) return -1;
		
		int ret = arr[1];
		arr[1] = arr[length--];
		int i = 1;
		while(i*2 <= length) {
			int left = i*2;
			if(arr[left] < arr[left+1])
				left++;
			
			if(arr[i] >= arr[left]) break;
			swap(left, i);
			i = left;
		}
		
		return ret;
	}
	
	public static void main(String[] args) {
		PriorityQueue pq = new PriorityQueue();
		pq.add(1);
		pq.add(2);
		pq.pop();
		pq.pop();
		pq.add(3);
		pq.add(2);
		pq.add(1);
		pq.print();
		pq.pop();
		pq.print();
		pq.pop();
		pq.print();
	}
}
