package designpattern.composite;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Cafe {
    private List<CafeComposite> composites;

    public Cafe() {
        composites = new ArrayList<>();
    }

    public void addComposite(final CafeComposite composite) {
        composites.add(composite);
    }

    public int getCafeTotalPrice() {
        return composites.stream()
                .mapToInt(CafeComposite::getPrice)
                .sum();
    }

    public String getCafeCompositeName() {
        return composites.stream()
                .map(CafeComposite::getName)
                .collect(Collectors.joining("\n"));
    }

    public void clearAllComposite() {
        composites.clear();
    }
}
