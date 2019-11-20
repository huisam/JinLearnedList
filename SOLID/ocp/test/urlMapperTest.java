package solid.ocp;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.assertThrows;

class urlMapperTest {
    @Test
    void url이_올바르게_매핑되는지_테스트() {
        /* Given */
        URLMapper urlMapper = new URLMapper();
        /* Then */
        assertThat(urlMapper.mapping("login.do")).isEqualTo("login");
        assertThat(urlMapper.mapping("mypage.do")).isEqualTo("mypage");
        assertThat(urlMapper.mapping("product.do")).isEqualTo("product");
        assertThat(urlMapper.mapping("shopping.do")).isEqualTo("shopping");
        assertThrows(IllegalArgumentException.class, () -> {
            urlMapper.mapping("nono.do");
        });
    }

    @Test
    void url이_올바르게_매핑되는지_테스트2() {
        /* Given */
        URLMapper urlMapper = new URLMapper();
        /* Then */
        assertThat(urlMapper.urlMapping("login.do")).isEqualTo("login");
        assertThat(urlMapper.urlMapping("mypage.do")).isEqualTo("mypage");
        assertThat(urlMapper.urlMapping("product.do")).isEqualTo("product");
        assertThat(urlMapper.urlMapping("shopping.do")).isEqualTo("shopping");
        assertThrows(IllegalArgumentException.class, () -> {
            urlMapper.urlMapping("nono.do");
        });
    }
}