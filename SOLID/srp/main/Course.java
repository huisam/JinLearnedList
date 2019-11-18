package solid.srp;

import java.util.Objects;

public class Course {
    private String name;

    public Course(final String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    void setName(final String name) {
        this.name = name;
    }

    @Override
    public boolean equals(final Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Course course = (Course) o;
        return Objects.equals(name, course.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name);
    }
}
