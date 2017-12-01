/*
  ==============================================================================

    containers_LinkedListPointer.cpp
    Created: 1 Dec 2017 7:44:16pm
    Author:  kurooka

  ==============================================================================
*/
/*

	�P�ƂŃ����N���ꂽ�I�u�W�F�N�g�̃��X�g�𑀍삷��̂ɖ𗧂��܂��B

	���X�g���̌㑱���ڂւ̃|�C���^���܂ނ悤�ɐ݌v���ꂽ�I�u�W�F�N�g�̏ꍇ�A
	���̃N���X�ɂ̓��X�g���������郁�\�b�h���܂܂�Ă��܂��B
	������g�p����ɂ́A�w��ObjectType�N���X�ɁAnextListItem�Ƃ���LinkedListPointer���܂܂�Ă���K�v������܂��B


	---

	LinkedListPointer< ObjectType >::Appender

	���X�g�Ɍ��ʓI�ɌJ��Ԃ��}���ł��܂��B

	���X�g���̍Ō�̗v�f���w��Appender�I�u�W�F�N�g���쐬���AAppender::append()���J��Ԃ��Ăяo���āA
	O�i1�j���ԓ��Ƀ��X�g�̍Ō�ɍ��ڂ�ǉ����邱�Ƃ��ł��܂��B
	(���ɂ�炸���̎��Ԃ��Ԃ������鑀��)

*/


#include "../JuceLibraryCode/JuceHeader.h"


struct MyObject
{
	int id;
	LinkedListPointer<MyObject> nextListItem;
	MyObject(int _id) : id(_id) {}

};


void core_containers_LinkedListPointer_test()
{
	DBG("core_containers_LinkedListPointer_test");


	LinkedListPointer<MyObject> myList;
	myList.append(new MyObject(1));
	myList.append(new MyObject(2));

	int numItems = myList.size(); // returns 2
	DBG(numItems);

	MyObject* lastInList = myList.getLast();
	MyObject* obj0 = myList[0];

	//���X�g�Ɋ܂܂�Ă���H
	if (myList.contains(obj0))
	{
		DBG("true");
	}

	//�}��
	myList.findPointerTo(obj0);
	myList.insertNext(new MyObject(3));

	//�}���Q
	myList.insertAtIndex(2, new MyObject(4));

	//�����I�ȌJ��Ԃ��}��
	LinkedListPointer<MyObject>::Appender apender(myList.getLast());

	for (int i = 5; i < 15; i++)
	{
		apender.append(new MyObject(i));
	}

	

	for (int i = 0; i < myList.size(); i++)
	{
		MyObject * e = myList[i];
	}

	myList.deleteAll();



}