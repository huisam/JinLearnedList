package designpattern.decorator;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class ToppingDecoratorTest {
    @Test
    @DisplayName("치즈피자에 토마토 토핑이 제대로 올라가는지 테스트")
    void FreshTomato_with_CheesePizza() {
        /* Given */
        Pizza cheesePizzaWithFreshTomato = new FreshTomato(new CheesePizza());
        /* Then */
        assertThat(cheesePizzaWithFreshTomato.getDescription()).isEqualTo("CheesePizza with FreshTomato");
        assertThat(cheesePizzaWithFreshTomato.getCost()).isEqualTo(10_300);
    }

    @Test
    @DisplayName("콤비네이션 피자에 올리브 토핑이 제대로 올라가는지 테스트")
    void Olive_with_CombinationPizza() {
        /* Given */
        Pizza combinationPizzaWithOlive = new Olive(new CombinationPizza());
        /* Then */
        assertThat(combinationPizzaWithOlive.getDescription()).isEqualTo("CombinationPizza with Olive");
        assertThat(combinationPizzaWithOlive.getCost()).isEqualTo(12_400);
    }
}