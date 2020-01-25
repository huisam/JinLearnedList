package designpattern.proxy;

import com.google.common.collect.Lists;

import java.util.List;

public class ProxyInternet implements Internet {
    private static List<String> bannedSite = Lists.newArrayList("abc.com", "def.com", "ijk.com");
    private Internet internet = new RealInternet();

    @Override
    public String connectTo(final String serverHost) {
        if (bannedSite.contains(serverHost.toLowerCase())) {
            throw new IllegalArgumentException(String.format("해당하는 호스트는 접근이 불가능합니다 : %s", serverHost));
        }

        return internet.connectTo(serverHost);
    }
}
