#ifndef CAT_TRAINING_POINTER_H
#define CAT_TRAINING_POINTER_H

// pending features
//	- Array support
//  - Safety features
// 
// 

#include <ostream>

#ifndef USING_TRAINING_POINTER
namespace cat
{
#endif // !USING_TRAINING_POINTER
	template<typename T>
	class tp final
	{
	public:
		// +-----------------+
		// |  Constructors   |
		// +-----------------+
		tp(T* pData)
			: m_pData{ pData }
		{
		}
		tp(const tp<T>& other)
			: m_pData{ other.m_pData }
		{
		}
		tp(tp<T>&& other) noexcept
			: m_pData{ std::move(other.m_pData) }
		{
		}
		tp(std::nullptr_t = nullptr)
			: m_pData{ nullptr }
		{
		}

		// +-----------------+
		// |    Operators    |
		// +-----------------+
		
		//Assignment operators
		tp<T>& operator=(const tp<T>& other)
		{
			if (this != &other)
			{
				m_pData = other.m_pData;
			}
			return *this;
		}
		tp<T>& operator=(tp<T>&& other) noexcept
		{
			if (this != &other)
			{
				m_pData = std::move(other.m_pData);
			}
			return *this;
		}
		tp<T>& operator=(std::nullptr_t)
		{
			m_pData = nullptr;
			return *this;
		}
		template<typename U>
		tp<T>& operator=(const U& other)
		{
			m_pData = other;
			return *this;
		}
		template<typename U>
		tp<T>& operator+=(const U& other)
		{
			m_pData += other;
			return *this;
		}
		template<typename U>
		tp<T>& operator-=(const U& other)
		{
			m_pData -= other;
			return *this;
		}

		//Increment/decrement operators
		tp<T>& operator++()
		{
			++m_pData;
		}
		tp<T>& operator--()
		{
			--m_pData;
		}
		tp<T> operator++(int)
		{
			m_pData++;
		}
		tp<T> operator--(int)
		{
			m_pData--;
		}

		//Arithmetic operators
		tp<T> operator+() const
		{
			return *this;
		}
		tp<T> operator-() const
		{
			return { -m_pData };
		}
		template<typename U>
		tp<T> operator+(const U& other) const
		{
			return m_pData + other;
		}
		template<typename U>
		tp<T> operator-(const U& other) const
		{
			return m_pData - other;
		}

		//Comparison operators
		template<typename U>
		bool operator==(const tp<U>& other) const
		{
			return m_pData == other.m_pData;
		}
		template<typename U>
		bool operator!=(const tp<U>& other) const
		{
			return m_pData != other.m_pData;
		}
		template<typename U>
		bool operator<(const tp<U>& other) const
		{
			return m_pData < other.m_pData;
		}
		template<typename U>
		bool operator>(const tp<U>& other) const
		{
			return m_pData > other.m_pData;
		}
		template<typename U>
		bool operator<=(const tp<U>& other) const
		{
			return m_pData <= other.m_pData;
		}
		template<typename U>
		bool operator>=(const tp<U>& other) const
		{
			return m_pData >= other.m_pData;
		}

		//Member access operators
		template<typename U>
		T& operator[](const U& index)
		{
			return m_pData[index];
		}
		T& operator*()
		{
			return *m_pData;
		}
		T* operator->()
		{
			return m_pData;
		}

		//Ostream operator
		friend std::ostream& operator<<(std::ostream& os, const tp<T>& pointer)
		{
			return os << pointer.m_pData;
		}

		// +-----------------+
		// |     friends     |
		// +-----------------+

		template<typename T, typename... Args>
		friend tp<T> New(Args&&...);
		template<typename T>
		friend void Delete(tp<T>);

	private:
		T* m_pData;
	};

	//friend functions
	template<typename T, typename... Args>
	tp<T> New(Args&&... args)
	{
		return tp<T>{ new T{ std::forward<Args>(args)... } };
	}
	template<typename T>
	void Delete(tp<T> trainingPointer)
	{
		delete trainingPointer.m_pData;
	}


#ifndef USING_TRAINING_POINTER
}
#endif // !USING_TRAINING_POINTER

#endif // !CAT_TRAINING_POINTER_H