#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <math.h>

template<class T>
void printVec(std::vector<T> vec);
std::vector<int> shuffle(std::vector<int> vec);
std::vector<int> MergeSort(std::vector<int> vec);
std::vector<int> Merge(std::vector<int> left, std::vector<int> right);

int main()
{
	std::vector<int> initial {1,2,3,4,5,6,7,8,9};
	std::vector<int> shuffled = shuffle(initial);
	printVec(shuffled);
	std::cout << "-------------------------------------" << std::endl;
	std::vector<int> sorted = MergeSort(shuffled);
	printVec(sorted);
}
template<class T>
void printVec(std::vector<T> vec)
{
	for(auto val : vec)
		std::cout << val << std::endl;
}

std::vector<int> shuffle(std::vector<int> vec)
{
	auto rng = std::default_random_engine {};
	rng.seed(unsigned(time(NULL)));
	std::shuffle(std::begin(vec), std::end(vec), rng);
	return vec;
}

std::vector<int> MergeSort(std::vector<int> vec)
{
	const int midpoint = floor(vec.size() / 2);
	std::vector<int> left, right;
	std::vector<int> leftSub(vec.begin(), vec.begin() + midpoint);
	std::vector<int> rightSub(vec.begin() + midpoint, vec.end());

	if(vec.size() <= 1)
		return vec;

	left = MergeSort(leftSub);
	right = MergeSort(rightSub);

	return Merge(left, right);
}

std::vector<int> Merge(std::vector<int> left, std::vector<int> right)
{
	std::vector<int> result;

	while(left.size() != 0 && right.size() != 0)
	{
		if(left.front() <= right.front())
		{
			result.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}

	while(left.size() != 0)
	{
		result.push_back(left.front());
		left.erase(left.begin());
	}

	while(right.size() != 0)
	{
		result.push_back(right.front());
		right.erase(right.begin());
	}

	return result;
}




