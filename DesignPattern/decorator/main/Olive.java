package designpattern.decorator;

class Olive extends ToppingDecorator {
    public Olive(final Pizza pizza) {
        super(pizza);
    }

    @Override
    public String getDescription() {
        return pizza.description + " with Olive";
    }

    @Override
    public int getCost() {
        return 400 + pizza.getCost();
    }
}
