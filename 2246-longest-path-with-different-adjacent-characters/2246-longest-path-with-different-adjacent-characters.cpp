class Solution {
public:
    void construct_tree(vector<int>& parent,vector<vector<int>>& Tree,int n,int idx)
    {
        for(int i=1;i<n;i++)
        {
            Tree[parent[i]].push_back(i);
        }
    }

    int ans=0;
    int solve(int u,vector<vector<int>> &Tree,string &s)
    {
        int prev_len=0;//to combine to branches of the tree at root u i will store onr of the branch as prev_len

        int maxi=0;//maxi_length that this subtree can give to its parent
        int max_path=0;//maximum path than can occur when i combine two branches

        int n=Tree[u].size();
        for(int i=0;i<n;i++)
        {
            int v=Tree[u][i];
            int len=solve(v,Tree,s);
            if(s[u]==s[v])
            {
                len=0;//make the len zero if the immidiate child has same character as its parent
            }
            max_path=max(max_path,len+prev_len+1);//to fix the maximum path possible from this root
            ans=max(ans,max_path);//to get the max answer possible for this entire tree
            prev_len=max(prev_len,len);//which branch gives the highest length
        }
        return prev_len+1;//the return the branch that give the highest length
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        if(n==1)
        {
            return 1;
        }
        vector<vector<int>>Tree(n);
        construct_tree(parent,Tree,n,0);
        solve(0,Tree,s);
        return ans;
    }
};