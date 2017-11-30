/*
  ==============================================================================

    containers_DefaultElementComparator.cpp
    Created: 30 Nov 2017 7:47:06pm
    Author:  kurooka

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
/*


	'<'���Z�q���T�|�[�g����I�u�W�F�N�g�̔z����\�[�g���邽�߂Ɏg�p�ł���P����ElementComparator�N���X�ł��B
	����́A���Z�q�u<�v ����������v���~�e�B�u�^����уI�u�W�F�N�g�ɑ΂��ċ@�\���܂��B

	��������Q�Ƃ̂���
		ElementComparator

	�I�[�o�[���C�h�O��Ƃ������͏������ق����Ƃ��Ɏg���Ƃ������Ƃ��ȁH

*/

void DefaultElementComparator_test()
{

	Array<int> myArray;
	DefaultElementComparator<int> sorter;

	juce::Random r;

	for (int i = 0; i < 32; i++)
	{
		myArray.add(r.nextInt());
	}

	myArray.sort(sorter);


	for each (int var in myArray)
	{
		juce::Logger::outputDebugString(juce::String(var));
	}



}
