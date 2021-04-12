#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// char *strcpy(char *strDest, char *strSrc)
// {
//     if (strDest == nullptr || strSrc == nullptr)
//         return nullptr;
//     char *ret = strDest;
//     while ((*strDest++ = *strSrc++) != '\0')
//         ;
//     return ret;
// }
void *
memcpy(void *Dest, const void *Src, size_t len)
{
    if (strDest == nullptr || strSrc == nullptr)
        return nullptr;
    void *ret = Dest;
    char *dst = Dest;
    const char *src = Src;
    if (src < dst && src + len > dst)
    {
        while ((*dst = *src++) != '\0')
            ;
    }
    else
    {
        dst += len - 1;
        src += len - 1;
        while (len--)
        {
            *dst-- = *src--;
        }
    }
    return ret;
}
int main()
{
    return 0;
}