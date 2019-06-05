package observer;

import java.util.ArrayList;
import java.util.List;

public class Subscriber implements Observable {

    private final List<Observer> observers = new ArrayList<>();
    private boolean newContent;

    public void makeNewContents() {
        newContent = true;
    }

    public boolean isNewContent() {
        return newContent;
    }

    @Override
    public void doSubscribe(final Observer observer) {
        observers.add(observer);
    }

    @Override
    public void exitSubscribe(final Observer observer) {
        observers.remove(observer);
    }

    @Override
    public void alarmToAllObservers() {
        observers.forEach(Observer::update);
    }
}
