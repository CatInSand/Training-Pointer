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
		tp();
		~tp();

	private:
		T* m_pData;
	};
#ifndef USING_TRAINING_POINTER
}
#endif // !USING_TRAINING_POINTER

#endif // !CAT_TRAINING_POINTER_H