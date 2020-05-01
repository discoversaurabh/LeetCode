/*
First Unique Number

You have a queue of integers, you need to retrieve the first unique integer in the queue.

Implement the FirstUnique class:

FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
void add(int value) insert value to the queue.


Example 1:

Input:
["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
[[[2,3,5]],[],[5],[],[2],[],[3],[]]
Output:
[null,2,null,2,null,3,null,-1]

Explanation:
FirstUnique firstUnique = new FirstUnique([2,3,5]);
firstUnique.showFirstUnique(); // return 2
firstUnique.add(5);            // the queue is now [2,3,5,5]
firstUnique.showFirstUnique(); // return 2
firstUnique.add(2);            // the queue is now [2,3,5,5,2]
firstUnique.showFirstUnique(); // return 3
firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
firstUnique.showFirstUnique(); // return -1

Example 2:

Input:
["FirstUnique","showFirstUnique","add","add","add","add","add","showFirstUnique"]
[[[7,7,7,7,7,7]],[],[7],[3],[3],[7],[17],[]]
Output:
[null,-1,null,null,null,null,null,17]

Explanation:
FirstUnique firstUnique = new FirstUnique([7,7,7,7,7,7]);
firstUnique.showFirstUnique(); // return -1
firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7]
firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3]
firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3,3]
firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7,3,3,7]
firstUnique.add(17);           // the queue is now [7,7,7,7,7,7,7,3,3,7,17]
firstUnique.showFirstUnique(); // return 17

Example 3:

Input:
["FirstUnique","showFirstUnique","add","showFirstUnique"]
[[[809]],[],[809],[]]
Output:
[null,809,null,-1]

Explanation:
FirstUnique firstUnique = new FirstUnique([809]);
firstUnique.showFirstUnique(); // return 809
firstUnique.add(809);          // the queue is now [809,809]
firstUnique.showFirstUnique(); // return -1



Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^8
1 <= value <= 10^8
At most 50000 calls will be made to showFirstUnique and add.
*/

#include"AllHeader.h"

class FirstUnique {
public:
	//list storing unique indexes or probabe unique indexes
	list<int> uniqueList;

	//SAURABH - Earlier I was taking the following DS and it was causing Run time exceeded error
	// as logic involved searching in unique list which was too long for a bigger and smartly designed test case
	//map storing number as key and pair of this number frequecy and list node address
	//unordered_map<int, pair<int, list<int>::iterator>> allNumMap;

	//map storing number as key and pair of <whether no is a part of unique list or not> and list node address
	unordered_map<int, pair<bool, list<int>::iterator>> allNumMap; //we surely need node address--think about it

	void smartlyAddNumberAndManipulate(int value)
	{
		if (allNumMap.find(value) == allNumMap.end())
		{
			uniqueList.push_back(value);
			allNumMap[value].first = true;
			list<int>::iterator i = uniqueList.end();
			i--;
			allNumMap[value].second = i; //uniqueList.rbegin();  //uniqueList.end()-1;   //access last elements
		}
		else
		{
			if (allNumMap[value].first)
			{
				//old - check whther already present in list then erase
				//if (allNumMap[value].first > 1)
				//{
					//pruning no need to find now - SAURABH HANDLED VERY SMARTLY HERE
				// THIS FIND WAS CAUSING THE RUN TIME EXCEEDED ERROR EARLIER - SAURABH
				 //   if(std::find(uniqueList.begin(), uniqueList.end(), value) != uniqueList.end())
				uniqueList.erase(allNumMap[value].second);
				//}
				allNumMap[value].first = false;
			}
		}
	}

	FirstUnique(vector<int>& nums) {
		int size = nums.size();
		for (int i = 0; i < size; i++)
		{
			smartlyAddNumberAndManipulate(nums[i]);
		}
	}

	int showFirstUnique() {
		return uniqueList.empty() ? -1 : uniqueList.front();
	}

	void add(int value) {
		smartlyAddNumberAndManipulate(value);
	}
};

int main()
{
	vector<int> num = { 7,7,7,7,7,7 };
	FirstUnique *fu = new FirstUnique(num);
	cout << "1 : "<< fu->showFirstUnique() << endl;  // return -1
	fu->add(7);            // the queue is now [7,7,7,7,7,7,7]
	fu->add(3);            // the queue is now [7,7,7,7,7,7,7,3]
	fu->add(3);            // the queue is now [7,7,7,7,7,7,7,3,3]
	fu->add(7);            // the queue is now [7,7,7,7,7,7,7,3,3,7]
	fu->add(17);           // the queue is now [7,7,7,7,7,7,7,3,3,7,17]
	cout << "2 : "<< fu->showFirstUnique() << endl; // return 17
}

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */