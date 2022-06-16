//鍑芥暟閲嶈浇锛屽彲浠ヨ鍑芥暟鍚嶇浉鍚岋紝鎻愰珮澶嶇敤鎬с�?
// 鍑芥暟閲嶈浇婊¤冻鏉′欢
// 1銆佸悓涓�涓綔鐢ㄥ煙涓? 2銆佸嚱鏁板悕绉扮浉鍚? 3銆? 鍑芥暟鐨勫弬鏁扮被鍨嬩笉鍚屾垨鑰呬釜鏁颁笉鍚屾垨鑰呴『搴忎笉鍚?

#include <iostream>
using namespace std;
void func()
{
    cout << "func()函数调用" << endl;
}

// void func(int a = 10)
// {
//     cout << "func(int a = 10)函数调用" << endl;
// }
void func(int a)
{
    cout << "func(int a函数调用" << endl;
}
void func(int a, double b)
{
    cout << "func(int a, double b)函数调用" << endl;
}
void func(double a, double b)
{
    cout << "func(double a, double b)函数调用" << endl;
}


int main()
{   
    func(10.1, 3);
    system("pause");
    return 0;

}