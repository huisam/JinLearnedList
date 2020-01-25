package designpattern.proxy;

public class RealInternet implements Internet {
    @Override
    public String connectTo(final String serverHost) {
        return "Connecting to " + serverHost;
    }
}
