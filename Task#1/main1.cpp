#include <iostream>
#include <string>
#include <vector>

class Talent //: virtual public Dog
{
public:
    virtual std::string skill() = 0;
};
class Dancing : public Talent
{
public:
    std::string skill() override
    {
        return "Dance";
    }
};
class Counting : public Talent
{
public:
    std::string skill() override
    {
        return "Count";
    }
};
class Swimming : public Talent
{
public:
    std::string skill() override
    {
        return "Swim";
    }
};

class Dog
{
    std::string name;
    std::vector<Talent *> talents;

public:
    Dog(std::string _name, int quantity) : name(_name)
    {
        for (int i = 0; i < quantity || i < 3; ++i)
        {
            if (i == 0)
                talents.push_back(new Swimming());
            else if (i == 1)
                talents.push_back(new Counting());
            else if (i == 2)
                talents.push_back(new Dancing());
        }
    }
    void show_talents()
    {
        std::cout << "This is " << name << " and it has some talents: " << std::endl;
        for (int i = 0; i < talents.size(); i++)
        {
            std::cout << "\tWIt can \"" << talents[i]->skill() << "\'" << std::endl;
        }
    }
};

int main()
{
    Dog dog1("Steve", 3);
    dog1.show_talents();
}