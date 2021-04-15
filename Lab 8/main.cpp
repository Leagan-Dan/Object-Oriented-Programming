#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

class Compare {
public:
	bool operator() (pair<string, int> p1, pair<string, int> p2) {
		if (p1.second < p2.second)
			return true;
		if (p1.second > p2.second)
			return false;
		if (p1.first < p2.first)
			return false;
		return true;
	}
};

int egale(char* s1, char* s2)
{
	int i = 0;
	while (s1[i] != NULL || s2[i] != NULL)
	{
		if (s1[i] != s2[i])
			return 0;
	}
	return 1;
}
int main()
{
	string s("I bought an apple. Then I eat an apple. Apple is my favorite.");
	int i = 0;
	while (s[i] != NULL)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] - ('A' - 'a');
		i++;
	}
	cout << s << endl;
	string sep = " .,?!";
	vector<string> v;
	
	int counter = 0;
	int l = 0;
	for (int i = 0; i < s.length(); i++)
	{
		char c = s.at(i);
		int k = 0;
		for (int j = 0; j < 5; j++)
			if (sep[j] == c)
				k = 1;
		if (k == 1 )
		{
			if ((s.at(l) >= 'a' && s.at(l) <= 'z') || (s.at(l) >= 'A' && s.at(l) <= 'Z'))
			{
				string sub = s.substr(l, i - l);
				l = i + 1;
				v.push_back(sub);
				counter++;
			}
			else
				l++;
		}
	}
	cout << endl;
	cout << "Primul vector, avand cuvintele delimitate: " << endl;
	for (int i = 0; i < counter; i++)
		cout << v[i] << endl;

	int counter2 = 0;

	vector<string> v2;
	map<string, int> myMap;

	for (int i = 0; i < counter; i++)
	{

		if (myMap.count(v[i]) != 0) {
			myMap[v[i]] += 1;
		}
		else {
			myMap[v[i]] = 1;
		}

		if (myMap[v[i]] == 1)
		{
			v2.push_back(v[i]);
			counter2++;
		}
	}
	cout << endl;
	cout << "Numarul de aparitii pentru fiecare cuvant:" << endl;
	for (int i = 0; i < counter; i++)
	{
		cout << myMap[v[i]] << " ";
	}
	cout << endl<<endl;

	cout << "Vectorul final, cu cate o aparitie pentru fiecare cuvant: (nesortat)" << endl;
	for (int i = 0; i < counter2; i++)
		cout << v2[i] << " => " << myMap[v2[i]] << endl;


	cout << endl;
	cout << "Vectorul sortat in functie de aparitii si alfabet"<<endl;
	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> myQueue;
	for (auto mapIterator = myMap.begin(); mapIterator != myMap.end(); mapIterator++) 
		myQueue.push(pair<string, int>(mapIterator->first, mapIterator->second));

		while (!myQueue.empty())
		{
			printf("%s => %d\n", myQueue.top().first, myQueue.top().second);
			myQueue.pop();
		}
	return 0;
}