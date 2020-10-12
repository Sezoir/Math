#pragma once
namespace Math::BackEnd
{
    template <typename Type, size_t Size>
    class _ArrayIterator
    {
        long mNum = 0;
        Type* mArray = nullptr;

    public:
        using iterator_category = std::random_access_iterator_tag;
        using difference_type = long;
        using value_type = Type;
        using pointer = Type*;
        using reference = Type&;

        explicit _ArrayIterator(Type* array, long _num = 0)
            : mNum(_num)
            , mArray(array)
        {
        }
        /**
         * @brief Prefix increment.
         * @return
         */
        inline _ArrayIterator& operator++()
        {
            mNum += 1;
            return *this;
        }

        /**
         * @brief Postfix increment.
         * @param n
         * @return
         */
        inline _ArrayIterator operator++(int)
        {
            _ArrayIterator retval = *this;
            ++(*this);
            return retval;
        }
        bool operator==(_ArrayIterator other) const
        {
            return (mNum == other.mNum); // && (mArray == other.mArray);
        }
        bool operator!=(_ArrayIterator other) const
        {
            return !(*this == other);
        }

        inline _ArrayIterator& operator--()
        {
            --mNum;
            return *this;
        }
        inline _ArrayIterator operator--(int) const
        {
            _ArrayIterator retval = *this;
            --(*this);
            return retval;
        }
        inline difference_type operator-(const _ArrayIterator& rhs) const
        {
            return mNum - rhs.mNum;
        }
        inline _ArrayIterator operator+(difference_type rhs) const
        {
            return _ArrayIterator(mArray, mNum + rhs);
        }
        inline _ArrayIterator operator-(difference_type rhs) const
        {
            return _ArrayIterator(mArray, mNum - rhs);
        }
        friend inline _ArrayIterator operator+(difference_type lhs, const _ArrayIterator& rhs)
        {
            return _ArrayIterator(rhs.mArray, lhs + rhs.mNum);
        }
        friend inline _ArrayIterator operator-(difference_type lhs, const _ArrayIterator& rhs)
        {
            return _ArrayIterator(rhs.mArray, lhs - rhs.mNum);
        }

        Type& operator*() const
        {
            return mArray[mNum];
        }
    };

    template <typename Type, size_t Size>
    class _ArrayConstIterator
    {

        long mNum = 0;
        const Type* mArray = nullptr;

    public:
        using iterator_category = std::random_access_iterator_tag;
        using difference_type = long;
        using value_type = Type;
        using pointer = const Type*;
        using reference = const Type&;

        explicit _ArrayConstIterator(const Type* array, long _num = 0)
            : mNum(_num)
            , mArray(array)
        {
        }
        /**
         * @brief Prefix increment.
         * @return
         */
        _ArrayConstIterator& operator++()
        {
            mNum += 1;
            return *this;
        }

        /**
         * @brief Postfix increment.
         * @param n
         * @return
         */
        _ArrayConstIterator operator++(int)
        {
            _ArrayConstIterator retval = *this;
            ++(*this);
            return retval;
        }
        bool operator==(_ArrayConstIterator other) const
        {
            return (mNum == other.mNum) && (mArray == other.mArray);
        }
        bool operator!=(_ArrayConstIterator other) const
        {
            return !(*this == other);
        }
        inline difference_type operator-(const _ArrayConstIterator& rhs) const
        {
            return mNum - rhs.mNum;
        }
        inline _ArrayConstIterator operator+(difference_type rhs) const
        {
            return _ArrayConstIterator(mArray, mNum + rhs);
        }
        inline _ArrayConstIterator operator-(difference_type rhs) const
        {
            return _ArrayConstIterator(mArray, mNum - rhs);
        }
        friend inline _ArrayConstIterator operator+(difference_type lhs, const _ArrayConstIterator& rhs)
        {
            return _ArrayConstIterator(rhs.mArray, lhs + rhs.mNum);
        }
        friend inline _ArrayConstIterator operator-(difference_type lhs, const _ArrayConstIterator& rhs)
        {
            return _ArrayConstIterator(rhs.mArray, lhs - rhs.mNum);
        }
        const Type& operator*() const
        {
            return mArray[mNum];
        }
    };
} // namespace Math::BackEnd