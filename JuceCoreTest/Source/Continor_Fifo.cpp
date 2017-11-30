/*
  ==============================================================================

    Fifo.cpp
    Created: 30 Nov 2017 6:45:47pm
    Author:  kurooka

  ==============================================================================
*/
#include "../JuceLibraryCode/JuceHeader.h"
#include <memory>

/*
���b�N�t���[��FIFO���������邽�߂ɕK�v�ȃ��W�b�N���J�v�Z�������܂��B
FIFO = First In, First Out

���̃N���X�́A�V���O�����[�_�A�V���O�����C�^FIFO���\�z����ۂɕK�v�ȃ��W�b�N���������܂��B
���ۂɂ̓f�[�^���͕̂ێ�����܂��񂪁AFIFO�N���X�ł́A�ǂݎ��܂��͏������ݎ��̈ʒu�ƃX�e�[�^�X���Ǘ����邽�߂ɂ����̂����ꂩ���g�p�ł��܂��B
������g�p����ɂ́AprepareToWrite()���Ăяo���āA��M�o�b�t�@�[�̊i�[�ꏊ�������̃o�b�t�@�[���Ŕ��ʂ��A
prepareToRead()���Ăяo���āA���̑��M�u���b�N�����ǂݎ�邩�𒲂ׂ邱�Ƃ��ł��܂��B
*/
class MyFifo
{
public:
	MyFifo() : abstractFifo(1024)
	{
	}
	void addToFifo(const int* someData, int numItems)
	{
		int start1, size1, start2, size2;
		abstractFifo.prepareToWrite(numItems, start1, size1, start2, size2);
		if (size1 > 0)
			memcpy(myBuffer + start1, someData, size1 * sizeof(int));
		if (size2 > 0)
			memcpy(myBuffer + start2, someData + size1, size2 * sizeof(int));
		abstractFifo.finishedWrite(size1 + size2);
	}
	void readFromFifo(int* someData, int numItems)
	{
		int start1, size1, start2, size2;
		abstractFifo.prepareToRead(numItems, start1, size1, start2, size2);
		if (size1 > 0)
			memcpy(someData, myBuffer + start1, size1 * sizeof(int));
		if (size2 > 0)
			memcpy(someData + size1, myBuffer + start2, size2 * sizeof(int));
		abstractFifo.finishedRead(size1 + size2);
	}
private:
	AbstractFifo abstractFifo;
	int myBuffer[1024];
};



void	AbstractFifo_test()
{

	int data[32];
	int out[64];
	memset(out, 0, sizeof(int) * 64);

	for (int i = 0; i < 32; i++)
		data[i] = i;

	MyFifo fifo;

	fifo.addToFifo(data, 32);
	fifo.addToFifo(data, 32);

	fifo.readFromFifo(out, 64);

	for (int i = 0; i < 64; i++)
		juce::Logger::outputDebugString(juce::String(out[i]));

}


