- 什么是类？
  类是C++用来实现抽象的一种工具。

- 类如何实现抽象、封装和数据隐藏？
  类通过提取抽象的数据特征和行为特征，然后分别使用对应的数据类型和函数来实现。类是一个独立的空间，类被设计之初就是用来保护和隐藏数据的，所以类中的数据没有特别说明都是隐藏状态的，但是为了强调数据的隐藏状态，可以通过private关键字来实现。类与外界交互使用的是public关键字所开放的数据或者方法，内部具体实现外界是无法得知的。

- 对象与类的概念？
  类只是表明了组成该类所需要的数据类型以及相应的函数，而对象是类的具体实现。类不是实际存在的，而对象确是实际存在的。

- 除了是函数之外，类函数成员与类数据成员之间的区别是什么？
  

- 定义一个类来表示银行账户。数据成员包括存储姓名，账号和存款。成员函数执行如下操作：
  - 创建一个对象并将其初始化
  - 显示储户姓名、账号和存款
  - 存入参数指定的款项
  - 取出参数指定的款项
  
  ```c++{.line-numbers}
  #include <string>
  class Account
  {
    private:
        std::string name;
        std::string ID;
        double balance;
        Account(Account& a);
        Account& operator=(Account& a);
    public:
        //Account(std::string& n = "None", std::string& i = "None", double b = 0.0);    error
        Account(const char* n = "None", const char* i = "None", double b = 0.0);
        Account(std::string& n, std::string& i, double b);

        ~Account() {}
        void ShowINFO(void) const;
        bool Withdraw(double m);
        bool Deposit(double m);
  }
  ```

插入一点，在定义上述类时，我想到了一个问题：如果我类的构造函数的参数是string类的引用，我是用c风格的字符串来初始化会有什么问题吗?
1,默认参数如果这样填写 ———— std::string& a = "aaa",这样是不被允许的，因为右边是一个C风格的字符串，并不是string类的一个对象，所以说它是一个没有string实体的参数，因为没有实体，所以不能使用引用符号。
2，构造函数中如果参数是string类的引用 ———— 同样不能够使用C风格字符串来初始化，原因同上。

- 类构造函数在何时被调用？类析构函数呢？
  在使用类声明一个对象是就会调用类的构造函数，在该程序执行到对象的作用域之外时，会调用对象的析构函数。

- 什么是默认构造函数，拥有默认构造函数有什么好处？
  拥有默认构造函数是由类设计的初衷所决定的，因为类是不同于结构体，所以必须要存在一个初始化函数，而类构造函数承担了这项任务。构造函数对于类来说是必不可少的，如果程序员没有编写，编译器将会提供，这是由C++的语法决定的。

- this与*this
  this是该对象的地址，而*this为该对象