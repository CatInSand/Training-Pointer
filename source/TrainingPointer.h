#ifndef CAT_TRAINING_POINTER_H
#define CAT_TRAINING_POINTER_H

namespace cat
{
	template<typename T>
	class tp final
	{
	public:
		tp();
		~tp();

	private:
		T* m_pData;
	};
}

#endif