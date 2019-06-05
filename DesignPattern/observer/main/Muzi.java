package observer;

public class Muzi implements Observer {
    @Override
    public void update() {
        System.out.println("무지: 콘텐츠 업데이트 받았어!");
    }
}
