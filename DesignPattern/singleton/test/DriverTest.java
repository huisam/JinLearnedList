package designpattern.singleton;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class DriverTest {
    @Test
    void 단일_객체를_보장하는지_테스트() {
        /* Given */
        Driver driver1 = Driver.INSTANCE;
        Driver driver2 = Driver.INSTANCE;

        /* Then */
        assertThat(driver1).isEqualTo(driver2);
    }
}