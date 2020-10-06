#pragma once
// Std libs
#include <cstddef>
#include <algorithm>
#include <array>
#include <utility>

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
            : mData{std::forward<Args>(args)...}
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

        class Iterator
        {

            long mNum = 0;
            Type* mArray = nullptr;

        public:
            using iterator_category = std::random_access_iterator_tag;
            using difference_type = long;
            using value_type = Type;
            using pointer = Type*;
            using reference = Type&;

            explicit Iterator(Type* array, long _num = 0)
                : mNum(_num)
                , mArray(array)
            {
            }
            /**
             * @brief Prefix increment.
             * @return
             */
            inline Iterator& operator++()
            {
                mNum += 1;
                return *this;
            }

            /**
             * @brief Postfix increment.
             * @param n
             * @return
             */
            inline Iterator operator++(int)
            {
                Iterator retval = *this;
                ++(*this);
                return retval;
            }
            bool operator==(Iterator other) const
            {
                return (mNum == other.mNum); // && (mArray == other.mArray);
            }
            bool operator!=(Iterator other) const
            {
                return !(*this == other);
            }

            inline Iterator& operator--()
            {
                --mNum;
                return *this;
            }
            inline Iterator operator--(int) const
            {
                Iterator retval = *this;
                --(*this);
                return retval;
            }
            inline difference_type operator-(const Iterator& rhs) const
            {
                return mNum - rhs.mNum;
            }
            inline Iterator operator+(difference_type rhs) const
            {
                return Iterator(mArray, mNum + rhs);
            }
            inline Iterator operator-(difference_type rhs) const
            {
                return Iterator(mArray, mNum - rhs);
            }
            friend inline Iterator operator+(difference_type lhs, const Iterator& rhs)
            {
                return Iterator(rhs.mArray, lhs + rhs.mNum);
            }
            friend inline Iterator operator-(difference_type lhs, const Iterator& rhs)
            {
                return Iterator(rhs.mArray, lhs - rhs.mNum);
            }

            Type& operator*() const
            {
                return mArray[mNum];
            }
        };

        class ConstIterator
        {

            long mNum = 0;
            const Type* mArray = nullptr;

        public:
            using iterator_category = std::random_access_iterator_tag;
            using difference_type = long;
            using value_type = Type;
            using pointer = const Type*;
            using reference = const Type&;

            explicit ConstIterator(const Type* array, long _num = 0)
                : mNum(_num)
                , mArray(array)
            {
            }
            /**
             * @brief Prefix increment.
             * @return
             */
            ConstIterator& operator++()
            {
                mNum += 1;
                return *this;
            }

            /**
             * @brief Postfix increment.
             * @param n
             * @return
             */
            ConstIterator operator++(int)
            {
                ConstIterator retval = *this;
                ++(*this);
                return retval;
            }
            bool operator==(ConstIterator other) const
            {
                return (mNum == other.mNum) && (mArray == other.mArray);
            }
            bool operator!=(ConstIterator other) const
            {
                return !(*this == other);
            }
            inline difference_type operator-(const ConstIterator& rhs) const
            {
                return mNum - rhs.mNum;
            }
            inline ConstIterator operator+(difference_type rhs) const
            {
                return ConstIterator(mArray, mNum + rhs);
            }
            inline ConstIterator operator-(difference_type rhs) const
            {
                return ConstIterator(mArray, mNum - rhs);
            }
            friend inline ConstIterator operator+(difference_type lhs, const ConstIterator& rhs)
            {
                return ConstIterator(rhs.mArray, lhs + rhs.mNum);
            }
            friend inline ConstIterator operator-(difference_type lhs, const ConstIterator& rhs)
            {
                return ConstIterator(rhs.mArray, lhs - rhs.mNum);
            }
            const Type& operator*() const
            {
                return mArray[mNum];
            }
        };

        Iterator begin()
        {
            return Iterator(mData);
        }

        ConstIterator cbegin()
        {
            return ConstIterator(mData);
        }

        Iterator end()
        {
            return Iterator(mData, Size - 1);
        }

        ConstIterator cend()
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

    private:
        Type mData[Size] = {0};
    };
} // namespace Math
