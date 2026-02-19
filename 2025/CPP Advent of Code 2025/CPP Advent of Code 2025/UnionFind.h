#pragma once
#include<vector>
#include<unordered_map>
#include <queue>
#include <functional>

class UnionFind
{

	private:
		std::vector<int> parent; 
	public:
		UnionFind(int i);
		int find(int i);
		void unite(int i, int j);
		long long getLargestThreeSizes(); 
		bool AllConnected();
		
	
};

