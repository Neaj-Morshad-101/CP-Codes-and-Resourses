
#include <iostream>
using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
///For pair Replace "int" with "pair<int, int>" 
//typedef tree<pair<ll,int>, null_type, less<pair<ll,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int main()
{
	ordered_set o_set;

	// insert function to insert in
	// ordered set same as SET STL
	o_set.insert(5);
	o_set.insert(1);
	o_set.insert(2);

	// Finding the second smallest element
	// in the set using * because
	// find_by_order returns an iterator
	cout << *(o_set.find_by_order(1))
		<< endl;

	// Finding the number of elements
	// strictly less than k=4
	cout << o_set.order_of_key(4)
		<< endl;

	// Finding the count of elements less
	// than or equal to 4 i.e. strictly less
	// than 5 if integers are present
	cout << o_set.order_of_key(5)
		<< endl;

	// Deleting 2 from the set if it exists
	if (o_set.find(2) != o_set.end())
		o_set.erase(o_set.find(2));

	// Now after deleting 2 from the set
	// Finding the second smallest element in the set
	cout << *(o_set.find_by_order(1))
		<< endl;

	// Finding the number of
	// elements strictly less than k=4
	cout << o_set.order_of_key(4)
		<< endl;


  // Thus we can now solve the above problem easily 
  // i.e. count of elements between l and r can be found by:
o_set.order_of_key(r+1) – o_set.order_of_key(l)
	return 0;
}
