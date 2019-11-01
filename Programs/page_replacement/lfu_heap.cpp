// C++ program for LFU cache implementation
#include <bits/stdc++.h>
using namespace std;

int faults = 0;
int cache_hits = 0;

void print_cache(vector<pair<int, int>> cache){
	for(auto c: cache){
		cout << c.first << " ";
	}
	cout << endl;
}

// Generic function to swap two pairs
void swap(pair<int, int>& a, pair<int, int>& b)
{
	pair<int, int> temp = a;
	a = b;
	b = temp;
}

// Returns the index of the parent node
inline int parent(int i)
{
	return (i - 1) / 2;
}

// Returns the index of the left child node
inline int left(int i)
{
	return 2 * i + 1;
}

// Returns the index of the right child node
inline int right(int i)
{
	return 2 * i + 2;
}

// Self made heap tp Rearranges
// the nodes in order to maintain the heap property
void heapify(vector<pair<int, int> >& v,
			unordered_map<int, int>& m, int i, int n)
{
	int l = left(i), r = right(i), minim;
	if (l < n)
		minim = ((v[i].second < v[l].second) ? i : l);
	else
		minim = i;
	if (r < n)
		minim = ((v[minim].second < v[r].second) ? minim : r);
	if (minim != i) {
		m[v[minim].first] = i;
		m[v[i].first] = minim;
		swap(v[minim], v[i]);
		heapify(v, m, minim, n);
	}
}

// Function to Increment the frequency
// of a node and rearranges the heap
void increment(vector<pair<int, int> >& v,
			unordered_map<int, int>& m, int i, int n)
{
	++v[i].second;
	heapify(v, m, i, n);
}

// Function to Insert a new node in the heap
void insert(vector<pair<int, int> >& v,
			unordered_map<int, int>& m, int value, int& n)
{

	if (n == v.size()) {
		m.erase(v[0].first);
		// cout << "Cache block " << v[0].first << " removed.\n";
		v[0] = v[--n];
		heapify(v, m, 0, n);
	}
	v[n++] = make_pair(value, 1);
	m.insert(make_pair(value, n - 1));
	int i = n - 1;

	// Insert a node in the heap by swapping elements
	while (i && v[parent(i)].second > v[i].second) {
		m[v[i].first] = parent(i);
		m[v[parent(i)].first] = i;
		swap(v[i], v[parent(i)]);
		i = parent(i);
	}
	// cout << "Cache block " << value << " inserted.\n";
}

// Function to refer to the block value in the cache
void refer(vector<pair<int, int> >& cache, unordered_map<int,
					int>& indices, int value, int& cache_size)
{
	if (indices.find(value) == indices.end()){
		faults++;
		cerr << "fault" << endl;
		insert(cache, indices, value, cache_size);
	}
	else{
		cache_hits++;
		cerr << "hit" << endl;
		increment(cache, indices, indices[value], cache_size);
	}
	print_cache(cache);
}

// Driver Code
int main()
{
  int cache_max_size, cache_size = 0;
  unordered_map<int, int> indices;

  vector<int> requests;
  int t, n;
  cout << "Enter the number of requests: " ;
  cin >> n;
  cout << "Enter the requests: " << endl;
  for (int i = 0; i < n; ++i){
    cin >> t;
    requests.push_back(t);
  }
  cout << "Enter the number of cache frames: ";
  cin >> cache_max_size;
	vector<pair<int, int> > cache(cache_max_size);

	for(int r: requests){
  	refer(cache, indices, r, cache_size);
	}

	cout << faults << " page faults" << endl;
	cout << cache_hits << " cache hits" << endl;
	return 0;
}
