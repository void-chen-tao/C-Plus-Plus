##  description
今天在测试自己编写的一个类时，在返回值时总是遇到*error: cannot bind non-const lvalue reference of type 'Complex&' to an rvalue of type 'Complex'*

##  mycode



##  lvalue and rvalue in C language
- **L-value**:
  "l-value" refers to *memory location which identifies an object*. l-value may appear as either left hand or right hand side of an assignment operator(=). l-value often represents as identifier.

  Expressions referring to modifiable locations are called "modifiable l-values". A modifiable l-value cannot have an array type, an incomplete type, or a type with the **const** attribute. For structures and unions to be modifiable **lvalues**, they must not have any members with the **const** attribute. The name of the identifier denotes a storage location,while the value of the variable is the value stored at that location.

  An identifier is a modifiable **lvalue** if it refers to a memory location and if its type is arithmetic, structure, union, or pointer. For example, if ptr is a pointer to a storage region, then *ptr is a modifiable l-value that designates the storage region to which **ptr** points.

  in C, the concept was renamed as **locator value**, and referred to expressions that locate (designate) objects. The l-value is one of the following:
  1.The name of the variable of any type i.e, an identifier of integral, floating, pointer, structure, or nuion type.
  2.A subscript([]) expression that does not evaluate to an array.
  3.A unary-indirection(*) expression that does not refer to an array
  4.An l-value expression in parenthese.
  5.A **const** object (a nonmodifiable l-value).
  6.The result of indirection through a pointer, provided that it isn't a function pointer.
  7.The result of member access through pointer(->or.)


- **R-value**：
  "r-value" refers to *data value that is stored at some address in memory*. A r-value is an expression that can't have a value assigned to it which means r-value can appear on right but not on left hand side of an assignment operator(=)


--------------------------

- 左值
  "左值"指的是一个对象确定的存储空间地址。"左值"可以出现在赋值操作符(=)的左边或者是右边。通常标识符(变量名)用来表示"左值"

  如果在表达式中使用了可以修改的存储空间，则称该空间为“可修改的左值”。一个可以修改的左值不能是数组类型，不完整的类型或者是拥有**常量**性质的类型。如果是一个可修改的结构体或者联合,该结构体或联合中的所有成员都不能拥有**const**性质。标识符的名称表明了存储空间的位置,该存储空间存储的值就是该变量的值。
  
  一个标识符如果指明了内存空间同时具有算术、结构体、联合、指针类型，则该标识符就是一个可修改的左值。例如，ptr是一个存储区域，那么*ptr就是一个可修改的左值，因为它表明了ptr所指向的存储空间。

  在C语言的名称中上述概念被重命名为了“locator value”(定位符)，定位符是定位对象的一个表达式。下面的都是左值：
  1、任意类型的变量名
  2、带下标表达式的数组
  3、一个不直接指向数组的取值表达式(*)
  4、圆括号中的左值表达式
  5、一个const对象(一个不可修改的左值)
  6、指针的间接访问
  7、成员的间接访问

- 右值
  右值是存储在某个位置的**数据**，右值不能通过复制运算符向右值赋值。(因为我不知道右值的地址到底在哪儿)

- 总结：
  左值是存储空间地址已知的**内存**；右值是存储空间地址未知的**数据**。


##  References in C++
- Reference
  When a variable is declared as a reference, it becomes an alternative name for an existiong variable. A variable can be declared as a reference by putting '&' in the declaration.

- Applications
  1.Modify the passed parameters in a function: if a function receives a reference to a variable, it can modify the value of the variable. For example, the following program varables are swapped using references.
  2.Avoiding a copy of large structures:Imagine a function that has to receive a large object. If we pass it without reference, a new copy of it is created which causes wastage of CPU time and memory. We can use references to avoid this.
  3.In For Each Loops to modify all objects: We can use references in for each loops to modify all elements.
  4.For Each Loop to avoid the copy of objects: We can use references in each loop to avoid a copy of individual objects when objects are large

- 引用
  当一个变量被声明为了引用，该变量就成了存在变量的可替换的名称。可以通过操作符&实现引用的声明。

- 引用的应用
  1、修改函数中传递的参数：如果一个函数接收了一个引用变量，该函数内部就能修改该变量的值。
  2、避免了复制大量的数据————造成的CPU和内存的浪费
  3、可以直接通过循环来修改所有的对象
  4、避免了每次循环在复制依次对象

- References VS Pointers:
  Both references and pointers can be used to change local variables of one function inside another function. Both of them can also be used to save copying of big objects when passed as arguments to functions or returned from functions, to get efficiency gain. Despite the above similarities, there are the following differences between references and pointers.
  - A pointer can be declared as void but a reference can never be void for example
    ```C++{.line-numbers}
    int a = 10;
    void* aa = &a;      //  it is valid
    void& ar = a;       //  it is not valid
    ```
 - The pointer variable has n-levels/multiple levels of indirection i.e. single-pointer, double-pointer, triple-pointer. Whereas, the reference variable has only one/single level of indirection. The reference variable has only one/single level of indirection. The following code reveals the mentioned points:
   ```C++{.line-numbers}
   int main(){
       int i = 10;      //  simple or ordinary variable.
       int *p = &i;     //  single pointer
       int **pt = &p;   //  double pointer
       int ***ptr = &pt;//  triple pointer
       //   All the above pointers differ in the value they store or point to.
       
       int a = 5;
       int &s = a;
       int &s0 = s;
       int &s1 = s0;
       //   All the above references do not differ in their values
       //   as they all refer to the same variable.
   }
   ```
 - Reference variable cannot be updated
 - Reference variable is an internal pointer
 - Declaration of Reference variable is preceded with '&' symbol (but do not read it as "address of")

- References are less powerful than pointers
  - Once a reference is created, it cannot be later made to reference another object; it cannot be reset. This is often done with pointers.
  - References cannot be NULL. Pointers are often made NULL to indicate that they are not pointing to any valid thing.
  - A reference must be initialized when declared. There is non such restriction with pointers.
  Due to the above limitations, references in C++ cannot be used for implementing data structures like Linked List, Tree, etc. In Java, references don't have the restrictions and can be used to implement all data structures. References being more powerful in Java is the main reason Java doesn't need pointers.

- References are safer and easier to use:
  - Safer:
    Since references must be initialized, wild references like wild pointers are unlikely to exist. it is still possible to have references that don't refer to a valid location.
  - Easier to use:
    References don't need a dereferencing operator to access the value. They can be used like normal variables. '&' operator is needed only at the time of declaration. Also, members of an object reference can be accessed with don't operator('.'), unlike pointers where arrow operator (->) is needed to access members.

- summary
  Together with the above reasons, there are few places like the copy constructor argument where pointer cannot be used. Reference must be used to pass the argument in the copy constructor. Similarly, references must be used for overloading some operators like ++.
  

- 引用VS指针
  指针和引用都能够在另一个函数中修改本函数的本地变量。当传递大量数据作为函数参数或者返回值时，它们都能节约拷贝的时间以提升效率。尽管它们之间存在很多的相似之处，但是它们同时也存在很大的区别。
  1，指针能够被声明为空类型，但是引用绝对不能是空类型
  2，指针能够存在多重间接访问。一维指针，二维指针，多维指针等。但是引用只有一重间接引用。
  3，引用变量不能被更新
  4，引用变量是一个整形指针

- 引用的权限比指针低
  - 引用一旦被创建，它不能再被引用其他对象；同时也不能被重置。
  - 不能使用NULL来初始化引用。而指针通常指向NULL来表明它们当前指向的是一个无意义的值
  - 引用在声明时必须初始化，而指针却没有这种限制。
  因为以上的这些原因，C++中的引用不能用来表示链表、数的复杂且灵活的数据类型。

- 引用比起指针更安全且更方便：
  - 安全
    因为引用必须初始化，所以不会出现向指针那样的野指针情况。但是引用还是可能存在无效的引用————引用了已经释放的临时变量。
  - 便利
    引用不需要再对地址做解引用操作符，就可以直接访问数据。


##  lvalues references and rvalues references
**"l-value" refers to a memory location that identifies an object. "r-value" refers to the data value that is stored at some address in memory.** References in C++ are nothing but the alternative to the already existing variable. They are declared using the '&' before the name of the vairable.

- Example
  ```C++{.line-numbers}
  int a = 10;

  //    Declaring lvalue reference
  int& lref = a;
  //    Declaring rvalue reference
  int&& rref = 20;
  ```

```C++{.line-numbers}
int main()
{
    int a{10};

    int& b = a;
    //  cout setting
    cout << (&a == &b) << endl;

    return 0;
}
```
- Explanation
  The following code will print True as *both the variable* are **pointing** to the *same memory location*. b is just an alternative name to the memory assigned to the variable a. The reference declared in the above code is lvalue reference(i.e., referring to variable in the lvalue) similarly the references for the values can also be declared.

- rvalue references have two properties that are useful:
  - rvalue references extend the lifespan of the **temporary object** to which they are assigned.
  - Non-const rvalue references allow you to modify the rvalue.
**IMPORTANT**: lvalue references can be assigned with the rvalues but rvalue references cannot be assigned to the lvalue.
```C++{.line-numbers}
int main()
{
    int a = 10;

    //  declaring lvalue reference
    int& lref = a;

    //  declaring rvalue reference
    int&& rref = 20;

    //  print the values
    cout << "lref = " << lref << endl;
    cout << "rref = " << rref << endl;

    //  value of both a and lref is changed
    lref = 30;

    //  value of rref is changed
    rref = 40;
    cout << "lref = " << lref << endl;
    cout << "rref = " << rref << endl;

    //  This line will generate an error as l-value cannot be assifned to the r-value references int&& ref = a;
    return 0;
}
```

- Uses of the lvalue reference:
  - lvalue references can be used to alias an existing object.
  - They can also be used to implement pass-by-reference semantics.

- Uses of rvalue references:
  - They are used in working with the move constructor and move assignment.
  - cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
  - cannot bind rvalue references of type 'int&&' to lvalue of type 'int'
  
**说明**：引用的使用限制是在引用的初始化时的限制。
不能使用右值去初始化non-const的左值引用，也就是说可以使用右值来初始化const的左值引用。不能使用左值来初始化右值引用。
```c++{.line-numbers}
int main()
{
  int& lref = 10;         //  invalid
  const int& lref = 10;   //  valid
  
  int a = 100;
  int&& rref = a;         //  invalid 
}
```

##  office documentation of MSVC
每个**C++表达式**都拥有类型，该类型属于**值类型(value category)**。值类型是在表达式求值时————创建、复制和移动临时对象时————编译器**必须**遵守的规则。
C++17是这样定义表达式的值类型的：
- *glvalue*是用于计算一个对象的赋值、位字段、函数的表达式
- *prvalue*是一个用于初始化对象、位字段、计算机操作符操作数的值，这些值有上下文明确指出
- *xvalue*