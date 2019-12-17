package designpattern.command;

class MusicOnCommand implements Command {
    private final Music music;

    MusicOnCommand(final Music music) {
        this.music = music;
    }

    @Override
    public String execute() {
        return music.on();
    }
}
