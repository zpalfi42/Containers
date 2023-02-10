#ifndef	IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace	ft
{
	/**
	 * @brief integral_constant is a template struct that identifies if 'T' is an integral constant or not. If it is, it initialize a 'value' that can be used by others, if not, this 'value' is NULL.
	 * 
	 * @tparam T 
	 * @tparam v 
	 */
	template <class T, T v>
	struct integral_constant
	{
		static const T value = v;
		typedef T value_type;
		typedef integral_constant<T,v> type;
		const T operator()( void ) { return v; }
	};

	typedef	const	ft::integral_constant<bool, true>	true_type;
	typedef	const	ft::integral_constant<bool, false>	false_type;

	/**
	 * @brief is_integral is a template struct that has some explicit templates. If is_integral is called with any specific template, it will inherit from true_type, else it will inherit from false_type.
	 * To see more information about true_type and false_type you can read the information about integral_constant.
	 * 
	 * 
	 * @tparam T 
	 */
	template <class T>
	struct	is_integral: public false_type {};

	/**
	 * @brief Explicit template for is_integral when an 'unsigned char' is passed as param.
	 * 
	 * @tparam  
	 */
	template <>
	struct	is_integral<unsigned char>: public true_type {};

	/**
	 * @brief Explicit template for is_integral when an 'unsigned short' is passed as param.
	 * 
	 * @tparam  
	 */
	template <>
	struct	is_integral<unsigned short>: public true_type {};

	/**
	 * @brief Explicit template for is_integral when an 'unsigned int' is passed as param.
	 * 
	 * @tparam  
	 */
	template <>
	struct	is_integral<unsigned int>: public true_type {};

	/**
	 * @brief Explicit template for is_integral when an 'unsigned long' is passed as param.
	 * 
	 * @tparam  
	 */
	template <>
	struct	is_integral<unsigned long>: public true_type {};

	/**
	 * @brief Explicit template for is_integral when a 'signed char' is passed as param.
	 * 
	 * @tparam  
	 */
	template <>
	struct	is_integral<signed char>: public true_type {};

	/**
	 * @brief Explicit template for is_integral when a 'short' is passed as param.
	 * 
	 * @tparam  
	 */
	template <>
	struct	is_integral<short>: public true_type {};

	/**
	 * @brief Explicit template for is_integral when a 'int' is passed as param.
	 * 
	 * @tparam  
	 */
	template <>
	struct	is_integral<int>: public true_type {};

	/**
	 * @brief Explicit template for is_integral when a 'long' is passed as param.
	 * 
	 * @tparam  
	 */
	template <>
	struct	is_integral<long>: public true_type {};

	/**
	 * @brief Explicit template for is_integral when a 'long long' is passed as param.
	 * 
	 * @tparam  
	 */
	template <>
	struct	is_integral<long long>: public true_type {};

	/**
	 * @brief Explicit template for is_integral when a 'char' is passed as param.
	 * 
	 * @tparam  
	 */
	template <>
	struct	is_integral<char>: public true_type {};

	/**
	 * @brief Explicit template for is_integral when a 'bool' is passed as param.
	 * 
	 * @tparam  
	 */
	template <>
	struct	is_integral<bool>: public true_type {};

	/**
	 * @brief Explicit template for is_integral when a 'wchar_t' is passed as param.
	 * 
	 * @tparam  
	 */
	template <>
	struct	is_integral<wchar_t>: public true_type {};
}

#endif