// Find the Longest Increasing Subsequence

// Time: O(NlogN)
// Space: O(n) : map stores the parents to print the values

#include <iostream>
#include <stack>
#include <set>
#include <map>

using namespace std;

// for index and element
struct Node {
    int elem;
    int index;
};

// overloading the compare operator for inserting into set
inline bool operator<(const Node& left, const Node& right)
{
    return left.elem < right.elem;
}

// printing the LIS using parents
void print(int input[], auto parent, set<Node>& st)
{
    // LIS will be stored in reverse order
    stack<int> lis;

    // start from the last item
    int index = st.rbegin()->index;

    int n = st.size();

    // retrieve LIS from parents
    while (n--) {
        lis.push(input[index]);
        index = parent[index];
    }

    // print LIS
    cout << ">> LIS: ";
    while (!lis.empty()) {
        cout << lis.top() << " ";
        lis.pop();
    }
}

void LIS(int arr[], int n)
{
    // empty ordered set "st"
    set<Node> st;

    // parent[i] stores the predecessor of element with index i
    // in the LIS ending at element with index i
    map<int, int> parent;

    for (int i = 0; i < n; i++) {
        // create new node from current element and its index
        Node curr = { arr[i], i };

        // skip the current element if already present in the set
        if (st.find(curr) != st.end()) {
            continue;
        }

        // insert current node into the set and get iterator to the
        auto it = st.insert(curr).first;

        // if the node is not inserted at the end, then delete the next node
        if (++it != st.end())
            st.erase(it);

        // update parent index
        it = st.find(curr);
        parent[i] = (--it)->index;
    }

    // print LIS using parent map
    print(arr, parent, st);
}

int main()
{
    int arr[] = { 2, 6, 3, 4, 1, 2, 9, 5, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);

    LIS(arr, n);

    return 0;
}

