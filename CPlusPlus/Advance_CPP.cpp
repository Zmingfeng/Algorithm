#include<iostream>

enum DATA_TYPE
{
	TYPE_INT,
	TYPE_FLOAT,
};

template <typename T> class TypeToID
{
public:
    static int const ID = -1;
};

template <> class TypeToID<uint8_t>
{
public:
    static int const ID = 0;
};

template <> class TypeToID<void*>
{
public:
    static int const ID = 0x401d;
};

void PrintID()
{
    std::cout << "ID of uint8_t: " << TypeToID<uint8_t>::ID << std::endl;
}

#define BIN_OP(type, a, op, b, result) (*(type *)(result)) = (*(type const *)(a)) op (*(type const*)(b))

void doDiv(void* out, void const* data0, void const* data1, DATA_TYPE type)
{
    if(type == TYPE_INT)
    {
        BIN_OP(int, data0, *, data1, out);
    }
    else
    {
        BIN_OP(float, data0, +, data1, out);
    }
}

int main(void)
{
    int a = 5,b = 6,c;
	DATA_TYPE my_int = TYPE_INT;
	doDiv(&c,&a,&b,my_int);
	std::cout << c << std::endl;
	PrintID();
	return 0;
}