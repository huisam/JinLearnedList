package dataStructure;

/**
 * 자바의 대표 Collection Framework의 구성요소 중 하나인 ArrayList를 직접 구현한다.
 * 원래, ArrayList Class의 경우 동적 배열이므로 원소 삽입시 2^n원소 마다 메모리를 할당받는 작업이 필요하다
 * 그러한 과정은 생략하여 코드를 작성했다. ( 기존 배열의 size * 2배만큼 배열을 새로 할당하여, Arrays.copy 작업 진행 )
 * @author huisam
 *
 */
public class ArrayList {
	
	/** 배열의 전체 사이즈를 나타낼 길이 */
	private int length = 0;
	
	/** 저장 배열을 나타낼 배열, 크기에 따라 사이즈를 늘리는 귀찮은 작업은 안했음 */
	private int[] d = new int[1000];
	
	/**
	 * 배열을 출력하는 함수
	 */
	public void print() {
		if (isEmpty()) return;
		System.out.print("(");
		for (int i = 0; i < length - 1; i++)
			System.out.print(d[i] + ", ");
		System.out.println(d[length-1] + ")");
	}
	
	/**
	 * 배열이 비어있니?
	 * @return 비었으면 true, 아니면 false
	 */
	public boolean isEmpty() {
		return length == 0 ? true : false;
	}
	
	/**
	 * 배열의 원소를 추가한다.
	 * 시간복잡도 O(1) , 메모리 재할당시 O(n) = A
	 * @param a
	 */
	public void add(int a) {
		d[length++] = a;
	}
	
	/**
	 * 중간 삽입의 경우, 해당 위치에 원소를 삽입하고 뒤에 원소를 전부 밀어내야 하므로
	 * 맨앞에 놓는 최악의 경우 모든 원소를 한칸씩 뒤로 밀어내야 한다
	 * 시간복잡도 O(n)
	 * @param index 배열의 인덱스
	 * @param num 값
	 * @throws IndexOutOfBoundsException
	 */
	public void addIndexOf(int index, int num) throws IndexOutOfBoundsException {
		if (get(index) == 0) throw new ArrayIndexOutOfBoundsException();
		for (int i = length; i > index; i--) {
			d[i] = d[i-1];
		}
		d[index] = num;
		length++;
	}
	
	/**
	 * 배열의 크기를 리턴한다
	 * @return 배열의 크기
	 */
	public int size() {
		return length;
	}
	
	/**
	 * 배열의 해당 원소를 리턴한다. 범위를 벗어나면 Exception발생
	 * get의 시간복잡도는 O(1)
	 * @param index
	 * @return d[index]
	 * @throws IndexOutOfBoundsException
	 */
	public int get(int index) throws IndexOutOfBoundsException {
		if (isEmpty() || index >= length) throw new IndexOutOfBoundsException();
		return d[index];
	}
	
	/**
	 * 배열의 해당 원소를 삭제한다. 범위를 벗어나면 Exception발생
	 * 보통의 삭제의 경우 배열의 크기를 축소하는 작업을 진행하기 때문에 모든 원소를 방문해야됨
	 * 시간복잡도는 O(N)
	 * @param index
	 * @throws IndexOutOfBoundsException
	 */
	public void remove(int index) {
		if (isEmpty() || index >= length) throw new IndexOutOfBoundsException();
		for(int i = index; i < length - 1; i++)
			d[i] = d[i + 1];
		d[--length] = 0;
	}
	
	/**
	 * 배열에 해당 원소가 있는지 검색하는 함수.
	 * 앞에서부터 순차적으로 검색하여 해당 원소를 포함하는지 여부를 조사한다.
	 * 최악의 경우 모든 원소를 검사하므로 시간복잡도는 O(n)
	 * @param num
	 * @return 찾으면 true, 없으면 false
	 */
	public boolean contains(int num) {
		if (isEmpty()) return false;
		for (int i = 0; i < length; i++) {
			if (d[i] == num) {
				return true;
			}
		}
		return false;
	}
	
	public static void main(String[] args) {
		ArrayList vec = new ArrayList();
		vec.add(2);
		vec.add(4);
		vec.add(6);
		vec.add(7);
		vec.print();
		vec.addIndexOf(2, 8);
		vec.print();
		vec.remove(3);
		vec.print();
	}
}
