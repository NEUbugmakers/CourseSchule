#pragma once
#ifndef ADJMATRIX_H
#define ADJMATRIX_H
#include<iostream>
#include<cstring>
#include<vector>
#include <queue>
#include <memory.h>
#define MAX 100
#define INF 0x3f3f3f3f
#define COURSE_LIMIT 3
using namespace std;


class AdjMatrix {
public:
	//nTΪ��ʦ������ nCΪ�γ̵�����
    AdjMatrix(int nT = 0, int nC = 0):nTeacher(nT),nCourse(nC) {
        memset(color,0,sizeof(color));
        for (int i = 0; i < MAX; ++i) {
            memset(map[i],0,sizeof(map[i]));
        }
    }
	int getMap(int i, int j) { return map[i][j]; }
	vector<int> getAdjNode(int i) { return AdjNode[i]; }
	string getTeacher(int i) { return teacher[i]; }
	string getCourse(int i) { return course[i]; }
	int getnTeacher() { return nTeacher; }
	int getnCourse() { return nCourse; }
	void setMap(int i, int j, int n) { map[i][j] = n; }
	void setAdjNode(int i, vector<int> n) { AdjNode[i] = n; }
	void setTeacher(int i, string p) { teacher[i] = p; }
	void setCourse(int i, string p) { course[i] = p; }
	void setnTeacher(int n) { nTeacher = n; }
	void setnCourse(int n) { nCourse = n; }
    bool paint_dfs(int vertice,int c);
    bool CheckBgraph();
private:
	int nTeacher, nCourse;
	int map[MAX][MAX];//�����ڵ�֮���Ȩ��(Ϊ0ʱ˵��δ���� Ϊ1ʱ˵��������) 
	vector<int> AdjNode[MAX];//��������ڵ��������Ϣ����Ӧ����ƥ�䣩 
							 //��������ʦ�������ڿγ� ���Դ˽ڵ�Ϊ�γ̽ڵ� 
							 //ͳһʹ�ô˱�������������Ϣ����UI��� 
	string teacher[MAX];
	string course[MAX];
    int color[MAX];
};


#endif
