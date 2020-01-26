package designpattern.decorator;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class CombinationPizzaTest {
    @Test
    @DisplayName("콤비네이션 피자 설명, 가격 테스트")
    void CombinationPizza_cost_test() {
        /* Given */
        Pizza combinationPizza = new CombinationPizza();
        /* Then */
        assertThat(combinationPizza.getDescription()).isEqualTo("CombinationPizza");
        assertThat(combinationPizza.getCost()).isEqualTo(12_000);
    }
}