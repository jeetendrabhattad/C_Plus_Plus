#include <iostream>

std::string removeChars(const std::string input_string, const std::string remove_string)
{
    std::string output_string = "";
    bool char_remove[128] = {false};

    int i=0;
    while(i < remove_string.length())
    {
        char_remove[remove_string[i]] = true;
        ++i;
    }

    i = 0;
    while(i < input_string.length())
    {
        if(char_remove[input_string[i]] == false)
            output_string += input_string[i];
        ++i;
    }
    return output_string;
}

int main()
{
    std::string input_string;
    std::string remove_string;
    std::string output_string;

    std::cout<<"\nEnter Input String:";
    getline(std::cin, input_string);
    std::cout<<"\nEnter Remove Characters String:";
    std::cin>>remove_string;
    output_string = removeChars(input_string, remove_string);

    std::cout<<"After removing "<<remove_string<<" from "<<input_string<<" "<<output_string<<std::endl;
}
