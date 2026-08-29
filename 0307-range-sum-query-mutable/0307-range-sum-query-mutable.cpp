class NumArray {
private:
    vector<int> tree;
    int n;
    int merge(int left, int right) {
        return left+right;
    }  
    void build(int node, int start, int end, vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        } 
        int mid = (start+end)/2; 
        build(2*node+1, start, mid, arr);
        build(2*node+2, mid + 1, end, arr); 
        tree[node] = merge(tree[2*node+1], tree[2*node+2]);
    } 
    int query(int node, int start, int end, int l, int r) { 
        if (r < start || end < l)
            return 0; 
        if (l <= start && end <= r)
            return tree[node]; 
        int mid = (start+end)/2; 
        int left = query(2*node+1, start, mid, l, r);
        int right = query(2*node+2, mid + 1, end, l, r); 
        return merge(left, right);
    } 
    void updateTree(int node, int start, int end, int pos, long long value) {
        if (start == end) {
            tree[node] = value;
            return;
        } 
        int mid = (start + end) / 2; 
        if (pos <= mid)
            updateTree(2*node+1, start, mid, pos, value);
        else
            updateTree(2*node+2, mid+1, end, pos, value);

        tree[node] = merge(tree[2*node+1], tree[2*node+2]);
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        if(n>0){
            tree.resize(4*n, 0);
            build(0, 0, n-1, nums);
        }
    }
    
    void update(int index, int val) {
        if(n == 0)  return;
        updateTree(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        if(n == 0)      return 0;
        return query(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */