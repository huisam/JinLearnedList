package abstractfactory;

public class ShapeFactory {

    enum ShapeType {
        CIRCLE("Circle") {
            @Override
            Shape create() {
                return new Circle();
            }
        },
        RECTANGLE("Rectangle") {
            @Override
            Shape create() {
                return new Rectangle();
            }
        };

        private final String type;

        ShapeType(String type) {
            this.type = type;
        }

        abstract Shape create();
    }

    public static Shape create(final String message) {
        return ShapeType.valueOf(message)
                .create();
    }
}
