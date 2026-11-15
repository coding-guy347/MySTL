#pragma once
#include<new>
#include<cstddef>
#include"type_traits.h"
#include<utility>
namespace mystl
{
	template<typename T>
	class  allocator
	{
	public:
		static T* allocate(size_t n)
		{
			if (n == 0) return nullptr;
			return static_cast<T*>(::operator new(n * sizeof(T)));
		}

		static void deallocate(T* p, size_t n)
		{
			if (p == nullptr) return;
			::operator delete(p);
		}

		template<typename...Args>
		static void construct(T* p, Args&&...args)
		{
			::new((void*)p)T(std::forward<Args>(args)...);
		}

		static void destroy_impl(T* p, true_type)
		{

		}
		static void destroy_impl(T* p, false_type)
		{
			p->~T();
		}
		static void destroy(T* p)
		{
			destroy_impl(p, is_trivially_destructible<T>{});
		}
	};
}