#include <iostream>

using namespace std;

class SingleInstance
{
public:
    static SingleInstance *Instance()
    {
        static SingleInstance singleInstacne;
        return &singleInstacne;
    }
    void Init()
    {
    }

private:
    SingleInstance() {}
    ~SingleInstance() {}
    SingleInstance(const SingleInstance &other) = delete;
    SingleInstance &operator=(const SingleInstance &other) = delete;
};
int main()
{
    SingleInstance::Instance()->Init();

    return 0;
}