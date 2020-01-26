package designpattern.decorator;

abstract class ToppingDecorator extends Pizza {
    protected Pizza pizza;

    ToppingDecorator(final Pizza pizza) {
        this.pizza = pizza;
    }

    public abstract String getDescription();
}
