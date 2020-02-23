package designpattern.templatecallback;

class Player {
    String play(final RockScissorPaper strategy) {
        return strategy.submit();
    }
}
