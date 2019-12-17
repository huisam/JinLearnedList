package designpattern.command;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class RemoteControllerTest {
    private RemoteController controller;

    @BeforeEach
    void setUp() {
        controller = new RemoteController();
    }

    @Test
    void 리모컨이_제대로_동작하는지_테스트() {
        /* Given */
        MusicOffCommand musicOffCommand = new MusicOffCommand(new Music());
        /* When */
        controller.setCommand(musicOffCommand);
        /* Then */
        assertThat(controller.pressButton()).isEqualTo("play off Music!!");
    }

    @Test
    void 리모컨에서_음악이_꺼지는지_테스트() {
        /* Given */
        MusicOnCommand musicOnCommand = new MusicOnCommand(new Music());
        /* When */
        controller.setCommand(musicOnCommand);
        /* Then */
        assertThat(controller.pressButton()).isEqualTo("play Music!!");
    }
}