package designpattern.adapter;

public class CarAdapter implements ToyCar {
    private final Car car;

    public CarAdapter(final Car car) {
        this.car = car;
    }

    @Override
    public String moveActionToCar() {
        return "Toy Car : " + car.drive();
    }
}
