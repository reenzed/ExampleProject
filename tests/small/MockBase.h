#include <trompeloeil.hpp>

class Base {
public:
    virtual ~Base() = default;
    virtual void foo(int) = 0;
};

class MockBase : public Base {
public:
    MAKE_MOCK1(foo, void(int), override);
};
