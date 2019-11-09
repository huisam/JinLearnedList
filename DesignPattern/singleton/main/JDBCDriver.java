package designpattern.singleton;

public class JDBCDriver {
    private static JDBCDriver ourInstance = new JDBCDriver();

    private JDBCDriver() {
    }

    public static JDBCDriver getInstance() {
        return ourInstance;
    }
}
