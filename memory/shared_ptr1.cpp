#include "../common/std.hpp"
#include <exception>

#include <boost/smart_ptr.hpp>
using namespace boost;

//测试1：shared_ptr
void case1()
{
    shared_ptr<int> spi(new int);
    assert(spi);
    *spi = 66;

    shared_ptr<std::string> sps(new std::string("smart"));
    assert(sps->size() == 5);
 
}

//测试2：shared_ptr的动态指针转换与静态指针转换
void case2()
{
    typedef shared_ptr<std::string> sp_t;//shared_ptr可以放入容器中
    std::map<sp_t, int> m;

    sp_t sp(new std::string("one"));
    m[sp] = 111;


    shared_ptr<std::exception> sp1(new std::bad_exception());//用一个基类指针，创建一个子类对象

    auto sp2 = dynamic_pointer_cast<std::bad_exception>(sp1);
    auto sp3 = static_pointer_cast<std::exception>(sp2);

    assert(sp3 == sp1);



}

int main()
{
    case1();
    case2();

    return 0;
}