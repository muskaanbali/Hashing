#include<iostream>
using namespace std;

class Hashing {

	int *hashTbl;
	int s;
public:
	Hashing(int size) {

		s = size;
		hashTbl = new int[s];
		for(int i=0;i<s;i++)
			hashTbl[i] = 0;
	}

	int Hash(int key) {

		return key%s;
	}

	void LinearProbe() {

		int key;
		cout<<"Enter key values\n";
		for(int j=0;j<s;j++) {
			cin>>key;
			int loc = Hash(key);
			if(hashTbl[loc] == 0) {
				hashTbl[loc] = key;
			}
			else {
				for(int i=1;i<s;i++) {

					loc = ((key%s)+(i*i))%s;
					if(hashTbl[loc] == 0) {
						hashTbl[loc] = key;
						break;
					}
				}
			}
		}
	}

	void printHash() {

		for(int i=0;i<s;i++) {

			cout<<hashTbl[i]<<" ";
		}
	}
};

int main() {

	int n;
	cout<<"Enter size of hash table\n";
	cin>>n;
	Hashing h(n);
	h.LinearProbe();
	h.printHash();
}

