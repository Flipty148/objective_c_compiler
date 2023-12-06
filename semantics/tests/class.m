@interface Myclass:NSObject
{
    int a[10], c;
}
    int b;
    + (int) func: (int) first :(int) second;
@end

@implementation Myclass:NSObject
{
    int a[10], c;
}
    int b;
    + (int) func: (int) first :(int) second
    {
        return first + second;
    }
@end

@implementation MyClass2
@end
