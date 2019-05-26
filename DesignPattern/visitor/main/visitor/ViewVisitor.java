package visitor.visitor;

import visitor.domain.Bus;
import visitor.domain.Truck;

public interface ViewVisitor {
    String visit(Bus bus);

    String visit(Truck truck);
}
