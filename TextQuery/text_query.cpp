#include "text_query.h"

using namespace std;

TextQuery::TextQuery(ifstream& fin) {
	_file = make_shared<vector<string>>();
	_wm = make_shared<map<string, set<line_no>>>();

	string lineContent;
	while (getline(fin,lineContent)) {
		_file->push_back(lineContent);

		line_no lineNo = _file->size();
		string word;
		istringstream iss(lineContent);
		while (iss>>word) {
			// 用auto& itsSet的话，后面就不能编译提示了？
			set<line_no>& itsSet = (*_wm)[word];

			itsSet.insert(lineNo);
		}
	}
	
}

QueryResult TextQuery::query(const string& word) {
	QueryResult qr;

	qr.word = word;
	qr._file = _file;

	//auto &se = (*_wm)[word];
	//decltype((*_wm)[word]) &se = (*_wm)[word];

	set<line_no>& se = (*_wm)[word];
	qr._lines.reset(&se); //TODO bind the shared_ptr to the set instance
	qr.count = se.size();

	return qr;
}

void runQueries(ifstream& fin) {
	TextQuery tq(fin);

	while(true){
		cout<<"enter target word or enter q to exit:";
		string word;
		if(cin>>word && word !="q"){
			QueryResult res = tq.query(word);
			if (res.count>0) {
				print(res);  // 为什么这里还用上面的cout?
				continue;
			} else {
				cout << "no results..." << endl;
				continue;
			}
			
		} else {
			cout << "stopped" << endl;
			break;
		}
	}

}

void print(const QueryResult& qs) {
	cout <<qs.word << ">>>>>>>>>> "<<qs.count << " lines found:" << endl;
	auto iter = qs._lines->begin();
	while (iter!= qs._lines->end()) {
		string& line = (*(qs._file))[(*iter)-1];
		cout <<"line ["<<*iter<<"]\t"<< line << endl;
		iter++;
	}
}

int main() {
	ifstream fin;
	fin.open("test.txt");
	runQueries(fin);

	system("pause");
}
