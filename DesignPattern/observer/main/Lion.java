package observer;

public class Lion implements Observer {
    @Override
    public void update() {
        System.out.println("라이언: 콘텐츠 업데이트 받았어!");
    }
}
