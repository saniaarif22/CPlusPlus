#include <iostream>
#include <vector>
#include <list>
using namespace std;

bool contains(list<int>& nums, int x)
{
	auto it = nums.begin();
	while(it!=nums.end())
	{
		if(*it==x) return true;
		it++;
	}
	return false;
}

void display(vector<int>& nums)
{
	auto it = nums.begin();
	while(it!=nums.end())
	{
		cout<<*it<<", ";
		it++;
	}
}

void insertSort(list<int>& nums, vector<int>& vecnum)
{
	auto lit = nums.begin(); //list iterator
	while(lit!=nums.end())
	{
		if(vecnum.size()==0) vecnum.push_back(*lit);
		else
		{
			auto vit = vecnum.begin(); //vector iterator
			while(*vit<*lit && vit!=vecnum.end())
				vit++;
			vecnum.insert(vit, *lit);
			cout<<endl;
		}
		display(vecnum);
		lit++;
	}
	cout<<endl;
}

void remove(vector<int>& vecnum)
{
	int s;
	while(vecnum.size()!=0)
	{
		cout<<"Enter position to delete between 0 and "<< vecnum.size()-1<<endl;
		cin>>s;
		if(s>vecnum.size()-1)
		{
			cout<<"Invalid index position"<<endl;
			continue;
		}
		auto vit = vecnum.begin();
		vecnum.erase(vit+s);
		cout<<"Remaining Elements:"<<endl;
		display(vecnum);
		cout<<endl;
	}
}

int main()
{
	list<int> nums;
	int n;
	cout<<"Enter N"<<endl;
	cin>>n;
	chrono::time_point<chrono::system_clock> begin, end;
	srand (time(NULL));
	while(nums.size()!=n)
	{
		int x = rand() % n + 1;
		if(!contains(nums, x))
			nums.push_back(x);
	}
	cout<<"List of Random numbers:"<<endl;
	auto it = nums.begin();
	while(it!=nums.end())
	{
		cout<<*it<<", ";
		it++;
	}
	
	cout<<endl;
	vector<int> vecnum;
	
	cout<<"Vectors:"<<endl;
	begin = chrono::system_clock::now();
	insertSort(nums, vecnum);
	end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end-begin;
    cout<< "Time elapsed: " << elapsed_seconds.count() << "s\n";
	
	remove(vecnum);
	
	return 0;
}
