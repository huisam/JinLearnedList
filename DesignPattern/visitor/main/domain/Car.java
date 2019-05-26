package visitor.domain;

import visitor.visitor.ViewVisitor;

public interface Car {
    int drive();

    int getFuel();

    String visit(ViewVisitor viewVisitor);
}
