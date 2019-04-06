package study;

/**
 * Java의 모든 것을 파헤쳐보자!
 * 1.객체 , 인스턴스의 차이? : 
 * 객체는 소프트웨어에 구현할 대상, 인스턴스는 클래스가 실제화 되었을때
 * 메모리에 할당된 실제화된 인스턴스 = 객체
 * 
 * 2.Call by value, Call by Reference의 차이? :
 * Java는 기본적으로 Call by value다. = 값만 넘겨준다.
 * 다만!!!! 참조자료형(클래스,배열)은 해당 변수가 가지는 주소값을 복사하여 전달한다!
 * 그 외의 기본자료형(int,char)는 해당 변수의 값만 넘겨준다!
 * @author huisam
 *
 */
public class InstanceFunction {

	static class Person {
		private String name;

		public Person(String name) {
			this.name = name;
		}

		public String getName() {
			return name;
		}

		public void setName(String name) {
			this.name = name;
		}

	}

	public static void setPersonName(Person p) {
		p.setName("nonono");
	}

	public static void newPerson(Person p) {
		p = new Person("new people"); // newPerson 영역 내에서만 유효
	}

	public static Person upgradeNewPerson(Person p) {
		return new Person("upgrade!!");
	}

	public static void main(String[] args) {
		Person p; // 객체 생성
		p = new Person("go"); // 인스턴스 생성

		newPerson(p); // Call by value
		System.out.println(p.getName()); // go
		// why? -> newPerson 메소드 내에서 새로운 인스턴스를 생성해도
		// 해당 stack영역 내에만 인스턴스 주소값을 참조하기 때문
		// 이것을 해결하기 위해서는 리턴값으로 받아야 함!
		
		p = upgradeNewPerson(p);
		System.out.println(p.getName()); // upgrade!!
		
		setPersonName(p); // Call by reference
		System.out.println(p.getName()); // nonono
	}
}
