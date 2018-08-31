#include <iostream>

enum DAYS{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

enum DIGITS{
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN
};

enum class DAYS11{
    MONDAY11,
    TUESDAY11,
    WEDNESDAY11,
    THURSDAY11,
    FRIDAY11,
    SATURDAY11,
    SUNDAY11
};

enum DIGITS11{
    ZERO11,
    ONE11,
    TWO11,
    THREE11,
    FOUR11,
    FIVE11,
    SIX11,
    SEVEN11,
    EIGHT11,
    NINE11,
    TEN11
};

int main()
{
    DAYS day = MONDAY;
    DIGITS digit = ZERO;
    std::cout << __cplusplus << std::endl;
    /* Warning seen with older declaration
    enum_difference.cpp:56:15: warning: comparison between ‘enum DAYS’ and ‘enum DIGITS’ [-Wenum-compare]
         if(day == digit)
    */
    if(day == digit)
    {
        std::cout<<"Day & Digits are Same...."<<std::endl;
    }

    DAYS11 day11 = DAYS11::MONDAY11;
    DIGITS11 digit11 = DIGITS11::ZERO11;
    /* Error seen with new declaration
     enum_difference.cpp:64:14: error: no match for ‘operator==’ (operand types are ‘DAYS11’ and ‘DIGITS11’)
         if(day11 == digit11)
    */
    if(day11 == digit11)
    {
        std::cout<<"Day11 & Digits11 are Same...."<<std::endl;
    }
    return 0;
}
