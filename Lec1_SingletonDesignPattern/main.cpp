#include <iostream>
#include <thread>


// Singleton Class
template <class T>
class Singleton {

private:
    static std::shared_ptr<T> m_instance;
    std::string m_clientName;

protected:
    Singleton(const std::string& clientName): m_clientName(clientName) {}

public:
    Singleton(Singleton& other) = delete;
    void operator=(const Singleton&) = delete;

    static std::shared_ptr<T> getInstance(const std::string& clientName);
};

template<typename T>
std::shared_ptr<T> Singleton<T>::m_instance = nullptr;
template<typename T>
std::shared_ptr<T> Singleton<T>::getInstance(const std::string &clientName)
{
    if (m_instance == nullptr)
    {
        m_instance = std::shared_ptr<T>( new T(clientName));
    }

    return m_instance;
}

// User Defined Classes: 
class Bar {
private:
    std::string m_clientName;
public:
    Bar(const std::string& clientName): m_clientName(clientName) {}
    void TestFunc()
    {
        std::cout << "Bar<" << m_clientName << ">.TestFunc() is called." << std::endl;
    }
};

class NoPublicConstructor{
private:
    std::string m_clientName;
    NoPublicConstructor(const std::string& clientName): m_clientName(clientName) {}
public:
    void TestFunc()
    {
        std::cout << "NoPublicConstructor<" << m_clientName << ">.TestFunc() is called." << std::endl;
    }
};

int main() {
    std::cout << "Singleton Design Pattern Client Usage" << std::endl;

    auto getSingletonBar = [](const std::string& clientName) -> std::shared_ptr<Bar> {
        auto BarObj = Singleton<Bar>::getInstance(clientName);
        BarObj->TestFunc();

        return BarObj;
    };

    std::thread thread3(getSingletonBar, "thread3");
    std::thread thread4(getSingletonBar, "thread4");

    thread3.join();
    thread4.join();

//    auto errorObj = Singleton<NoPublicConstructor>::getInstance("ClientA"); -> Compiler Error, calling a private constructor.
//    errorObj->TestFunc();

    return 0;
}
