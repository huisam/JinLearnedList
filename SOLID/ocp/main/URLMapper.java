package solid.ocp;

public class URLMapper {
    public String mapping(String url) {
        if ("shopping.do".equals(url)) {
            return "shopping";
        } else if ("login.do".equals(url)) {
            return "login";
        } else if ("mypage.do".equals(url)) {
            return "mypage";
        } else if ("product.do".equals(url)) {
            return "product";
        }

        throw new IllegalArgumentException("해당하는 url이 없습니다");
    }

    public String urlMapping(String url) {
        return URL.matchOf(url)
                .getMatchResult();
    }
}
