1. Range Maximum Query
Ex :  (i) https://codeforces.com/problemset/problem/1709/D

ll maxArr[4*N], a[N];

void PointUpdate(ll si , ll ss , ll se , ll qi) {
        if(ss == se) {
            maxArr[si] = a[ss];
            return;
        }
        ll mid = (ss+se)>>1;
        if(qi <= mid) PointUpdate(2*si , ss , mid , qi);
        else PointUpdate(2*si+1, mid+1 , se , qi);
        maxArr[si] = max(Tree[2*si],Tree[2*si+1]);
}
 
ll Query(ll si, ll ss, ll se, ll li, ll ri) {
        if(li>se || ri<ss) {
            return (-1)*MOD;
        }
        if(ss>=li && se<=ri) {
            return maxArr[si];
        }
        ll mid = (ss+se)>>1;
        ll l = Query(2*si, ss, mid, li, ri);
        ll r = Query(2*si+1, mid+1, se, li, ri);
        return max(l,r);
}
 
void BuildTree(ll si, ll ss, ll se) {
        if(ss==se){
            maxArr[si] = a[ss];
            return;
        }
        ll mid = ss+(se-ss)/2;
        BuildTree(2*si, ss, mid);
        BuildTree(2*si+1, mid+1, se);
        maxArr[si]= max(maxArr[2*si], maxArr[2*si+1]);
}



2. Range Minimum Query
Ex : (i) https://www.spoj.com/problems/RMQSQ/

ll minArr[4*N], a[N];

ll query(ll si, ll ss, ll se, ll li, ll ri) {
        if(li>se || ri<ss){
            return INT_MAX;
        }
        if(ss>=li && se<=ri){
            return minArr[si];
        }
        ll mid = (ss+se)/2;
        ll l = query(2*si, ss, mid, li, ri);
        ll r = query(2*si+1, mid+1, se, li, ri);
        return min(l,r);
}

void buildTree(ll si, ll ss, ll se) {
        if(ss==se){
            minArr[si]=a[ss];
            return;
        }
        ll mid = ss+(se-ss)/2;
        buildTree(2*si, ss, mid);
        buildTree(2*si+1, mid+1, se);
        minArr[si]= min(minArr[2*si], minArr[2*si+1]);
}

