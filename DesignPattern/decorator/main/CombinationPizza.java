package designpattern.decorator;

class CombinationPizza extends Pizza {
    public CombinationPizza() {
        this.description = "CombinationPizza";
    }

    @Override
    public int getCost() {
        return 12_000;
    }
}
