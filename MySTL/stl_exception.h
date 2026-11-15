#pragma once
#include<exception>
namespace mystl
{
	class out_of_range :public std::exception
	{
	public:
		const char* what() const noexcept {
			return "mystl::out_of_range: 索引越界啦！";
		}
	};

    class empty_container : public std::exception {
    public:
        const char* what() const noexcept override {
            return "mystl::empty_container: 容器是空的，没法操作！";
        }
    };

    class bad_alloc : public std::exception {
    public:
        const char* what() const noexcept override {
            return "mystl::bad_alloc: 内存不够了！";
        }
    };
}