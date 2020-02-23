package designpattern.templatecallback;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class PlayerTest {
    private Player player;

    @BeforeEach
    void setUp() {
        this.player = new Player();
    }

    @Test
    @DisplayName("플레이어가 가위를 제대로 내는지 테스트")
    void scissor_test() {
        /* Given */
        RockScissorPaper strategy = () -> "Scissor";
        /* Then */
        assertThat(player.play(strategy)).isEqualTo("Scissor");
    }

    @Test
    @DisplayName("플레이어가 가위를 제대로 내는지 테스트")
    void rock_test() {
        /* Given */
        RockScissorPaper strategy = () -> "Rock";
        /* Then */
        assertThat(player.play(strategy)).isEqualTo("Rock");
    }

    @Test
    @DisplayName("플레이어가 가위를 제대로 내는지 테스트")
    void paper_test() {
        /* Given */
        RockScissorPaper strategy = () -> "Paper";
        /* Then */
        assertThat(player.play(strategy)).isEqualTo("Paper");
    }
}