package solid.lsp;

public class Square extends Rectangle {
    @Override
    public void setWidth(final double width) {
        this.height = width;
        this.width = width;
    }

    @Override
    public void setHeight(final double height) {
        this.height = height;
        this.width = height;
    }
}
