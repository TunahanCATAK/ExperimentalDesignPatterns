#include <iostream>
#include <thread>

class Foo {

private:
    static std::shared_ptr<Foo> m_instance;
    std::string m_clientName;

protected:
    Foo(const std::string& clientName): m_clientName(clientName) {}

public:
    // Singleton object should not be copyable:
    Foo(Foo& other) = delete;
    void operator=(const Foo&) = delete;

    static std::shared_ptr<Foo> getInstance(const std::string& clientName);

    void TestFunc()
    {
        std::cout << "Foo<" << m_clientName << ">.TestFunc() is called." << std::endl;
    }
};

std::shared_ptr<Foo> Foo::m_instance = nullptr;
std::shared_ptr<Foo> Foo::getInstance(const std::string& clientName)
{
    if (m_instance == nullptr)
    {
        m_instance = std::shared_ptr<Foo>( new Foo(clientName));
    }

    return m_instance;
};

int main() {
    std::cout << "Singleton Design Pattern Client Usage" << std::endl;

    //auto FooObj = Foo::getInstance("ClientA");
    //FooObj->TestFunc();

    auto getSingleton = [](const std::string& clientName) -> std::shared_ptr<Foo> {
        auto FooObj = Foo::getInstance(clientName);
        FooObj->TestFunc();

        return FooObj;
    };

    std::thread thread1(getSingleton, "thread1");
    std::thread thread2(getSingleton, "thread2");

    thread1.join();
    thread2.join();


    return 0;
}
