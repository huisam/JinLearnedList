package designpattern.decorator;

abstract class Pizza {
    protected String description = "Original Pizza";

    public String getDescription() {
        return description;
    }

    public abstract int getCost();
}
