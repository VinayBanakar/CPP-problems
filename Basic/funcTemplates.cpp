#include <iostream>
#include <cstring>

template<typename T>
T max(T x, T y){
    return (x>y)?x:y;
}

// Since function params can be a Class type and its not a good idea to pass Class by value,
// make the params and return types of our templated func const refernces.

template<typename T1>
const T1& min(const T1& x, const T1& y) {
    return (x>y)?y:x;
}

template<typename T>
class A{
    public:
        T val;
    A(T x=0):val(x){}

    /**
     * ==== Right to left ====
     * For instance, int const&* const** means «A pointer to int const&* const*»;  
     * the * in types operates on everything on the left of it.
     * 
     *      * const applies to what is to the left of const
     *      * the exception to the rule is when const comes first
     *      * in which case const applies to the thing to the right of const
     *      * because if const comes first, then there is nothing to the left of const
     * 
     */ 

    friend bool operator>(A const& a1, A const& a2){ 
        return (a1.val > a2.val);
    }
};

template<typename T, int z>
class Array{
    private:
        T m_array[z];
    public:
        T* getArray() { return m_array;}

        T& operator[](int index){
            //can also validate if index is OOB.
            return m_array[index];
        }
};

template <typename T, int size>
void print(Array<T,size> &array){
    for(int i =0;i < size; ++i){
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

// This overrides print function to catter specific needs by specific type and size of Array.
template<>
void print(Array<char, 6> &array){
    // Something
}

int main(){
    A<int> a1(5);
    A<int> a2(6);
    std::cout << min(a1,a2).val << std::endl;

    Array<int,5> arr;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    print(arr);

    Array<char,5> arc;
    strcpy(arc.getArray(), "vinay");
    print(arc);
}