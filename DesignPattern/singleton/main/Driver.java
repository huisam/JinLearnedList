package designpattern.singleton;

public enum Driver {
    INSTANCE;

    private final String name = "This is JDBC Driver";

    public String getName() {
        return name;
    }
}
