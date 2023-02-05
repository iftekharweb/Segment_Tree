1. Range Update & Query


ll Tree[4*N] , lazy[4*N] , a[N] , given[N];

void RangeUpdate(ll si , ll ss , ll se , ll li , ll ri , ll val) {
        // Is there any pending update? 
        if(lazy[si]) {
            ll dx = lazy[si];
            lazy[si] = 0;
            Tree[si] += dx*(se-ss+1);
            if(ss != se) {
                lazy[2*si] += dx;
                lazy[2*si+1] += dx;
            }
        }
        // Do the rest..
        if(li>se || ri<ss) return;
        if(li<=ss && ri>=se) {
            ll dx = val * (se-ss+1);
            Tree[si] += dx;
            if(ss != se) {
                lazy[2*si] += val;
                lazy[2*si+1] += val;
            }
            return;
        }
        ll mid = (ss+se)>>1;
        RangeUpdate(2*si, ss, mid , li , ri , val);
        RangeUpdate(2*si+1, mid+1 , se , li , ri , val);
        Tree[si] = Tree[2*si]+Tree[2*si+1];
        return;
}

ll Query(ll si , ll ss, ll se , ll li , ll ri) {
        // Is there any pending update? 
        if(lazy[si]) {
            ll dx = lazy[si];
            lazy[si] = 0;
            Tree[si] += dx*(se-ss+1);
            if(ss != se) {
                lazy[2*si] += dx;
                lazy[2*si+1] += dx;
            }
        }
        // Do the rest..
        if(li>se || ri<ss) return 0;
        if(li<=ss && ri>=se) {
            return Tree[si];
        }
        ll mid = (ss+se)>>1;
        return Query(2*si, ss , mid , li , ri) + Query(2*si+1, mid+1, se, li, ri);
}

void BuildTree(ll si , ll ss , ll se) {
        if(ss == se) {
            Tree[si] = a[ss];
            return;
        }
        ll mid = (ss+se)>>1;
        BuildTree(2*si, ss , mid);
        BuildTree(2*si+1, mid+1 , se);
        Tree[si] = Tree[2*si]+Tree[2*si+1];
        return;
}

2. 
        
void RangeUpdate(int si , int ss , int se , int li , int ri , int val,vector<int>& Tree,vector<int>& lazy) {
        // Is there any pending update? 
        if(lazy[si]) {
            int dx = lazy[si];
            lazy[si] = 0;
            Tree[si] += dx*(se-ss+1);
            if(ss != se) {
                lazy[2*si] += dx;
                lazy[2*si+1] += dx;
            }
        }
        // Do the rest..
        if(li>se || ri<ss) return;
        if(li<=ss && ri>=se) {
            int dx = val * (se-ss+1);
            Tree[si] += dx;
            if(ss != se) {
                lazy[2*si] += val;
                lazy[2*si+1] += val;
            }
            return;
        }
        int mid = (ss+se)>>1;
        RangeUpdate(2*si, ss, mid , li , ri , val,Tree,lazy);
        RangeUpdate(2*si+1, mid+1 , se , li , ri , val,Tree,lazy);
        Tree[si] = Tree[2*si]+Tree[2*si+1];
        return;
}
 
int Query(int si , int ss, int se , int li , int ri, vector<int>& Tree,vector<int>& lazy) {
        // Is there any pending update? 
        if(lazy[si]) {
            int dx = lazy[si];
            lazy[si] = 0;
            Tree[si] += dx*(se-ss+1);
            if(ss != se) {
                lazy[2*si] += dx;
                lazy[2*si+1] += dx;
            }
        }
        // Do the rest..
        if(li>se || ri<ss) return 0;
        if(li<=ss && ri>=se) {
            return Tree[si];
        }
        int mid = (ss+se)>>1;
        return Query(2*si, ss , mid , li , ri,Tree,lazy) + Query(2*si+1, mid+1, se, li, ri,Tree,lazy);
}
 
void BuildTree(int si , int ss , int se, vector<int>& Tree,vector<int>& lazy,vector<int>& a) {
        if(ss == se) {
            Tree[si] = a[ss];
            return;
        }
        int mid = (ss+se)>>1;
        BuildTree(2*si, ss , mid, Tree,lazy,a);
        BuildTree(2*si+1, mid+1 , se, Tree,lazy,a);
        Tree[si] = Tree[2*si]+Tree[2*si+1];
        return;
}
