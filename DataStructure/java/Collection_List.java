package test;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;

public class Collection_List {
	static class Node implements Comparable<Node> {
		int x;
		int y;

		public Node(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		// 비교 우선순위 오버라이딩
		public int compareTo(Node o) {
			return Integer.compare(this.x, o.x);
		}
		// 해시코드 오버라이딩
		public int hashCode() {
			return Integer.hashCode(x+y);
		}
		// Hash를 이용하기 위해서는 반드시 hashCode() + equals() 를 오버라이딩 하자
		public boolean equals(Object obj) {
			Node comp = (Node)obj;
			return (x == comp.x && y == comp.y);
		}

		public String toString() {
			return "(x=" + x + ", y=" + y + ")";
		}

	}

	public static void main(String[] args) {
		ArrayList<Node> arr = new ArrayList<>();
		/** 메서드 시간복잡도 정리
		 * get(i) : 	O(1)
		 * size() : 	O(1)
		 * add(i) : 	O(1)
		 * remove(i) : 	O(N)
		 * isEmpty(i) : O(1)
		 * contains(i) : O(N)
		 */
		arr.add(new Node(4, 5));
		arr.add(new Node(2, 2));
		arr.add(new Node(7, 3));
		arr.add(new Node(1, 9));
		arr.add(new Node(9, 1));
		arr.add(new Node(2, 7));
		Collections.sort(arr); // ArrayList는 컬렉션 소트,, 일반배열은 Arrays.sort
		System.out.println("ArrayList: " + arr);
		
		LinkedList<Node> ll = new LinkedList<>();
		/** DoublyLinkedList로 이루어져있다.
		 * 메서드 시간복잡도 정리
		 *  add(i) : 	O(1)
		 *  get(i) : 	O(N)
		 *  remove(i) : O(1)
		 *  
		 */
		ll.add(new Node(2, 3));
		ll.add(new Node(1, 9));
		ll.add(new Node(7, 6));
		ll.add(new Node(6, 1));
		ll.add(new Node(9, 3));
		ll.add(new Node(4, 2));
		ll.remove(2);
		System.out.println("LinkedList: " + ll);
		
		HashSet<Node> hs = new HashSet<>();
		/** 반드시!! HashCode와 equals를 오버라이딩 하자
		 * 메서드 시간복잡도 정리
		 * add(i) : 	 O(1)
		 * contains(i) : O(1)
		 * remove(i) : 	 O(1)
		 */
		hs.add(new Node(2, 3));
		hs.add(new Node(1, 9));
		hs.add(new Node(7, 6));
		hs.add(new Node(2, 3)); // 값 중복
		hs.add(new Node(3, 5));
		hs.add(new Node(2, 9));
		System.out.println("Hashset: " + hs);
		
		HashMap<Integer, Node> hm = new HashMap<>();
		/** 마찬가지로 key에 대한 equals와 hashcode 오버라이딩이 필요
		 * 메서드 시간복잡도 정리
		 * put(i,j) : O(1)
		 * contains(i) : O(1)
		 * remove(i) : O(1)
		 */
		hm.put(1, new Node(2,3));
		hm.put(0, new Node(2,3)); // value값은 똑같아도된다
		hm.put(1, new Node(3,5)); // key=1은 중복되서 덮어쓰기됨
		hm.put(5, new Node(2,3));
		hm.put(3, new Node(4,3));
		System.out.println("Hashmap: " + hm);
	}
}
