package strategy;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class ScissorTest {
    @Test
    void 가위를_제대로_내는지_테스트() {
        assertThat(new Scissor().submit()).isEqualTo("Scissor");
    }
}