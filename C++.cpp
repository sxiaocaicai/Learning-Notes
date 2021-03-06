C与C++的区别？
一、C++介绍
    本贾尼·斯特劳斯特卢普，与1979年4月份贝尔实验室的本贾尼博士在分析UNIX系统分布内核流量分析时，希望有一种有效的更加模块化的工具。
    1979年10月完成了预处理器Cpre，为C增加了类机制，也就是面向对象，1983年完成了C++的第一个版本，C with classes也就是C++。
    C++与C的不同点：
    1、C++基本兼容C的语法
    2、支持面向对象的编程思想
    3、支持运算符重载
    4、支持泛型编程、模板
    5、支持异常处理
    6、类型检查严格

二、第一个C++程序
    1、文件扩展名
        .cpp .cc .C .cxx
    2、编译器
        g++ 大多数系统需要额外安装，Ubuntu系统下的安装命令：
            sudo apt-get update
            sudo apt-get install g++
        gcc也可以继续使用，但需要增加参数 -xC++ -lstdc++
    3、头文件
        #include <iostream>
        #include <stdio.h> 可以继续使用，但C++建议使用 #include <cstdio>
    4、输入/输出
        cin >> 输入数据
        cout << 输出数据   
        cin/cout会自动识别类型
        scanf/printf可以继续使用
        注意：cout和cin是类对象，而scanf/printf是标准库函数。
    5、增加了名字空间
        std::cout
        using namespace std;
        
三、名字空间
    1、什么是名字空间
    在C++中经常使用多个独立开发的库来完成项目，由于库的作者或开发人员没见过面，因此命名冲突在所难免。
    2、为什么需要名字空间
    在项目中函数名、全局变量、结构、联合、枚举、类，非常有可能名字冲突，而名字空间就对这些命名进行逻辑空间划分（不是物理单元划分），
为了解决命名冲突，C++之父为防止命名冲突给C++设计一个名字空间的机制。
    通过使用namespace XXX把库中的变量、函数、类型、结构等包含在名字空间中，形成自己的作用域，避免名字冲突。
    namespace xxx
    {

    }// 没有分号
    注意：名字空间也是一种标识符，在同一作用域下不能重名。

    3、同名的名字空间有自动合并（为了声明和定义可以分开写）
    同名的名字空间中如果有重名的依然会命名冲突

    4、名字空间的使用方法
    ::域限定符
    空间名::标识符 // 使用麻烦，但是非常安全
    using namespace 空间名; 把空间中定义的标识符导入到当前代码中
        不建议这样使用，相当于把垃圾分类后，又导入同一个垃圾车，依然会冲突

    5、无名名字空间
    不属于任何名字空间中的标识符，隶属于无名名字空间。
    无名名字空间中的成员使用 ::标识符 进行访问。
    如何访问被屏蔽的全局变量。

    6、名字空间的嵌套
    名字空间内部可以再定义名字空间，这种名字空间嵌套
    内层的名字空间与外层的名字空间的成员，可以重名，内层会屏蔽外层的同名标识符。
    多层的名字空间在使用时逐层分解。
    n1::n2::num;
    namespace n1
    {
        int num = 1;
        namespace n2
        {   
            int num = 2;
            namespace n3
            {

            }
        }
    }

    7、可以给名字空间取别名
    由于名字空间可以嵌套，这样就会导致在使用内层成员时过于麻烦，可以给名字空间取别名来解决这类问题。
    namespace n123 = n1::n2::n3;

四、C++的结构
    1、不再需要 typedef ，在定义结构变量时，可以省略struct关键字
    2、成员可以是函数（成员函数），在成员函数中可以直接访问成员变量，不需要.或->，但是C的结构成员可以是函数指针。
    3、有一些隐藏的成员函数（构造、析构、拷贝构造、赋值构造）。
    4、可以继承，可以设置成员的访问权限（面向对象）。

五、C++的联合
    1、不再需要 typedef ，在定义结构变量时，可以省略union关键字
    2、成员可以是函数（成员函数），在成员函数中可以直接访问成员变量，不需要.或->，但是C的结构成员可以是函数指针。
    3、有一些隐藏的成员函数（构造、析构、拷贝构造、赋值构造）。
  
六、C++的枚举
    1、定义、使用方法与C语言基本一致。
    2、类型检查比C语言更严格

七、C++的布尔类型
    1、C++具有真的布尔类型，bool是C++中的关键字，在C语言中使用布尔类型需要导入头文件stdbool.h（在C11中bool应该是数据类型了）。
    2、在C++中 true false 是关键字，而在C语言中不是。
    3、在C++中 true false 是1字节，而C语言中是4字节。

八、C++的void*
    1、C语言中void* 可以与任意类型指针 自动转换。
    2、C++中void*不能给其他类型的指针直接赋值，必须强制类型转换，但其他类型的指针可以自动给void*赋值。
    3、C++为什么这样修改void*？
        为了更安全，所以C++类型检查更严格。
        

九、操作符别名
    某些特殊语言的键没有~,&符合，国际标准化组织为一些操作符规定了别名，以便使用这些语言的键盘也能输入正确的C/C++代码。 C95和C++98以后的语言标准都支持ISO-646 
    and     &&
    or      ||
    not     !
    {       <%    
    }       %>
    #       :%

十、函数重载
    1、函数重载
        在同一作用域下，函数名相同，参数列表不同的函数，构成重载关系。
    2、重载实现的机制
        C++代码在编译时会把函数的参数类型添加到参数名中，借助这个方式来实现函数重载，也就是C++的函数在编译期间经历换名的过程。
    因此，C++代码不能调用C函数（C语言编译器编译出的函数）
    3、extern "C" {}
        告诉C++编译器按照C语言的方式声明函数，这样C++就可以调用C编译器编译出的函数了（C++目标文件可以与C目标文件合并生成可执行程序）。
        如果C想调用C++编译出的函数，需要将C++函数的定义用extern "C"包括一下。
        注意：如果两个函数名一样，一定会冲突。
    4、重载和作用域
        函数的重载关系发生在同一作用域下，不同作用域下的同名函数，构成隐藏关系。
    5、重载解析
        当调用函数时，编译器根据实参的类型和形参的匹配情况，选择一个确定的重载版本，这个过程叫重载解析。
        实参的类型和形参的匹配情况有三种：
            1、编译器找到与实参最佳的匹配函数，编译器将生成调用代码。
            2、编译找不到匹配函数，编译器将给出错误信息。
            3、编译器找到多个匹配函数，但没有一个最佳的，这种错误叫二义性。
        在大多数情况下编译器都能立即找到一个最佳的调用版本，但如果没有，编译就会进行类型提升，这样备选函数中就可能具有多个可调用
的版本，这样就可能产生二义性错误。
    6、确定存在函数的三个步骤
        1）候选函数
        函数调用的第一步就是确定所有可调用的函数的集合（函数名、作用域），该集合中的函数就是候选函数。
        2）选择可行函数
        从候选函数中选择一个或多个函数，选择的标准是参数个数相同，而且通过类型提升实参可被隐式转换为形参。
        3）寻找最佳匹配
        优先每个参数都完全匹配的方案，其次参数完全匹配的个数，再其次是浪费内存的字节数。
    7、指针类型会对函数重载造成影响
        C++函数的形参如果是指针类型，编译时函数名中会追加Px。

十一、默认形参
    1、在C++中函数的形参可以设置默认值，调用函数，如果没有提供实参数，则使用默认形参。
    2、如果形参只有一部分设置了默认形参，在某个提供了默认值的参数后面，所有的参数都必须提供默认值。
    3、函数的默认形参是在编译阶段确定的，因此只能使用常量、常量表达式、全局变量数据作为默认值。
    提问：如果函数的声明和定义需要分开，那么默认形参设置在声明、定义，还是声明定义都需要设置？
    4、默认形参会对函数重载造成影响，设置默认形参时一定要慎重。

十二、内联函数
    1、普通函数调用时是生成调用指令（跳转），然后当代码执行到调用位置时跳转到函数所在的代码段执行。
    2、内联函数就把函数编译好的二进制指令直接复制到函数的调用位置。
    3、内联函数的优点就是提高程序的运行速度（因为没有跳转，也不需要返回），但这样会导致可执行文件增大（冗余），也就是牺牲空间来换取时间。
    4、内联分为显示内联和隐式内联
        显示内联：在函数前 inline（C语言C99标准也支持）
        隐式内联：结构、类中内部直接定义的成员函数，则该类型函数会被优化成内联函数。
    5、宏函数在调用时会把函数体直接替换到调用位置，与内联函数一样也是使用空间来换取时间，所以宏函数与内联函数的区别（优缺点）？
        1、宏函数不是真正的函数，只是代码替换，不会有参数压栈、出栈以及返回值，也不会检查参数类型，因此所有类型都能使用，但这样会
有安全隐患。
        2、内联函数是真正的函数，被调用时会进行传参，会进行压栈、出栈，可以有返回值，并会严格检查参数类型，这样就不能通用，如果想被
多种类型调用需要重载。
    6、内联适用的条件
        由于内联会造成可执行文件变大，并增加内存开销，因此只有频繁调用的简单函数适合作为内联。
        调用比较少的复杂函数，内联后并不显著提高性能，不足以抵消牺牲空间带来的损失，所以不适合内联。
        带有递归特性和动态绑定特性的函数，无法实施内联，因此编译器会忽略声明部分的inline关键字。

十三、引用
    引用就是取艺名（别名）。
    1、引用的基本特性
        引用就是取别名，声明一个标识符为引用，就表示该标识符是另一个对象的外号。
        1、引用必须初始化，不存在空引用，但有悬空引用（变量死了，名还留着）。
        2、可以引用无名对象（临时对象），但必须使用常引用。
        3、引用不能更换目标
        4、引用目标如果具有const属性，引用也需要具有const属性。
        引用一旦完成了定义和初始化就和普通变量名一样，它就代表了目标，一经引用终身不能再引用其他目标。
    2、引用型参数
        引用当作函数的参数能达到指针同样的效果，但不具备指针的危险，还比指针方便。
        引用可以非常简单的实现函数间共享变量的目的，而且是否使用引用由被调函数说了算。
        引用当作函数的参数还能提高传递参数效率，指针至少还需要4字节内存，而引用只需要增加一条标识符与内存之间的绑定（映射）。
    3、引用型返回值
        不要返回局部变量的引用，会造成悬空引用。
        如果返回值是一个临时值（右值），如果非要使用引用接收的话，必须使用常引用。
    注意：C++中的引用时一种取别名的机制，而C语言中的指针是一种数据类型（代表内存编号的无符号整数）。
    练习1：实现一个C++版本的swap函数。

    指针和引用的相同点和不同点：
        相同点：跨函数共享变量，优化传参效率，避免传参的时候调用拷贝构造
        不同点：指针有自己的存储空间，借助指针可以使用堆内存，引用不行。引用取别名，指针是数据类型。指针可以为空，引用不可以为空。
指针可以不初始化，引用必须初始化。指针可以改变指向，引用不能引用其他对象（可以定义指针的指针，不能定义引用的引用。可以定义指针的
引用，不能定义引用的指针。可以定义指针的数组，但不能定义引用的数组。可以定义数组的引用）。

#include <iostream>
using namespace std;

void swap(int& a,int& b) //引用
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a=3,b=4;
	swap(a,b);
	cout<<a<<" "<<b<<endl;
}
    

十四、C++的内存管理
    1、new/delete C++具备申请/释放堆内存功能的运算符
        相当于C语言中的malloc和free。
        new 类型：会自动计算类型所需要字节数，然后从堆中分配对应字节数的内存，并返回内存的首地址（具备类型）。
        
        delete 指针：会自动释放堆内存。
        注意：new/delete与malloc/free不能混用，因为new和delete会自动调用类、结构的构造函数、析构函数。

    2、数组的分配与释放
        new 类型[n]； n表示数组长度，如果类、结构会自动调用n次构造函数。
        delete[] 指针；通过new[] 分配的内存，必须通过delete[]释放。
        new[] 返回值前4个字节中存放着数组的长度。

    3、重复释放
        delete/delete[]不能重复释放同一块内存。
        delete/delete[]释放野指针的后果不确定，但释放空指针是安全的。
#include <iostream>
using namespace std;

struct Student
{
	Student(void)
	{
		cout<<"我是构造函数，创建对象时，我就会执行" << endl;
	}

	~Student(void)
	{
		cout<< "我是析构函数，释放对象时，我就会执行" << endl;
	}
};

int main()
{
	int* p = new int;
	*p = 10;

	cout<< *p <<endl;

	Student stu;
	
	Student* s = new Student;
	delete(s);
	cout << endl;

	Student* a = new Student[3];
	p = (int*)a;
	cout << *(p-1) << endl;
	delete[] a;	
}

    4、内存分配失败
        当分配的内存过大，没有能满足需求的整块内存就会抛出异常，std::bad_alloc。
        new/delete和C语言的malloc/free的相同点和不同点（区别）？
        不同点：
            身份     运算符               标准库函数
            参数     类型（自动计算）      字节数（手动计算）
            返回值   带类型的地址          void*地址
            调用构造 自动调用              不能调用构造/析构函数
            出错     抛出异常              返回NULL
        相同点：
            1、都能管理堆内存
            2、不能重复释放
            3、可以释放NULL
    
    注意：在C++中尽量使用引用、new/delete
#include <iostream>
using namespace std;

int main()
{
	int *p = NULL;
	try{
		p = new int[~0];
	}
	catch(std::bad_alloc& ex)
	{
		cout << "error" << endl;
	}
}

十五、强制类型转换






























面向过程编程：
    关注是问题解决的过程步骤，算法

面向对象编程：
    关注的是谁能解决问题（类），需要什么样的数据（成员变量），具备什么样的技能（成员函数）才能解决问题。
    抽象：找出一个能够解决问题的“对象”（观察研究对象），找出解决所必须的数据（属性）、功能（成员函数）。
    封装：把抽象的结果，归结为一个类（数据类型），然后实例化出类对象，设置对象的属性，调用对象的功能达到解决问题的目的。
    继承：在解决问题前，先寻找之前的类能不能解决问题，或解决部分问题，如果可以则把旧的类继承后再次拓展，来缩短解决问题的时间，降低
解决问题的难度。
    多态：对象的多种形态，外部看到一个对象发出指令，对象会根据自身情况做出独特的反应。

一、类和对象
    1、通过分析对象的属性和行为设计出一个类。
    2、类就是数据类型
        简单类型：只能表示一个属性（变量），C/C++内建数据类型
        数组类型：可以表示多个属性（变量），类型必须相同。
        结构类型：可以表示多个属性（变量），但缺少行为（函数）。
        类类型：即能表示属性，也能表示行为，一直复合数据类型。
    3、对象就是类这种数据类型创建出的实例，相当于结构变量。
    class Student
    {
        属性(成员变量);
        行为（成员函数）;
    };

    Student stu;

二、类的定义与实例化
    1、类的一般形式
    class 类名 : 继承方式 父类
    {
    public/private/protected: // 访问控制限制符

        成员变量;

        // 构造函数
        类名(形参表)
        {
            
        }

        // 析构函数
        ~类名(void)
        {

        }
    };
    2、类的访问控制限定符
    public：公有成员，在任何位置都可以访问
    private：私有成员，只能在类（自己）的成员函数中访问
    protected：受保护成员，只能在类（自己）和子类中访问
    注意：类中的成员变量、成员函数默认是 private，结构中的成员和成员函数默认是 public。
    注意：C++中类和结构的区别只有成员函数和成员变量的默认访问权限不同。
    3、构造函数
        1）什么是构造函数：类的同名函数就是构造函数，没有返回值。
        2）什么时候调用，谁调用，调用几次？
            创建类对象时会被自动调用（每创建一个类对象，就会调用一次），对象整个生命周期中一定会被
调用一次，只能被调用一次。
        3）负责干什么
            成员变量的初始化，分配相关资源，设置对象的初始状态。

        class 类名 : 继承方式 父类
        {
            // 构造函数
         类名(形参表)
            {
            
            }
        };
    4、类型的创建过程
        1.分配类型所需要空间，无论栈还是堆。
        2.传递实参调用构造函数，完成如下任务：
            1）根据继承表依次调用父类的构造函数
            2）根据成员变量的顺序依次调用成员变量的构造函数。
            3）执行构造函数体中的代码。
    注意：执行构造函数的代码是整个构造函数的最后一步。
    要保证构造函数代码所需要的一切资源和先决条件在该代码执行前已经准备充分，并得到正确的初始化。
    5、对象的创建方法
        1.在栈上创建：类名 对象；// 不需要括号
            类名 对象(实参);
        2.在堆上创建：类名* 对象指针 = new 类名；
            类名* 对象指针 = new 类名(实参)；
        3.创建多个对象：
            类名 对象 = {类名(实参)，类名(实参)，类名(实参)};
            类名* 对象指针 = new 类名[n]{类名(实参),类名(实参)};
        注意：通过malloc创建的类对象不能调用构造函数。
        注意：通过new[]创建的对象，一定要通过delete[]释放。
    6、类的声明、实现、调用
        1.在头文件中声明
        class 类名 : 继承方式 父类
        {
            成员变量;
        public: // 访问控制限制符
            // 构造函数
            类名(形参表);
            // 析构函数
            ~类名(void);
            // 其他成员函数
            返回值 函数名(参数列表);
        };

        2.源文件实现类的相关函数
        返回值 类名::函数名（参数列表）
        {

        }

        3.调用时只需要导入头文件，然后与类函数所在的源文件一起编译即可。
        注意：如果一个类内容不多，可以考虑在头文件中完全实现。
            也可以只在头文件中实现一些简单的成员函数。
        注意：类中自动生成的函数，在源文件中实现时，也需要在头文件中声明。

    class和struct的区别？
        class的默认继承和访问权限是private，struct的默认继承和访问权限是public。class能做模板的参数，struct不行。

三、构造函数与初始化列表
    1、构造函数可以被重载（同一个名字的函数有多个不同版本）
    2、缺省构造是编译器自动生成的一个什么都不做的构造函数（唯一的作用就是避免编译错误）。
    注意：当类实现一个有参构造时，缺省构造就不会再自动生成，如果有需要必须显示地写出来。
    3、无参构造未必无参，当给有参构造的所有参数设置默认形参，调用这种构造函数就不需要传参。

    注意：所谓的“编译器生成的某某函数”其实不是真正语法意义上的函数，而是功能意义上的函数，编译器作为可执行指令的生成者，它会直接生成
具有某项功能的二进制指令，不需要借助高级语言语义上的函数完成此任务。

    注意：如果一个类是其他类的成员变量，那么一定要保证它有一个无参构造，当B的构造函数执行时会执行成员变量的无参构造，而此时类B是无
法给类A成员变量提供参数的。
    4、单参构造与类型转换
        如果构造函数的参数只有一个，那么Test t = n语句就不会出错，它会自动调用单参构造来达到类型转换的效果。
        如果想禁止这种类型转换需要在单参构造前加 explicit
    5、初始化列表
        为类成员进行初始化用的。
        构造函数(参数):成员1(参数1),成员2(参数2)...
        const int num;
        Test(int n):num(n)
        {
        }
        通过初始化列表可以给类成员变量传递参数，以此调用类成员的有参构造。
        初始化列表也可以给 const 成员、引用成员进行初始化。
#include <iostream>
using namespace std;

class A
{
public:
	int num;
	A(int _num)
	{
		num = _num;
		cout<<"我A的有参构造"<<endl;
	}
};

class Test
{
public:
	string str;
	const int num;
	int& xiu;
	A a;
	Test(int num,const char* str,int& x):num(num),str(str),a(num),xiu(x)
	{
		cout<<"---"<<endl;
	}
};

int main()
{
	int x = 100;
	Test t(10,"aa",x);
	//Test t = {10};
	//t.num = 100;
	cout<< t.num << endl;
	cout<<t.xiu<<endl;
	x = 1000;
	cout<<t.xiu<<endl;
}

        成员的初始化顺序与初始化列表没有关系，而是在类中的定义顺序有关。
#include <iostream>
using namespace std;

class A
{
public:
	A(int n)
	{
		cout<<"A"<<endl;
	}
};

class B
{
public:
	B(int n)
	{
		cout<<"B"<<endl;
	}
};

class C
{
public:
	C(int n)
	{
		cout<<"C"<<endl;
	}
};

class Test
{
public:
	A a;
	C c;
	B b;
	//A a;
	Test(int c1,int a1,int b1):c(c1),a(a1),b(b1)
	{
	}
};

int main()
{
//	A a1;
//	B b1;
//	C c1;
	Test t(1,2,3);
}
        注意：初始化列表运行类成员变量还没有定义成功。

作业1：封装一个List类

附加题：以C++编程方式实现2048游戏。


































一、this指针
    类的成员变量单独存储在每个类对象中，成员函数存储在代码段中，所有的类对象共享一份成员函数。
    
    成员函数是如何区别调用它的是哪个类对象的？
    答：借助了this指针，类的每个成员函数都有一个隐藏的参数this指针，它指向类对象。

    类的构造函数中也同样有this指针，指向的就是正在构造的这个对象。

    在类中（成员、构造、析构函数）对成员变量、成员函数的访问都是借助了this指针。

    this指针是隐藏的，但也可以显示使用：
        1、参数与成员一样时，使用this可以区别出成员与参数名。
        2、在成员函数中如果想返回当前对象的指针、引用等，可以使用this指针实现。
        3、将this指针作为函数的参数，从一个对象传递给另一个其它类对象，可以实现对象间的交互。
#include <iostream>
#include <cstring>
using namespace std;

class User
{
	char name[20];
	char pass[7];
public:
	User(const char* name,const char* pass)
	{
		strcpy(this->name,name);
		strcpy(this->pass,pass);
		//show();
	}

	User& func(void)
	{
		return *this;
	}

	void show(void)//隐藏this指针
	{
		cout<< name << " "<< pass <<endl;
	}
	User* this = const this;
};

int main()
{
	User u1("aaa","123");
	User u2("bbb","321");
	User& u3 = u1.func();
	u1.show();
	u2.show();
	u3.show();
}

二、常函数
    在函数的参数列表与函数体之间有const修饰的函数，这个const其实就是在修饰this指针。
    不能在常函数内修改成员变量的值，普通成员函数可以调用常函数，而常函数只能调用常函数。

    如果在常函数中真的需要修改某个成员变量的数据，那么需要这个成员被 mutable修饰。
mutable char name[20];
void show(void) const//隐藏this指针
{
    strcpy(name,"------");
    cout<< name << " "<< pass <<endl;
}
    
    普通函数不能声明为常函数（因为没有this指针）。

三、析构函数
    1、特殊的成员函数 
        ~类名(void)
        {

        }
        没有参数、没有返回值、不能重载
    2、谁来调用
        析构函数会在销毁对象时自动调用，在对象的整个生命周期内最多被调用一次。
    3、析构函数负责什么
        负责释放在构造函数期间获取的所有资源，它的执行过程：
        1.先执行析构函数本身代码
        2.调用成员类的析构函数
        3.调用父类的析构函数
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class A
{
public:
	A(void)
	{
		cout << "A 's 构造" <<endl;
	}
	~A(void)
	{
		cout<<"A 's 析构"<<endl;
	}
};

class B
{
public:
	B(void)
	{
		cout << "B 's 构造" <<endl;
	}
	~B(void)
	{
		cout<<"B 's 析构"<<endl;
	}
};

class User : public A
{
	char* name;
	char* pass;
	B b;
	//char name[20];
	//char pass[10];
public:
	User(const char* name,const char* pass)
	{
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);
		this->pass = new char[strlen(pass)+1];
		strcpy(this->pass,pass);
		cout<< "构造"<<endl;
		cout<<"-----"<<endl;
	}

/*	User(void)
	{
		cout<<"构造"<<endl;
	}
*/
	~User(void)
	{
		delete name;
		delete pass;
		cout<<"析构"<<endl;
	}
};

int main()
{
	User* u1 = new User("asd","ads");
	//exit(0);
	delete u1;
	//User u2;

}

    4.缺省的析构函数
        如果一个类没有实现析构函数，编译器会自动生成一个具有析构函数功能的二进制指令，它负责释放编译器能够看得到的资源（成员变量、
类成员、弗雷成员），这就是缺省析构。
        如果类中没有动态资源，也不需要做善后工作，缺省析构就完全共用了，不需要再实现新析构函数。
        注意：缺省析构无法释放动态资源（堆内存）【堆内存是动态资源，动态资源不一定是堆内存】

    作业：类对象的创建过程与释放过程。
        创建：分配内存（对象）-> 父类构造-> 成员构造-> 自己构造
            父类构造：按照继承表从左到右依次构造。
            成员构造：按照声明顺序从上至下依次构造。
        释放：自己析构-> 成员析构-> 父类析构-> 释放内存（对象）
            成员析构：按照声明顺序从下到上依次构造。
            父类析构：按照继承表从右到左依次构造。

四、拷贝构造
    拷贝构造又称为复制构造，是一种特殊的构造函数，它是使用一个现有的旧对象构造一个新的对象时调用的函数，只有一个引用型的参数（对象本身）。
    类名(类& )
    {

    }
    拷贝构造的参数应该加 const 保护，但编译器并没有强行限制。
    编译器会自己生成一个拷贝构造函数，它负责把旧对象中的所有数据拷贝给新创建的对象。

    深拷贝与浅拷贝的区别：
        如果类成员有指针，浅拷贝只拷贝指针变量的值，而深拷贝指针变量所指向的目标。
    什么情况下需要实现拷贝构造：
        当类成员中没有指针成员，此时默认的拷贝构造（浅拷贝）就无法完成任务，需要自己动手实现拷贝构造（深拷贝）。
    什么情况下会调用拷贝构造：
        1、使用旧对象给新对象赋值时
        User user1 = user;
        2、使用对象当作函数的参数，当调用函数时，就会一起调用拷贝构造。
#include <iostream>
#include <cstring>

using namespace std;

class User
{
	char* name;
	char pass[7];
	int id;
public:
	User(const char* name,const char* pass)
	{
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);
		strcpy(this->pass,pass);
	}
	void show(void)
	{
		cout<<name <<" " <<pass <<endl;
	}

	~User(void)
	{
		cout<<"析构"<<&name <<endl;
		delete[] name;
	}

	User(User& that)
	{
		name = new char[strlen(that.name)];
		strcpy(name,that.name);
		strcpy(pass,that.pass);
		cout << "我是拷贝构造" << endl;
	}

};

void func(User& user)
{
	user.show();
}

int main()
{
	User u1("a","aa");
	u1.show();
	// 调用拷贝构造
	User u2 = u1;
	u2.show();
	func(u1);
}

五、赋值构造（赋值运算符）
    当一类对象给另一个类对象赋值时，就会调用赋值构造
    void opeator = (类&)
    {

    }
    什么时会调用：对象 = 对象；
    编译器会生成一个缺省的赋值构造，它负责把一个对象的内存拷贝给另一个对象。
    什么情况需要实现赋值构造：
        当需要深拷贝时，需要自己动手实现赋值构造，也就是拷贝构造与赋值构造需要同时实现。
    编译器会自动生成四个成员函数：构造、析构、赋值构造、拷贝构造。    
#include <iostream>
#include <cstring>

using namespace std;

class User
{
	char* name;
	char pass[7];
public:
	User(const char* name,const char* pass)
	{
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);
		strcpy(this->pass,pass);
	}
	void show(void)
	{
		cout<<name <<" " <<pass <<endl;
	}

	~User(void)
	{
		cout<<"析构"<<&name <<endl;
		delete[] name;
	}

	User(User& that)
	{
		name = new char[strlen(that.name)];
		strcpy(name,that.name);
		strcpy(pass,that.pass);
		cout << "我是拷贝构造" << endl;
	}
	
	User& operator = (const User& that)
	{
		cout<< this <<" "<< &that << endl;
		if(this != &that)
		{
			cout<<"我是赋值构造"<<endl;
			// 释放旧空间
			delete[] name;
		
			// 申请新空间
			name = new char[strlen(that.name)+1];

			// 拷贝内容
			strcpy(name,that.name);
			strcpy(pass,that.pass);
			
			/*
			User temp(that);
			swap(name,temp.name);
			*/
		}
		return *this;
	}

};

int main()
{
	User u1("a","aa");
	User u2("bbbb","bb");
	User u3("ccc","cc");
	//赋值构造
	u1 = u1;
	//u2 = u1 = u3;
	u1.show();
	u2.show();
	u3.show();
	
}

六、关于拷贝构造、赋值构造的建议
    1、缺省的拷贝构造、赋值构造函数不光会拷贝本类的数据，也会调用成员类对象和父类的拷贝构造和赋值构造，而不是单纯的按字节复制，
因此尽量少用指针成员。
    2、在函数参数中，尽量使用类指针或引用来当参数（不要直接使用类对象），减少调用拷贝构造和赋值构造的机会，也可以降低数据传递的开销。
    3、如果由于特殊原因无法实现完整的拷贝构造、赋值构造，建议将它们私有化，防止误用。
    4、一旦为一个类实现了拷贝构造，那么也一定要实现赋值构造。（<=>）

七、静态成员
    类成员一旦被 static 修饰就会变成静态成员，而是单独一份存储在bss或data内存段中，所有的类对象共享（静态成员属于类，而不属于某个对象）。
    静态成员在类内声明，但必须在类外定义、初始化。与成员函数一样需要加“类名::”限定符表示它属于哪个类，但不需要再额外增加 static

    成员函数也可以被static修饰，这种函数叫静态成员函数，这种成员没有this指针，因此在静态函数中不能直接访问类的成员，但可以直接访问
静态成员，但可以直接访问静态成员变量、静态成员函数。
    静态成员变量、函数依然受访问控制限定符的影响。
    因为在代码编译完成后，静态成员已经定义完成（有了存储空间），一次可以不用活类对象而直接调用，类名::静态成员名

    静态成员变量可以被当做全局变量来使用（访问限定符必须是public），静态成员函数可以当作类的接口，实现对类的管理。

八、单例模式
    什么是单例模式，只能创建出一个类对象（只有一实际的实例）的叫单例模式。
    单例模式的应用场景：
        Windows系统的任务管理器
        Linux/Unix系统的日志系统
        网站的访问计数器
        服务端程序的连接池、线程池、数据池
    获取单一对象的方法：
        1、定义全局（C语言），但不受控制，防君子不能防小人。
        2、专门写一个类，把类的构造函数设置私有，借助静态成员函数提供一个接口，以此来获取唯一的实例。
    C++如何实现单例：
        1、禁止类的外部创建类对象：构造函数设置私有
        2、类自己维护一个唯一的实例：使用静态指针指向
        3、提供一个获取实例的方法：静态成员函数获取静态指针

    饿汉模式：
        将单例类的唯一实例对象定义为成员变量，当程序开始运行时，实例对象就已经创建完成
        优点：加载进程时，静态创建单例对象，线程安全。
        缺点：无论使用与否，总要创建，浪费内存。
    懒汉模式：
        用静态成员指针来指向单例类的唯一实例对象，只有真正调用获取实例的静态接口时，实例对象才被创建。
        优点：什么时候用什么时候创建，节约内存。
        缺点：在第一次调用获取实例对象的静态接口时，才真正创建，如果在多线程操作情况下有可能被创建出多个实例对象（虽然可能性很低），
存在线程不安全问题。

总结：C语言与C++有哪些不同点
    内存管理  malloc/free  new/delete
    static
    const
    void*
    字符串：string系列函数  string类 





























一、操作符函数重载
    什么是操作符函数：在C++中针对类类型的对象的运算符，由于它们肯定不支持真正的运算操作，因此编译器会将它们翻译成函数，这种就叫做
操作符函数（运算符函数）。
    编译器把运算翻译成运算符函数，可以针对自定义的类类型设计它独有的运算功能。
    其实各种运算符已经具备一些功能，再次实现它的就是叫作运算符重载。

    双目运算符：
        a+b
        成员函数
            a.operator+(b);
        全局函数
            operator+(a,b);
    单目运算符：
        !a
        成员函数
            a.operator!(void);
        全局函数
            operator!(a);

二、双目操作符函数重载
    成员函数：
    const 类对象 operator#(const 类& that) const
    {
        return 类(参数#参数);
    }
    注意：双目录运算符的运算结果是个右值，返回值应该加 const ，然后为了const对象能够调用，参数应写const，函数也应该具备const属性。

    全局函数：
    const 类 operator#(const 类& a,const 类& b)
    {

    }
    注意：全局函数不是成员函数，可能会需要访问到类的私有成员，解决这种问题可以把函数声明为类的友元函数（友元不是成员）。
    友元：在类的外部想访问类的私有成员（public/protected/private）时，需要把所在的函数声明为友元，但是友元只是朋友，因此它只有访
问权，没有实际的拥有权（其根本原因是它没有this指针）。
    友元声明：把函数的声明写一份到类中，然后在声明前加上friend 关键字。使用友元即可把操作符函数定义为全局的，也可以确保类的封装性。
    注意：友元函数与成员函数不会构成重载关系，因此它们不在同一个作用域内。

三、赋值类型的双目操作符
    成员
        类 operator#(void)
        {
            
        }
    全局
        类 operator#(const 类& that)
        {

        }
    1、获取单参构造成赋值运算的调用方式。
    String str = "xxx"; // 会调用单参构造，而不调用赋值运算符
    str = "hhh";

    2、左操作数据不能具有const属性
        1.成员函数不能是常函数
        2.全局函数第一个参数不能有const属性
    3、返回值应该都（成员/全局）具备const属性

四、单目操作符函数重载
    -,~,!,&,*,->,++,--
    成员
        const 类 operator#(void) const
        {
            
        }
    全局
        const 类 operator#(const 类& that)
        {

        }
    前++/--
        类& operator#(void)
        {

        }
        类& operator#(类& that)
        {

        }
    后++/--(哑元)
        const 类& operator#(void)
        {

        }
        const 类& operator#(类& that,int)
        {

        }

五、输入输出操作符重载
    cout 是 ostream 类型的对象，cin 是 istream 类型的对象。
    如果<</>>运算实现为成员函数，那么调用者应该是ostream/istream,而我们无权增加标准库的代码，因此输入/输出运算符只能定义为全局函数。

    ostream& operator<<(ostream& os,const 类& n)
    {

    }

    istream& operator>>(istream& os,类& n)
    {

    }

    注意：在输入输出过程中，cin/cout会记录错误标志，因此不能加const属性。

六、特殊操作符的重载（笔试面试比较重要）
    1、下标操作符 []，常用于在容器类型中以下标方式获取元素。
    类型& operator[](int i)
    {

    }
    2、函数操作符()，一个类如果重载函数操作符，那么它的对象就可以像函数一样使用，参数的个数、返回值类型，可以不确定，它是唯一一个
可以参数有缺省参数的操作符。
#include <iostream>
#include <stdlib.h>
using namespace std;

class Array
{
	int* arr;
	size_t len;
public:
	Array(size_t len):len(len)
	{
		arr = new int[len];
	}

	void operator()(void)
	{
		cout<<"emmm"<<endl;
	}

	int& operator[](int i)
	{
		if(i < 0 || i >= len)
		{
			cout<<"下标错误"<<endl;
			exit(0);
		}
		return arr[i];
	}
};

int main()
{
	Array arr(100);
	for(int i=0; i<10; i++)
	{
		arr[i] = i;
		cout<< arr[i] << endl;
	}
	arr();
}


    3、解引用操作符*，成员访问操作符->
        如果一个类重载了*和->，那么它的对象就可以像指针一样使用。
        所谓的智能指针就是一种类对象，它支持解引用和成员访问操作符。
    4、智能指针
        常规指针的缺点：
            当一个常规指针离开它的作用域时，只有该指针所占用的空间会被释放，而它指向的内存空间能否被释放就不一定了，在一些特殊情
况（人为、业务逻辑特殊）free或delete没有执行，就会形成内存泄漏。
        智能指针的优点：
            智能指针是一个封装了常规指针的类类型对象，当它离开作用域时，它的析构函数会自动执行，它的析构函数会负责释放常规指针所
指向的动态内存（以正确方式创建的智能指针，它的析构函数才会正确执行）。
        智能指针和常规指针的相同点：都支持*和->运算。
        智能指针和常规指针的不同点：
            任何时候，一个对象只能使用一个智能指针来指向，而常规指针可以指向多次。
            只能指针的赋值操作需要经过拷贝构造和赋值构造特殊处理（深拷贝）。
#include <iostream>
using namespace std;

class Int
{
public:
	int val;
	Int(int val=0):val(val){ }

	void set_val(int val)
	{
		this->val = val;
	}
	int get_val(void)
	{
		return val;
	}

	Int& operator=(const int val)
	{
		this->val = val;
		return *this;
	}

	~Int(void)
	{
		cout<<"我是Int的析构函数"<<endl;
	}

	friend ostream& operator>>(ostream& os,Int& n);
};
ostream& operator<<(ostream& os,Int& n)
{
	return os<<n.val;
}

class IntPointer
{
	Int* ptr;
public:
	IntPointer(Int* ptr):ptr(ptr){ }
	Int& operator*(void)
	{
		return *ptr;
	}
	~IntPointer(void)
	{
		delete ptr;
	}
};

int main()
{
	Int* num =new Int(100);
	IntPointer p = num;
	*p = 20;
	cout<<*p <<endl;
	*p = 10;
	cout<<*p <<endl;
}

        auto_ptr:标准库中封装好的智能指针，实现了常规指针的基本功能，头文件 #include <memory>
            用法：auto_ptr<指向的类型> 指针变量名(对象的地址)
        auto_ptr的局限性：
            不要使用 auto_ptr 对象保存指向动态、静态分配数组的指针。
            不能跨作用域使用，一旦离开作用域指针变量会释放它指向的对象也会释放。
            不能放入标准容器。
            不能指向对象数组。
#include <iostream>
#include <memory>
using namespace std;

class A
{
public:
	A(void)
	{
		cout<<"构造"<<endl;
	}

	~A(void)
	{
		cout<<"析构"<<endl;
	}

	void show(void)
	{
		cout<<"A's show"<<endl;
	}

};

int main()
{
	auto_ptr<A> ptr(new A);
	(*ptr).show();
}

    5、new/delete/new[]/delete[]运算符重载
        1.C++缺省的堆内存管理器速度较慢，重载new/delete底层使用malloc/free可以提高运行速度。
        2.new在失败会产生异常，而每次使用new时为了安全都应该进行异常捕获，而重载new操作符只需要在操作符函数中进行一次错误处理即可。
        3.在一些占字节数比较小的类，频繁使用new，可能会产生大量的内存碎片，而重载new操作符后，可以适当的扩大每次申请的字节数，减
少内存碎片产生的机率。
        4.重载 new/delete 可以记录堆内存使用的信息
        5.重载 delete 可以检查到释放内存失败时的信息，检查到内存泄漏。

七、重载操作符的限制
    1、不能重载的操作符
        域限定符 ::
        直接成员访问操作符 .
        三目操作符 ?:
        字节长度操作符 sizeof
        类型信息操作符 typeid
    2、重载操作符不能修改操作符的优先级
    3、无法重载所有基本类型的操作符运算
    4、不能修改操作符的参数个数
    5、不能发明新的操作符

关于操作符重载的建议：
    1、在重载操作符时要根据操作符实际的功能和意义来确定具体参数，返回值，是否具有const属性，返回值是否是引用或者临时对象。
    2、重载操作符要符合情理（要有意义），要以实际用途为前提。
    3、重载操作符的意义是为了让对象的操作更简单、方便，提高代码的可读性，而不是为了炫技。
    4、重载操作符要与默认的操作符的功能、运算规则一致，不要出现反人类的操作。
    #define ture 0
    #define false 1



































一、类的继承
    1、共性与个性
        表达不同类型事物之间公有的属性和行为。
        个性用于刻画每种事物特有的属性和行为。
    2、共性表示为父类（基类），个性表示为子类（派生类）。
        子类继承自父类
        基类派生出子类

二、继承的基本语法
    1、继承表
    一个子类可以同时继承零到多个父类，每个父类的继承方式可以相同也可以不同。
    class 子类：继承方式1 父类1,继承方式2 父类2,...
    {

    }
    2、继承方式
        public 公有继承：父类的特性可通过子类向外扩展。
        private 私有继承：父类的特性只能为子类所有。
        protected 保护继承：父类的特性只能在继承链内扩展。

三、继承的基本特点
    1、公共特点（所有继承都有的特点）
        子类对象可以当作父类对象使用，子类对象与父类没有本质上的区别。
        子类的逻辑空间小于父类，但它的物理空间要大于等于父类。
        子类对象 IS A 父类对象
    2、向上和向下转换（造型）
        从子类到父类：子类的指针或引用可以隐式转换成父类的指针或引用，这是一种缩小类型的转换，对于编译器来说是安全的。
        从父类到子类：父类的指针或引用不可以转换成子类的指针或引用，这是一种扩大类型的转换，在编译器看来是危险的。（子类的指针指
向父类的对象，不安全）
        编译器仅仅是检查指针或引用的数据类型，而对实际引用的目标对象不关心（构成多态的基础）。
        类型一致：父类的指针或引用实际的目标类型是否需要转换成实际的指针或引用由程序自己决定。
    3、子类会继承父类的所有成员（公有，私有，保护）
    4、子类会隐藏父类的同名成员
        1.可以通过域限定符 父类::隐藏成员 进行访问父类中的隐藏成员
        2.可以使用父类的指针或引用来指向子类对象，然后访问父类中的隐藏成员。
    5、虽然子类继承所有父类中的成员，但不能访问父类中的私有成员。

四、继承方式影响访问控制


































一、子类的构造、析构、拷贝
    1、子类的构造在执行它的构造函数前会根据继承表的顺序执行父类的构造函数。
        默认执行父类的无参构造
        显示调用有参构造，在子类的构造函数后，初始化列表中显示调用父类的有参构造函数。
    2、子类在它的析构执行完后，会根据继承表的顺序，逆顺序执行父类的析构函数。
        注意：父类的指针可以指向子类对象，当通过父类指针释放对象时，只会调用父类的析构函数，而这种析构方式有可能造成内存泄漏。
    3、当使用子类对象来初始化新的子类对象时，会自动调用子类缺省的拷贝构造函数，并且会先调用父类缺省的拷贝构造函数。
        如果子类中实现的拷贝构造，需要显式调用父类拷贝构造，否则就会调用无参构造。

二、私有继承、保护继承
    1、私有继承
    使用 private 方式继承父类，公开的变成私有，其他的不变（有争议），这种继承方式防止父类的成员扩散。
    
    使用 protected 方式继承父类，公开成员在子类中会变成保护的，其他不变，这种继承方式可以有效防止父类的成员扩散。

    子类以私有或保护方式继承父类，会禁止向上造型（子类的指针或引用不能隐式转换成父类的指针或引用，要想实现多态只能以公开方式继承
父类）。

三、多重继承、钻石继承、虚继承
    1、多重载继承
    在C++中一个子类可以有多个父类，在继承表中按照顺序继承多个父类中的属性和行为，并按照顺序表，调用父类的构造函数。
    按照从低到高的地址顺序排序父类，子类中会标记每个父类存储位置。
    当子类指针转换成父类的隐式指针时候，编译器会自动计算父类中的内容在子类中的位置，地址会自动进行偏移计算。


    2、名字冲突
    如果父类中有同名的成员，可以正常继承，但如果直接使用，会造成歧义，需要 类名::成员名 进行访问。


    3、钻石继承
    假如有一个类A，类B继承类A，类C也继承类A，类D继承B和C。
    一个子类继承多个父类，这些父类有一个共同的祖先，这种继承叫钻石继承。
    注意：钻石继承不会导致继承错误，但访问祖先类中的成员时每次需要使用 类名::成员名 ，重点是这种继承会造成冗余。

    4、虚继承 virtual
    当进行钻石继承时，祖先类中的内容会有冗余，而进行虚继承后，在子类中的内容只会保留一份。
    注意：但使用虚继承时，子类中会多了一些内容（指向从祖先类继承来的成员）。
#include <iostream>
#include <stdio.h>
using namespace std;

class A
{
public:
	int a;
};

class B:virtual public A{};
class C:virtual public A{};
class D:public B,public C{};

int main()
{
	cout<< sizeof(B)<<endl;
	B* p = new B;
	p->a = 100;
	A* ap = p;
	A* ap1 = new C;
	ap1->a = 111;
	printf("%d %d\n",*(int*)ap,*(int*)ap1);
//	printf("%d\n",*((int*)p+1));
//	printf("%p %p\n",p,ap);
}

    5、构造函数
    一旦进行了虚继承祖先类的构造函数只执行一次，由孙子类直接调用，祖先类的有参构造也需要在孙子类中显示调用。

    6、拷贝构造
    在虚拟继承（钻石）中祖先类拷贝构造也由孙子类直接调用，子类中不再调用祖先类的拷贝构造，在手动实现的拷贝构造时（深拷贝），祖先
类中的内容也由孙子类负责拷贝，同理赋值构造也一样。

四、虚函数、覆盖、多态
    1、虚函数
    类的成员函数前加 virtual 这种函数就叫做虚函数。

    2、覆盖
    子类会覆盖父类的虚函数。

    3、多态
    当子类覆盖了父类的虚函数时，通过父类指针指向子类对象时，调用虚函数，会根据具体的对象是谁来决定执行谁的函数，这就是多态。
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Base
{
public:
	virtual void func(void)
	{
		cout << "我是Base的func函数"<<endl;
	}
};

class A:public Base
{
public:
	void func(void)
	{
		cout<<"我是类A的func函数" << endl;
	}
};

class B:public Base
{
public:
	void func(void)
	{
		cout<<"我是类B的func函数" << endl;
	}
};

class C:public Base
{
public:
	void func(void)
	{
		cout<<"我是类C的func函数" << endl;
	}
};

int main()
{
/*覆盖
	A* a = new A;
	Base* p = a;
	Base* b = new Base;
	b->func(); // 并没有消失
	a->func(); // 调用子类函数
	p->func(); // 如果父类的函数是虚函数，调用子类函数
*/

	srand(time(NULL));

	// 这就是多态
	Base* arr[] = {new A,new B,new C};
	arr[rand()%3]->func();
}

五、覆盖和多态的条件
    1、覆盖的条件
        必须是虚函数
        必须是父子类之间
        函数签名必须相同（参数列表完全一致，const属性也会影响覆盖的结果）
        返回值必须是同类型或父子类（子类的返回值要能向父类隐式转换）
        访问属性不会影响覆盖
        常函数属性也会影响覆盖
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Base
{
public:
	virtual Base* func(void)
	//virtual void func(void)
	{
		cout << "我是Base的func函数"<<endl;
	}
};

class A:public Base
{
public:
	A* func(void)
    //在覆盖版本的函数中，所得到的this指针依然是实际对象地址，依然能够调用子类中的函数。
	//void func(int num,char* str)
	{
		cout<<"我是类A的func函数" << endl;
	}
};

int main()
{

	A* a = new A;
	Base* p = a;
	p->func();
}    
    
    2、重载、隐藏、覆盖（重写）的区别
        重载：同一作用域下的同名函数，函数签名不同（类型、个数、顺序、常函数等），构成重载关系。
        覆盖：
            必须是虚函数
            必须是父子类之间
            函数签名必须相同（参数列表完全一致，const属性也会影响覆盖的结果）
            返回值必须是同类型或父子类（子类的返回值要能向父类隐式转换）
            访问属性不会影响覆盖
            常函数属性也会影响覆盖
        隐藏：父子类之间的同名成员如果没有形成覆盖，且能通过编译，必定构成隐藏。
    3、多态的条件
        1、父子类之间有的函数有覆盖关系。
        2、父类的指针或引用指向子类的对象。
    4、在构造、析构函数中调用虚函数
        在父类的构造函数中调用虚函数，此时子类还没有创建完成（回顾构造函数的调用过程），因此只能调用父类的虚函数，而不是覆盖版本
的虚函数。
        在父类的析构函数中调用虚函数，此时子类已经释放完成，因此只能调用父类的虚函数，而不是覆盖版本的虚函数。
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Base
{
public:
	Base(void)
	{
		func();
	}

	virtual void func(void)
	{
		cout << "我是Base的func函数"<<endl;
	}

	~Base(void)
	{
		func();
	}
};

class A:public Base
{
public:
	A(void)
	{
		func();
	}

	void func(void)
	{
		cout<<"我是类A的func函数" << endl;
	}

	~A(void)
	{
		func();
	}
};

int main()
{
	A aa;

//	A* a = new A;
//	Base* p = a;
//	p->func();
}

六、纯虚函数和抽象类
    1、纯虚函数
    在虚函数的声明的后面添加=0，这种虚函数就叫做纯虚函数，可以不实现，但如果实现必须在类外（只能在父类的构造函数、析构函数中调用）。
    virtual 返回值 函数名(参数) = 0;

#include <iostream>
#include <stdio.h>
using namespace std;

class Base
{
public:
	Base(void)
	{
		func();
	}
	// 纯虚函数
	virtual void func(void) = 0;
	~Base(void)
	{
		func();
	}
};

class A:public Base
{
public:
	void func(void)
	{
		cout << "我是纯虚函数的覆盖"<<endl;
	}
};

void Base::func(void)
{
	cout<< "我是虚函数" << endl;
}

int main()
{
	A a;
	a.func();
	//Base b;
	//b.func();
}

    2、抽象类
    成员函数中有纯虚函数，这种类叫抽象类，抽象类不能实例化（不能创建对象）。
    抽象类必须被继承且纯虚函数被覆盖后，由子类实例化对象。
    如果继承抽象类，但没有覆盖纯虚函数，那么子类也将成为抽象类，不能实例化。

    3、纯抽象类
    所有成员函数都是纯虚函数，这种只能被继承的类叫纯抽象类。
    这种类一般用来设计接口，这种类在子类被替换后不需要修改或少量的修改即可继续使用。
#include <iostream>
using namespace std;

class Base
{
public:
	virtual void show(void) = 0;
};

class A:public Base
{
public:
	void show(void)
	{
		cout << "我是类A的show函数" << endl;
	}
};
class B:public Base
{
public:
	void show(void)
	{
		cout << "我是类B的show函数" << endl;
	}
};
class C:public Base
{
public:
	void show(void)
	{
		cout << "我是类C的show函数" << endl;
	}
};

enum ClassType{typeA,typeB,typeC};

// 工厂类模式
Base* creat_object(ClassType type)
{
	switch(type)
	{
		case typeA: return new A;
		case typeB: return new B;
		case typeC: return new C;
		default: return NULL;
	}
}

int main()
{
	Base* p = creat_object(typeA);
	p->show();
}

































一、虚函数表
    什么是虚函数表，在C++的类中，一旦成员函数中有虚函数，这个类中就会多一个虚函数表指针，这个指针指向一个虚函数表，表里面记录了
这个类中所有的虚函数，当这个类被继承，它的子类中也会有一个虚函数表（不管子类中有没有虚函数），如果子类的成员函数中有函数签名与父
类的虚函数一样，就会用子类中的函数替换它在虚函数表中的位置，这样就达到了覆盖的效果。
    当通过类指针或引用调用函数时，会根据对象中实际的虚函数表记录来调用函数，这样就达到了多态的效果。
    多态类中的虚函数表建立在编译阶段。

二、虚析构
    当使用delete释放一个父类指针时，不管实际指向的对象是子类还是父类都只会调用父类的析构函数（多态肯定会出现的问题）。
    如果子类的析构函数有需要负责释放的内存，就会造成内存泄漏。
    为了解决这个问题，可以把父类的析构函数设置为虚函数，析构函数进行覆盖时不会比较函数名。

    当父类的析构函数为虚函数时，通过父类指针或引用释放子类对象时，会自动调用子类的析构函数，子类的析构函数执行完成后也会调用父类
的析构函数。
    注意：析构函数可以是虚函数，但构造函数不行

三、强制类型转换
    注意：C++中为了兼容C语言，(目标类型)源类型 依然可以继续使用，但C语言的强制类型转换安全性差，因此建议使用C++中的强制类型转换。
    注意：C++之父认为如果代码设计的完善，根本不需要用到强制类型转换，而C++的强制类型转换之所以设计的很复杂，是为了让程序员多关注
代码本身的设计，尽量少使用。
    
    C++中的强制类型转换保证没有很大安全隐患。

    static_cast<目标类型>(源类型)   编译器会对源类型和目标类型做兼容性检查，不通过则报错。
    dynamic_cast<目标类型>(源类型)  编译器会对源类型和目标类是否同为指针或引用，并且存在多态型的继承关系。
    const_cast<目标类型>(源类型)    编译器会对源类型和目标类检查，是否同为指针或引用，除了常属性外其他必须完全相同，否则报错。
    reinterpret_cast<目标类型>(源类型)  编译器会对源类型和目标类是否为指针或整数进行检查，也就是说把整数转换成指针或把指针转换
为整数。

拓展：
    静态编译：指针或引用的目标是确定的，在编译时期就确定了所有的类型检查、函数调用。
    动态编译：指针或引用的目标是不确定的（多态），只有在函数调用的时候才确定具体是哪一个子类。


四、I/O流
    I/O流的打开模式：
        ios::in     以读权限打开文件，不存在则失败，存在不清空
        ios::out    以写权限打开文件，不存在则创建，存在则清空
        ios::app    打开文件用于追加，不存在则创建，存在不清空
        ios::binary 以二进制模式进行读写
        ios::ate    打开时定位到文件末尾
        ios::trunc  打开文件时清空
    fstream/ifstream/ofstream 类用于进行文件操作。
        构造函数或成员函数 open 用于打开文件
        good成员函数检查流是否可用
        eof成员函数用于输入流是否结束

    >> 操作符用于从文件中读取数据到变量
    << 操作符用于输出数据到文件

    IO流有一系列格式化控制函数，类似：左对齐、右对齐、宽度、填充、小数点位数。
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream fsi("test.txt",ios::in);
	//fs.open("test.txt",ios::in);
	if(!fsi.good())
	{
		cout <<"打开失败"<<endl;
	}
	else
	{
		cout <<"打开成功"<<endl;
	}


	string str,s1,s2,s3;
	int num = 0;
/*	fsi >> str;	//读到空格或换行就停止
	fsi >> num >> s1 >> s2 >> s3;
	cout<<str<<"-"<<num<<"-"<<s1<<"-"<<s2<<"-"<<s3<<endl;
*/

	string arr[10];
	int i = 0;
	while(1)
	{
		fsi >> arr[i];
		if(arr[i].size() == 0)
		{
			break;
		}
		i++;
	}

	for(int j=0; j<i; j++)
	{
		cout << arr[j] <<"-";
	}

	fstream fso("test.txt",ios::out);
	fso << "hehe" << " " << 100 <<" " <<"adsadsad"<<endl;
}


    二进制读写：read/write
        read (char_type *__s,streamsize __n)
        write (char_type *__s,streamsize __n)

        gcount成员函数可以获取上次流的二进制读写操作的字节数。

    随机读写：
        seekp (off_type,ios_base::seekdir)
        功能：设置文件的位置指针。
        off_type：偏移值
            正值向右，负值向左
        seekdir：基础位置
            ios::beg    文件开头
            ios::cur    当前位置
            ios::end    文件末尾
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	fstream fs("test.txt",ios::in);
	if(!fs.good())
	{
		cout << "文件打开失败" << endl;
		return -1;
	}
	// 调整文件的位置指针到末尾
	fs.seekp(0,ios::end);
	cout << "文件的字节数：" << fs.tellp() << endl;
	fs.close();
}

    练习：使用C++标准IO，实现带覆盖检查的cp命令。
        ./cp src dest

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char* argv[])// 写的有点问题0.0
{
	if(argc != 3)
	{
		cout << "命令错误" << endl;
	}
	// 读写
	fstream fi(argv[1],ios::in);
	fstream fo(argv[2],ios::out);
	if(!fi.good())
	{
		cout << "源文件不存在" << endl;
	}
	cout << "是否要覆盖目标文件,y/n" << endl;

	while(1)
	{
		string a;
		cin >> a;
		if(a == "y")
		{
			break;
		}

		else if(a == "n")
		{
			return 0;
		}

		else
		{
    		cout << "指令错误" << endl;
			continue;
		}
	}

	while(1)
	{
		string str;
		fi >> str;
		if(str.size() == 0)
		{
			break;
		}
		fo << str <<" "; // 文件末尾多个空格，需要删除，并且没有换行功能
	}
}

五、类型信息 typeid
    用于获取数据的类型信息。
    name成员函数，可以获取类型的名字，内建类型名字使用缩写。
    同时还支持 == != 用来比较是否是同一种类型。

    如果用于判断父子类的指针或引用，它不能准确判断出实际的对象类型。但可以判断出具有多态继承关系的父子类的指针或引用，它的实际对象。
#include <iostream>
#include <typeinfo>
using namespace std;

class Base
{
public:
	virtual ~Base(void)
	{
	}
};

class Test:public Base
{

};

int main()
{
	Base b;
	Test t;
	cout << typeid(b).name() << endl;
	cout << (typeid(t) == typeid(b)) << endl;

	cout << endl;
	Base* p = new Test;
	cout << (typeid(*p) == typeid(Test)) << endl;
	cout << (typeid(p) == typeid(Test*)) << endl;

}

    扩展：
        sudo find / -name filename
        sudo find / | grep "std"
        grep 'Base' *               当前目录查找包含此字符的文件
        grep -r 'Base' *            当前目录及所有子级目录，查找包含此字符的文件
        grep -r 'Base' * dir        指定目录下及所有子级目录，查找包含此字符的文件


五、异常处理
    抛异常
        throw 数据
        抛异常对象
        抛基本类型
        注意：不能抛出局部对象的指针或引用（构造函数和析构函数不能抛出异常）。
        注意：如果异常没有被捕获处理，程序就会停止。
    捕获异常
        try{
            可以抛出异常的代码
        }
        catch(类型 变量名) // 根据数据类型进行捕获
        {
            处理异常，如果无法处理可以继续抛出异常
        }
        注意：捕获异常的顺序是自上而下的，而不是最精准的匹配，针对子类异常捕获时要放在父类的前面。

        函数的异常声明：
            返回值类型 函数名(参数列表)throw(类型1,类型2,...)
            注意：如果不写异常声明表示什么类型的异常都可能抛出。
            注意：如果写了异常声明表示只抛出某些类型的异常，一旦超出异常声明的范围，程序会直接停止，无法捕获。
            注意：throw() 表示什么类型都不会抛出
            

        设计异常类：
        class Error
        {
            int errno;
            char errmsg[255];
        public:
            Error(int errno = -1,const char* msg = "未知错误")
            {
                this->errno = errno;
                strcpy(errmsg,msg);
            }
            int getError(void)
            {
                return errno;
            }
            const char* getErrmsg(void)
            {
                return errmsg;
            }
        }
