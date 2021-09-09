#include<vector>;
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

class ReConstructBinaryTree
{
	
		public: void Test();
			  //给前序、中序找 树
			  TreeNode* ReConstructBinaryTree1(vector<int> pre, vector<int> vin);
			  //拓展：  给中序、后序找树
			  TreeNode* ReConstructBinaryTree2(vector<int> after, vector<int> vin);
		private:
};

