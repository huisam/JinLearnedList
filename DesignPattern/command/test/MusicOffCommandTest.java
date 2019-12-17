package designpattern.command;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class MusicOffCommandTest {
    @Test
    void 음악이_제대로_꺼지는지_테스트() {
        /* Given */
        MusicOffCommand musicOffCommand = new MusicOffCommand(new Music());
        /* Then */
        assertThat(musicOffCommand.execute()).isEqualTo("play off Music!!");
    }
}