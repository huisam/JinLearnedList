package solid.isp;

public class Galaxy2 implements SmartPhone, Galaxy2Function {
    @Override
    public String telephone() {
        return "ring ring";
    }

    @Override
    public String internet() {
        return "connect complete!";
    }

    public String video() {
        return "play video";
    }
}
