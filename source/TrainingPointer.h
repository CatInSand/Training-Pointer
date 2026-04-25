#ifndef CAT_TRAINING_POINTER_H
#define CAT_TRAINING_POINTER_H

#ifndef USING_TRAINING_POINTER
namespace cat
{
#endif // !USING_TRAINING_POINTER
	template<typename T>
	class tp final
	{
	public:
		tp(const tp<T>& other)
			: m_pData{ other.m_pData }
		{
		}
		tp<T>& operator=(const tp<T>& other)
		{
			if (this != &other)
			{
				m_pData = other.m_pData;
			}
			return *this;
		}
		tp(tp<T>&& other) noexcept
			: m_pData{ std::move(other.m_pData) }
		{
		}
		tp<T>& operator=(tp<T>&& other) noexcept
		{
			if (this != &other)
			{
				m_pData = std::move(other.m_pData);
			}
			return *this;
		}

		tp(std::nullptr_t = nullptr)
			: m_pData{ nullptr }
		{
		}
		tp<T>& operator=(std::nullptr_t)
		{
			m_pData = nullptr;
			return *this;
		}
		template<typename T>
		friend tp<T> New(T);
		template<typename T>
		friend void Delete(tp<T>);

	private:
		tp(T* pData)
			: m_pData{ pData }
		{
		}

		T* m_pData;
	};

	//friend functions
	template<typename T>
	tp<T> New(T data = T{})
	{
		return tp<T>{ new T{ data } };
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