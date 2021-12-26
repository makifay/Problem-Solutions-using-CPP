// ----------------------------------
// Union Find Data Structure 

class UnionFind {
public:
	UnionFind(int n) 
		: roots(n), size(n,1), cnt(n) { 
		// size[i] = 1; // firstly, size of each component is 1 
		
		// >> Link to itself (self root)	
		std::generate(roots.begin(), roots.end(), 
					  [f = 0 ]() mutable { return f++; }  );
	}
    
	/* i is a root node when "roots[i]=i" */
	int findRoot(int id) { // with path compression
        if(id == roots[id]) return id;
         
        return roots[id] = findRoot(roots[id]);
    }
    /*Alternative iterative way:
	int findRoot(int id) {

    // Find the root of the component/set
    int root = id;
    while (root != roots[root]) root = roots[root];

    // path compression: changing root value if possible
    while (id != root) {
      int next = roots[id];
      roots[id] = root;
      id = next;
    }
    return root;
  }*/

	void unify(int id, int dir_id) { 
		// check whether they're already connected      
        if(connected(id, dir_id)) return;  
	
        int dirRoot = findRoot(dir_id); 
        int idRoot = findRoot(id);
        
		// Combine smaller component into the larger
        if(size[idRoot] >= size[dirRoot] ){
            roots[dirRoot] = idRoot;
            size[idRoot] += size[dirRoot]; 
			size[dirRoot] = 0;
        }
        else{
            roots[idRoot] = dirRoot;
            size[dirRoot] += size[idRoot] ; 
			size[idRoot] = 0;
        }
		
		// Decrease the number of components 
		// because 2 distinct component are combined
        --cnt;
    }
	
	 // check if the 'a' and 'b' are in the same component
	bool connected(int a, int b) {
		return find(a) == find(b);
	}

	// size of the component which has 'a'
	int componentSize(int a) {
		return size[find(a)];
	}

	// the number of remaining components/sets
	int componentCnt() {
		return cnt;
	}

private:
	int cnt ; // number of elements in the UF
	vector<int> size; // size of each component
	vector<int> roots; // roots[i]: parent of "i"
};
