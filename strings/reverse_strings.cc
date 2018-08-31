#include <iostream>
#include <string>

void reverseSentenceWords(std::string &input_string, std::string &output_string)
{
    char const *traverse = input_string.c_str();
    int i = 0;
    std::string temp = "";
    while(i < input_string.length())
    {
        if(input_string[i] == ' ')
        {   
            std::cout<<temp<<std::endl;
            output_string += temp + " ";
            temp = "";
        }
        else
        {
            temp = input_string[i]+temp;
        }
        i++;
    }
    std::cout<<temp;
    output_string += temp;
}

int main()
{
    std::string input_string;
    std::string output_string;

    std::cout<<"\nEnter Input Sentence:-";
    getline(std::cin,input_string);

    reverseSentenceWords(input_string, output_string);

    std::cout<<"\nReverse Sentence of "<<input_string<<" is "<<output_string<<std::endl;
    return 0;
}
