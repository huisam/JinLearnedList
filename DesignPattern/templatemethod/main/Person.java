package templatemethod;

public abstract class Person {
    // Template Method
    public void readyToTrip() {
        makeUp();
        dressUp();
        System.out.println("ready : 밖으로 나가자!");
        System.out.println("ready : 여행 준비가 끝났어!!");
    }

    // Hook Method
    void dressUp() {
        System.out.println("dressUp : 속옷을 입자!");
    }

    // abstract Method
    protected abstract void makeUp();
}
