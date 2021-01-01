#pragma once
#ifndef HUNGARIAN_H
#define HUNGARIAN_H
#include "AdjMatrix.h"
class Hungarian :public AdjMatrix{
public:
	Hungarian(AdjMatrix Adj):AdjMatrix(Adj){}
	bool find(int i);
	int getMaxLength();
public:
    bool search_P();//寻找未匹配的点
    bool match_(int u);//匹配DFS
    int MaxMatch();//HK算法，输出最大匹配数
    void print_adj();//输出到显示结构体
public:
    bool multipleMatch();
private:
    int Mx[MAX],My[MAX];
    int dx[MAX],dy[MAX],dis;
private:
	int MaxLength;
	bool IsUsed[MAX];
private:
    bool multipleMatch_DFS(int x);
    int mp[MAX][MAX];
    bool used[MAX];
    int cnt[MAX];
    int cap[MAX];
    int mat[MAX][MAX];

};
#endif
