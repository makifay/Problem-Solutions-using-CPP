// LeetCode-323: Number of Connected Components in an Undirected Graph
// author: Akif Aydogmus

#include <iostream>
#include <vector>
#include <set>
#include <array>
using namespace std;

class Solution{
public: 
int countComponents(int n, vector<vector<int>>& edges ){
	vector<int> ids (n); 
			
	for (int i=0; i<n; ++i ) ids[i]=i; 
	for (auto edge : edges) unify(edge[0], edge[1], ids); 
			
	set<int> st; 
	for (int i=0; i<n; ++i ) st.insert(find(i, ids));  
	   
	return st.size(); 
}

private:
// union of 2 nodes 
void unify (int node1, int node2, vector<int>& ids){
	int parent1= find(node1, ids); 
	int parent2= find(node2, ids); 
		
	if (parent1==parent2){ return; }
	else if (node1<node2){
		ids[parent1] = parent2; 
	}else{
		ids[parent2] = parent1; 
	}
}
	
// finding the parent of node, (taking id==taking root)
int find (int node, vector<int>& ids){
	if ( ids[node] != node ) 
	     ids[node] = find(ids[node], ids); 

	return ids[node];  // it's root 
}

};

int main(void){
    int n1= 5;   vector<vector< int>> edges1 {{0,1},{1,2},{3,4}} ; 
    int n2= 5;   vector<vector< int>> edges2 {{0,1},{1,2},{2,3},{3,4}}; 
    int n3= 8;   vector<vector< int>> edges3 {{0,1},{2,1},{3,4},{5,3}, {6,7} };    
    // ids: dbg1:  1 2 2 4 5 5 7 7,  dbg1:  2 2 2 5 5 5 7 7
    
    Solution s; 
    cout << "output-1: "<<  s.countComponents(n1, edges1) << endl;
    cout << "output-2: "<<  s.countComponents(n2, edges2) << endl;
    cout << "output-3: "<<  s.countComponents(n3, edges3) << endl;
}
