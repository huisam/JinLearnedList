package solid.dip;

public class KakaoPay implements Pay {
    @Override
    public String payment() {
        return "kakao";
    }
}
