#include <HashMap.cpp>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef MapElem<string, int> WordFreqElem;
typedef HashMap<WordFreqElem> WordFreqMap;

class WordFrequency {
public:
	WordFrequency()
	{
		map = new WordFreqMap();
	}
	
	~WordFrequency()
	{
		delete map;
	}
	
	void ReadText(const char* filename)
	{
		string line;
		ifstream file(filename);
		if(file.is_open())
		{
			while (getline(file, line))
			{
				istringstream iss(line);
				
				do
				{
					string sub;
					string temp = "";
					iss >> sub;
					if ( sub == "\0" )
					{
						break;
					}
					
					for ( int i = 0 ; i < sub.size(); i++ )
					{
						if ( (sub[i] >= 'a' && sub[i] <= 'z') || (sub[i] >= 'A' && sub[i] <= 'Z' ))
						{
							temp = temp + sub[i];
						}
						else
						{
							if ( temp == "" )
							{
								continue;
							}
							transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
							IncreaseFrequency(temp);
							temp = "";
						}
					}
					if ( temp == "" )
					{
						continue;
					}
					sub = temp;
					transform(sub.begin(), sub.end(), sub.begin(), ::tolower);
					IncreaseFrequency(sub);
					temp = "";
				} while (iss);
			}
		}
		file.close();
	}
	
	int GetFrequency(string word)
	{
		WordFreqElem* cursor = this->map->find(word);
		if ( cursor != NULL )
		{
			return cursor->val;
		}
		else
		{
			return 0;
		}
	}
	
	void IncreaseFrequency(string word)
	{
		WordFreqElem* cursor = this->map->find(word);
		if ( cursor != NULL )
		{
			cursor->val += 1;
		}
		else
		{
			this->map->insert(word, 1);
		}
	}
	
	void PrintAllFrequency()
	{
		map->print();
	}
	
private:
	WordFreqMap* map;
};
