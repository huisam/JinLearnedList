package designpattern.command;

class MusicOffCommand implements Command {
    private final Music music;

    MusicOffCommand(final Music music) {
        this.music = music;
    }

    @Override
    public String execute() {
        return music.off();
    }
}
