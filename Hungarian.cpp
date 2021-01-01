#include"Hungarian.h"
#include<iostream>
#include<vector>

using namespace std;

int Hungarian::getMaxLength() {
    MaxLength = 0;
    int i, j;
    for (i = 1; i <= getnTeacher(); i++) {
        memset(IsUsed, false, sizeof(IsUsed));
        if (find(i)) MaxLength++;
        else continue;
        for (j = 1; j <= getnCourse(); j++) {
            vector<int> p = getAdjNode(j);
            if (!p.empty()) {
                cout << getTeacher(p[0]) << "->" << j << endl;
            }
        }
        cout << "--------------------" << endl;
    }
    return MaxLength;
}

bool Hungarian::find(int i) {
    int j;
    for (j = 1; j <= getnCourse(); j++) {
        if (!IsUsed[j] && getMap(i, j) == 1) {
            IsUsed[j] = true;
            vector<int> p = getAdjNode(j);
            if (p.empty() || find(p[0])) {
                p.clear();
                p.push_back(i);
                setAdjNode(j, p);
                return true;
            }
        }
    }
    return false;
}

bool Hungarian::search_P() {
    queue<int> Q;
    dis = INF;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    for (int i = 0; i < getnTeacher(); i++)
        if (Mx[i] == -1) {
            Q.push(i);
            dx[i] = 0;
        }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (dx[u] > dis) break;
        for (int v = 0; v < getnCourse(); v++)
            if (getMap(u, v) && dy[v] == -1) {
                dy[v] = dx[u] + 1;
                if (My[v] == -1) dis = dy[v];
                else {
                    dx[My[v]] = dy[v] + 1;
                    Q.push(My[v]);
                }
            }
    }
    return dis != INF;
}

bool Hungarian::match_(int u) {
    for (int v = 0; v < getnCourse(); v++)
        if (!IsUsed[v] && getMap(u, v) && dy[v] == dx[u] + 1) {
            IsUsed[v] = true;
            if (My[v] != -1 && dy[v] == dis) continue;
            if (My[v] == -1 || match_(My[v])) {
                My[v] = u;
                Mx[u] = v;
                return true;
            }
        }
    return false;
}

int Hungarian::MaxMatch() {
    int res = 0;
    memset(Mx, -1, sizeof(Mx));
    memset(My, -1, sizeof(My));
    while (search_P()) {
        memset(IsUsed, 0, sizeof(IsUsed));
        for (int i = 0; i < getnTeacher(); i++)
            if (Mx[i] == -1 && match_(i)) res++;
    }
    return res;
}


void Hungarian::print_adj() {
    for (int i = 0; i < getnCourse(); ++i) {
        if (My[i] == 0) {
            continue;
        } else {
            vector<int> a;
            a.push_back(My[i]);
            setAdjNode(i, a);
        }
    }
}

bool Hungarian::multipleMatch() {
    int nCourse = getnCourse();
    int nTeacher = getnTeacher();
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            mp[i][j] = -1;
    for (int i = 0; i < nCourse; i++) {
        cnt[i] = 0;
    }
    for (int i = 0; i < nTeacher; i++) {
        for (int j = 0; j <= nTeacher; j++)
            used[j] = 0;
        if (!multipleMatch_DFS(i))
            return false;
    }
    vector<int> teachers;
    for (int i=0;i<nCourse;i++){
        for(int j=0;j<cnt[i];j++){
            teachers.push_back(mat[i][j]);
        }
        setAdjNode(i,teachers);
        teachers.clear();
    }
    return true;
}

bool Hungarian::multipleMatch_DFS(int x) {
    int nCourse = getnCourse();
    int nTeacher = getnTeacher();
    for(int j=0;j<nCourse;j++){
        if(cnt[j]==0){
            mat[j][cnt[j]++] = x;
            return true;
        }
    }
    for (int i = 0; i < nCourse; i++)
        if (getMap(x,i) && !used[i]) {
            used[i] = 1;

            if (cnt[i] < COURSE_LIMIT) {
                mat[i][cnt[i]++] = x;
                return true;
            }else{
                for(int j=0;j< COURSE_LIMIT;j++){
                    if(multipleMatch_DFS(mat[i][j])){
                        mat[i][j] = x;
                        return true;
                    }
                }
            }
        }
    return false;
}