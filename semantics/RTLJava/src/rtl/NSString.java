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
     * + (id)stringWithCString: (const char *)byteString
     * */

    public static NSString stringWithCStringStatic(char[] s) {
        return new NSString(new String(s));
    }

    /**
     * Создание строки на основе другой строки. <br/>
     * + (id)stringWithString: (NSString *)aString
     * */
    public static NSString stringWithStringStatic(NSString s) {
        return new NSString(s);
    }

    /**
     * Возвращает строку c, оканчивающуюся на 0-символ. <br/>
     * - (const char *)сString
     */
    public char[] cStringDynamic() {
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
    public NSString capitalizeStringDynamic() {
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
     * - (unichar)characterAtIndex: (NSUInteger)index
     * */
    public char characterAtIndexDynamic(int index) {
        return string.charAt(index);
    }

    /**
     * Возвращает результат проверки того, что строка начинается с prefix. <br/>
     * - (BOOL)hasPrefix: (NSString *)aString
     * */
    public int hasPrefixDynamic(NSString prefix) {
        return string.startsWith(prefix.string) ? 1 : 0;
    }

    /**
     * Возвращает результат проверки того, что строка заканчивается на suffix. <br/>
     * - (BOOL)hasSuffix: (NSString *)aString
     * */
    public boolean hasSuffixDynamic(NSString suffix) {
        return string.endsWith(suffix.string);
    }

    public NSString initDynamic() {
        super.initDynamic();
        return this;
    }

    /**
     * Возвращает целое число. <br/>
     * - (int)intValue
     * */
    public int intValueDynamic() {
        return Integer.parseInt(string);
    }

    /**
     * Возвращает равенство строк. <br/>
     * - (BOOL)isEqual: (id)anObject
     * */
    public int isEqualDynamic(NSObject other) {
        if (!(other instanceof NSString)) return 0;
        return string.equals(((NSString)other).string) ? 1 : 0;
    }

    @Override
    public boolean equals(Object other) {
        if (!(other instanceof NSString)) return false;
        return string.equals(((NSString)other).string);
    }

    /**
     * Возвращает равенство строк. <br/>
     * - (BOOL)isEqualToString: (NSString *)aString
     * */
    public int isEqualToStringDynamic(NSString other) {
        return string.equals(other.string) ? 1 : 0;
    }

    /**
     * Возвращает длину строки. <br/>
     * - (NSUInteger)length
     * //TODO Заменить на NSInteger
     * */
    public int lengthDynamic() {
        return string.length();
    }

    /**
     * Возвращает строку в нижнем регистре. <br/>
     * - (NSString *)lowercaseString
     * */
    public NSString lowercaseStringDynamic() {
        return new NSString(string.toLowerCase());
    }

    /**
     * Возвращает строку в верхнем регистре. <br/>
     * - (NSString *)uppercaseString
     * */
    public NSString uppercaseStringDynamic() {
        return new NSString(string.toUpperCase());
    }

    /**
     * Возвращает новую строку с добавлением другой строки. <br/>
     * - (NSString *)stringByAppendingString: (NSString *)aString
     * */
    public NSString stringByAppendingStringDynamic(NSString other) {
        return new NSString(string + other.string);
    }

    public NSString descriptionDynamic() {
        return new NSString(string);
    }

    @Override
    public String toString() {
        return string;
    }
}
