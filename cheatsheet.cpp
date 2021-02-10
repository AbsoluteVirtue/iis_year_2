#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int get_random_range(int lower, int upper)
{
    return lower + (rand() % (upper - lower));
}

std::size_t strlen(const char* start) {
   const char* end = start;

   while (*end++ != 0);

   return end - start - 1;
}

void split(const std::string & str, const std::string & delim, std::vector<std::string> & parts)
{
    size_t start, end = 0;
    while (end < str.size())
    {
        start = end;
        while (start < str.size() && (delim.find(str[start]) != std::string::npos))
        {
            start++;
        }
        end = start;
        while (end < str.size() && (delim.find(str[end]) == std::string::npos))
        {
            end++;
        }
        if (end - start != 0)
        {
            parts.push_back(std::string(str, start, end - start));
        }
    }
}

int main(int argc, char const *argv[])
{
    std::istringstream buf;
    buf.str("1 2\n3 4\n");
    for (std::string line; std::getline(buf, line); )
    {
        std::cout << line;
    }
    
    return 0;
}
