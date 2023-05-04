#ifndef	ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace	ft
{
	/**
	 * @brief If a condition is passed as a tparam the enable_if struct does not define the 'type' type.
	 * 
	 * @tparam Cond 
	 * @tparam T 
	 */
	template <bool Cond, class T = void>
	struct enable_if
	{

	};

	/**
	 * @brief If no condition is passed as a tparam the enable_if struct defines the 'type' type.
	 * 
	 * @tparam T 
	 */
	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
}

#endif