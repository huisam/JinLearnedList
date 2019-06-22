package designpattern.factorymethod;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.assertThrows;

class CarFactoryTest {
    @Test
    void 현대차를_제대로_생산하는지_테스트() {
        /* Then */
        assertThat(CarFactory.create("Hyundai").getCarName()).isEqualTo("Hyundai");
    }

    @Test
    void 기아차를_제대로_생산하는지_테스트() {
        /* Then */
        assertThat(CarFactory.create("Kia").getCarName()).isEqualTo("Kia");
    }

    @Test
    void 차가_없을때_예외인지_테스트() {
        assertThrows(IllegalArgumentException.class, () -> {
            CarFactory.create("Tesla");
        });
    }
}