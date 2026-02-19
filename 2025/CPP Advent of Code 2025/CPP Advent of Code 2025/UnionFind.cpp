#include "UnionFind.h"


struct CompareOnSecondElement {
	bool operator()(const std::tuple<int, long long>& a, const std::tuple<int, long long>& b)
	{
		return std::get<1>(a) < std::get<1>(b);
	}

};

UnionFind::UnionFind(int len)
{
	parent.resize(len);

	for (int i = 0; i < len; i++)
	{
		parent[i] = i;
	}
}
int UnionFind::find(int i)
{
	int root = parent[i];
	if (parent[root] != root)
	{
		return parent[i] = find(root);
	}
	return root; 

}
void UnionFind::unite(int i, int j)
{
	//int iRoot = find(i);
	//int jRoot = find(j);

	//if (iRoot == jRoot)
	//{
	//	return; 
	//}

	//parent[i] = jRoot; 
	//find(i);

	// Representative of set containing i
	int irep = find(i);

	// Representative of set containing j
	int jrep = find(j);

	// Make the representative of i's set
	// be the representative of j's set
	parent[irep] = jrep;
}

long long UnionFind::getLargestThreeSizes()
{
	long long ans = 1ll; 
	std::unordered_map<int,int> map; 
	
	for (int i = 0; i < parent.size(); i++)
	{
		map.try_emplace(parent[i], 0);
		map[parent[i]]++;
	}
	
	std::priority_queue<std::tuple<int, long long>,
		std::vector<std::tuple<int,  long long>>,
		CompareOnSecondElement> maxHeap;

	for (auto const& x : map)
	{
		maxHeap.push(std::tuple<int, long long>(x.first, x.second));
	}
	for (int i = 0; i < 3; i++)
	{
		ans *= std::get<1>(maxHeap.top());
		maxHeap.pop();
	}
	return ans; 
	
}