#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Node {
	int n;
	vector<Node*> c;
	int in_cnt = 0;
	int visit = 0;
};

vector<Node*> nodes;

bool dfs(Node* node) {
	if (node->visit == 1) return false;
	
	bool result = true;
	for (auto it = node->c.begin(); it != node->c.end(); it++) {
		if (node->n == (*it)->n) result = false;
		if (!dfs(*it)) result = false;
	}

	node->visit = 1;

	return result;
}

/* 615 - Is it a tree? */
int main() {
	int N1, N2;
	int k = 0;
	while (cin >> N1 >> N2 && N1 >= 0) {
		// test case number
		k++;

		// add them to vector
		bool fail = false;
		nodes.clear();
		if (N1 != 0) {
			// add first node
			Node *child = new Node();
			child->n = N2;
			child->in_cnt++;

			Node *parent = new Node();
			parent->n = N1;
			parent->c.push_back(child);

			nodes.push_back(parent);
			nodes.push_back(child);
			while (cin >> N1 >> N2 && N1 != 0) {
				parent = child = nullptr;
				for (unsigned int i = 0; i < nodes.size(); ++i) {
					if (nodes[i]->n == N1) {
						parent = nodes[i];
					}
					if (nodes[i]->n == N2) {
						child = nodes[i];
					}
				}

				if (child == nullptr) {
					child = new Node();
					child->n = N2;
					nodes.push_back(child);
				}
				if (parent == nullptr) {
					parent = new Node();
					parent->n = N1;
					nodes.push_back(parent);
				}
				child->in_cnt++;
				if (child->in_cnt > 1) fail = true;
				parent->c.push_back(child);
			}
			// find root node
			Node *root = nullptr;
			for (unsigned int i = 0; i < nodes.size(); ++i) {
				if (nodes[i]->in_cnt == 0) {
					root = nodes[i];
					break;
				}
			}
			if (root == nullptr) {
				fail = true;
				goto exit;
			}
			// DFS traverse
			if (!dfs(root))
				fail = true;
			// is there any nonvisit node?
			for (auto it = nodes.begin(); it != nodes.end(); it++) {
				if ((*it)->visit == 0) {
					fail = true;
					goto exit;
				}
			}
				
		}
		exit:
		cout << "Case " << k;
		if (!fail) cout << " is a tree.";
		else cout << " is not a tree.";
		cout << endl;

		// clear
		for (auto it = nodes.begin(); it != nodes.end(); it++)
			delete *it;
	}

	return 0;
}
