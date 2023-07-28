#include <iostream>
#include <string>
#include <vector>

template<typename T>
T maximum(T a, T b){
    return (a>b) ? a : b;
}

template<typename Tattribut1, typename Tattribut2>
class Pair{
    private:
    Tattribut1 nb1;
    Tattribut2 nb2;
    public:
    Pair(const Tattribut1& _nb1, Tattribut2 _nb2) : nb1(_nb1), nb2(_nb2){};

    int getFirst(){
        std::cout<<nb1<<std::endl;
        return nb1;
    }
    float getSecond(){
        std::cout<<nb2<<std::endl;
        return nb2;
    }
};

template<typename Tattribut3>
class Pair2{
    private:
    Tattribut3 nb1;
    Tattribut3 nb2;
    public:
    Pair2(const Tattribut3& _nb1, Tattribut3 _nb2) : nb1(_nb1), nb2(_nb2){};

    int getFirst(){
        std::cout<<nb1<<std::endl;
        return nb1;
    }
    float getSecond(){
        std::cout<<nb2<<std::endl;
        return nb2;
    }
};


int main(){
int tableau[]={1, 4, 3, 6, 8};
int max = sizeof(tableau)/sizeof(int);
int a = tableau[0];

for (size_t i = 0; i < max; i++)
{
    a= maximum(a, tableau[i]);
}
std::cout<< "Le nombre max est : "<< a << std::endl;

Pair<int, float> both(2, 4.5);
Pair2<int> intPair(2, 4);
Pair2<float> floatPair(2.2, 6.3);
Pair2<std::string> stringPair("Hello", "World");

both.getFirst();
both.getSecond();
intPair.getFirst();
intPair.getSecond();
floatPair.getFirst();
floatPair.getSecond();

return 0;
}