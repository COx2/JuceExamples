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
	initialiseJuce_GUI();	//GUI���������ł��Ă��Ȃ��Ɠ��삵�Ȃ�

	ApplicationProperties apppro;
	PropertiesFile::Options options;

	//�t�@�C���������肷��
	options.applicationName = "ApplicationPropertiesTest";
	options.filenameSuffix = ".settings";
	options.osxLibrarySubFolder = "Application Support";
	apppro.setStorageParameters(options);

	//���ꂪ���߂ČĂяo�����ƁA�v���p�e�B�t�@�C�����쐬����ă��[�h����܂��B
	juce::PropertiesFile* commonProperties = apppro.getCommonSettings(true);


	//���ɂ��ȉ��̃t�H���_�Ɋi�[�����
	//windows	C:\Documents and Settings\username\Application Data\[folderName]\[applicationName].[filenameSuffix]
	//macos		~/Library/[osxLibrarySubFolder]/[folderName]/[applicationName].[filenameSuffix]
	//linux		~/[folderName]/[applicationName].[filenameSuffix]
	juce::PropertiesFile* userProperties = apppro.getUserSettings();
	userProperties->setValue("mode", true);
	userProperties->setValue("x", 1);
	userProperties->setValue("y", 1.5f);
	userProperties->setValue("z", 1.2);

	//���݂̒l�̃f�B�X�N�ւ̏������݂������I�ɍs���܂��B
	userProperties->save();

	//�Ō�̒l����ύX����Ă���΁A���ׂĂ̒l���f�B�X�N�Ƀt���b�V������܂�
	apppro.saveIfNeeded();

    return 0;
}
