package observer;

import org.junit.jupiter.api.Test;

public class ObserverTest {
    @Test
    void Observer가_제대로_작동하는지_확인() {
        /* Given */
        Subscriber subscriber = new Subscriber();
        Observer lion = new Lion();
        Observer muzi = new Muzi();

        /* When */
        subscriber.doSubscribe(lion);
        subscriber.doSubscribe(muzi);
        subscriber.makeNewContents();
        subscriber.alarmToAllObservers();

        subscriber.exitSubscribe(muzi);
        subscriber.alarmToAllObservers();
        /* Then */
    }
}
