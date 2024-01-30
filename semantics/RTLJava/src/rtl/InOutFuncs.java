package rtl;

public class InOutFuncs {

    //---------- Print Methods ----------
    public static void printIntStatic(int i) {
        System.out.println(i);
    }

    public static void printCharStatic(char c) {
        System.out.println(c);
    }

    public static void printNSStringStatic(NSString s) {
        System.out.println(s.toString());
    }

    public static void printCharArrayStatic(char[] s) {
        System.out.println(new String(s));
    }

    public static void printObjectStatic(Object o) {
        System.out.println(o);
    } //TODO Возможно стоит заменить на NSObject

    //---------- Read Methods ----------
    /**
     * Считывает строку с консоли
     * */
    public static String readStatic() {
        return  System.console().readLine();
    }

    /**
     * Считывает целое число с консоли
     * */
    public static int readIntStatic() {
        int res = 0;
        try {
            res = Integer.parseInt(readStatic());
        } catch (NumberFormatException e) {
            res = 0;
        }
        return res;
    }

    /**
     * Считывает символ с консоли
     * */
    public static char readCharStatic() {
        return  readStatic().charAt(0);
    }
}
