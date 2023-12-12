@interface Myclass:NSObject
{
    int a[10], f;
    int d;
}
    int b = 5;
    int a[10];
    int c[20];
    + (int) func: (int) first :(int) second;
    @property (readonly) int f,e;
    @property int d;
@end

@implementation Myclass:NSObject
{
    int a[10], f;
    int d;
}
    int b;
    int a[10];
    + (int) func: (int) first :(int) second
    {
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

int main()
{
    int a;
    int b[10];
    Myclass*obj = [Myclass new];
    return 0;
}
