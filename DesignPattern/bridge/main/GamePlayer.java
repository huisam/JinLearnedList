package designpattern.bridge;

abstract class GamePlayer {
    protected PlayGameAPI playGameAPI;

    public GamePlayer(final PlayGameAPI playGameAPI) {
        this.playGameAPI = playGameAPI;
    }

    public abstract String play();
}
