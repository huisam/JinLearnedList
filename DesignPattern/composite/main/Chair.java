package designpattern.composite;

class Chair extends CafeComposite {
    Chair(final String name, final int price) {
        super(name, price);
    }

    @Override
    public String typeOf() {
        return "Chair";
    }
}
