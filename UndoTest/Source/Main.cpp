/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"

#include <cstdio>


class ActionObject : public UndoableAction
{
public:
	ActionObject() {}
	virtual ~ActionObject() {}

	/*
	���̃��\�b�h�́AUndoManager�ɂ���ČĂяo����܂��B
	@returns�A�N�V�������G���[�Ȃ��Ŏ��s�ł���ꍇ��true�B
	*/
	virtual bool perform()
	{
		return true;
	}

	/*
	���̃��\�b�h�́AUndoManager�ɂ���ČĂяo����܂��B
	�Ăяo���\�� undo�i�j���\�b�h�ŌĂяo�����s��Ȃ��悤�ɒ��ӂ��Ă�������
	�ċA�I��UndoManager :: perform�i�j���\�b�h�ɖ߂�

	@returns�A�N�V�������G���[�Ȃ��Ō��ɖ߂����Ƃ��ł���ꍇ��true�B
	*/

	virtual bool undo()
	{
		return true;
	}

};


void undoTest()
{

	juce::UndoManager undomanager(200,30); //Undo���X�g�̍ő吔���w��

	//undo�̃q�X�g���[���N���A
	undomanager.clearUndoHistory();

	//UndoableAction�I�u�W�F�N�g���i�[���邽�߂Ɏg�p����X�y�[�X�̌��݂̗ʂ�Ԃ��܂��B
	int size = undomanager.getNumberOfUnitsTakenUpByStoredCommands();
	Logger::outputDebugString( juce::String(size) );

	//UndoableAction�I�u�W�F�N�g���i�[���邽�߂Ɏg�p�ł���̈�̗ʂ�ݒ肵�܂��B
	undomanager.setMaxNumberOfStoredUnits(200,30);

	//Undo�\�ȃA�N�V�����̎��s
	undomanager.beginNewTransaction();			//����beginNewTransaction�܂ŃO���[�v���i�g�����U�N�V�����j�����
	undomanager.perform(new ActionObject());

	//Undo�\�ȃA�N�V�����̎��s2
	undomanager.beginNewTransaction("named transaction"); //�g�����U�N�V�����ɖ��O��t����
	undomanager.perform(new ActionObject(),"named action");

	//�O���[�v��
	undomanager.beginNewTransaction("group transaction");
	undomanager.perform(new ActionObject());
	undomanager.perform(new ActionObject());
	undomanager.perform(new ActionObject());

	undomanager.setCurrentTransactionName("in 3 action"); //���݂̃g�����U�N�V�����̖��O�̕ύX

	//���݂̃g�����U�N�V�����̖��O��Ԃ�
	Logger::outputDebugString( undomanager.getCurrentTransactionName() );

	//Undo���X�g��Undo�\�ȃA�N�V���������邩?
	if (undomanager.canUndo())
	{
		Logger::outputDebugString("Undo is OK");
	}
	else {
		Logger::outputDebugString("Undo is NG");
	}

	//Undo���Ăяo���ꂽ�Ƃ��̃g�����U�N�V��������Ԃ�
	Logger::outputDebugString(undomanager.getUndoDescription());


	//Undo �Ō�̃g�����U�N�V���������[���o�b�N���܂��B
	//�g�����U�N�V���������������Ƃ��ł���ꍇ��true�A���s�����ꍇ�A�������g�����U�N�V�������Ȃ��ꍇ��false
	if (undomanager.undo())
	{
		Logger::outputDebugString("Undo = true ");
	}
	else {
		Logger::outputDebugString("Undo = false ");
	}

	//canRedo Redo�\���H
	if (undomanager.canRedo())
	{
		Logger::outputDebugString("Redo is OK");
	}
	else {
		Logger::outputDebugString("Redo is NG");
	}


	//redo�i�j���Ăяo���ꂽ�Ƃ��ɂ�蒼���g�����U�N�V�����̖��O��Ԃ��܂��B
	Logger::outputDebugString(undomanager.getRedoDescription());
	
	//redo�̎��s
	if (undomanager.redo())
	{
		Logger::outputDebugString("redo = true ");
	}
	else {
		Logger::outputDebugString("redo = false ");
	}


	//���݂̃g�����U�N�V�����ɒǉ����ꂽ�A�N�V���������[���o�b�N���悤�Ƃ��܂��B
	//
	//Undo�̍Ō�̌Ăяo����ɒǉ����ꂽUndo���X�g�ł������̃A�N�V�������ǉ�����Ă���ꍇ�̂ݎ��s���ł��܂��B
	//��̓I�ȗp�@�Ƃ��Ă͎��ۂ�beginNewTransaction���ɃA�N�V�������������Ăяo�����̂��ɃA�N�V���������ۂɎ��s���邩�𔻒f�����̃g�����U�N�V�����Ăяo�������������Ƃɂł��܂��B
	Logger::outputDebugString(undomanager.getUndoDescription());
	undomanager.beginNewTransaction("fail action");
	undomanager.perform(new ActionObject());
	undomanager.perform(new ActionObject());
	undomanager.perform(new ActionObject());
	Logger::outputDebugString(undomanager.getUndoDescription());

	if (undomanager.undoCurrentTransactionOnly())
	{
		Logger::outputDebugString("undoCurrentTransactionOnly = true ");
	}

	Logger::outputDebugString(undomanager.getUndoDescription());


	// getActionsInCurrentTransaction
	//���݊J���Ă���g�����U�N�V�������Ɏ��s���ꂽUndoableAction�I�u�W�F�N�g�̃��X�g��Ԃ��܂��B
	//	���ʓI�ɁA�����undoCurrentTransactionOnly�i�j�����Ăяo���ꂽ�Ƃ��Ɍ��ɖ߂����A�N�V�����̃��X�g�ł��B
	//	���X�g���̍ŏ��̍��ڂ́A���s���ꂽ�ł������̃A�N�V�����ł��B
	undomanager.beginNewTransaction("getActionsInCurrentTransaction test");
	undomanager.perform(new ActionObject());
	undomanager.perform(new ActionObject());

	juce::Array<const UndoableAction*> actionlist;
	undomanager.getActionsInCurrentTransaction(actionlist);
	Logger::outputDebugString(juce::String( actionlist.size() ));

	for each (const UndoableAction* var in actionlist){
		//�v�f�̌�����
	}
	
	//undo�i�j���Ăяo���ꂽ�Ƃ��ɏ�Ԃ���������鎞����Ԃ��܂��B
	//���ɖ߂����Ƃ��ł��Ȃ��ꍇ�ATime�i�j��Ԃ��܂��B
	juce::Time _time = undomanager.getTimeOfUndoTransaction();
	Logger::outputDebugString( _time.toString(false, true) );

	//redo�i�j���Ăяo���ꂽ�Ƃ��ɏ�Ԃ���������鎞����Ԃ��܂��B
	//��蒼�������݉\�łȂ��ꍇ�ATime::getCurrentTime�i�j��Ԃ��܂��B
	_time = undomanager.getTimeOfRedoTransaction();
	Logger::outputDebugString(_time.toString(false, true));



}

//==============================================================================
int main (int argc, char* argv[])
{

    // ..your code goes here!
	undoTest();

    return 0;
}
