
struct Node {
    ll mi = MOD;
    ll mx = -MOD;
};
Node query(ll si, ll ss, ll se, ll li, ll ri, vector<Node>& Tree, vector<ll>& a) {
        if(li>se || ri<ss){
            Node tmp;
            tmp.mi = MOD;
            tmp.mx = -MOD;
            return tmp;
        }
        if(ss>=li && se<=ri){
            return Tree[si];
        }
        ll mid = (ss+se)/2;
        Node l = query(2*si, ss, mid, li, ri,Tree,a);
        Node r = query(2*si+1, mid+1, se, li, ri,Tree,a);
        Node tmp;
        tmp.mi = min(l.mi,r.mi);
        tmp.mx = max(l.mx,r.mx);
        return tmp;
}

void buildTree(ll si, ll ss, ll se,vector<Node>& Tree, vector<ll>& a) {
        if(ss==se){
            Tree[si].mi = a[ss];
            Tree[si].mx = a[ss];
            return;
        }
        ll mid = ss+(se-ss)/2;
        buildTree(2*si, ss, mid,Tree,a);
        buildTree(2*si+1, mid+1, se,Tree,a);
        Tree[si].mi= min(Tree[2*si].mi, Tree[2*si+1].mi);
        Tree[si].mx= max(Tree[2*si].mx, Tree[2*si+1].mx);
}
