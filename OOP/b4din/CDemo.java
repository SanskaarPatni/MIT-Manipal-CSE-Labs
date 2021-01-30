class C<T>
{
T data;
C(T t) { data = t; }
}
class CDemo
{
public static void main(String[] args)
{
C<String> co = new C<String>("Hi");
C<Integer> ci = new C<>(44);
C<Integer> csi = new C<Integer>(44);
C<Integer> cip = new C<Integer>(3);
C<String> cs = new C<String>("Hi");
String[ ] s = {"a", "b", "c"};
C < String [ ] > csa = new C <String [ ] >(s);
}
}