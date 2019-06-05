package observer;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class SubscriberTest {
    @Test
    void 컨텐츠가_제대로_등록되는지_확인() {
        /* Given */
        Subscriber subscriber = new Subscriber();

        /* When */
        subscriber.makeNewContents();

        /* Then */
        assertThat(subscriber.isNewContent()).isTrue();
    }
}