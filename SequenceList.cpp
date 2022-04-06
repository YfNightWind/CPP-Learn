//
// Created by Alex Lin on 2022/4/3.
//
#include <iostream>

const int MaxSize = 10;

typedef struct {
	int data[MaxSize];
	int length;
} SeqList;

// 初始化顺序表
void InitList(SeqList &L) {
	L.length = 0;
}

// 插入数据
bool ListInsert(SeqList &L, int i, int e) {
	if (i < 1 || i > L.length + 1) {
		return false;
	}
	// 将第i个元素往后移
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}

// 删除顺序表元素
bool ListDelete(SeqList &L, int i, int &e) {
	if (i < 1 || i > L.length) {
		return false;
	}
	return true;
}

// 输出列表
void PrintList(SeqList &L) {
	for (int i = 0; i < L.length; i++) {
		std::cout << L.data[i] << std::endl;
	}
}

int main() {
	SeqList L;
	InitList(L);
	for (int i = 0; i < 10; i++) {
		ListInsert(L, i, i);
	}
	PrintList(L);
	return 0;
}

