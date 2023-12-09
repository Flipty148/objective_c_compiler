@interface Myclass:NSObject
{
    int a[10], c;
}
    int b = 5;
    int a[10];
    int c[20];
    + (int) func: (int) first :(int) second;
@end

@implementation Myclass:NSObject
{
    int a[10], c;
}
    int b;
    int a[10];
    + (int) func: (int) first :(int) second
    {
        int test;
        return first + second;
    }
    - (void) func2: (int) first :(int) second
    {
        int test;
        c = first + second;
    }
@end

@implementation MyClass2
{
    int a,d[15];
}
@end

@implementation MyClass3
@end
