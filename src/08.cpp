//============================================================================
// Name        : Ktylhy.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
using namespace std;

int main() {
	map<char, int> mymap;

	string str;
	string str2;
	getline(cin, str);

	for(unsigned int i = 0; i < str.size(); i++){
		mymap[str[i]] += 1;
		if(mymap[str[i]] == 1){
			str2 += str[i];
		}
	}

	int max = 0, pos = 0;

	for (auto it = mymap.begin(); it != mymap.end(); ++it){
		if(max == it->second){
		}
		if(max < it->second){
			max = it->second;
		}
	}
	for(auto it = mymap.begin(); it != mymap.end(); ){
		if(max != it->second){
			mymap.erase(it);
			it = mymap.begin();
		}
		else{
			it++;
		}
	}

	if(mymap.size() == 1){
		for(auto it = mymap.begin(); it != mymap.end(); ++it){
			if(max == it->second){
				cout << it->first << " " << max << endl;
				break;
			}
		}
	}
	else{
		for(unsigned int i = 0; i < str2.size(); i++){
			bool flag = true;
			for(auto it = mymap.begin(); it != mymap.end(); ++it){
				if(it->first == str2[i]){
					flag = false;
				}
			}
			if(flag){
				str2.erase(i, 1);
				i--;
			}
		}
		if(mymap.size() % 2 == 0){
			pos = mymap.size() / 2 - 1;
		}
		else{
			pos = mymap.size() / 2;
		}
		cout << str2[pos] << " " << max << endl;
	}

//	for(unsigned int i = 0; i < str2.size(); i++){
//		cout << str2[i] << endl;
//	}
	return 0;
}
