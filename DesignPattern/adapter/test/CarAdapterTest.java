package designpattern.adapter;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class CarAdapterTest {
    @Test
    void 장난감_현대차가_제대로_동작하는지_확인() {
        /* Given */
        Car car = new HyundaiCar();
        ToyCar toyCar = new CarAdapter(car);

        /* Then */
        assertThat(toyCar.moveActionToCar()).isEqualTo("Toy Car : Broong Broong");
    }

    @Test
    void 장난감_기아차가_제대로_동작하는지_확인() {
        /* Given */
        Car car = new KiaCar();
        ToyCar toyCar = new CarAdapter(car);

        /* Then */
        assertThat(toyCar.moveActionToCar()).isEqualTo("Toy Car : Go Go");
    }
}