#include<utility>
#include <iostream>
#include <chrono>
using namespace std;
class  Buffer
{
public:
	Buffer(Buffer&&other) noexcept :data(other.data), size(other.size) {
		other.data = nullptr;
		other.size = 0;
	 }
    Buffer(size_t n,int number)
    {
        data = new int[n];
        for (int i = 0;i < n;i++)
        {
            data[i] = number;   
        }
        size = n;
    }
    Buffer(Buffer& other)
    {
        data = new int[other.size];
        for (int i = 0;i < other.size;i++)
        {
            data[i] = other.data[i];
        }
        size = other.size;
    }
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;          // 释放自己原有资源
            data = other.data;      // 偷
            size = other.size;
            other.data = nullptr;   // 置空
            other.size = 0;
        }
        return *this;
    }
    Buffer& operator=(Buffer& other)
    {
        if (this !=&other)
        {
            delete[] data;
            data = new int[other.size];
            for (int i = 0;i < other.size;i++)
            {
                data[i] = other.data[i];
            }
            size = other.size;
        }
        return *this;
    }
    ~Buffer() { delete[] data; }
private:
	int* data;
	size_t size;
};


int main()
{
    Buffer a(100000000, 1);
    auto start1 = std::chrono::high_resolution_clock::now();
    Buffer b= move(a);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> fms = end1 - start1;
    std::cout << "耗时: " << fms.count() << " ms\n";
    Buffer c(100000000, 1);
    start1= std::chrono::high_resolution_clock::now();
    Buffer d = c;
    end1 = std::chrono::high_resolution_clock::now();
    fms = end1 - start1;
    std::cout << "耗时: " << fms.count() << " ms\n";
}