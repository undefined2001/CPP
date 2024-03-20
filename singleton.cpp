#include <iostream>

/**
 * @brief this code is to show the use of singleton which is refer to the design where
 * @brief a single instance is created of a particular class and Shared throughout all the codes
*/

class Singleton
{
protected:
    Singleton() = default;

public:
    int age = 22;
    
    static Singleton _instance;
    static Singleton &get_instance()
    {
        return _instance;
    }
};

Singleton instance =  Singleton::get_instance();

int not_main()
{
    std::cout << instance.age << std::endl;

    return 0;
}