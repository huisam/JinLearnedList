package templatemethod;

import org.junit.jupiter.api.Test;

class PersonTest {
    @Test
    void 소년과_소녀가_제대로_나갈준비하는지_알아보자() {
        /* Given */
        Person boy = new Boy();
        Person girl = new Girl();

        /* Then */
        boy.readyToTrip();
        System.out.println("---------");
        girl.readyToTrip();
    }
}