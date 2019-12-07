package solid.dip;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class PayServiceTest {
    private PayService payService = new PayService();

    @Test
    void 삼성페이가_올바르게_결제되는지_테스트() {
        /* Given */
        Pay samsungPay = new SamsungPay();
        /* When */
        payService.setPay(samsungPay);
        /* Then */
        assertThat(payService.payment()).isEqualTo("samsung");
    }

    @Test
    void 카카오페이가_올바르게_결제되는지_테스트() {
        /* Given */
        Pay kakaoPay = new KakaoPay();
        /* When */
        payService.setPay(kakaoPay);
        /* Then */
        assertThat(payService.payment()).isEqualTo("kakao");
    }
}