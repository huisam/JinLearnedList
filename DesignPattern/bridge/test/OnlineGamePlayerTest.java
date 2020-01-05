package designpattern.bridge;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class OnlineGamePlayerTest {
    private GamePlayer gamePlayer;

    @Test
    void LOL이_올바르게_실행되는지_테스트() {
        /* Given */
        final PlayGameAPI LOL = new LOL();
        final String id = "Ashe";
        final String password = "ad";
        /* When */
        gamePlayer = new OnlineGamePlayer(LOL, id, password);
        /* Then */
        assertThat(gamePlayer.play()).isEqualTo("LOL Connect complete! [id=Ashe password=ad]");
    }

    @Test
    void Overwatch가_올바르게_실행되는지_테스트() {
        /* Given */
        final PlayGameAPI LOL = new Overwatch();
        final String id = "Ashe";
        final String password = "bob!!";
        /* When */
        gamePlayer = new OnlineGamePlayer(LOL, id, password);
        /* Then */
        assertThat(gamePlayer.play()).isEqualTo("Overwatch Connect complete! [id=Ashe password=bob!!]");
    }
}