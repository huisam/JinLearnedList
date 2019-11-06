package designpattern.composite;

class Desk extends CafeComposite{
    Desk(final String name, final int price) {
        super(name, price);
    }

    @Override
    public String typeOf() {
        return "Desk";
    }
}
