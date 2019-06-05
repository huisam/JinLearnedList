package observer;

public interface Observable {
    void doSubscribe(Observer observer);

    void exitSubscribe(Observer observer);

    void alarmToAllObservers();
}
