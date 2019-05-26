package visitor.domain;

import org.junit.jupiter.api.Test;
import visitor.visitor.CarViewVisitor;

import static org.assertj.core.api.Assertions.assertThat;

class BusTest {
    @Test
    void 버스가_운전하고_상태를_제대로_출력하는지_테스트() {
        /* Given */
        Bus bus = new Bus(10);
        /* When */
        bus.drive();
        /* Then */
        assertThat(bus.getFuel()).isEqualTo(9);
        assertThat(bus.visit(new CarViewVisitor())).isEqualTo("현재 버스의 기름 상태 : 9");
    }
}