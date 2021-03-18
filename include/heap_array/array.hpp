#pragma once

#include <array>
#include <tuple>
#include <heap_array/array_type.hpp>

template <typename T, size_t ...N>
class HeapArray
{
private:
	using t = mp::array_type_t<T, N...>;
	using t_ptr = std::add_pointer_t<t>;
	using t_ref = std::add_lvalue_reference_t<t>;

public:
	using value_type = T;
	using size_type = size_t;

	template <size_t I>
	constexpr size_type size() const
	{
		static_assert(I < sizeof...(N));
		return std::tuple_element_t<I, std::tuple<std::integral_constant<size_t, N>...>>::value;
	}

	HeapArray()
		: data_(nullptr)
	{
		data_ = reinterpret_cast<t_ptr>(operator new(sizeof(t)));
	}

	~HeapArray()
	{
		operator delete(data_);
	}

	decltype(auto) operator[](size_t i) const
	{
		return data()[i];
	}

private:
	t_ref data() const
	{
		return *data_;
	}

	t_ptr data_;
};
