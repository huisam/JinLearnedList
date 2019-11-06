package designpattern.composite;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class CafeTest {
    private Cafe cafe;

    @BeforeEach
    void setUp() {
        cafe = new Cafe();
    }

    @Test
    void 카페에_있는_물건들의_총합이_올바른지_테스트() {
        /* Given */
        Chair chair = new Chair("No1.chair", 3000);
        Desk desk = new Desk("No1.desk", 2000);
        CoffeeBean coffeeBean = new CoffeeBean("Columbia", 300);
        /* When */
        cafe.addComposite(chair);
        cafe.addComposite(desk);
        cafe.addComposite(coffeeBean);
        /* Then */
        assertThat(cafe.getCafeTotalPrice()).isEqualTo(5300);
    }

    @Test
    void 카페에_있는_물건들의_이름이_올바른지_테스트() {
        /* Given */
        Chair chair = new Chair("No1.chair", 3000);
        Desk desk = new Desk("No1.desk", 2000);
        CoffeeBean coffeeBean = new CoffeeBean("Columbia", 300);
        /* When */
        cafe.addComposite(chair);
        cafe.addComposite(desk);
        cafe.addComposite(coffeeBean);
        /* Then */
        assertThat(cafe.getCafeCompositeName()).isEqualTo("No1.chair\nNo1.desk\nColumbia");
    }

    @AfterEach
    void tearDown() {
        cafe.clearAllComposite();
    }
}