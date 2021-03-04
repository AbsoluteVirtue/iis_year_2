#include <cmath>
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

double binary()
{
    const char *bin = "1010";
    double res = 0;
    for (int i = 0, j = strlen(bin) - 1; j >= 0; ++i, --j)
    {
        if (bin[j] == '1')
            res += pow(2, i);
    }
    return res;
}

char *_strcat(char *dest, const char *src, size_t n)
{
    size_t i, j;
    for (i = 0; dest[i] != '\0'; i++)
        ;
    for (j = 0; src[j] != n; j++)
    {
        if (src[j] == '\0')
            break;
        dest[i + j] = src[j];
    }

    dest[i + j] = '\0';
    return dest;
}

std::string get_address(const void * val)
{
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

int main(int argc, char const *argv[])
{
    std::istringstream buf;
    buf.str("1 2\n3 4\n");
    for (std::string line; std::getline(buf, line); )
    {
        std::cout << line;
    }

    int * p = new int(10);
    std::cout << get_address(p);
    
    return 0;
}
