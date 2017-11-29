/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
int main (int argc, char* argv[])
{
	//undo manager�쐬
	juce::UndoManager undomanager(200000, 30);

	//�l�̏�����
	juce::ValueTree v(juce::Identifier("vertices"));
	juce::Value count(var(1));

	undomanager.beginNewTransaction();
	v.setProperty("count", count, &undomanager);
	v.setProperty("x", 10, &undomanager);
	v.setProperty("y", 5, &undomanager);
	v.setProperty("z", -15, &undomanager);

	//count = 1
	juce::Logger::outputDebugString(v["count"].toString());

	//cout <- 12
	undomanager.beginNewTransaction();
	v.setProperty("count", 12, &undomanager);
	//count = 12
	juce::Logger::outputDebugString( v["count"].toString() );

	//�ϐ� count �̒l������ƕς���Ă��Ȃ��Q�Ƃ͖���
	juce::Logger::outputDebugString(count.toString());

	//undo�����Ă݂� count = 1�ɂȂ�
	undomanager.undo();
	juce::Logger::outputDebugString( "undo = " + v["count"].toString());


	//�v���p�e�B���𒲂ׂ�
	juce::Logger::outputDebugString(juce::String(v.getNumProperties()));


	//********************************************** 
	//	XML�ł̉^�p 
	//********************************************** 

	//	XML(������j�֏o��(�f�o�b�O�p�r�j	
	juce::Logger::outputDebugString(v.toXmlString());


	//���ۂɓǂݏ����O��Ŏg�p����ꍇ
	juce::XmlElement* outxml = v.createXml();
	//e->writeToFile();

	//�J�����g�̃��[�L���O�f�B���N�g�����擾
	juce::File f = juce::File::getCurrentWorkingDirectory();
	juce::String filepath = f.getFullPathName() + "\\test.xml";

	//XML�t�@�C���̏����o��
	outxml->writeToFile( filepath ,"" );
	
	delete outxml;

	//XML�̓ǂݍ��� 
	juce::File readf(filepath);
	juce::XmlDocument xmldoc(readf);
	juce::ValueTree v2(juce::Identifier("vertices"));
	juce::XmlElement* inxml = xmldoc.getDocumentElement();
	v2.fromXml(*inxml);

	juce::Logger::outputDebugString(juce::String(v2.getNumChildren()));
	juce::Logger::outputDebugString(juce::String(v2.getNumProperties()));
	juce::Logger::outputDebugString(v2.toXmlString());
	delete inxml;

	//********************************************** 
	//	Juce�o�C�i���t�H�[�}�b�g�ł̉^�p 
	//********************************************** 

	//�o�C�i���t�H�[�}�b�g�ł̏o��
	filepath = f.getFullPathName() + "\\test.bin";
	juce::FileOutputStream binfile( filepath );
	v.writeToStream(binfile);


    return 0;
}
