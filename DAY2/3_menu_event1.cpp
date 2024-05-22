#include <iostream>
#include <algorithm>
#include <functional>

// 4항 함수
void foo( int a, int b, int c, int d)
{
    printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
    foo(1,2,3,4);   // 4항 함수..

    // std::bind : 인자의 값을 고정한 새로운 함수를 만드는 도구

    // 사용법 : std::bind( M항함수주소, M개 인자)

    auto f1 = std::bind(&foo, 1, 2, 3, 4);

    f1(); // foo(1,2,3,4) 의 의미.  즉, 4항 함수 => 0항 함수로


    auto f2 = std::bind(&foo, 3, _1, 7, _2);

    f2(8, 4);
}

