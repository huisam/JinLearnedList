package solid.ocp;

import java.util.Arrays;

public enum URL {
    SHOPPING("shopping.do", "shopping"),
    LOGIN("login.do", "login"),
    MY_PAGE("mypage.do", "mypage"),
    PRODUCT("product.do", "product");

    private final String url;
    private final String matchResult;

    URL(final String url, final String matchResult) {
        this.url = url;
        this.matchResult = matchResult;
    }

    public static URL matchOf(String url) {
        return Arrays.stream(values())
                .filter(urls -> urls.match(url))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("해당하는 url이 없습니다"));
    }

    private boolean match(final String url) {
        return this.url.equals(url);
    }

    public String getMatchResult() {
        return matchResult;
    }
}
