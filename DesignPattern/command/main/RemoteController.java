package designpattern.command;

public class RemoteController {
    private Command command;

    public void setCommand(final Command command) {
        this.command = command;
    }

    public String pressButton() {
        return command.execute();
    }
}
