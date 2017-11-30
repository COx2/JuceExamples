/*
  ==============================================================================

    containers_dynamic.cpp
    Created: 30 Nov 2017 7:02:05pm
    Author:  kurooka

  ==============================================================================
*/
#include "../JuceLibraryCode/JuceHeader.h"

/*
	���I�Ɏ��������I�u�W�F�N�g��\���܂��B
	���̃N���X�͎�ɃX�N���v�e�B���O����I�u�W�F�N�g�����b�v���邽�߂̂��̂ł����A���̖ړI�ɂ��g�p�ł��܂��B
	DynamicObject�̃C���X�^���X���g�p���Ė��O�t���v���p�e�B���i�[���AhasMethod()�����invokeMethod()���T�u�N���X�����邱�Ƃɂ���āA
	�I�u�W�F�N�g���\�b�h��^���邱�Ƃ��ł��܂��B
*/



void containers_dynamic_test()
{
	juce::DynamicObject* objbase = new juce::DynamicObject();
	juce::DynamicObject& obj = *objbase;

	obj.setProperty("a", 1);
	obj.setProperty("b", 2);
	obj.setProperty("c", 3);
	obj.setProperty("x", 4);
	obj.setProperty("y", 5);

	if (obj.hasProperty("a"))
	{
		juce::Logger::outputDebugString("have a.");
	}
	else {
		juce::Logger::outputDebugString("don't have a.");
	}

	juce::Logger::outputDebugString( obj.getProperty("a").toString() );

	//Json�o��
	juce::File f = juce::File::getCurrentWorkingDirectory();
	juce::String filepath = f.getFullPathName() + "\\test.json";
	FileOutputStream file(filepath);

	obj.writeAsJSON(file,true,false,1024);

	/* test.json
		{
		"a": 1,
		"b": 2,
		"c": 3,
		"x": 4,
		"y": 5
		}
	*/

	//�N���[���@deep�R�s�[
	juce::DynamicObject::Ptr obj2 = obj.clone();
	obj.setProperty("a", 10);

	//deep�Ȃ̂ŕύX����Ă��Ȃ�
	juce::Logger::outputDebugString(obj2->getProperty("a").toString());

	delete objbase;
}
