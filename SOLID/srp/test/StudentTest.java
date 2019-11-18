package solid.srp;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.assertj.core.api.Assertions.assertThat;

class StudentTest {
    @Test
    void 학생이_과목을_올바르게_변경하는지_테스트_1번_케이스() {
        /* Given */
        Student student = new Student();
        Course math = new Course("math");
        Course english = new Course("english");
        Course computer = new Course("computer");
        List<Course> courses = Arrays.asList(math, computer);
        /* When */
        student.chooseCourse(math);
        student.chooseCourse(english);
        student.modifyCourse(english, "computer");
        /* Then */
        assertThat(student.getCourses()).isEqualTo(courses);
        assertThat(english.getName()).isEqualTo("english");
    }

    @Test
    void 학생이_과목을_올바르게_변경하는지_테스트_2번_케이스() {
        /* Given */
        Student student = new Student();
        Course math = new Course("math");
        Course english = new Course("english");
        Course computer = new Course("computer");
        List<Course> courses = Arrays.asList(math, computer);
        /* When */
        student.chooseCourse(math);
        student.chooseCourse(english);
        student.modifyCourse(english, computer);
        /* Then */
        assertThat(student.getCourses()).isEqualTo(courses);
        assertThat(english.getName()).isEqualTo("english");
    }
}