package rtl;

public class NSString extends  NSObject {

    private String string;

    private NSString(String str) {
        string = str;
    }

    private NSString(NSString str) {
        string = str.string;
    }

    /**
     * Создание пустой строки. <br/>
     * + (id)string
     * */
    public static NSString stringStatic() {
        return new NSString("");
    }

    /**
     * Создание строки на основе строки c. <br/>
     * + (id)stringWithCString
     * */

    public static NSString stringWithCStringStatic(char[] s) {
        return new NSString(new String(s));
    }

    /**
     * Создание строки на основе другой строки. <br/>
     * + (id)stringWithString
     * */
    public static NSString stringWithStringStatic(NSString s) {
        return new NSString(s);
    }

    /**
     * Возвращает строку c, оканчивающуюся на 0-символ. <br/>
     * - (const char *)сString
     */
    public char[] cString() {
        char[] res = new char[string.length()+1];
        for (int i = 0; i < string.length(); i++) {
            res[i] = string.charAt(i);
        }
        res[string.length()] = '\0';
        return res;
    }

    /**
     * Возвращает строку ,где каждый символ после белого разделителя переводится в верхний регистр. <br/>
     * - (NSString *)capitalizedString
     * */
    public NSString capitalizeString() {
        String res = "";
        for (int i = 0; i < string.length(); i++) {
            if (i == 0 || Character.isWhitespace(string.charAt(i - 1))) {
                res += Character.toUpperCase(string.charAt(i));
            } else {
                res += string.charAt(i);
            }
        }
        return new NSString(res);
    }

    /**
     * Возвращает символ по индексу. <br/>
     * - (unichar)characterAtIndex
     * */
    public char characterAtIndex(int index) {
        return string.charAt(index);
    }

    /**
     * Возвращает результат проверки того, что строка начинается с prefix. <br/>
     * - (BOOL)hasPrefix
     * */
    public boolean hasPrefix(NSString prefix) {
        return string.startsWith(prefix.string);
    }

    /**
     * Возвращает результат проверки того, что строка заканчивается на suffix. <br/>
     * - (BOOL)hasSuffix
     * */
    public boolean hasSuffix(NSString suffix) {
        return string.endsWith(suffix.string);
    }

    public NSString init() {
        super.init();
        return this;
    }

    /**
     * Возвращает целое число. <br/>
     * - (int)intValue
     * */
    public int intValue() {
        return Integer.parseInt(string);
    }

    /**
     * Возвращает равенство строк. <br/>
     * - (BOOL)isEqual
     * */
    public boolean isEqual(NSObject other) {
        if (!(other instanceof NSString)) return false;
        return string.equals(((NSString)other).string);
    }

    @Override
    public boolean equals(Object other) {
        if (!(other instanceof NSString)) return false;
        return string.equals(((NSString)other).string);
    }

    /**
     * Возвращает равенство строк. <br/>
     * - (BOOL)isEqualString
     * */
    public boolean isEqualString(NSString other) {
        return string.equals(other.string);
    }

    /**
     * Возвращает длину строки. <br/>
     * - (NSUInteger)length
     * //TODO Заменить на NSInteger
     * */
    public int length() {
        return string.length();
    }

    /**
     * Возвращает строку в нижнем регистре. <br/>
     * - (NSString *)lowercaseString
     * */
    public NSString lowercaseString() {
        return new NSString(string.toLowerCase());
    }

    /**
     * Возвращает строку в верхнем регистре. <br/>
     * - (NSString *)uppercaseString
     * */
    public NSString uppercaseString() {
        return new NSString(string.toUpperCase());
    }

    /**
     * Возвращает новую строку с добавлением другой строки. <br/>
     * - (NSString *)stringByAppendingString
     * */
    public NSString stringByAppendingString(NSString other) {
        return new NSString(string + other.string);
    }

    public NSString description() {
        return new NSString(string);
    }

}
