#include <iostream>
#include <string>

int totalPerms = 1;
void printString(const std::string& str) 
{
    std::cout << str << ' ';
    if (totalPerms % 26 == 0) std::cout << std::endl;
    totalPerms++;
}

bool isAllAfterZ(const std::string& str, int index)
{
    bool isAllZ = true;
    for (int i = index + 1; i < str.size(); i++)
    {
        if (str[i] != 'z')
            isAllZ = false;
    }
    return isAllZ;
}

bool isSomeAfterLessZ(const std::string& str, int index)
{
    bool isSomeLessZ = false;
    for (int i = index + 1; i < str.size(); i++)
    {
        if (str[i] < 'z')
            isSomeLessZ = true;
    }
    return isSomeLessZ;
}

int main()
{
    std::string s = "aaaa";
    std::string target(s.size(), 'z');
    printString(s);
    int counter = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i != s.size() - 1 && isSomeAfterLessZ(s, i)) continue; 
        if (s.compare(target) == 0) break;  
    
        if (i == s.size() - 1 || isAllAfterZ(s, i))
        {
            s.replace(i, 1, 1, ++s[i]);
            for (int j = i + 1; j < s.size(); j++)
               s.replace(j, 1, 1, 'a');
        }

        printString(s);
        i = -1;
    }
    std::cout << std::endl;
}
