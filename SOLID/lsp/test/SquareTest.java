package solid.lsp;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class SquareTest {
    @Test
    void 직사각형이_제대로_넓이를_구하는지_테스트() {
        /* Given */
        Rectangle rectangle = new Rectangle();
        /* When */
        rectangle.setHeight(4);
        rectangle.setWidth(5);
        /* Then */
        assertThat(rectangle.getArea()).isEqualTo(20);
    }

    @Test
    void 정사각형이_제대로_넓이를_구하는지_테스트() {
        /* Given */
        Rectangle rectangle = new Square();
        /* When */
        rectangle.setHeight(4);
        rectangle.setWidth(5);
        /* Then */
        assertThat(rectangle.getArea()).isEqualTo(20);
    }
}