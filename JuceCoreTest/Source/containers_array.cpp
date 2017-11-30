/*
  ==============================================================================

    containers_array.cpp
    Created: 30 Nov 2017 6:48:11pm
    Author:  kurooka

  ==============================================================================
*/
#include "../JuceLibraryCode/JuceHeader.h"

/*
	Array< ElementType, TypeOfCriticalSectionToUse, minimumAllocatedSize >

	�v���~�e�B�u�I�u�W�F�N�g�܂���copy-by-value�I�u�W�F�N�g�̃T�C�Y�ύX�\�Ȕz���ێ����܂��B

	�z��̗�͎��̂Ƃ���ł��B
	
	Array<int>
	Array<Rectangle>
	�܂���Array<MyClass *>

	Array�N���X���g�p����ƁA�P���Ȕ�|�����t�B�b�N�I�u�W�F�N�g��v���~�e�B�u�^��ێ��ł��܂��B
	���̂��߂ɂ́A�N���X�����̗v���𖞂����Ă���K�v������܂��B

	�R�s�[�R���X�g���N�^�Ƒ�����Z�q���K�v�ł�
	�����memcpy�ɂ���ă������ɍĔz�u�ł��Ȃ���΂Ȃ�܂���B
	���̂��߁A�O���|�C���^�⎩�g�ւ̎Q�ƂɈˑ�����@�\�����I�u�W�F�N�g�͎g�p�ł��܂���B
	�������A�I�u�W�F�N�g�̔C�ӂ̎�ނւ̃|�C���^�̔z��������Ƃ��ł��܂��B 
	Array <MyClass *>�ł����A������s���Ɣz��̓I�u�W�F�N�g�̏��L���������܂���B
	�I�u�W�F�N�g�̃��X�g��ێ����邽�߂̂�苭�͂ȕ��@�ɂ��ẮAOwnedArray�N���X�܂���ReferenceCountedArray�N���X���Q�Ƃ��Ă��������B

	������̃��X�g��ێ�����ɂ́AArray <String>���g�p���邱�Ƃ��ł��܂����A�ʏ�A����ȃN���XStringArray���g�p��������֗��ł��B

	���ׂĂ̔z��̃��\�b�h���X���b�h�Z�[�t�ɂ���ɂ́A�f�t�H���g��DummyCriticalSection�ł͂Ȃ��A�e���v���[�g��TypeOfCriticalSectionToUse�p�����[�^�Ƃ��� "CriticalSection"��n���܂��B
*/

CriticalSection objectLock;

void	ArrayTemplateTest()
{
	//DummyCriticalSection�ō쐬����� = �X���b�h�Z�[�t�ł͂Ȃ�
	juce::Array<int> int_array; 

	for (int i = 0 ; i < 32 ; i++ )
		int_array.add(i);

	//�X���b�h�Z�[�t�Ȕz�񑀍�
	juce::Array<int, CriticalSection, 64> int_array2;
	{
		//�X�R�[�v���b�N
		const ScopedLock myScopedLock(objectLock);

		for (int i = 0; i < 32; i++)
			int_array2.add(i);
	}
}
