#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <chrono>
using namespace std;
template <typename T>
void display(const T& nums)
{
	for(auto it = nums.begin(); it!=nums.end(); it++)
	{
		cout<<*it<<", ";
	}
}

void displaymap(map<int,int>& nums)
{
	for(auto it = nums.begin(); it!=nums.end(); it++)
	{
		cout<<it->first<<", ";
	}
}

template <typename T1, typename T2>
void insertSort( T1& nums, T2& vecnum)
{
	for(auto lit = nums.begin(); lit!=nums.end(); lit++)
	{
		if(vecnum.size()==0) vecnum.push_back(*lit);
		else
		{
			auto vit = vecnum.begin(); //vector iterator
			while(*vit<*lit && vit!=vecnum.end())
				vit++;
			vecnum.insert(vit, *lit);
		}
	}
}

template <typename T>
void remove(T& vecnum)
{
	while(vecnum.size()!=0)
	{
		int s = rand() % vecnum.size();
		auto vit = vecnum.begin();
		while(s!=0)
		{
			s--;
			vit++;
		}
		vecnum.erase(vit);
	}
}

int main()
{
	vector<int> nums;
	map<int, int> mapnum;
	vector<int> vecnum;
	list<int> listnum;
	int n;
	cout<<"Enter N"<<endl;
	cin>>n;
	chrono::time_point<chrono::system_clock> begin, end;
	srand (time(NULL));
	while(nums.size()!=n)
	{
		int x = rand() % n + 1;
		if(find(nums.begin(), nums.end(), x) == nums.end())
			nums.push_back(x);
	}
	// cout<<"List of Random numbers:"<<endl;
	// auto it = nums.begin();
	// while(it!=nums.end())
	// {
	// 	cout<<*it<<", ";
	// 	it++;
	// }
	// cout<<"Sorting and inserting:"<<endl;
	
	begin = chrono::system_clock::now();
	insertSort(nums, vecnum);
	end = chrono::system_clock::now();
	chrono::duration<double> elapsed_seconds = end-begin;
	cout<< "Time elapsed for vectors insertion: " << elapsed_seconds.count() << "s\n";
	begin = chrono::system_clock::now();
	remove(vecnum);
	end = chrono::system_clock::now();
	elapsed_seconds = end-begin;
	cout<< "Time elapsed for vectors deletion: " << elapsed_seconds.count() << "s\n";
	

	begin = chrono::system_clock::now();
	insertSort(nums, listnum);
	end = chrono::system_clock::now();
    elapsed_seconds = end-begin;
    cout<< "Time elapsed for list insertion: " << elapsed_seconds.count() << "s\n";
	begin = chrono::system_clock::now();
	remove(listnum);
	end = chrono::system_clock::now();
	elapsed_seconds = end-begin;
	cout<< "Time elapsed for list deletion: " << elapsed_seconds.count() << "s\n";

	begin = chrono::system_clock::now();
	while(mapnum.size()!=n)
	{
		int x = rand() % n + 1;
		mapnum.insert(pair<int, int>(x,1));
		//displaymap(nums);
		//cout<<endl;
	}
	end = chrono::system_clock::now();
    elapsed_seconds = end-begin;
    cout<< "Time elapsed for map insertion: " << elapsed_seconds.count() << "s\n";
	begin = chrono::system_clock::now();
	remove(mapnum);
	end = chrono::system_clock::now();
	elapsed_seconds = end-begin;
	cout<< "Time elapsed for map deletion: " << elapsed_seconds.count() << "s\n";
	
	return 0;
}
