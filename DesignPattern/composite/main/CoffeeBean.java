package designpattern.composite;

class CoffeeBean extends CafeComposite{
    CoffeeBean(final String name, final int price) {
        super(name, price);
    }

    @Override
    public String typeOf() {
        return "CoffeeBean";
    }
}
