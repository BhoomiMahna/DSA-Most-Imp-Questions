class Solution {
public:
    class Node{
        public:
        Node* children[10];
        bool eow;
        Node(){
            for(int i=0;i<10;i++){
                children[i]=nullptr;
            }
            eow=false;
        }
    };
    Node* root=new Node();
    void insert(string s){
        Node* curr=root;
        for(char c:s){
            int idx=c-'0';
            if(curr->children[idx]==nullptr){
                curr->children[idx]=new Node();
            }
            curr=curr->children[idx];
        }
        curr->eow=true;
    }
    void dfs(Node* node,string curr,vector<int>&ans){
        if(node->eow)ans.push_back(stoi(curr));
        for(int i=0;i<=9;i++){
            if(node->children[i]){
                dfs(node->children[i],curr+char(i+'0'),ans);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        for(int i=1;i<=n;i++){
            insert(to_string(i));
        }
        vector<int>ans;
        dfs(root,"",ans);
        return ans;
    }
};