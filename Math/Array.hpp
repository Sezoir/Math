#pragma once
// Std libs
#include <cstddef>
#include <algorithm>
#include <array>
#include <utility>
// Project files
#include "ArrayIterator.hpp"

namespace Math
{
    template <typename Type, size_t Size>
    class Array
    {
    public:
        /******************************************************************************
         *  Constructors
         ******************************************************************************/

        template <typename... Args>
        constexpr Array(Args... args)
            : mData{std::forward<Type>(args)...}
        {
        }

        /******************************************************************************
         *  Functions
         ******************************************************************************/

        [[nodiscard]] constexpr size_t size() const
        {
            return Size;
        }

        [[nodiscard]] constexpr bool empty() const
        {
            return Size == 0;
        }

        [[nodiscard]] constexpr size_t maxSize() const
        {
            return Size;
        }

        constexpr void fill(const Type& value)
        {
            std::fill_n(mData, Size, value);
        }

        constexpr void swap(Array& other)
        {
            std::swap_ranges(begin(), begin() + Size, other.begin());
        }
        /******************************************************************************
         *  Iterators
         ******************************************************************************/

        using Iterator = Math::BackEnd::_ArrayIterator<Type, Size>;
        using ConstIterator = Math::BackEnd::_ArrayConstIterator<Type, Size>;

        Iterator begin()
        {
            return Iterator(mData);
        }

        ConstIterator cbegin() const
        {
            return ConstIterator(mData);
        }

        Iterator end()
        {
            return Iterator(mData, Size - 1);
        }

        ConstIterator cend() const
        {
            return ConstIterator(mData, Size - 1);
        }

        /******************************************************************************
         *  Operator Overloads
         ******************************************************************************/

        Type& operator[](size_t index)
        {
            return mData[index];
        }

        const Type& operator[](size_t index) const
        {
            return mData[index];
        }

        template <typename T>
        Array<T, Size> to() const
        {
            Array<T, Size> result = {};
            for(size_t i = 0; i < Size; i++)
            {
                result[i] = static_cast<T>(mData[i]);
            }
            return std::move(result);
        }

        Array<Type, Size> operator+(const Array<Type, Size>& array) const
        {
            Array<Type, Size> result = {};
            for(int32_t i = 0; i < Size; i++)
            {
                result[i] = mData[i] + array.mData[i];
            }
            return std::move(result);
        }

        Array<Type, Size> operator-(const Array<Type, Size>& array) const
        {
            Array<Type, Size> result = {};
            for(int32_t i = 0; i < Size; i++)
            {
                result[i] = mData[i] - array.mData[i];
            }
            return std::move(result);
        }

        Array<Type, Size> operator/(const Array<Type, Size>& array) const
        {
            Array<Type, Size> result = {};
            for(int32_t i = 0; i < Size; i++)
            {
                result[i] = mData[i] / array.mData[i];
            }
            return std::move(result);
        }

        Array<Type, Size> operator*(const Array<Type, Size>& array) const
        {
            Array<Type, Size> result = {};
            for(int32_t i = 0; i < Size; i++)
            {
                result[i] = mData[i] * array.mData[i];
            }
            return std::move(result);
        }

        Array<Type, Size>& operator+=(const Array<Type, Size>& array)
        {
            for(int32_t i = 0; i < Size; i++)
            {
                mData[i] = mData[i] + array[i];
            }
            return *this;
        }

        Array<Type, Size>& operator-=(const Array<Type, Size>& array)
        {
            for(int32_t i = 0; i < Size; i++)
            {
                mData[i] = mData[i] - array[i];
            }
            return *this;
        }

        Array<Type, Size>& operator/=(const Array<Type, Size>& array)
        {
            for(int32_t i = 0; i < Size; i++)
            {
                mData[i] = mData[i] / array[i];
            }
            return *this;
        }

        Array<Type, Size>& operator*=(const Array<Type, Size>& array)
        {
            for(int32_t i = 0; i < Size; i++)
            {
                mData[i] = mData[i] * array[i];
            }
            return *this;
        }

        bool operator==(Array<Type, Size>& arrayRhs) const
        {
            return std::move(std::equal(cbegin(), cend(), arrayRhs.cbegin()));
        }

        bool operator!=(Array<Type, Size>& arrayRhs) const
        {
            return std::move(!std::equal(cbegin(), cend(), arrayRhs.cbegin()));
        }

    private:
        Type mData[Size] = {0};
    };
} // namespace Math
