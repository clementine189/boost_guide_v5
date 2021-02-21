#include "../common/std.hpp"
using namespace std;

#include <boost/smart_ptr.hpp>
#include <boost/smart_ptr/make_unique.hpp>
using namespace boost;

//测试1：scoped_ptr的基本使用
void case1()
{
    cout << endl << "case1:" << endl;
    scoped_ptr<string> sp(new string("scoped_ptr"));
    assert(sp);
    assert(sp != nullptr);

    cout << "*sp  = " <<*sp << endl;
    cout << "size = " << sp->size() << endl;

}

//测试2：scoped_ptr的使用
struct posix_file
{
    posix_file(const char* filename)
    {
        cout << "open file " << filename << endl;
    }

    ~posix_file()
    {
        cout << "close file." << endl;
    }
};

void case2()
{
    scoped_ptr<posix_file> fp(new posix_file("/tmp/a.txt"));

    scoped_ptr<int> p(new int);

    if (p)
    {
        *p = 100;
        cout << *p << endl;
    }

    p.reset();

    assert(p == 0);
    if (!p)
    {   cout << "scoped_ptr == nullptr" << endl;   }

}

//测试3：make_unique工厂函数
void case_unique()
{
    auto p = boost::make_unique<int>(10);

    assert(p && *p == 10);

    p.release();
    assert(!p);

    auto a = boost::make_unique<int[]>(5);

    a[0] = 100;
    a[4] = 500;
    //a[5] = 1000;
}

int main()
{
    case1();
    case2();
    case_unique();
    return 0;
}

