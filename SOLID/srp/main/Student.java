package solid.srp;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Student {
    private List<Course> courses;

    public Student() {
        courses = new ArrayList<>();
    }

    public void chooseCourse(final Course course) {
        courses.add(course);
    }

    public void modifyCourse(final Course course, final String courseName) {
        courses.stream()
                .filter(schoolCourse -> schoolCourse.equals(course))
                .forEach(schoolCourse -> schoolCourse.setName(courseName));
    }

    public void modifyCourse(final Course course, final Course modifidedCourse) {
        courses.remove(course);
        courses.add(modifidedCourse);
    }

    public List<Course> getCourses() {
        return Collections.unmodifiableList(courses);
    }
}
