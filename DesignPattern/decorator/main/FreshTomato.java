package designpattern.decorator;

class FreshTomato extends ToppingDecorator {
    public FreshTomato(final Pizza pizza) {
        super(pizza);
    }

    @Override
    public String getDescription() {
        return pizza.description + " with FreshTomato";
    }

    @Override
    public int getCost() {
        return 300 + pizza.getCost();
    }
}
