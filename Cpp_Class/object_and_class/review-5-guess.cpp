#include <iostream>
#include <string>

class Test
{
private:
    std::string name;
    Test(Test&);
    Test& operator=(Test&);
public:
    Test();
    //Test(std::string n);            //  if only define this way, do C-Style init will OK
    //Test(std::string& n);           //  if only define this way, do C-Style init occurrence error
    //Test(std::string& n = "hello world");       //  error
    ~Test();
    void ShowName(void) const;
};

Test::Test()
{
    
}

Test::Test(std::string& n)
{
    name = n;
}

 void Test::ShowName(void) const
 {
     std::cout << name << std::endl;
 }

int main(void)
{
    Test t1{"hello world"};
}