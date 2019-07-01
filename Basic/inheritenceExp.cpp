#include <iostream>
#include <string>

class Person{
    private: 
        int m_val;
    public:
        std::string m_name;
        int hideMe;
        int m_age;

        Person(std::string name = "", int age = 0, int val = 1):
            m_name(name),
            m_age(age),
            m_val(val) {}

        std::string getName() const {return m_name;}
        int getAge() const {return m_age;}      
    protected:
        void protectFunc(){
            std::cout << "val\t" <<  m_val << std::endl;
        }
};

// Class BaseBallPlayer inherits Person
class BaseBalllPlayer : public Person{
    private: 
    // making hideMe inaccsessible
    using Person::hideMe;
    public:
        double m_battingAverage;
        int m_homeRuns;
    
        BaseBalllPlayer(double batAverage = 0.0, int homeRun = 0):
            m_battingAverage(batAverage),
            m_homeRuns(homeRun){}
        // Will make the inherited protected protectFunc public.
        using Person::protectFunc;
};

int main(){
    BaseBalllPlayer num1;
    num1.m_name = "rock";
    std::cout << num1.getName() << std::endl;
    // Accesing protected method from Base. Protected is only for its children class.
    num1.protectFunc();
    // num1.hideMe; This wont work because BaseBallPlayer hid the value that was derived from Person.

}