package designpattern.proxy;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.assertThrows;

class ProxyInternetTest {
    private Internet internet;

    @BeforeEach
    void setUp() {
        internet = new ProxyInternet();
    }

    @Test
    @DisplayName("도메인이 올바르게 연결되는지 테스트")
    void proxy_internet_connecting_test() {
        /* Then */
        assertThat(internet.connectTo("naver.com")).isEqualTo("Connecting to naver.com");
    }

    @Test
    @DisplayName("접근금지인 도메인은 예외를 던지는지 테스트")
    void proxy_internet_ban_test() {
        /* Then */
        assertThrows(IllegalArgumentException.class, () -> internet.connectTo("abc.com"));
    }
}