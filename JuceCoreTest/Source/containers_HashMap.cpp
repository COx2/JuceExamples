/*
  ==============================================================================

    containers_HashMap.cpp
    Created: 1 Dec 2017 7:19:50pm
    Author:  kurooka

  ==============================================================================
*/

/*

	�������̃L�[�ƒl�̃y�A�̊Ԃ̃}�b�s���O�̃Z�b�g��ێ����܂��B

	key�����value�I�u�W�F�N�g�̌^�́A�e���v���[�g�p�����[�^�Ƃ��Đݒ肳��܂��B
	�N���X���w�肵�āA�L�[�l���n�b�V�����ꂽ�����ɕϊ�����n�b�V���֐���񋟂��邱�Ƃ��ł��܂��B
	���̃N���X�̌`���͎��̂Ƃ���ł��B

	struct MyHashGenerator
	{
		int generateHash (MyKeyType key, int upperLimit) const
		{
			// The function must return a value 0 <= x < upperLimit
			return someFunctionOfMyKeyType (key) % upperLimit;
		}
	};



	Array�N���X�Ɠ��l�ɁA�L�[�ƒl�̌^�̓R�s�[�^�ł���Ɨ\�z����܂��B
	���������āA�|�C���^�^�Ƃ��Ē�`����ƁA���̃N���X�͂���炪�w���I�u�W�F�N�g���폜���܂���B

	HashFunctionType�e���v���[�g�p�����[�^�̃N���X���w�肵�Ȃ��ꍇ�A�f�t�H���g�̂��͕̂������int�̒P���ȃ}�b�s���O��񋟂��܂��B


	Iterator��
	HashMap< KeyType, ValueType, HashFunctionType, TypeOfCriticalSectionToUse >::Iterator


*/


#include "../JuceLibraryCode/JuceHeader.h"


struct MyHashGenerator
{
	int generateHash(int key, int upperLimit) const
	{
		// The function must return a value 0 <= x < upperLimit
		return DefaultHashFunctions::generateHash(key, 567890);
	}
};

void	core_containers_HashMap_test()
{

	HashMap<int, String> hash;
	hash.set(1,"test1");
	hash.set(2, "test2");

	//�C�e���[�^�[
	HashMap<int, String>::Iterator itr(hash);
	while (itr.next())
	{
		DBG(itr.getKey() << " -> " << itr.getValue());
	}


	juce::Logger::outputDebugString(hash[1]);
	juce::Logger::outputDebugString(hash[2]);

	hash[1] = "test3";
	juce::Logger::outputDebugString(hash[1]);
	hash.set(1, "test3");
	juce::Logger::outputDebugString(hash[1]);

	//�Ǝ��n�b�V�������{�N���e�B�J���Z�N�V����
	HashMap<int, String, MyHashGenerator,CriticalSection> hash2;
	hash2.set(1, "aaaaa");
	hash2.set(2, "abaaa");

	//�N���e�B�J���Z�N�V�����̂�
	HashMap<int, String, DefaultHashFunctions, CriticalSection> hash3;


}


