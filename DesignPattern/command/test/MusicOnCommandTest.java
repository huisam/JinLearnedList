package designpattern.command;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class MusicOnCommandTest {
    @Test
    void 음악이_제대로_켜지는지_테스트() {
        /* Given */
        MusicOnCommand musicOnCommand = new MusicOnCommand(new Music());
        /* Then */
        assertThat(musicOnCommand.execute()).isEqualTo("play Music!!");
    }
}