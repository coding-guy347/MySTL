#pragma once

namespace mystl {

    template<bool B, typename T, typename F>
    struct conditional { using type = T; };

    template<typename T, typename F>
    struct conditional<false, T, F> { using type = F; };

    template<bool B, typename T, typename F>
    using conditional_t = typename conditional<B, T, F>::type;

    // 2. 标签
    struct true_type {
        static constexpr bool value = true;
        using type = true_type;
    };

    struct false_type {
        static constexpr bool value = false;
        using type = false_type;
    };

    // 3. is_same (修复了报错)
    template<typename T, typename U>
    struct is_same : public false_type {};

    template<typename T>
    struct is_same<T, T> : public true_type {};

    // 4. 判断算术类型
    template<typename T> struct is_arithmetic : false_type {};
    template<> struct is_arithmetic<bool> : true_type {};
    template<> struct is_arithmetic<char> : true_type {};
    template<> struct is_arithmetic<int> : true_type {};
    template<> struct is_arithmetic<long> : true_type {};
    template<> struct is_arithmetic<float> : true_type {};
    template<> struct is_arithmetic<double> : true_type {};
    template<> struct is_arithmetic<short> : true_type {};
    template<> struct is_arithmetic<long long> : true_type {};
    template<> struct is_arithmetic<unsigned int> : true_type {};
    template<> struct is_arithmetic<unsigned long> : true_type {};
    template<> struct is_arithmetic<unsigned long long> : true_type {};
    // 5. 判断指针
    template<typename T> struct is_pointer : false_type {};
    template<typename T> struct is_pointer<T*> : true_type {};

    // 6. 纯手工打造 is_trivially_destructible
    template<typename T>
    struct is_trivially_destructible
        : public conditional_t< (is_arithmetic<T>::value || is_pointer<T>::value),
        true_type,
        false_type >
    {};

    template<bool B, typename T = void>
    struct enable_if {
        using type = T;
    };

    template<typename T>
    struct enable_if<false, T> {
    };

    template<bool B, typename T = void>
    using enable_if_t = typename enable_if<B, T>::type;
}