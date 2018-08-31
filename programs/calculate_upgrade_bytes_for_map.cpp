// you can use includes, for example:
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
std::vector<std::string> getLines(const std::string &input)
{
    std::vector<std::string> lines;
    size_t line_index = input.find("\n");
    size_t prev_index = 0;
    size_t length = line_index;
    if(line_index == std::string::npos)
    {
#if DEBUG
        std::cout<<"Adding Line:"<<input<<std::endl;
#endif
        lines.push_back(input); 
    }
    while(line_index != std::string::npos)
    {
        std::string line = input.substr(prev_index, length);
#if DEBUG
        std::cout<<"Adding Line:"<<line<<std::endl;
#endif
        lines.push_back(line);
        prev_index = line_index+1;
        line_index = input.find("\n", prev_index+1);
#if DEBUG
        std::cout<<"next find index:"<<line_index<<std::endl;
#endif
        if(line_index == std::string::npos)
        {
            line = input.substr(prev_index, input.length()-prev_index);
            lines.push_back(line);
        }
        else
        {
            length = line_index - prev_index;
        }
    }
#if DEBUG
    for(auto &x : lines)
        std::cout<<"Line:"<<x<<std::endl;
#endif
    return lines;
}
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
bool getInstalledVersions(const std::vector<std::string> &lines, std::map<std::string, int> &installed_versions)
{
    for(auto &x : lines)
    {
        size_t count = std::count(x.begin(), x.end(), ',');
        if(count != 1)
        {
            std::cout<<"Ignoring Line as it is not in expected format:"<<std::endl;
            continue;
        }
        size_t position = x.find(",");
        std::string region_name = x.substr(0, position);
        std::string region_version = x.substr(position+1, x.length() - position);
#if DEBUG
        std::cout<<"region_name:"<<region_name<<std::endl;
        std::cout<<"region_version:"<<region_version<<std::endl;
#endif
        installed_versions.emplace(region_name, stoi(region_version));
    }
    return true;
}

int upgradeBytes(std::vector<std::string>& lines, const std::string &region, const int version)
{
    int bytes = 0;
    for(auto& x: lines)
    {
        if(x.find(region) != std::string::npos)
        {
            size_t count = std::count(x.begin(), x.end(), ',');
            if(count != 2)
            {
                std::cout<<"Ignoring Line as it is not in expected format:"<<std::endl;
                continue;
            }
            size_t version_start_index = x.find(",");
            size_t bytes_start_index = x.find(",", version_start_index+1);
            int version_no = stoi(x.substr(version_start_index+1, bytes_start_index-version_start_index -1));
            int bytes_needed = stoi(x.substr(bytes_start_index+1, x.length()));

#if DEBUG
            std::cout<<"Version_No "<<version_no<<" bytes "<<bytes_needed<<std::endl;
#endif
            if(version_no > version)
            {
                bytes += bytes_needed;
            }
        }
    }
#if DEBUG
    std::cout<<"Total Bytes Needed for upgarde:"<<bytes<<std::endl;
#endif
    return bytes;
}
int solution(const std::string &S, const std::string &T, const std::string &U) {
        // write your code in C++14 (g++ 6.2.0)
        if(S.find(U) == std::string::npos)
                    return -1;
        std::map<std::string, int> installed_versions;
        std::vector<std::string> available_versions_lines = getLines(S);
        std::vector<std::string> installed_versions_lines = getLines(T);
        getInstalledVersions(installed_versions_lines, installed_versions);
#if DEBUG
        std::cout<<"Installed Versions:";
        for(auto &x : installed_versions)
                std::cout << " [" << x.first << ':' << x.second << ']'<<std::endl;
#endif
        int installed_version = 0;
        auto found = installed_versions.find(U);
        if(found != installed_versions.end())
            installed_version = found->second;
#if DEBUG
        std::cout<<"Installed version for region :"<<U<<" is "<<installed_version<<std::endl;
#endif
        int bytes_to_upgrade = upgradeBytes(available_versions_lines, U, installed_version);
#if DEBUG
        std::cout<<"Bytes Needed to Upgarde:"<<bytes_to_upgrade;
#endif
        return bytes_to_upgrade;
}

int main()
{
    int result = solution("Netherlands,1,25000\nNetherlands,2,3000\nNetherlands,3,1000", "Netherlands,1", "Netherlands");
    std::cout<<"Expected 4000 Got "<<result<<std::endl;
    result = solution("Netherlands,1,25000\nNetherlands,2,3000\nNetherlands,3,1000", "Netherlands,2\nBelgium,4", "United Kingdom");
    std::cout<<"Expected -1 Got "<<result<<std::endl;
    result = solution("Netherlands,1,25000\nNetherlands,2,3000\nNetherlands,3,1000", "Netherlands,2\nBelgium,4\nIndia,5", "Netherlands");
    std::cout<<"Expected 1000 Got "<<result<<std::endl;
}
