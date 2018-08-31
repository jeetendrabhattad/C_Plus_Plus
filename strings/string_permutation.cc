#include <iostream>
#include <vector>
void Permutations(std::string &input_str, std::string prefix, std::vector<std::string> &permutations)
{
    if(0 == input_str.length())   
    {
        //std::cout<<"Permutation:"<<prefix<<std::endl;
        permutations.push_back(prefix);
    }
    else
    {
        for(int i = 0 ; i < input_str.length() ; i++)
        {
            //std::cout<<input_str<<":"<<input_str.substr(0, i)<<":"<<input_str.substr(i+1)<<":"<<i<<std::endl;
            
            std::string rem = input_str.substr(0, i) + input_str.substr(i+1);
            //std::cout<<"rem:"<<rem<<":"<<prefix+input_str.at(i)<<std::endl;
            Permutations(rem, prefix+input_str.at(i), permutations);
        }
    }
}

int main()
{
    std::string input_str = "";
    std::cout<<"Enter String Whose Permutations are to be printed :-";
    std::cin>>input_str;
    std::vector<std::string> permutations;
    Permutations(input_str, "", permutations);

    for (auto it = permutations.begin() ; it != permutations.end() ; it++)
        std::cout<<*it<<std::endl;
    std::string permutate_string;
    std::cout<<"Enter String in which to check how many of the permutations are present:-";
    std::cin>>permutate_string;
    int count = 0;
    for (auto it = permutations.begin() ; it != permutations.end() ; it++)
    {
        if(permutate_string.find(*it))
            count++;
    }
    std::cout<<"Total Number of Permutations of "<<input_str<<":"<<permutate_string<<" is "<<count<<std::endl;
    return 0;
}
