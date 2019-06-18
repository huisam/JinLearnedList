package abstractfactory;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class ShapeFactoryTest {
    @Test
    void 도형을_제대로_생산하는지_확인() {
        /* Then */
        assertThat(ShapeFactory.create("CIRCLE").getType()).isEqualTo("Circle");
        assertThat(ShapeFactory.create("RECTANGLE").getType()).isEqualTo("Rectangle");
    }
}