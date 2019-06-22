package designpattern.factorymethod;

import java.util.HashMap;
import java.util.Map;
import java.util.function.Supplier;

public class CarFactory {
    private static Map<String, Supplier<Car>> cars;

    static {
        cars = new HashMap<>();
        cars.put("Kia", KiaCar::new);
        cars.put("Hyundai", HyundaiCar::new);
    }

    public static Car create(final String carName) {
        try {
            return cars.get(carName).get();
        } catch (NullPointerException e) {
            throw new IllegalArgumentException("해당하는 차가 없습니다!");
        }
    }
}
