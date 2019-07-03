#include <iostream>
using namespace std;

#define Leng 30000

typedef struct LeafNode
{
	int Module;
	int Max;
	LeafNode* NextLeafNode;
}LeafNode;

typedef struct Node
{
	Node* NextNode[3];
	LeafNode* lfNode;
}Node;

Node* Root;
short MinArr[Leng];
bool PairArr[Leng] = { 0, };

void Init()
{
	Root = new Node;
	for (register int i = 0; i < 3; i++)
		Root->NextNode[i] = nullptr;
	Root->lfNode = nullptr;
}

void NewNode(Node* Front, int Count)
{
	Node* Temp;
	Temp = new Node();
	for (register int i = 0; i < 3; i++)
		Temp->NextNode[i] = nullptr;
	Temp->lfNode = nullptr;
	Front->NextNode[Count] = Temp;
}

void NewLeafNodeFromNode(Node* Front, int InputModule, int InputMax)
{
	LeafNode* Temp;
	Temp = new LeafNode();
	Temp->Module = InputModule;
	Temp->Max = InputMax;
	Temp->NextLeafNode = nullptr;
	Front->lfNode = Temp;
}

void NewLeafNodeFromLeafNode(LeafNode* Front, int InputModule, int InputMax) {
	LeafNode* Temp;
	Temp = new LeafNode();
	Temp->Module = InputModule;
	Temp->Max = InputMax;
	Temp->NextLeafNode = nullptr;
	Front->NextLeafNode = Temp;
}

void TreeDelete(Node* Current, int Count)
{
	LeafNode* Cur;
	if (Count == 15) {
		while (Current->lfNode) {
			Cur = Current->lfNode;
			delete(Cur);
			Current->lfNode = Current->lfNode->NextLeafNode;
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			if (Current->NextNode[i]) {
				TreeDelete(Current->NextNode[i], Count + 1);
			}
		}
		delete(Current->NextNode);
	}
}

int makeBlock(int module[][4][4])
{
	int Val, Max, Min, Ret = 0;
	bool Flag;
	Node* CurrentNode;
	LeafNode* CurrentLeafNode;


	Init();
	/* 1. Ʈ�� ����� */
	for (register int i = 0; i < Leng; i++) {
		Max = 0;
		Min = 1000;
		CurrentNode = Root;
		for (register int x = 0; x < 4; x++) {
			for (register int y = 0; y < 4; y++) {
				if (Max < module[i][x][y])
					Max = module[i][x][y];
				if (Min > module[i][x][y])
					Min = module[i][x][y];
			}
		}
		if (Max != Min) {
			MinArr[i] = short(Min);
			for (register int x = 0; x < 4; x++) {
				for (register int y = 0; y < 4; y++) {
					if (CurrentNode->NextNode[module[i][x][y] - Min] == nullptr)
						NewNode(CurrentNode, module[i][x][y] - Min); // �޾��ְ�
					CurrentNode = CurrentNode->NextNode[module[i][x][y] - Min];
				}
			}
			if (CurrentNode->lfNode == nullptr) { // ������忡 �ƹ��͵� ������ �޾��ش�.
				NewLeafNodeFromNode(CurrentNode, i, Max);
			}
			else { // ������忡 ���� �ִٸ�
				LeafNode* Front = nullptr;
				CurrentLeafNode = CurrentNode->lfNode;
				while (CurrentLeafNode->NextLeafNode != nullptr) {// �ǵ� or �־���� ������ �̵��Ѵ�.
					if (CurrentLeafNode->Max > Max) {
						Front = CurrentLeafNode;
						CurrentLeafNode = CurrentLeafNode->NextLeafNode;
					}
					else
						break;
				}
				if (Front == nullptr) {// �ٷ� �տ���
					Front = CurrentNode->lfNode;
					NewLeafNodeFromNode(CurrentNode, i, Max);
					CurrentNode->lfNode->NextLeafNode = Front;
				}
				else if (CurrentLeafNode->NextLeafNode != nullptr) {// �߰��� ���
					NewLeafNodeFromLeafNode(Front, i, Max);
					Front->NextLeafNode->NextLeafNode = CurrentLeafNode;
				}
				else { // ������
					NewLeafNodeFromLeafNode(CurrentLeafNode, i, Max);
				}
			}
		}
	}

	//printf("����� ��\n");
	/* 2. Pair �˻� �� LeafNode ���� */
	int CCount;
	for (register int i = 0; i < Leng; i++) {
		if (!PairArr[i]) {
			CCount = 0;
			Node* LeafNodeCmp[4] = { nullptr,nullptr ,nullptr ,nullptr };
			CurrentNode = Root;
			Flag = false;
			for (register int x = 0; x < 4; x++) {
				for (register int y = 3; y >= 0; y--) {
					if (CurrentNode->NextNode[2 - (module[i][x][y] - MinArr[i])] != nullptr)
						CurrentNode = CurrentNode->NextNode[2 - (module[i][x][y] - MinArr[i])];
					else {
						Flag = true;
						break;
					}
				}
				if (Flag)
					break;
			}
			/* Pair�� ã��. */
			while (!Flag && CurrentNode->lfNode != nullptr) {
				CurrentLeafNode = CurrentNode->lfNode;
				if (PairArr[CurrentLeafNode->Module]) {
					CurrentNode->lfNode = CurrentLeafNode->NextLeafNode;
					delete(CurrentLeafNode);
				}
				else {
					LeafNodeCmp[0] = CurrentNode;
					CCount++;
					break;
				}
			}
			/* �n */
			CurrentNode = Root;
			Flag = false;
			for (register int y = 0; y < 4; y++) {
				for (register int x = 0; x < 4; x++) {
					if (CurrentNode->NextNode[2 - (module[i][x][y] - MinArr[i])] != nullptr)
						CurrentNode = CurrentNode->NextNode[2 - (module[i][x][y] - MinArr[i])];
					else {
						Flag = true;
						break;
					}
				}
				if (Flag)
					break;
			}
			/* Pair�� ã��. */
			while (!Flag && CurrentNode->lfNode != nullptr) {
				CurrentLeafNode = CurrentNode->lfNode;
				if (PairArr[CurrentLeafNode->Module]) {
					CurrentNode->lfNode = CurrentLeafNode->NextLeafNode;
					delete(CurrentLeafNode);
				}
				else {
					LeafNodeCmp[1] = CurrentNode;
					CCount++;
					break;
				}
			}
			CurrentNode = Root;
			Flag = false;
			for (register int x = 3; x >= 0; x--) {
				for (register int y = 0; y < 4; y++) {
					if (CurrentNode->NextNode[2 - (module[i][x][y] - MinArr[i])] != nullptr)
						CurrentNode = CurrentNode->NextNode[2 - (module[i][x][y] - MinArr[i])];
					else {
						Flag = true;
						break;
					}
				}
				if (Flag)
					break;
			}
			/* Pair�� ã��. */
			while (!Flag && CurrentNode->lfNode != nullptr) {
				CurrentLeafNode = CurrentNode->lfNode;
				if (PairArr[CurrentLeafNode->Module]) {
					CurrentNode->lfNode = CurrentLeafNode->NextLeafNode;
					delete(CurrentLeafNode);
				}
				else {
					LeafNodeCmp[2] = CurrentNode;
					CCount++;
					break;

				}
			}
			CurrentNode = Root;
			Flag = false;
			for (register int y = 3; y >= 0; y--) {
				for (register int x = 3; x >= 0; x--) {
					if (CurrentNode->NextNode[2 - (module[i][x][y] - MinArr[i])] != nullptr)
						CurrentNode = CurrentNode->NextNode[2 - (module[i][x][y] - MinArr[i])];
					else {
						Flag = true;
						break;
					}
				}
				if (Flag)
					break;
			}
			/* Pair�� ã��. */
			while (!Flag && CurrentNode->lfNode != nullptr) {
				CurrentLeafNode = CurrentNode->lfNode;
				if (PairArr[CurrentLeafNode->Module]) {
					CurrentNode->lfNode = CurrentLeafNode->NextLeafNode;
					delete(CurrentLeafNode);
				}
				else {
					LeafNodeCmp[3] = CurrentNode;
					CCount++;
					break;
				}
			}
			/* �n */
			/* Pair ���� ū ���� ã�Ƽ� Pair üũ. */
			if (CCount > 0) {
				int CmpMax = 0;
				int CmpMaxi;
				for (int j = 0; j < 4; j++) {
					if (LeafNodeCmp[j]) {
						if (LeafNodeCmp[j]->lfNode->Max > CmpMax) {
							CmpMax = LeafNodeCmp[j]->lfNode->Max;
							CmpMaxi = j;
						}
					}
				}

				Ret += (CmpMax + MinArr[i]);
				PairArr[LeafNodeCmp[CmpMaxi]->lfNode->Module] = true;
				PairArr[i] = true;
				CurrentLeafNode = LeafNodeCmp[CmpMaxi]->lfNode;
				LeafNodeCmp[CmpMaxi]->lfNode = CurrentLeafNode->NextLeafNode;
				delete(CurrentLeafNode);
			}
		}
	}
	//printf("Test\n");

	/* Ʈ�� ���� */
	TreeDelete(Root, 0);

	return Ret;
}