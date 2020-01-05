package designpattern.bridge;

class OnlineGamePlayer extends GamePlayer {
    private final String id;
    private final String password;

    public OnlineGamePlayer(final PlayGameAPI playGameAPI, final String id, final String password) {
        super(playGameAPI);
        this.id = id;
        this.password = password;
    }

    @Override
    public String play() {
        return playGameAPI.playGame(id, password);
    }
}
