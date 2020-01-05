package designpattern.bridge;

class LOL implements PlayGameAPI {
    @Override
    public String playGame(final String id, final String password) {
        return "LOL Connect complete! [id=" + id + " password=" + password + "]";
    }
}
