@class Myclass, NSString;
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
    @property (readonly) int f,e;
    @property int d;
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
        for (int i = 0; i < 10; i++)
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

@implementation MyClass2
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
    obj->a = 10;
}
- (void) func
{
    [obj1 func2: 1 :2];
}
@end

int main()
{
    int a;
    int b[10];
    NSString *st = @"NS";
    if ("abc" != "abc") return 0;
    Myclass* obj = [Myclass new];
    [Myclass func: 2 :3];
    obj->a;
    return 0;
}
