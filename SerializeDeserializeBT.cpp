/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    int splitData(string &data)
    {
        int pos=data.find(",");
        int val = stoi(data.substr(0, pos));
        //update main dtaa
        data = data.substr(pos+1);
        return val;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," +serialize(root->right);   
    }
    
    TreeNode* deserializeUtil(string &data)
    {
        if(data[0] == '#')
        {
            if(data.size() >= 2) data = data.substr(2);
            return NULL;
        }
        else
        {
            TreeNode *node = new TreeNode(splitData(data));
            node->left = deserializeUtil(data);
            node->right = deserializeUtil(data);
            return node;
        }
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return deserializeUtil(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
