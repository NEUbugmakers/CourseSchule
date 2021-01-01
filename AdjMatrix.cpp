#include "AdjMatrix.h"


bool AdjMatrix::paint_dfs(int vertice,int c){//一般为c=1
    this->color[vertice] = c;
    for (int i = 0; i < MAX; ++i) {
        if(this->map[vertice][i] == 1){
            if (this->color[i] == c){
                return false;
            }
            if(this->color[i] == 0 && !paint_dfs(i,-c)){
                return false;
            }
        }
    }
    return true;
}

bool AdjMatrix::CheckBgraph() {
    for (int i = 0; i < MAX; ++i) {
        if(color[i] == 0){
            if (!paint_dfs(i,1)){
                return true;
            }
        }
    }
    return false;
}