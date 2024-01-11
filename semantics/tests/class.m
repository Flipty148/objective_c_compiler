@class Myclass, NSString, MyClass3;
@interface Myclass:NSObject
{
    int a[10], f;
    int d;
}
    int b = 5;
    NSString *str = @"abc";
    int a[10];
    int c[20];
    + (int) func: (int) first :(int) second;
    + (Myclass*) new;
@end

@implementation Myclass:NSObject
{
    int a[10], f;
    int d;
}
    int b;
    NSString *str;
    int a[10];
    + (int) func: (int) first :(int) second
    {
        int y = 44560;
        int test;
        for (int i = 0, j = 0; i < 10; i = i + 1)
        {
            a[i] = 0;
        }
        return first + second;
    }
    - (void) func2: (int) first :(int) second
    {
        int test[10];
        d = first + second;
    }
    + (Myclass*) new
    {

    }
@end

@implementation MyClass2 : NSObject
{
    int a,d[15];
    NSString *name;
}
@end

@implementation MyClass3 : MyClass2
{
    MyClass2 *obj;
    Myclass *obj1;
}
+ (void) funcMyClass3
{
    // 1=1 = [Myclass2 new];
    obj->a = 10;
    // 1+1->a;
}
-  func
{
    [obj1 func2: 't' :'a'];
}
@end

@implementation MyClass5 : NSObject

int a = 10;

@end

@implementation MyClass6 : MyClass5

+ (void) printA {
    a = 5;
}
@end

int main()
{
    int a;
    // int b[-10];
    // b = a;
    // b[@"str"] = 1;
    int t = 't';
    char c[] = "abc";
    NSString *st = @"NS";
    if ("abc" != "abc") return 0;
    Myclass* obj = [Myclass new];
    // int i;
    // for ( i in obj) {

    // }
    // for (NSString *str in st) {

    // }
    [Myclass func: 2 :3];
    obj->a;
    return 0;
}
