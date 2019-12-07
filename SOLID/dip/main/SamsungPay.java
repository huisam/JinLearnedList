package solid.dip;

class SamsungPay implements Pay {
    @Override
    public String payment() {
        return "samsung";
    }
}
