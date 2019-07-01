#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;

// Use structs for data only and classes for data + behavior
// A class defaults its members to private. A struct defaults its members to public.
// Also classes does not require forward declaration of methods in public.
class DataClass {

    int m_year; // private by default
    int m_month;
    int m_day;
    
    public:
        std::string m_val = "Monday";
        void setDate(int month, int day, int year){
            m_month = month;
            m_day = day;
            m_year = year;
        }

        void print(){
            cout << m_year << "/" << m_month << "/" << m_day << " " << m_val << endl;
        }

        void copyForm(DataClass& d){
            m_month = d.m_month;
            m_year = d.m_year;
            m_day = d.m_day;
        }
};

class Stack{
    public:
        std::vector<int>* vec = new std::vector<int>;
        Stack(){
            push(100);
            push(200);
        }
        // Says first do Stack() then do rest of code in the braces.
        Stack(int x):Stack(){
            push(300);
            push(400);
        }

        // friend functions which overloads '+' operator to add top elements of each stack.
        // friend functions is not a member function, even though the prototype appeass in 
        // class definition. It can access private and protected members of the calss.
        friend int operator+(const Stack &s1, const Stack &s2);

        // This is automatically called when the object is destroyed. A destructor.
        ~Stack(){
            cout << "Destructing Stack" << '\n';
            delete vec;
        }

        bool randomFunc(int x);

        void push(int x){
            (*vec).push_back(x);
        }

        void pop(){
            (*vec).pop_back();
        }

        int top(){
            return (*vec).back();
        }

        void print(){
            for(int i = 0; i< (*vec).size(); ++i){
                cout << (*vec)[i] << " ";
            }
            cout << endl;
        }
};

// This friend function can also be defined inside the Class, there is no harm.
int operator+(Stack& s1, Stack& s2){
    return s1.top() + s2.top();
}

bool Stack::randomFunc(int x){
    push(x);
}

class Timer {
    private:
        using clock_t = std::chrono::high_resolution_clock;
        using second_t = std::chrono::duration<double, std::ratio<1>>;

        std::chrono::time_point<clock_t> m_beg;
    
    public:
        Timer(): m_beg(clock_t::now()){}

        void reset(){
            m_beg = clock_t::now();
        }

        double elapsed() const {
            return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
        }
};

int main(){
    Timer t;

    DataClass today;
    today.setDate(7,1,2019);
    today.m_val = "random";
    today.print();

    DataClass* abc = new DataClass();
    //(*abc).setDate(0,0,0);
    (*abc).copyForm(today);
    (*abc).print();

    delete abc;

    Stack stack(1);
    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.randomFunc(11);
    stack.print();
    stack.pop();
    cout << stack.top() << endl;
    Stack stack2(2);
    cout << "stack + stack2: " << stack + stack2 << endl;
    cout << "Total time taken for main(): " << t.elapsed() << endl;
}