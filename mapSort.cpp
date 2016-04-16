#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

void displaymap(map<int,int>& nums)
{
	auto it = nums.begin();
	while(it!=nums.end())
	{
		cout<<it->first<<", ";
		it++;
	}
}

void remove(map<int,int>& nums)
{
	while(nums.size()!=0)
	{
		//cout<<"Enter position to delete between 0 and "<< vecnum.size()-1<<endl;
		int s = rand() % nums.size();
		//cin>>s;
		// if(s>vecnum.size()-1)
		// {
		// 	cout<<"Invalid index position"<<endl;
		// 	continue;
		// }
		auto vit = nums.begin();
		while(s!=0)
		{
			s--;
			vit++;
		}
		nums.erase(vit);
		cout<<"Remaining Elements:"<<endl;
		displaymap(nums);
		cout<<endl;
	}
}

int main()
{
	map<int, int> nums;
	int n;
	cout<<"Enter N"<<endl;
	cin>>n;
	chrono::time_point<chrono::system_clock> begin, end;
	srand (time(NULL));
	int i =0;
	while(nums.size()!=n)
	{
		int x = rand() % n + 1;
		nums.insert(pair<int, int>(x,i));
		displaymap(nums);
		cout<<endl;
	}
	remove(nums);
}