#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;

        queue <UndirectedGraphNode *> node_queue;
        queue <UndirectedGraphNode *> visited_queue;
        unordered_set <UndirectedGraphNode *> visited_hash;
        UndirectedGraphNode* tmp;

		//initialize value, adding root node into queue and incrementing count & level 
		node_queue.push(node);
        visited_queue.push(node);
        visited_hash.insert(node);
        UndirectedGraphNode *p;
        int i;

		while(node_queue.size()>0){
			//Check first node in stack and remove it
			tmp=node_queue.front();
			node_queue.pop();

            p = new UndirectedGraphNode(tmp->label);
			int size=tmp->neighbors.size();
            tmp->neighbors.push_back(p);

			//cout << tmp->label << endl;            
            for(i=0;i<tmp->neighbors.size()-1;i++){
				//cout <<" sub"<<  tmp->neighbors[i]->label << endl;
                if (visited_hash.find(tmp->neighbors[i]) == visited_hash.end()){
					//cout << "push" <<  tmp->neighbors[i]->label << endl;
                    node_queue.push(tmp->neighbors[i]);
                    visited_hash.insert(tmp->neighbors[i]);
                    visited_queue.push(tmp->neighbors[i]);
                }
            }
		}
		//cout <<"node"<< endl;
        UndirectedGraphNode *result = node->neighbors.back();
		while(visited_queue.size()>0){
			tmp=visited_queue.front();
			node_queue.push(tmp);
            visited_queue.pop();
            p=tmp->neighbors.back();
			//cout << p->label << endl;           
            for(i=0;i<tmp->neighbors.size()-1;i++){
                p->neighbors.push_back(tmp->neighbors[i]->neighbors.back());
				//cout <<" sub"<<  p->neighbors.back()->label << endl;				
            }
		}
		//cout <<"link"<< endl;

		while(node_queue.size()>0){
			tmp=visited_queue.front();
			node_queue.front()->neighbors.pop_back();
            node_queue.pop();
		}
		//cout <<"revert"<< endl;
        return result;
    }
};



int main()
{
	//{0,1,5#1,2,5#2,3#3,4,4#4,5,5#5}

	UndirectedGraphNode* p0 = new UndirectedGraphNode(0);
	UndirectedGraphNode* p1 = new UndirectedGraphNode(1);
	UndirectedGraphNode* p2 = new UndirectedGraphNode(2);
	UndirectedGraphNode* p3 = new UndirectedGraphNode(3);
	UndirectedGraphNode* p4 = new UndirectedGraphNode(4);
	UndirectedGraphNode* p5 = new UndirectedGraphNode(5);
	p0->neighbors.push_back(p1);
	p0->neighbors.push_back(p5);
	p1->neighbors.push_back(p2);
	p1->neighbors.push_back(p5);
	p2->neighbors.push_back(p3);
	p3->neighbors.push_back(p4);
	p3->neighbors.push_back(p4);
	p4->neighbors.push_back(p5);
	p4->neighbors.push_back(p5);
//	p5->neighbors.push_back(p5);
		
	Solution solution;
	UndirectedGraphNode* r = solution.cloneGraph(p0);
#if 0
	cout << r->label << " " << r->neighbors.back()->label << endl;
#else
    queue <UndirectedGraphNode *> node_queue;
    unordered_set <UndirectedGraphNode *> visited_hash;
    UndirectedGraphNode* tmp;

	node_queue.push(r);
    visited_hash.insert(r);
    int i;
	while(node_queue.size()>0){
		//Check first node in stack and remove it
		tmp=node_queue.front();
		node_queue.pop();
		cout <<  tmp->label << endl;
        for(i=0;i<tmp->neighbors.size();i++){
			cout <<" sub"<<  tmp->neighbors[i]->label << endl;
	        if (visited_hash.find(tmp->neighbors[i]) == visited_hash.end()){
                node_queue.push(tmp->neighbors[i]);
                visited_hash.insert(tmp->neighbors[i]);
            }
		}
	}
#endif
	return 0;
}
