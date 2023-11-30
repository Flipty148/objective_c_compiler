@interface Myclass:NSObject
{
    int a;
}
    int b;
    + (int) func: (int) first :(int) second;
@end

@implementation Myclass:NSObject
{
    int a;
}
    int b;
    + (int) func: (int) first :(int) second
    {
        return first + second;
    }
@end
