ll Tree[4*(N+1)][4*(N+1)] , a[N+1][N+1];

void PointUpdateY(int six, int ssx, int sex, int siy, int ssy,int  sey, int x, int y, int val){
        if(ssy == sey){
            if(ssx == sex){
                Tree[six][siy] += val;
            }else{
                Tree[six][siy] = Tree[six*2][siy] + Tree[six*2+1][siy];
            }
            return;
        }
        int mid = (ssy + sey)/2;
        if(ssy <= y && y <= mid){
            PointUpdateY(six, ssx, sex, siy*2, ssy, mid, x,y,val);
        }
        else{
            PointUpdateY(six, ssx, sex, siy*2+1, mid+1, sey, x,y,val);
        }
        Tree[six][siy] = Tree[six][siy*2] + Tree[six][siy*2+1];
}
    
void PointUpdateX(int six, int ssx, int sex, int x, int y, int val){
        if(ssx == sex){
            PointUpdateY(six, ssx, sex, 1, 1, N, x, y, val);
            return;
        }
        int mid = (ssx+sex)/2;
        if(ssx <= x && x <= mid){
            PointUpdateX(six*2, ssx, mid, x,y,val);
        }
        else{
            PointUpdateX(six*2+1, mid+1, sex, x,y,val);
        }
        PointUpdateY(six, ssx, sex, 1, 1, N, x, y, val);
}

ll QueryY(int six, int siy, int ssy, int sey, int y1, int y2) {
        if(sey < y1 || y2 < ssy)return 0;
        
        if(ssy == sey){
            return Tree[six][siy];
        }
        if(y1 <= ssy && sey <= y2){
            return Tree[six][siy];
        }
        int mid = (ssy+sey)/2;
        return QueryY(six, siy*2, ssy, mid, y1,y2) + QueryY(six, siy*2+1, mid+1, sey, y1,y2);
}

ll QueryX(int six, int ssx, int sex, int x1, int x2, int y1, int y2) {
        if(sex<x1 || x2 < ssx)return 0;

        if(ssx == sex){
            return QueryY(six, 1, 1, N, y1, y2);
        }
        if(x1 <= ssx && sex <= x2){
            return QueryY(six, 1, 1, N, y1, y2);
        }
        int mid = (ssx+sex)/2;
        return  QueryX(six*2, ssx, mid, x1,x2,y1,y2) + QueryX(six*2+1, mid+1, sex, x1,x2,y1,y2);
}

void BuildTreeY(int six, int ssx, int sex, int siy, int ssy, int sey) {
        if(ssy == sey){
            if(ssx == sex){
                Tree[six][siy] = a[ssx][ssy];
            }
            else{
                Tree[six][siy] = Tree[six*2+0][siy] + Tree[six*2+1][siy];
            }
            return;
        }
        int mid = (ssy+sey)/2;
        BuildTreeY(six, ssx, sex, siy*2+0, ssy, mid);
        BuildTreeY(six, ssx, sex, siy*2+1, mid+1, sey);
        Tree[six][siy] = Tree[six][siy*2+0] + Tree[six][siy*2+1];
}
    
void BuildTreeX(int six, int ssx, int sex) {
        if(ssx == sex){
            BuildTreeY(six, ssx, sex, 1, 1, N);
            return;
        }
        int mid = (ssx+sex)/2;
        BuildTreeX(six*2 + 0, ssx, mid);
        BuildTreeX(six*2 + 1, mid+1, sex);
        BuildTreeY(six, ssx, sex, 1, 1, N);
}
